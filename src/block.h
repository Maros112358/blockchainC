typedef unsigned char BYTE;    
typedef struct{
    unsigned long int timestamp;
    BYTE* data;
    BYTE* prevBlockHash;
    BYTE* hash;
} Block;

Block* createBlock(BYTE* data, BYTE* prevBlockHash);
Block* newGenesisBlock();