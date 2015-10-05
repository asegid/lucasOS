ASM = nasm

all: boot.bin floppy

boot.bin: boot.asm
	@echo '编译MBR..'
	$(ASM) boot.asm -o boot.bin

.PHONY: floppy
floppy: 
	@echo '制作软盘镜像..'
	dd if=/dev/zero of=empty.img bs=512 count=2880
	dd if=boot.bin of=lucasOS.img bs=512 count=1
	dd if=empty.img of=lucasOS.img skip=1 seek=1 bs=512 count=2879

.PHONY: clean
clean:
	rm boot.bin *.img
