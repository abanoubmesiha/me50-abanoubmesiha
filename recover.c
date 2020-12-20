#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, string argv[])
{
    // check if card name didn't passed to the program
    if (argc < 2)
    {
        printf("Please, type the name of the card\n");
        return 1;
    }

    string card = argv[1];

    // open card
    FILE *data = fopen(card, "r");

    // check if can't open
    if (data == NULL)
    {
        printf("Could not open card.raw.\n");
        return 1;
    }
    // create buffer
    unsigned char buffer[BUFFER_SIZE];

    // filename counter
    int count = 0;

    FILE *pic = NULL;

    // check if we've found a jpeg or not
    int jpg_found = 0; //false

    // go through card until there aren't any data left
    while (fread(buffer, BUFFER_SIZE, 1, data) == 1)
    {
        // read first 4 bytes of buffer and see if jpg signature using bitwise on last byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                // We found the start of a new pic so we close out the current pic
                fclose(pic);
            }
            else
            {
                // jpg discovered and now we start writing
                jpg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", count);
            pic = fopen(filename, "a");
            count++;
        }

        if (jpg_found == 1)
        {
            // write 512 bytes to file when we start finding jpgs
            fwrite(&buffer, BUFFER_SIZE, 1, pic);
        }

    }

    // close files
    fclose(data);
    fclose(pic);

    return 0;
}