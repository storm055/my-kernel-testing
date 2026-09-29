  int linha = 12; // variaveis globais!
  int coluna = 40;
  void putchar(char c);
void print_hex(unsigned int num);
void print_hex(unsigned int num);


unsigned short *VideoMemory = (unsigned short*) 0xb8000;

void putchar(char c);

void print(char* str){

    for (int i = 0; str[i] != '\0'; ++i){
        putchar(str[i]);
    }
}


void kmain(void *multiboot_structure, unsigned int magicnumber){
    print("hello, world!\n");
    print("este e um kernel experimental. tudo que ha de novo nele podera ser removido, adicionado ou melhorado.");
    
    print_hex(0x12345678);
        putchar('\n');
    while (1) {
        __asm__ volatile ("hlt"); // deixa a cpu em modo de espera //
    }
        
    return;
}

void clear_screen(void)
{
    for (int i = 0; i < 2000; i++)
    {
        VideoMemory[i] = ' ';
    }
}

    void putchar(char c) {

    if (c == '\n') {
    linha = linha + 1;
    coluna = 0;
    }

else {
    VideoMemory[linha * 80 + coluna] = (VideoMemory[linha * 80 + coluna] & 0xFF00) | c;
    coluna = coluna + 1;
}
if (coluna == 80) {
    linha = linha + 1;
    coluna = 0;
 }
}
 void print_hex(unsigned int num) 
 {
    char *hex = "0123456789ABCDEF";

 for (int i = 0; i < 8; i++) {  
      putchar(hex[(num >> (28 - (i * 4))) & 0xF]);
}
 }
 
