# Tên file nguồn và file thực thi
TARGET = ex2
SRC = ex2.c

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Mặc định: build và run luôn
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

# Xoá file thực thi
clean:
	rm -f $(TARGET)
