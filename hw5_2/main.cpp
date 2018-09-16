/*判斷是否為迴文
因不知道數字有幾位數字，因此使用vector來儲存各個位數的數字，並且練習vector相關用法
vector宣告: vector<型態>
vector塞值: num.push_back(temp)
取vector大小: num.size()
取vector某個位置的值: num.at(位置)
*/

#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(int input) {
    vector<int> num;
    int temp;
    while(input != 0) {
        temp = input % 10;
        num.push_back(temp);
        input /= 10;
    }
    int begin = 0;
    int end = num.size() - 1;
    while (begin != end) {
        if (num.at(begin) != num.at(end)) {
            return 0;
        }
        begin++;
        end--;
    }
    return 1;
}

int main() {
    int input;
    do{
        cout << "Please input a positive number(>9): ";
        cin >> input;
        if (input <= 9) {
            cout << "Error input" << endl;
            continue;
        }
        else {
            if (isPalindrome(input)) {
                cout << "It is a Palindrome" << endl;
            }
            else {
                cout << "It is not a Palindrome" << endl;
            }
        }
    }while(1);
    return 0;
}
