

void print(char* str){
    unsigned short* Videomemory = (unsigned short*) 0xb8000;

    for (int i = 0; str[i] != '\0'; ++i){
        Videomemory[i] = 
                (Videomemory[i] & 0xFF00) | str[i];

    }
}

void kmain(void *multiboot_structure, unsigned int magicnumber){
    while(1)
    {
        print("hello, world!\n");
    }
    return;
}
