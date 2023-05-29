#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

// Author: Peter Burkholder, with assistance from ChatGPT, 2023 

#define KEY_SIZE 32
#define TAG_SIZE 16

void handleErrors()
{
    ERR_print_errors_fp(stderr);
    exit(1);
}

void chacha20_poly_encrypt(const unsigned char *plaintext, int plaintext_len,
                           const unsigned char *key, const unsigned char *nonce,
                           unsigned char *ciphertext, unsigned char *tag)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_chacha20_poly1305(), NULL, NULL, NULL))
        handleErrors();

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, sizeof(nonce), NULL))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, nonce))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_GET_TAG, TAG_SIZE, tag))
        handleErrors();

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    // Generate a random 256-bit key
    unsigned char key[KEY_SIZE];
    if (RAND_bytes(key, sizeof(key)) != 1)
        handleErrors();

    // Generate a random 96-bit nonce
    unsigned char nonce[12];
    if (RAND_bytes(nonce, sizeof(nonce)) != 1)
        handleErrors();

    // Plaintext to be encrypted
    unsigned char plaintext[] = "This is a plaintext message.";

    // Determine the length of the plaintext
    int plaintext_len = strlen((const char *)plaintext);

    // Calculate the ciphertext size
    int ciphertext_len = plaintext_len;

    // Allocate memory for the ciphertext and tag
    unsigned char *ciphertext = malloc(ciphertext_len);
    unsigned char *tag = malloc(TAG_SIZE);
    if (ciphertext == NULL || tag == NULL)
        handleErrors();

    // Encrypt the plaintext with ChaCha20-Poly1305
    chacha20_poly_encrypt(plaintext, plaintext_len, key, nonce, ciphertext, tag);

    // Print the ciphertext and tag
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    printf("Tag: ");
    for (int i = 0; i < TAG_SIZE; i++)
        printf("%02x", tag[i]);
    printf("\n");

    free(ciphertext);
    free(tag);

    return 0;
}

