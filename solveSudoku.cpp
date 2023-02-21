#include <iostream>
#include <vector>
#define N 9

using namespace std;

typedef vector<vector<int>> Board;

bool check(Board &b, int row, int col, int val) {
    int startRow = row/3 * 3;
    int startCol = col/3 * 3;

    // check hang
    for (int x = 0; x <= 8; x++)
        if (b[row][x] == val)
            return false;

    // check cot
    for (int x = 0; x <= 8; x++)
        if (b[x][col] == val)
            return false;

    // check o 3x3
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i + startRow][j + startCol] == val)
                return false;
    return true;
}

bool solve(Board &b, int row, int col) {
    if (row == N - 1 && col == N)
        return true;
    if (col == N) {
        row++;
        col = 0;
    }
    if (b[row][col] > 0) {
        return solve(b, row, col + 1);
    }
    for (int i = 1; i <= N; i++) {
        if (check(b, row, col, i)) {
            b[row][col] = i;
            if (solve(b, row, col+1))
                return true;
        }

        b[row][col] = 0;
    }
    
    return false;
}

void display(Board b) {
    for (int i = 0, row = 1; i < N, row <= N; i++, row++) {
        for (int j = 0, col = 1; j < N, col <= N; j++, col++) { 
            cout << b[i][j] << "  ";
            if (col % 3 == 0) {
                cout << "|  ";
            }
        }
        if (row % 3 == 0)
            cout << endl << "----------------------------------" << endl;
        else 
            cout << endl;
    }
}

int main() {
    Board b = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    if (solve(b, 0, 0) == true) {
        display(b);
    } else {
        cout << "no solution exists" << endl;
    }

    return 0;
}