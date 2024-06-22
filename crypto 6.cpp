#include <stdio.h>
#include <string.h>
#include <ctype.h>
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
void affineDecrypt(char *ciphertext, int a, int b, char *plaintext) {
    int a_inv = modInverse(a, 26);
    if (a_inv == 0) {
        printf("Decryption is not possible. 'a' has no modular inverse.\n");
        return;
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            int x = toupper(ciphertext[i]) - 'A';
            int p = (a_inv * (x - b + 26)) % 26;
            plaintext[i] = (char)(p + 'A');
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char ciphertext[256];
    char plaintext[256];
    int a, b;
    char mostFrequentCipher = 'B';
    char secondMostFrequentCipher = 'U';
    char mostFrequentPlain = 'E';
    char secondMostFrequentPlain = 'T';
    int y1 = mostFrequentCipher - 'A';
    int y2 = secondMostFrequentCipher - 'A';
    int x1 = mostFrequentPlain - 'A';
    int x2 = secondMostFrequentPlain - 'A';
    int x_diff = (x1 - x2 + 26) % 26;
    int y_diff = (y1 - y2 + 26) % 26;
    int x_diff_inv = modInverse(x_diff, 26);
    a = (y_diff * x_diff_inv) % 26;
    if (a < 0) a += 26;
    b = (y1 - a * x1) % 26;
    if (b < 0) b += 26;
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';
    affineDecrypt(ciphertext, a, b, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}