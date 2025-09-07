#include <stdio.h>
#include <setjmp.h>
#include <string.h>

enum ErrorCodes {
    NO_ERROR = 0,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
};

static jmp_buf g_env;
static int g_error_code;
static char g_error_message[256];

#define TRY if ((g_error_code = setjmp(g_env)) == 0)
#define CATCH(x) else if (g_error_code == (x))
#define END_TRY else if (g_error_code != 0)

#define THROW(code, msg) do { \
    g_error_code = (code); \
    strncpy(g_error_message, (msg), sizeof(g_error_message)-1); \
    g_error_message[sizeof(g_error_message)-1] = '\0'; \
    longjmp(g_env, g_error_code); \
} while(0)

void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    printf("Kết nối mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi mạng: Không thể kết nối đến server.");
}

void calculateData() {
    printf("Tính toán dữ liệu...\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán: Chia cho 0 trong phép tính.");
}

int main() {
    TRY {
        readFile();
        networkOperation();
        calculateData();
    }
    CATCH(FILE_ERROR) {
        printf("[CATCH FILE_ERROR] %s\n", g_error_message);
    }
    CATCH(NETWORK_ERROR) {
        printf("[CATCH NETWORK_ERROR] %s\n", g_error_message);
    }
    CATCH(CALCULATION_ERROR) {
        printf("[CATCH CALCULATION_ERROR] %s\n", g_error_message);
    }
    END_TRY {
        printf("Lỗi không xác định!\n");
    }

    printf("Chương trình kết thúc an toàn.\n");
    return 0;
}
