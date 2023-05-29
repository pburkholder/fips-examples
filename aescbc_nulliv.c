#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

// Author: Peter Burkholder, with assistance from ChatGPT, 2023 

#define KEY_SIZE 32
#define IV_SIZE 16

void handleErrors()
{
    ERR_print_errors_fp(stderr);
    exit(1);
}

void aes_cbc_encrypt(const unsigned char *plaintext, int plaintext_len,
                     const unsigned char *key, const unsigned char *iv,
                     unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    /* This no longer works with OpenSSL 3.0, so commenting away
    if (FIPS_mode_set(1) != 1)
    {
        fprintf(stderr, "Error enabling FIPS mode.\n");
        return 1;
    }
    */ 

    // Generate a random 256-bit key
    unsigned char key[KEY_SIZE];
    if (RAND_bytes(key, sizeof(key)) != 1)
        handleErrors();

    // Generate a random 128-bit IV
    unsigned char iv[IV_SIZE];
    if (RAND_bytes(iv, sizeof(iv)) != 1)
        handleErrors();

    // Plaintext to be encrypted
    unsigned char plaintext[] = "This is a plaintext message.";

    // Determine the length of the plaintext
    int plaintext_len = sizeof(plaintext) - 1; // Exclude the null terminator

    // Calculate the ciphertext size
    int ciphertext_len = (plaintext_len + EVP_MAX_BLOCK_LENGTH - 1) /
                         EVP_MAX_BLOCK_LENGTH * EVP_MAX_BLOCK_LENGTH;

    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(ciphertext_len);
    if (ciphertext == NULL)
        handleErrors();

    // Encrypt the plaintext
    aes_cbc_encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    free(ciphertext);

    return 0;
}
