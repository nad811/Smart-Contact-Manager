CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/contact.c src/file_manager.c
OUT = contact_manager

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	rm -f $(OUT)
