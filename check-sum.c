#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int checkSumCheck(char* Data,int Size)
{
    char leftHalf[100], rightHalf[100];
    int length, mid, i, k;

    length = strlen(Data);

    mid = length / 2;

    for (i = 0; i < mid; i++) {
        leftHalf[i] = Data[i];
    }
    leftHalf[i] = '\0';

    for (i = mid, k = 0; i < length; i++, k++) {
        rightHalf[k] = Data[i];
    }
    rightHalf[k] = '\0';

    printf("Left half : %s\n", leftHalf);
    printf("Right half : %s\n", rightHalf);

    int length_1 = strlen(leftHalf);
    bool result[length_1];

    for (int i = 0; i < length_1; i++) {
        if (leftHalf[i] != rightHalf[i])
            result[i] = '1';
        else
            result[i] = '0';
    }
    result[i] = '\0';  // Null-terminate the result string

    printf("Boolean Addition Result: ");
    for (int i = 0; i < length_1; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;


    
}
int main()
{
    char inputData[100];
    int blockSize;

    printf("Enter your Data");
    scanf("%s",inputData);

    blockSize=2;

    int result = checkSumCheck(inputData, blockSize);

    // if (result) {
    //     printf("No errors detected. Data transmission successful.\n");
    // } else {
    //     printf("Error detected. Data transmission unsuccessful.\n");
    // }
}


