#ifndef STEGO_H
#define STEGO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int read_hidden_byte(FILE *fp);
void write_hidden_byte(char c, FILE *fp);

#endif