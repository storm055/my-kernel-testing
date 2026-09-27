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
    /* 1. Configura o ponteiro de pilha para o TOPO do buffer */
    mov $kernel_stack_top, %esp

    /* 2. Passa os parâmetros do Multiboot via pilha (convenção cdecl 32 bits) */
    push %ebx    /* 2º argumento: Endereço da estrutura de informação do Multiboot */
    push %eax    /* 1º argumento: Magic number do Multiboot (0x2BADB002) */

    /* 3. Chama a função C principal: void kmain(uint32_t magic, uint32_t multiboot_addr) */
    call kmain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
.align 16
kernel_stack_bottom:
    .skip 2*1024*1024    /* Aloca 2 MB para a pilha */
kernel_stack_top:

.section .note.GNU-stack,"",@progbits