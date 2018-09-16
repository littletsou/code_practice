/*列出1~1000間的質數*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    bool arr[1001];
    for (int i = 1; i < 1001; i++) {
        arr[i] = 1;
    }
    for (int i = 3; i < 1001; i++) {
        for (int j = 2; j <= pow(i, 0.5); j++) {
            if (i % j == 0) {
                arr[i] = 0;
                break;
            }
        }
    }
    for (int i = 2; i < 1001; i++) {
        if (arr[i]) {
            cout << i << " ";
        }
    }
	return 0;
}
