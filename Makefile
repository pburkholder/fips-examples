
ALL := md_fail md_ok md_force aescbc_ok

all: ${ALL}

% : %.c
	gcc -o $@ $< -lcrypto
