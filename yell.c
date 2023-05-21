#include <stdio.h>

void addBooleanNumbers(unsigned char boolean1[], unsigned char boolean2[], unsigned char result[]) {
    for (int i = 0; i < 8; i++) {
        result[i] = ((boolean1[i] - '0') ^ (boolean2[i] - '0')) + '0';
    }
    result[8] = '\0';  // Add null terminator to make it a valid string
}

int main() {
    unsigned char boolean1[9];
    unsigned char boolean2[9];

    printf("Enter the first boolean number (8 bits): ");
    scanf("%s", boolean1);

    printf("Enter the second boolean number (8 bits): ");
    scanf("%s", boolean2);

    unsigned char result[9];
    addBooleanNumbers(boolean1, boolean2, result);

    printf("Result: %s\n", result);

    return 0;
}
