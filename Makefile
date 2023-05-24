
ALL := md_fail md_ok md_force

% : %.c
	gcc -lcrypto $< -o $@