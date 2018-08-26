#include <iostream>

using namespace std;

int main()
{
    cout << "愛多美麗充滿香氣，只是在心裡他總是酸溜溜地" << endl;
    cout << endl;
    cout << "Please enter 3 integers: ";
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    cin >> num1 >> num2 >> num3;
    cout << "Answer : " << num1 * num1 * num1 + num2 * num2 * num2 + num3 * num3 * num3;
    return 0;
}
