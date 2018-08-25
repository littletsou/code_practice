#include <iostream>

using namespace std;
int add(int num1, int num2){
    int sum;
    sum = num1 + num2;
    return sum;
}
int main()
{
    int num1;
    int num2;
    num1 = 1;
    num2 = 2;
    int sum;
    sum = add(num1, num2);
    cout << "sum:" << sum << endl;
    return 0;
}

