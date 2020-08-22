#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])

{
    // If more than 2 arguments, ends code
    if (argc != 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Check if command argument promt is only digits
    int i = 0;
    while (argv[1][i] != '\0')
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        i++;
    }


    // Convert argv to an integer
    int key = atoi(argv[1]);
    
    // Take mod of the key
    int newkey = key % 26;
    
    // Get a string from the user
    string plaintext = get_string("plaintext:");
    
    // Loop the letters in the string and check that they are uppercase or lowercase
    printf("ciphertext:");

    for (i = 0; plaintext [i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Convert to ciphertext
            int letter = plaintext[i];
            int newletter = (letter - 64);
            int cipherletter = ((newletter + newkey) % 26);
            int f_lower = (cipherletter + 64);
            char finallower = f_lower;
            printf("%c", finallower);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i];
            int newletter = letter - 96;
            int cipherletter = (newletter + newkey) % 26;
            int f_upper = cipherletter + 96;
            char finalupper = f_upper;
            printf("%c", finalupper);
        }
        else 
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
