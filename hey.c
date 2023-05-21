#include <stdio.h>
#include <string.h>

// Function to add two binary digits and handle carry
void addBinaryDigits(char bit1, char bit2, int *result, int *carry) {
    *result = (bit1 - '0') ^ (bit2 - '0');  // XOR operation
    *carry = (bit1 - '0') & (bit2 - '0');  // AND operation
}

// Function to add binary numbers
void addBinaryNumbers(char *num1, char *num2, char *result) {
    int length = strlen(num1);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--) {
        int bit1 = num1[i];
        int bit2 = num2[i];
        int sum, carryBit;

        addBinaryDigits(bit1, bit2, &sum, &carryBit);

        // Adjust the sum if there is a carry from the previous iteration
        sum ^= carry;

        // Store the result bit
        result[i] = sum + '0';

        // Update the carry for the next iteration
        carry = carryBit;
    }

    // Add the carry bit to the least significant bit (LSB) of the result
    result[length] = carry + '0';

    // Check if an extra bit is generated
    if (carry == 1) {
        // Add 1 to the LSB of the result
        result[length] ^= 1;
    }

    //result[length + 1] = '\0';
}

int main() {
    char num1[9], num2[9], result[10];

    // Input the first binary number
    printf("Enter the first binary number (8 bits): ");
    scanf("%s", num1);

    // Input the second binary number
    printf("Enter the second binary number (8 bits): ");
    scanf("%s", num2);

    // Check if both numbers have valid lengths
    if (strlen(num1) != 8 || strlen(num2) != 8) {
        printf("Invalid input. Binary numbers must be 8 bits long.\n");
        return 1;
    }

    // Perform binary addition
    addBinaryNumbers(num1, num2, result);

    // Output the result
    printf("Result: %s\n", result);

    return 0;
}