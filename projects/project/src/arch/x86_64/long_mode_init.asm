global long_mode_start

section .text
bits 64
long_mode_start:
    ; load 0 into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    ; print `OKAY` to screen
    mov rax, 0x2f59
    mov rax, 0x2f4e2f4e2f4f2f4a
mov qword [0xb8000], rax
    ;mov rax, 0x2f4A 2f4F 2f4E 2f4E 2f59
    hlt