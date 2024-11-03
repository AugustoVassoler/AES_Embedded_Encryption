#include <stdio.h>
#include "aes_decrypt.h"

int main() {
    // Texto codificado fornecido
    uint8_t encrypted_text[] = {
        0xa5, 0x7f, 0xd9, 0x72, 0x5f, 0xb5, 0x3c, 0x53,
        0xd5, 0xbd, 0x0b, 0x56, 0x18, 0x5d, 0xa5, 0x0f,
        0x70, 0xab, 0x9b, 0xae, 0xa5, 0xa4, 0x35, 0x23,
        0xb7, 0x6c, 0x03, 0xe3, 0xeb, 0x98, 0x9a, 0x20
    };

    uint8_t key[AES_KEY_SIZE] = "thisisasecretkey";
    uint8_t decrypted_text[32] = {0};

    // Chama a funcao de decodificacao
    if (aes_decrypt(encrypted_text, decrypted_text, key) == 0) {
        printf("Texto decodificado: %s\n", decrypted_text);
    } else {
        fprintf(stderr, "Falha ao decodificar o texto.\n");
    }

    return 0;
}