#include "stego.h"

struct ppm {
    char magic_number[3];
    char comments[2];
    int width;
    int height;
    int Maxval;
    
};

void print2screen(char *message) {
    printf("The hidden message is: %s\n", message);
}


int readHeader(struct ppm *pi, FILE *fp) {
    int c;
    int *pm;

    // Read magic number
    for (int i = 0; !isspace(c = getc(fp)) && i < 2; ++i) {
        pi->magic_number[i] = c;
    }
    pi->magic_number[2] = '\0';

    // Check for comments
    if ((c = getc(fp)) == '#') {
        // Process comment line
        pi->comments[0] = c;
        pi->comments[1] = '\0';

        // Skip all characters in the comment line until newline
        while ((c = getc(fp)) != '\n')
            ;
    } else {
        // No comment, push back the character
        ungetc(c, fp);
    }

    // Initialize dimensions and Maxval
    pi->width = pi->height = pi->Maxval = 0;
    pm = &pi->width;

    // Read width, height, and Maxval
    for (int i = 0; i < 3; i++) {
        while (!isspace(c = getc(fp))) {
            if (!isdigit(c)) {
                printf("Corrupted format\n");
                return -1;
            }
            *pm = *pm * 10 + (c - '0');
        }
        ++pm;
    }

    return 0;
}

 void readMsg(FILE *fp)
 {
    




 }


int main()
{

    FILE *fp = fopen("TU_modified.ppm", "rb");
    struct ppm img;

    if (readHeader(&img, fp) != 0) 
    {
    printf("Error reading header\n");
    fclose(fp);
    return -1;
    }

    printf("Magic Number: %s\n", img.magic_number);
    printf("Width: %d\n, Height: %d, Maxval: %d\n", img.width, img.height, img.Maxval);

    // Proceed to read pixel data...
    fclose(fp);















    return 0;
}
