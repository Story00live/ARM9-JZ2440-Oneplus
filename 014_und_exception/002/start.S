/**
  *********************************************************************************************************
  * @File               : start.s 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-02 23:00:23 
  * @Brief              : Start
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

.text
.global __start

__start:
		b		reset												/* vector 0x00000000 : reset */
		ldr		pc,		undef_addr									/* vector 0x00000004 : undefine commend */
		
undef_addr:
		.word	do_undef
		
do_undef:
		/* -执行到这里之前-
		 * -1. lr_undef保存有被中断模式中的下一条即将执行的指令的地址-
		 * -2. SPSR_undef保存有被中断模式的CPSR-
		 * -3. CPSR中的M4-M0被设置为11011, 进入到undef模式-
		 * -4. 跳到0x00000004的地方执行程序-
		 */
		
		/* -sp_undef未设置, 先设置它- */
		ldr		sp,		=0x34000000
		
		/* -保存现场- */
		/* -在undef异常处理函数中有可能会修改r0-r12, 所以先保存- */
		/* -lr是异常处理结束后的返回地址, 也要保存- */
		stmdb	sp!,		{r0-r12, lr}
		
		/* -处理undef异常- */
		mrs		r0,		cpsr
		ldr		r1,		=undef_string
		bl		printException
		
		/* -恢复现场- */
		ldmia	sp!,		{r0-r12, pc}^									/* ^会把spsr的值恢复到cpsr里 */
		
undef_string:
		.string	"undefined instruction exception"
		
.align 4
		
reset:
		/* -关闭看门狗- */
		ldr		r0,		=0x53000000
		ldr		r1,		=0x00000000
		str		r1,		[r0]
		
		/* -设置MPLL, FCLK : HCLK : PCLK = 400M : 100M : 50M- */
		/* -LOCKTIME(0x4C000000) = 0xFFFFFFFF- */
		ldr		r0,		=0x4C000000
		ldr		r1,		=0xFFFFFFFF
		str		r1,		[r0]
		
		/* -CLKDIVN(0x4C000014) = 0x5, tFCLK : tHCLK : tPCLK = 1 : 4 : 8- */
		ldr		r0,		=0x4C000014
		ldr		r1,		=0x00000005
		str		r1,		[r0]
		
		/* -设置CPU工作于异步模式- */
		mrc		p15,		0,	r0,	c1,	c0,	0
		orr		r0,		r0,	#0xc0000000
		mcr		p15,		0,	r0,	c1,	c0,	0
		
		/* -设置MPLLCON(0x4C000004) = (92<<12)|(1<<4)|(1<<0)-
		 * -m = MDIV + 8 = 92 + 8 = 100-
		 * -p = PDIV + 2 = 1 + 2 = 3-
		 * -s = SDIV = 1-
		 * -FCLK = 2*m*Fin/(p*2^s) = 2*100*12/(3*2^1) = 400M-
		 */
		ldr		r0,		=0x4C000004
		ldr		r1,		=(92<<12)|(1<<4)|(1<<0)
		str		r1,		[r0]
		
		/* -一旦设置PLL,就会锁定lock time直到PLL输出稳定-
		 * -然后CPU工作于新的频率FCLK-
		 */
		
		/* -设置内存: SP栈- 
		 * -分辨是nor/nand启动-
		 * -写0到0地址, 再读出来-
		 * -如果得到0, 表示0地址上的内容被修改了, 它对应ram, 这就是nand启动-
		 * -否则就是nor启动-
		 */
		mov		r1,		#0
		ldr		r0,		[r1]											/* 读取0地址数据备份 */
		str		r1,		[r1]											/* 0 -> [0] */
		ldr		r2,		[r1]											/* r2 = [0] */
		cmp		r1,		r2											/* r1==r2? 如果相等表示是NAND启动 */
		ldr		sp,		=0x40000000+4096								/* 先假设是nor启动 */
		moveq	sp,		#4096										/* nand启动 */
		streq	r0,		[r1]											/* 恢复原来的值 */
		
		/* -调用sdram_init函数- */
		bl		sdram_init
		
		/* -重定位text, rodata, data段- */
		bl		copy2sdram
		
		/* -清除bss段- */
		bl		clean_bss
		
		ldr		pc,		=sdram
		
sdram:
		/* -初始化串口- */
		bl		uart0_init
		
		bl		dbg_print1
		
		/* -故意加入一条未定义指令- */
undef_code:
		.word	0xdeadc0de
		
		bl		dbg_print2
		
		/* -调用main函数- */
		ldr		pc,		=main										/* 绝对跳转, 程序跳转到SDRAM中执行 */
		
halt:
		/* -死循环- */
		b		halt
		
/********************************************** END OF FLEE **********************************************/
