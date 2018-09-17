/*題目: 產生大小為1~10之間奇數大小的magic square
練習使用動態二維宣告
*/
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter an odd number as size of magic square(1 <= N <= 10): ";
    int input;
    cin >> input;
    int** magic_square = new int*[input];
    for (int i = 0; i < input; i++) {
        magic_square[i] = new int[input];
    }

    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            magic_square[i][j] = 0;
        }
    }

    int range = input * input;
    int row = input / 2;
    int column = input - 1;
    for (int num = 1; num <= range;) {
        if (row == -1 && column == input) {
            row = 0;
            column = input - 2;
        } else {
            if (row == -1) {
                row = input - 1;
            }
            if (column == input) {
                column = 0;
            }
        }
        if (magic_square[row][column]) {
            row += 1;
            column -= 2;
            continue;
        } else {
            magic_square[row][column] = num++;
        }
        row -=  1;
        column += 1;
    }

    cout << endl;
    for (int i = 0; i < input; i++) {
        for (int j = 0; j <input; j++) {
            cout << magic_square[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
