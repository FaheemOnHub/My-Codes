#include <stdio.h>
#include <string.h>

int calculateParityBit(const char* data, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == '1') {
            count++;
        }
    }

    int parityBit = (count % 2 == 1) ? 1 : 0;
    return parityBit;
}

int simpleParityCheck(const char* transmittedData, int blockSize) {
    int numBlocks = strlen(transmittedData) / blockSize;


    for (int block = 0; block < numBlocks; block++) {
        const char* currentBlock = transmittedData + (block * blockSize);
        int parityBit = calculateParityBit(currentBlock, blockSize - 1);

        
        if (parityBit != (currentBlock[blockSize - 1] - '0')) {
      
            return 0;
        }
    }

    
    return 1;
}

int main() {
    char transmittedData[100];
    int blockSize;

    
    printf("Enter the transmitted data: ");
    scanf("%s", transmittedData);

   
    blockSize=strlen(transmittedData);


    int result = simpleParityCheck(transmittedData, blockSize);

    if (result) {
        printf("No errors detected. Data transmission successful.\n");
    } else {
        printf("Error detected. Data transmission unsuccessful.\n");
    }

    return 0;
}
