#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void print_data(int data) {
    cout << data << " ";
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {23,6,14,7,24,645,9,56,723,1};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        print_data(arr[i]);
    }
    cout << endl;

    int count = 0;
    while (count < sizeof(arr) / sizeof(arr[0])) {
        print_data(arr[count]);
        count++;
    }
    cout << endl;

    int count2 = 0;
    do {
        print_data(arr[count2]);
        count2++;
    } while(count2 < sizeof(arr) / sizeof(arr[0]));
    cout << endl;

    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        print_data(arr[i]);
    }

    return 0;
}
