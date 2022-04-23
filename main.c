#include "./src/blockchain.h"
#include <stdio.h>

int main() {
    Blockchain* bc = createBlockChain();
    
    AddBlock(bc, "Send 1 BTC to Ivan");
    AddBlock(bc, "Send 2 more BTC to Ivan");

    for (int i = 0; i < bc -> length; i++) {
        printf("Prev. hash: %x\n", bc -> blocks[i] -> prevBlockHash);
        printf("Data: %s\n", bc -> blocks[i] -> data);
        printf("Hash: %x\n", bc -> blocks[i] -> hash);
        printf("\n");
    }
    return 0;
}