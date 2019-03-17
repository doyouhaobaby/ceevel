#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR  *dp;
    struct dirent *dirp;

    if (argc != 2) {
        err_quit("请输入文件夹名字");
    }

    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("文件夹无法打开 %s", argv[1]);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}

