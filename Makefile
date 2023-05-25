
ALL := md_fail md_ok aescbc_ok aescbc_nulliv

all: ${ALL}

% : %.c
	gcc -o $@ $< -lcrypto
