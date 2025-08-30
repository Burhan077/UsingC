#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple XOR encryption/decryption
void xor_encrypt_decrypt(FILE *in, FILE *out, const char *key) {
    int c;
    size_t key_len = strlen(key);
    size_t i = 0;

    while ((c = fgetc(in)) != EOF) {
        fputc(c ^ key[i % key_len], out);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input> <output> <key>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    FILE *fout = fopen(argv[2], "wb");
    if (!fin || !fout) {
        perror("File error");
        return 1;
    }

    xor_encrypt_decrypt(fin, fout, argv[3]);

    fclose(fin);
    fclose(fout);
    printf("Done! File written to %s\n", argv[2]);
    return 0;
}
