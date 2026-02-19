CC = clang

.SILENT:
run:
	$(CC) src/main.c -o main && ./main
