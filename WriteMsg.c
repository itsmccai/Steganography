#include "stego.h"



int hidePxl(char *message, FILE *fp) 
{
    // int length = strlen(messgae);
    // char c = char(length);



    for (int i = 0; i < 8; i++) {
        write_hidden_byte(message[i], fp);
    }

    return 0;
}




