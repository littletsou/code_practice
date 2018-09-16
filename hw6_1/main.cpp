/*練習寫遞迴*/
#include <iostream>
using namespace std;
int Ackermann(int m, int n) {
    if (m == 0) {
        return (n +1);
    }
    else if (m > 0 && n == 0) {
        return Ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main()
{
    int m;
    int n;
    do {
        cout << "m: ";
        cin >> m;
        cout << "n: ";
        cin >> n;
        int answer = Ackermann(m,n);
        cout << "A(" << m << ", " << n << ") = " << answer << endl;
    }while (1);

    return 0;
}
