#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTES 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //if the input is not formated correctly
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    //if there is no data in file
    if (!card)
    {
        printf("Forensic image cannot be opened. \n");
        return 1;
    }

    //create buffer array
    BYTE store[BYTES];
    //count images
    int count = 0;
    //store img numbers
    char name[8];
    //create current image file
    FILE *img = NULL;

    while (fread(store, BYTES, 1, card) == 1)
    {
        //looking for JPEG header
        if (store[0] == 0xff && store[1] == 0xd8 &&
            store[2] == 0xff && (store[3] & 0xf0) == 0xe0)
        {
            //create file name
            sprintf(name, "%03i.jpg", count);
            count ++;
            //the first file on the card
            if (count == 1)
            {
                img = fopen(name, "w");
                fwrite(store, BYTES, 1, img);
            }
            else
            {
                fclose(img);
                img = fopen(name, "w");
                fwrite(store, BYTES, 1, img);
            }
        }
        else
        {
            //if there already if an opened jpeg file
            if (count > 0)
            {
                fwrite(store, BYTES, 1, img);
            }
        }
    }
    fclose(card);
    fclose(img);
    return 0;
}
