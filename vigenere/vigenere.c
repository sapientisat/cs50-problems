// Encrypts messages using Vigenère’s cipher
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check for k argument
    if (argc != 2)
    {
        printf("Wrong argument!\nUsage: ./vigenere key\n");
        return 1;
    }
    else
    {
        // Get key value
        string k = argv[1];
        int key_length = strlen(k);
        // Array of integers used as a key
        int key[key_length];
        for (int j = 0; j < key_length; j++)
        {
            if (!isalpha(k[j]))
            {
                // if char is not a letter
                printf("Wrong argument!\nUsage: ./vigenere key\n");
                return 1;
            }
            else
            {
                // convert char to modifier
                key[j] = toupper(k[j]) - 65;
            }

        }

        // Prompt user for plaintext
        string p = get_string("plaintext: ");
        string c = p;
        // Iterate through the string and replace chars if necessary
        for (int i = 0, j = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
            {
                if (isupper(p[i]))
                {
                    c[i] = 65 + (p[i] + key[j] - 65) % 26;
                }
                else
                {
                    c[i] = 97 + (p[i] + key[j] - 97) % 26;
                }
                j = (j + 1) % key_length;
            }
        }
        // Print ciphertext
        printf("ciphertext: %s\n", c);
        return 0;
    }
}
