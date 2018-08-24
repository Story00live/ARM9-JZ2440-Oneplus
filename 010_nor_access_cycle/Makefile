all :
	arm-linux-gcc -c -o led.o led.c
	arm-linux-gcc -c -o uart.o uart.c
	arm-linux-gcc -c -o init.o init.c
	arm-linux-gcc -c -o main.o main.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led.o uart.o init.o main.o -o init.elf
	arm-linux-objcopy -O binary -S init.elf init.bin
	arm-linux-objdump -D init.elf > init.dis

clean :
	rm *.bin *.o *.elf *.dis

cleanother :
	rm *.o *.elf

.PHONY : all clean cleanother
