/*題目: 動態宣告二維的char陣列
使用亂數去做陣列的初始化
比較及練習指標的應用*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int ary_size = 10;
    char** ary = new char* [ary_size];
    for (int i = 0; i < ary_size; i++) {
        ary[i] = new char [ary_size];
    }
    for (int i = 0; i < ary_size; i ++) {
        for (int j = 0; j < ary_size; j++) {
            int num = rand() % 9 + 1;
            //cout << num << endl;
            ary[i][j] = num + 48;
        }
    }
    //Print the address of array pointer ¡§ary¡¨
    cout << "address of array pointer \"ary\": " << &ary << endl;

    //Print the value of array pointer ¡§ary¡¨
    cout << "value of array pointer \"ary\": " << ary << endl;

    //Declare a pointer which point to ary[5][2] ,
    //then assign value ¡¥0¡¦ by the pointer
    cout << "ary[5][2]: " << ary[5][2] << endl;
    char* ptr = &ary[5][2];
    *ptr = '0';
    cout << "ary[5][2]: " << ary[5][2] << endl;

    //Fill ¡§7thstring¡¨ into the space where ary[6] points to
    cout << "ary[6][9]: " << ary[6][9] << endl;
    char str[] = {'7', 't', 'h', 's', 't', 'r', 'i', 'n', 'g'};
    for (int i = 0; i < sizeof(str); i++) {
        ary[6][i] = str[i];
        cout << ary[6][i];
    }
    cout << endl;
    //What is the value of ary[6][9]? Why?
    cout << "ary[6][9]: " << ary[6][9];
    return 0;
}
