all : start.o main.o led.o uart.o init.o exception.o
#	arm-linux-ld -Ttext 0 -Tdata 0x30000000 start.o led.o uart.o init.o main.o -o sdram.elf
	arm-linux-ld -T sdram.lds $^ -o sdram.elf
	arm-linux-objcopy -O binary -S sdram.elf sdram.bin
	arm-linux-objdump -D sdram.elf > sdram.dis

clean :
	rm *.bin *.o *.elf *.dis

cleanother :
	rm *.o *.elf

.PHONY : all clean cleanother

%.o : %.c
	arm-linux-gcc -c -o $@ $<

%.o : %.S
	arm-linux-gcc -c -o $@ $<
