/*寫萬年曆
主程式呼叫perpetual_calendar()判斷並印出該年月的月曆並以"*"標出該日期
其中perpetual_calendar()會呼叫isLeapYear()判斷該年分是否為閏年
*/
#include<iostream>
using namespace std;
bool isLeapYear(int year);
void perpetual_calendar(int year, int month, int date) {
    switch(month) {
        case 1:
            cout << "Jan\t" << year << endl;
            break;
        case 2:
            cout << "Feb\t" << year << endl;
            break;
        case 3:
            cout << "Mar\t" << year << endl;
            break;
        case 4:
            cout << "Apr\t" << year << endl;
            break;
        case 5:
            cout << "May\t" << year << endl;
            break;
        case 6:
            cout << "Jun\t" << year << endl;
            break;
        case 7:
            cout << "Jul\t" << year << endl;
            break;
        case 8:
            cout << "Aug\t" << year << endl;
            break;
        case 9:
            cout << "Set\t" << year << endl;
            break;
        case 10:
            cout << "Oct\t" << year << endl;
            break;
        case 11:
            cout << "Nov\t" << year << endl;
            break;
        case 12:
            cout << "Dec\t" << year << endl;
            break;
    }
    cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
    int day_num[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) {
        day_num[1] = 29;
    }

    int remainder = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    for (int i = 0; i < (month-1); i++) {
		remainder += day_num[i];
    }
    int count = remainder % 7 + 1;
    for (int i = 0; i < count; i++) {
		cout << "\t";
	}
	for (int i = 0; i < day_num[month - 1]; i++) {
		if (i == date - 1) {
			cout << "*";
		}
		cout << i + 1 << "\t";
		if (count >= 6) {
			cout << endl;
			count = 0;
		} else {
			count++;
		}
	}
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int main()
{
	cout << "Please input the day: ";
	int year;
	int month;
	int date;
	cin >> year >> month >> date;
	perpetual_calendar(year, month, date);
	return 0;
}
