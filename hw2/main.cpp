#include <iostream>
#include <string>

using namespace std;

void bubble_sort (int *num, int size) {
    for (int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

int main()
{
    cout << "Please enter year: ";
    int year;
    cin >> year;
    if (year % 4 == 0 && year % 100 != 0) {
        cout << year << " is leap year.";
    }
    else if (year % 400 == 0 && year % 3200 != 0) {
        cout << year << " is leap year.";
    }
    else {
        cout << year << " is not leap year." << endl;
    }

    cout << "Please enter 5 integers: ";
    int num[5];
    cin >> num[0] >> num[1] >> num[2] >> num[3]>> num[4];
    bubble_sort(num, sizeof(num) / sizeof(num[0]));
    cout << "Largest is " << num[4] << endl;
    cout << "Middle is " << num[2] << endl;
    cout << "smallest is " << num[0] << endl;

    return 0;
}
