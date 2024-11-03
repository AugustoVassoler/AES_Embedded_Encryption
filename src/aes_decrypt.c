#include "aes_decrypt.h"
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int aes_decrypt(const uint8_t *encrypted_text, uint8_t *decrypted_text, const uint8_t *key) {
    if (encrypted_text == NULL || decrypted_text == NULL || key == NULL) {
        fprintf(stderr, "Erro: Parâmetro nulo fornecido à função aes_decrypt.\n");
        return -1;
    }

    AES_KEY decrypt_key;
    if (AES_set_decrypt_key(key, 128, &decrypt_key) != 0) {
        fprintf(stderr, "Erro: Falha ao configurar a chave de decodificação AES.\n");
        return -1;
    }

    AES_decrypt(encrypted_text, decrypted_text, &decrypt_key);
    return 0;
}