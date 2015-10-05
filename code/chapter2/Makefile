CC = gcc
ASM = nasm
LD = ld

CC_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector
LD_FLAGS = -T link.ld -m elf_i386 -nostdlib

all: boot.o kernel.o link update_kernel

boot.o: boot.asm
	@echo '编译boot, 生成GRUB需要的信息..'
	$(ASM) -f elf boot.asm

kernerl.o: kernel.c
	@echo '编译kernel..'
	$(CC) $(CC_FLAGS) kernel.c -o kernel.o

.PHONY: kernel
link:
	@echo '链接boot和kernel, 生成最终kernel..'
	$(LD) $(LD_FLAGS) boot.o  kernel.o -o kernel

.PHONY: update_kernel
update_kernel:
	@echo '将kernel拷贝到主引导记录后， 最终生成OS启动镜像lucasOS.img'
	sudo mount lucasOS.img /mnt/lucasOS
	sudo cp kernel /mnt/lucasOS/kernel
	sleep 1
	sudo umount /mnt/lucasOS

.PHONY: clean
clean:
	rm *.o kernel
