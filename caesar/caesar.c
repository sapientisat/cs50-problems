// Encrypts messages using Caesar’s cipher
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
        printf ("Wrong argument!\nUsage: ./caesar k\n");
        return 1;
    }
    else
    {
        // Get key value
        int k = atoi(argv[1]);

        // Prompt user for plaintext
        string p = get_string("plaintext: ");
        string c = p;
        // Iterate through the string and replace chars if necessary
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
            {
                if (isupper(p[i]))
                {
                    c[i] = 65 + (p[i] + k - 65) % 26;
                }
                else
                {
                    c[i] = 97 + (p[i] + k - 97) % 26;
                }
            }
        }
        // Print ciphertext
        printf("ciphertext: %s\n", c);
        return 0;
    }
}
