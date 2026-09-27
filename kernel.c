  int linha = 12; // variaveis globais!
  int coluna = 40;

void print(char* str){
    unsigned short* VideoMemory = (unsigned short*) 0xb8000;

    for (int i = 0; str[i] != '\0'; ++i){
        VideoMemory[i] = 
                (VideoMemory[linha * 80 + coluna] & 0xFF00) | str[i];
                if (str[i] == '\n') {
                    linha = linha + 1; // avança para proxima linha      
                    coluna = 0; // volta para coluna anterior         
                }
                else {
                    VideoMemory[linha * 80 + coluna];
                }

    }
}

void kmain(void *multiboot_structure, unsigned int magicnumber){
    print("hello, \nworld!");
    print("este e um kernel experimental. tudo que ha de novo nele podera ser removido, adicionado ou melhorado.")
    while[1] {
        
        _asm_ volatile ("hlt"); // deixa a cpu em modo de espera
    }
        
    return;
}
