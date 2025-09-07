#include <stdio.h>
#include <setjmp.h>
#include <string.h>

#define TRY do { jmp_buf ex_buf__; int exception_code = setjmp(ex_buf__); if (exception_code == 0)
#define CATCH(x) else if (exception_code == (x))
#define FINALLY else
#define END_TRY } while(0)

// Biến toàn cục để lưu mã lỗi và thông điệp lỗi
static int g_error_code;
static char g_error_message[256];
static jmp_buf g_env;

// Macro THROW chấp nhận cả mã lỗi và thông điệp
#define THROW(code, msg) do {                                   \
    g_error_code = (code);                                      \
    strncpy(g_error_message, (msg), sizeof(g_error_message)-1); \
    g_error_message[sizeof(g_error_message)-1] = '\0';          \
    longjmp(g_env, g_error_code);                               \
} while(0)

// Ví dụ: hàm chia
double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Lỗi: Phép chia cho 0!");
    }
    if (a == 13) {
        THROW(2, "Lỗi: Số 13 không được phép!");
    }
    return (double)a / b;
}

// Ví dụ: hàm sqrt đơn giản
double mysqrt(int x) {
    if (x < 0) {
        THROW(3, "Lỗi: Không thể tính căn bậc 2 của số âm!");
    }
    return (double)x; // demo thôi
}


int main() {
    if (setjmp(g_env) == 0) {
        // Thử các tình huống khác nhau
        printf("Thử divide(10, 2): %f\n", divide(10, 2));
        printf("Thử divide(10, 0): %f\n", divide(10, 0));
        printf("Thử divide(13, 1): %f\n", divide(13, 1));
        printf("Thử mysqrt(-5): %f\n", mysqrt(-5));
    } else {
        // Xử lý lỗi
        switch (g_error_code) {
            case 1:
                printf("[CATCH 1] %s\n", g_error_message);
                break;
            case 2:
                printf("[CATCH 2] %s\n", g_error_message);
                break;
            case 3:
                printf("[CATCH 3] %s\n", g_error_message);
                break;
            default:
                printf("[CATCH ?] Lỗi không xác định!\n");
        }
    }

    return 0;
}