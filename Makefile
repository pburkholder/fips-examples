
ALL := md_fail md_ok md_force

all: ${ALL}

% : %.c
	gcc -o $@ $< -lcrypto
