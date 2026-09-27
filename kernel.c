  int linha = 12; // variaveis globais!
  int coluna = 40;
unsigned short *VideoMemory = (unsigned short*) 0xb8000;

void print(char* str){

    for (int i = 0; str[i] != '\0'; ++i){
        VideoMemory[i] = 
                (VideoMemory[linha * 80 + coluna] & 0xFF00) | str[i];
                if (str[i] == '\n') {
                    linha = linha + 1; // avança para proxima linha //     
                    coluna = 0; // volta para coluna anterior //        
                }
                else {
                    //VideoMemory[linha * 80 + coluna]; // volta a anterior // 
                }
                if (coluna == 80) {
                    linha = linha + 1;
                    coluna = 0;
                }
    }
}

void kmain(void *multiboot_structure, unsigned int magicnumber){
    print("hello, \nworld!");
    print("este e um kernel experimental. tudo que ha de novo nele podera ser removido, adicionado ou melhorado.");
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