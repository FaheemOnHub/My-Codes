#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned char calculateChecksum(const unsigned char* data, int size) {
    unsigned char checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum ^= data[i]; 
    }
    return checksum;
}


unsigned char binaryToHex(const char* binary) {
    unsigned char hex = (unsigned char)strtol(binary, NULL, 2);
    return hex;
}


void decimalToBinary(unsigned char value, char* binary) {
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = (value >> i) & 1 ? '1' : '0';
    }
    binary[8] = '\0'; 
}

int main() {
    int dataSize;
    printf("Enter the number of data elements: ");
    scanf("%d", &dataSize);

    
    char** binaryData = (char**)malloc(dataSize * sizeof(char*));
    for (int i = 0; i < dataSize; i++) {
        binaryData[i] = (char*)malloc(9 * sizeof(char));
        printf("Enter binary data %d: ", i + 1);
        scanf("%s", binaryData[i]);
    }

    
    unsigned char* data = (unsigned char*)malloc(dataSize * sizeof(unsigned char));
    for (int i = 0; i < dataSize; i++) {
        data[i] = binaryToHex(binaryData[i]);
    }

    
    unsigned char checksum = calculateChecksum(data, dataSize);

    
    unsigned char* dataWithChecksum = (unsigned char*)malloc((dataSize + 1) * sizeof(unsigned char));
    for (int i = 0; i < dataSize; i++) {
        dataWithChecksum[i] = data[i];
    }
    dataWithChecksum[dataSize] = checksum;

    
    printf("Transmitted data: ");
    for (int i = 0; i < dataSize + 1; i++) {
        char binary[9];
        decimalToBinary(dataWithChecksum[i], binary);
        printf("%s ", binary);
    }
    printf("\n");

    
    unsigned char* receivedData = (unsigned char*)malloc((dataSize + 1) * sizeof(unsigned char));
    for (int i = 0; i < dataSize + 1; i++) {
        receivedData[i] = dataWithChecksum[i];
    }

   
    unsigned char receivedChecksum = receivedData[dataSize];
    receivedData[dataSize] = 0; 
    unsigned char calculatedChecksum = calculateChecksum(receivedData, dataSize);
    if (receivedChecksum == calculatedChecksum) {
        printf("Checksum verification successful. No errors detected.\n");
    }
    else {
        printf("Checksum verification failed. Errors detected.\n");
    }

    
    for (int i = 0; i < dataSize; i++) {
        free(binaryData[i]);
    }
    free(binaryData);
    free(data);
    free(dataWithChecksum);
    free(receivedData);

    return 0;
}