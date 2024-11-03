#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "aes_decrypt.h"

static void test_aes_decrypt_success(void **state) {
    (void) state;  // Evita warnings de parâmetro não usado

    uint8_t encrypted_text[] = {
        0xa5, 0x7f, 0xd9, 0x72, 0x5f, 0xb5, 0x3c, 0x53,
        0xd5, 0xbd, 0x0b, 0x56, 0x18, 0x5d, 0xa5, 0x0f,
        0x70, 0xab, 0x9b, 0xae, 0xa5, 0xa4, 0x35, 0x23,
        0xb7, 0x6c, 0x03, 0xe3, 0xeb, 0x98, 0x9a, 0x20
    };
    uint8_t key[AES_KEY_SIZE] = "thisisasecretkey";
    uint8_t decrypted_text[32] = {0};

    // Texto esperado após a decodificação
    const char *expected_output = "Expected plain text";

    // Chama a função de decodificação
    assert_int_equal(aes_decrypt(encrypted_text, decrypted_text, key), 0);
    assert_string_equal((const char*) decrypted_text, expected_output);
}

static void test_aes_decrypt_null_parameters(void **state) {
    (void) state;  // Evita warnings de parâmetro não usado

    uint8_t key[AES_KEY_SIZE] = "thisisasecretkey";
    uint8_t decrypted_text[32] = {0};

    // Testa com texto codificado nulo
    assert_int_equal(aes_decrypt(NULL, decrypted_text, key), -1);

    // Testa com chave nula
    uint8_t encrypted_text[32] = {0xa5, 0x7f, 0xd9, 0x72, 0x5f, 0xb5, 0x3c, 0x53};
    assert_int_equal(aes_decrypt(encrypted_text, decrypted_text, NULL), -1);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_aes_decrypt_success),
        cmocka_unit_test(test_aes_decrypt_null_parameters),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}