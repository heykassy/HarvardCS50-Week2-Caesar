#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check if the user is inputing just one command-line argument, otherwise print how they should use it
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if argv[1] is a digit, otherwise print how they should use it
    bool isitdigit = only_digits(argv[1]);
    if (isitdigit == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from 'string' to 'int'
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");


    // Print encrypted message
    string encrypted = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        encrypted[i] = rotate(plaintext[i], key);
    }
    printf("Ciphertext: %s\n", encrypted);
}


// Function to check if command-line argument is only digits
bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to encrypt plaintext
char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c - 65 + n) % 26 + 65;
        }
        else
        {
            c = (c - 97 + n) % 26 + 97;
        }
    }
    return c;
}