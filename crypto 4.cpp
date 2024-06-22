#include <stdio.h>
#include <string.h>
#include <ctype.h>
void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
void generateKey(char text[], char key[], char newKey[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < textLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
}
void encryptText(char text[], char key[], char encryptedText[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i;
    for (i = 0; i < textLen; ++i) {
        encryptedText[i] = ((text[i] + key[i]) % 26) + 'A';
    }
    encryptedText[i] = '\0';
}
void decryptText(char encryptedText[], char key[], char decryptedText[]) 
{
    int textLen = strlen(encryptedText);
    int keyLen = strlen(key);
    int i;
    for (i = 0; i < textLen; ++i) {
        decryptedText[i] = (((encryptedText[i] - key[i]) + 26) % 26) + 'A';
    }
    decryptedText[i] = '\0';
}
int main() 
{
    char text[100], key[100], newKey[100], encryptedText[100], decryptedText[100];
    printf("Enter plaintext: ");
    gets(text);
    printf("Enter key: ");
    gets(key);
    toUpperCase(text);
    toUpperCase(key);
    generateKey(text, key, newKey);
    encryptText(text, newKey, encryptedText);
    decryptText(encryptedText, newKey, decryptedText);
    printf("Plaintext: %s\n", text);
    printf("Key: %s\n", key);
    printf("Generated Key: %s\n", newKey);
    printf("Encrypted Text: %s\n", encryptedText);
    printf("Decrypted Text: %s\n", decryptedText);
    return 0;
}
