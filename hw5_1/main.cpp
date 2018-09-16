/*主程式呼叫isPerfect()來判斷是否為perfect number

練習目的
寫function
次方使用 pow(底數, 次方) 要include <math.h>*/
#include <iostream>
#include <math.h>
using namespace std;
bool isPerfect(int num) {
    int sum = 1;
    int quotient;
    for (int divisor = 2; divisor <= pow(num,0.5); divisor++) {
        if (num % divisor == 0) {
            quotient = num / divisor;
            sum += quotient;
            sum += divisor;
        }
    }
    if (num == sum) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int input;
    do {
        cout << "Please input a positive number(-1 to quit): ";
        cin >> input;
        if (input < 0) {
	    if (input == -1) {
		break;
	    }
            cout << "Error input" << endl;
        } else {
            if (isPerfect(input)) {
                cout << "It's a perfect number" << endl;
            } else {
                cout << "It's not a perfect number" << endl;
            }
        }
    } while(1);
    return 0;
}
