#include <stdio.h>


int main(int argc, char **argv) {
    if (argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("hello world\n");
    return 0;
}