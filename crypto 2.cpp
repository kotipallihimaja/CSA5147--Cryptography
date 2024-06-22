#include <stdio.h>
#include <string.h>
#include <ctype.h>
void monoalphabeticCipher(char *text, const char *key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isupper(ch)) {
            text[i] = key[ch - 'A'];
        } else if (islower(ch)) {
            text[i] = tolower(key[ch - 'a']);
        }
    }
}

int main() {
    char text[100];
    char key[26] ="HYDGTBDYNNUDFYSYHURUWU";
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    monoalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}

