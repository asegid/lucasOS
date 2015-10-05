org 7c00h

mov ax, cs
mov es, ax 
mov ax, msg
mov bp, ax
mov cx, msgLen
mov ax, 1301h
mov bx, 000fh
mov dl, 0
int 10h

msg: db "hello world, welcome to OS!"
msgLen: equ $ - msg
times 510 - ($ - $$) db 0
dw 0aa55h
