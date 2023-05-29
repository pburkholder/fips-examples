#include <openssl/evp.h>
#include <openssl/err.h>


// Orginal code from https://ubuntu.com/blog/how-to-develop-linux-applications-for-fips-on-ubuntu
// by Nikos Mavrogiannopoulos

/* Demonstrate message digest */

static
int digest_message(const unsigned char *message, size_t message_len,
		   unsigned char *output, unsigned int max_output_size,
		   const EVP_MD *type)
{
	EVP_MD_CTX *mdctx;
	int output_size = EVP_MD_size(type);

	if (output_size > max_output_size)
		return -1;

	if ((mdctx = EVP_MD_CTX_new()) == NULL) {
		ERR_print_errors_fp(stderr);
		return -1;
	}

	if (1 != EVP_DigestInit_ex(mdctx, type, NULL)) {
		ERR_print_errors_fp(stderr);
		return -1;
	}

	if (1 != EVP_DigestUpdate(mdctx, message, message_len)) {
		ERR_print_errors_fp(stderr);
		return -1;
	}

	if (1 != EVP_DigestFinal_ex(mdctx, output, &output_size)) {
		ERR_print_errors_fp(stderr);
		return -1;
	}

	EVP_MD_CTX_free(mdctx);

	return output_size;
}

int main()
{
	unsigned char out[64];
	int out_len;
	int i;

	out_len = digest_message("abc", 3, out, sizeof(out), EVP_md5());
	if (out_len == -1) {
		fprintf(stderr, "could not hash\n");
		return 1;
	}

	for (i = 0; i < out_len; i++) {
		printf("%.2x", out[i]);
	}

	fputc('\n', stdout);
	return 0;
}
