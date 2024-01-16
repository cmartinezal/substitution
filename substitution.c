#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
string encrypt(string text, string key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (is_valid_key(key) == false)
    {
        return 1;
    }

    string text = get_string("plaintext: ");
    string ciphertext = encrypt(text, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool is_valid_key(string key)
{
    int key_max_chars = 26;
    int len = strlen(key);

    if (len != key_max_chars)
    {
        printf("Key must contain %i characters but has %i.\n", key_max_chars, len);
        return false;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key contains invalid characters.\n");
            return false;
        }
        if (strchr(key + i + 1, key[i]))
        {
            printf("Key contains duplicated letters.\n");
            return false;
        }
    }
    return true;
}

string encrypt(string text, string key)
{

    for (int i = 0; i < strlen(text); i++)
    {
        int offset;
        char letter = text[i];

        if (isupper(letter))
        {
            offset = 'A';
            text[i] = toupper(key[toupper(letter) - offset]);
        }
        else if (islower(text[i]))
        {
            offset = 'a';
            text[i] = tolower(key[tolower(letter) - offset]);
        }
    }
    return text;
}
