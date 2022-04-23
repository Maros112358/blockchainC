#include <stdio.h>

typedef struct{
    long int timestamp;
} Block;

int main() {
    Block block = {1};
    printf("%d\n", block.timestamp);
    return 0;
}