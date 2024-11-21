#include "stego.h"



int read_hidden_byte(FILE *fp) 
{
    int byteNum = 0;

    if(fp!= NULL)
    {
        char c = getc(fp);
        byteNum++;
        if(c == EOF)
        {
            return EOF;
        }
    }

    return byteNum;

}



void write_hidden_byte(char c, FILE *fp) {
    char byte = 0;
    for(int i = 7; i >= 0; i--) {
        byte = getc(fp);
        ungetc(0,fp);
        putc((byte & ~0x01) | ((c >> i) & 0x01), fp);
    }
}
