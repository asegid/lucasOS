MBOOT_MAGIC  equ 0x1BADB002  ; multiboot magic域，必须为此值
MBOOT_FLAGS  equ 0x00        ; multiboot flag域, GRUB启动时是否要做一些特殊操作
MBOOT_CHECKSUM  equ -(MBOOT_MAGIC + MBOOT_FLAGS) ; multiboot checksum域，校验上面两个域是否正确

[BITS 32]                    ; 以32位编译

section .text
  dd  MBOOT_MAGIC
  dd  MBOOT_FLAGS
  dd  MBOOT_CHECKSUM
  dd  start

[GLOBAL start]
[GLOBAL glb_mboot_ptr]
[EXTERN kernel_main]

start:
    cli
    mov esp, STACK_TOP
    mov ebp, 0
    and esp, 0FFFFFFF0H
    mov [glb_mboot_ptr], ebx
    call kernel_main      ; 调用内核入口函数
stop:
    hlt
    jmp stop

;-----------------------------------------------------------------------------

section .bss
stack:
    resb 32768
glb_mboot_ptr:
    resb 4

STACK_TOP equ $-stack-1
