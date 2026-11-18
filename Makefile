main: main.c
	$(CC) main.c -o main -Wall -Wextra -pedantic -std=c99
vm: vm.c
	$(CC) vm.c -o vm -Wall -Wextra -pedantic -std=c99