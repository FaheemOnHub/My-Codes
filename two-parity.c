#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the parity bit for each row and column
void calculateParity(vector<vector<int>>& data) {
    int numRows = data.size();
    int numCols = data[0].size();

    // Calculate row parity
    for (int i = 0; i < numRows; i++) {
        int parity = 0;
        for (int j = 0; j < numCols; j++) {
            parity ^= data[i][j];  // XOR operation
        }
        data[i].push_back(parity);  // Append parity bit to each row
    }

    // Calculate column parity
    vector<int> colParity(numCols + 1, 0);
    for (int j = 0; j < numCols + 1; j++) {
        for (int i = 0; i < numRows; i++) {
            colParity[j] ^= data[i][j];  // XOR operation
        }
    }
    data.push_back(colParity);  // Append column parity row
}

// Function to display the transmitted data
void displayTransmittedData(const vector<vector<int>>& data) {
    int numRows = data.size();
    int numCols = data[0].size();

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;

    cout << "Enter the number of columns: ";
    cin >> numCols;

    vector<vector<int>> data(numRows, vector<int>(numCols));

    cout << "Enter the data (0 or 1) row by row:\n";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> data[i][j];
        }
    }

    calculateParity(data);

    cout << "\nTransmitted Data:\n";
    displayTransmittedData(data);

    return 0;
}
