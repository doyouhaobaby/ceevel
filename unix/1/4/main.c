#include "apue.h"

#define BUFFSIZE  4096

// 输入输出
// ./a.out > data
// touch hello.txt
// ./a.out < ./hello.txt > data2
// 复制文件内容
int main(void) {
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("写入文件失败");
        }
    }

    if (n < 0) {
        err_sys("读取失败");
    }

    exit(0);
}