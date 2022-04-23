#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib/sha256.h"

typedef unsigned char BYTE;    
typedef struct{
    unsigned long int timestamp;
    BYTE* data;
    BYTE* prevBlockHash;
    BYTE* hash;
} Block;

BYTE* sha256(BYTE* data, size_t len) {
    /* 
        Creates 32-byte hash from data with size len using SHA256 algorithm
        wrapper around lib/sha256.c
    */
    SHA256_CTX myCtx;
    sha256_init(&myCtx);
    sha256_update(&myCtx, data, len);

    BYTE* hash = malloc(sizeof(BYTE) * 32);
    sha256_final(&myCtx, hash);
    return hash;
} 

void generateBlockHash(Block* block) {
    /* 
        generates hash of the block from its data, previous block hash, and timestamp
    */
    if (block == NULL) {
        printf("generateBlockHash | block pointer is NULL\n");
        exit(1);
    }

    BYTE timestampStr[20];
    sprintf(timestampStr, "%u", block -> timestamp); 

    size_t headersSize = strlen(timestampStr) + strlen(block -> prevBlockHash) + strlen(block -> data);
    BYTE* headers = malloc(sizeof(BYTE) * headersSize);
    headers[0] = '\0';

    strcat(headers, block -> prevBlockHash);
    strcat(headers, block -> data);
    strcat(headers, timestampStr);

    block -> hash = sha256(headers, strlen(headers));
    free(headers);
    return;
}

int main() {
     return 0;
}


// block -> timestamp = (unsigned long) time(NULL);