/*題目: 宣告二維陣列並亂數產生20個數，並使用bubble sort 進行排序*/
#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	int num;
	srand(time(NULL));
	int arr[20][2];

	for (int i = 0; i < 20; i++) {
	    arr[i][0] = i + 1;
		arr[i][1] = rand() % 101;
	}

	for (int i = 0; i < 20 - 1; i++) {
		for (int j = 0; j < 20 - 1 - i; j++) {
			if (arr[j][1] > arr[j + 1][1]) {
			    int temp_id = arr[j + 1][0];
			    arr[j + 1][0] = arr[j][0];
			    arr[j][0] = temp_id;

			    int temp_num = arr[j + 1][1];
			    arr[j + 1][1] = arr[j][1];
			    arr[j][1] = temp_num;
			}
		}
	}
	cout << "id\tscore" << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i][0] << "\t" << arr[i][1] << endl;
	}
    return 0;
}
