CC = clang

.SILENT:
run:
	$(CC) src/main.c -o main.out && ./main.out
