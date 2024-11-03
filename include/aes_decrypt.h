#include <stdint.h>

#define AES_KEY_SIZE 16    // 128 bits

/**
 * @brief Decodifica um texto AES-128-ECB.
 *
 * Esta função realiza a decodificação de um texto que foi codificado utilizando o 
 * algoritmo AES com o modo de operação ECB (Electronic Codebook). O texto 
 * codificado deve ser fornecido em formato hexadecimal.
 *
 * @param[in] encrypted_text Ponteiro para o texto codificado em hexadecimal que 
 * deve ser decodificado.
 * @param[out] decrypted_text Buffer onde o texto decodificado será armazenado. 
 * @param[in] key Ponteiro para a chave de decodificação (deve ter tamanho de 
 * AES_KEY_SIZE, que é 16 bytes).
 * 
 * @return Retorna 0 se a decodificação for bem-sucedida, ou -1 em caso de erro.
 */
int aes_decrypt(const uint8_t *encrypted_text, uint8_t *decrypted_text, const uint8_t *key);

#endif // AES_DECRYPT_H