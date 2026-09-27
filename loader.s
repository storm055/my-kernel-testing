.set MAGIC, 0x1BADB002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .align 4
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kmain
.global LOADER

LOADER:
    mov $kernel_stack, %rsp
    movl %ebx, %edi
    movl %eax, %esi
    call kmain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
.align 16
kernel_stack:
    .skip 2*1024*1024

.section .note.GNU-stack,"",@progbits