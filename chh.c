#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 9

void binaryAddition(const char *boolean1, const char *boolean2, char *result) {
    int carry = 0;
    int i;
    int length = strlen(boolean1);

    for (i = length - 1; i >= 0; i--) {
        int bit1 = boolean1[i] - '0';
        int bit2 = boolean2[i] - '0';

        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        int bitSum = sum % 2;

        result[i] = bitSum + '0';
    }

    result[length] = '\0';
}

int main() {
    char boolean1[MAX_LENGTH + 1];
    char boolean2[MAX_LENGTH + 1];
    char result[MAX_LENGTH + 1];

    printf("Enter the first binary number (up to 8 bits): ");
    scanf("%s", boolean1);

    printf("Enter the second binary number (up to 8 bits): ");
    scanf("%s", boolean2);

    binaryAddition(boolean1, boolean2, result);

    printf("Result: %s\n", result);

    return 0;
}
