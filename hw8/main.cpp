/*
題目1: 使用動態宣告產生大小為5的整數陣列，並使用亂數做初始化
宣告指標去修改陣列中的值

題目2: 多項式的加、減、乘
使用動態陣列去存各個次方的係數
練習將陣列傳入function中，呼叫print_polynomial()印出結果
傳陣列進function中是傳指標以及陣列大小
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void print_polynomial(int* polynomial, int size){
    for (int i = size; i >= 0; i--) {
        if(polynomial[i] > 0) { //
            if(i != 0) { //
                if(i == size) { //
                    if(polynomial[i] == 1) {
                        cout << "x^" << i;
                    } else {
                        cout << polynomial[i] << "x^" << i;
                    }
                } else if (i == 1) {
                    cout << "+" << polynomial[i] << "x";
                } else { //
                    if(polynomial[i] == 1) {
                        cout << "+" << "x^" << i;
                    } else {
                        cout << "+" << polynomial[i] << "x^" << i;
                    }
                }
            } else { //
                cout << "+" << polynomial[i];
            }

        } else if (polynomial[i] < 0) { //

            if(i != 0) {
                if (i == 1) {
                    cout << polynomial[i] << "x";
                } else {
                cout << polynomial[i] << "x^" << i;
                }
            } else {
                cout << i;
            }
        }
    }
}

int main()
{
    int ary[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        ary[i] = rand() % 100 + 1;
    }
    cout << "Address of array pointer: " << &ary << endl;
    cout << "Value of array pointer: " << ary << endl;
    cout << "ary[5]: " << ary[5] << endl;
    int *ptr;
    ptr = &ary[5];
    *ptr = 200;
    cout << "ary[5]: " << ary[5] << endl << endl;

    cout << "==========================" << endl << endl;

    cout << "Input first polynomial:" << endl;
    cout << "Input degree of first polynomial: ";
    int first_polynomial;
    cin >> first_polynomial;
    int* first_array = new int[first_polynomial + 1];

    for(int i = first_polynomial; i >= 0; i--) {
        cout << "x^" << i << ": ";
        cin >> first_array[i];
    }
    cout << endl << endl << "The first polynomial: " << endl << endl;
    print_polynomial(first_array, first_polynomial);
    cout << endl << endl;


    cout << "Input second polynomial:" << endl;
    cout << "Input degree of second polynomial: ";
    int second_polynomial;
    cin >> second_polynomial;
    int* second_array = new int[second_polynomial + 1];

    for(int i = second_polynomial; i >= 0; i--) {
        cout << "x^" << i << ": ";
        cin >> second_array[i];
    }
    cout << endl << endl << "The second polynomial: " << endl << endl;
    print_polynomial(second_array, second_polynomial);
    cout << endl << endl;

    cout << "Result:" << endl;
    int* sum_array;
    int* sub_array;
    int start_degree;
    int degree;
    if (first_polynomial > second_polynomial) {
        //cout <<"case1 " << first_polynomial << endl;
        sum_array = new int[first_polynomial + 1];
        sub_array = new int[first_polynomial + 1];
        for (int i = first_polynomial; i >= 0; i--) {
            sum_array[i] = first_array[i];
            sub_array[i] = first_array[i];
        }
        degree = first_polynomial;
        start_degree = second_polynomial;
    } else {
        //cout <<"case2" << endl;
        sum_array = new int[second_polynomial + 1];
        sub_array = new int[second_polynomial + 1];
        for (int i = second_polynomial; i >= 0; i--) {
            sum_array[i] = second_array[i];
            sub_array[i] = second_array[i];
        }
        degree = second_polynomial;
        start_degree = first_polynomial;
    }
    int* mul_array = new int[first_polynomial + second_polynomial + 1];
    for (int i = first_polynomial + second_polynomial + 1; i >= 0; i--) {
        mul_array[i] = 0;
    }

    //Summation
    for (int i = start_degree; i >= 0; i--) {
        sum_array[i] = first_array[i] + second_array[i];
    }

    //Subtraction
    for (int i = start_degree; i >= 0; i--) {
        sub_array[i] = first_array[i] - second_array[i];
    }

    //Multiplication
    for (int i = first_polynomial; i >=0; i--) {
        for (int j = second_polynomial; j >= 0; j--) {
            mul_array[i + j] += first_array[i] * second_array[j];
        }
    }

    cout << "Summation: ";
    print_polynomial(sum_array, degree);
    cout << endl;
    cout << "Subtraction: ";
    print_polynomial(sub_array, degree);
    cout << endl;
    cout << "Multiplication: ";
    print_polynomial(mul_array, first_polynomial + second_polynomial);

    return 0;
}
