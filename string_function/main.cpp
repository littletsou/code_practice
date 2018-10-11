#include <iostream>
#include <string>
using namespace std;

int _strlen(const char *s) {
    int length = 0;
    while(*(s + length) != '\0') {
        length++;
    }
    return length;
}

int _strcmp( const char *s1, const char *s2 ) {
    if (*s1 == '\0' && *s2 == 0) {
        return (*s1 - *s2);
    }
    if (*s2 == '\0' && *s1 == 0) {
        return (*s2 - *s1);
    }
    while (*s1 != '\0' && *s2 != '\0') {
        if(*s1 > *s2) {
            return (*s1 - *s2);
        } else if(*s1 < *s2) {
            return (*s2 - *s1);
        }
        s1++;
        s2++;
    }
    if (*s1 != '\0') {
        return 1;
    } else if (*s2 != '\0') {
        return -1;
    }
    return 0;
}

char * _strcpy( char *s1, const char *s2 ) {
    int temp = 0;
    while (*s2 != '\0') {
        *(s1 + temp) = *s2;
        temp++;
        s2++;
    }
    *(s1 + temp) = '\0';
    return s1;
}

char * _strncpy( char *s1, const char *s2, int size_t ) {
    for (int i = 0; (*s2 != '\0') && i < size_t; i++, s2++) {
        *(s1 + i) = *s2;
    }
    *(s1 + size_t) = '\0';
    return s1;
}

char * _strcat( char *s1, const char *s2 ) {
    char *ptr = s1;
    while (*s1 != '\0') {
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    s1 = '\0';
    return ptr;
}

char * _strncat( char *s1, const char *s2, int size_t ) {
    char *ptr = s1;
    while (*s1 != '\0') {
        s1++;
    }
    for (int i = 0; (*s2 != '\0') && i < size_t; i++, s1++, s2++) {
        *s1 = *s2;
    }
    s1 = '\0';
    return ptr;
}

int main() {
    string s_string;
    string s_string_1;
    string s_string_2;

    cout << "Please enter string: ";
    cin >> s_string;
    cout << "Please enter string_1: ";
    cin >> s_string_1;
    cout << "Please enter string_2: ";
    cin >> s_string_2;
    cout << "===========================" << endl;
    //cout << "string: " << s_string << endl;
    //cout << "string_1: " << s_string_1 << endl;
    //cout << "string_2: " << s_string_2 << endl;

    const char *s = s_string.c_str();
    const char *s1 = s_string_1.c_str();
    const char *s2 = s_string_2.c_str();
    char s3[20];
    char s4[3];
    char s5[100] = "";//如果沒有 ="" 的話 在記憶最後一個位置的時候 會記憶到 s3[99]，之後附加的字串就會超過s3[100]的陣列
    char s6[100] = "";
    //cout << *(s+1);
    cout << "strlen of string: " << _strlen(s) << endl;
    cout << "strcmp of string_1 and string_2: " << _strcmp(s1, s2) << endl;
    cout << "strcpy of string_2: " << _strcpy(s3, s2) << endl;
    cout << "strncpy of string_2 and size is 3: " << _strncpy(s3, s2, 3) << endl;
    _strcat(s5, s1);
    _strcat(s5, s2);
    cout << "strcat of string_1 and string_2: " << s5 << endl;
    cout << "strncat of string_1 and string_2: " << _strncat(s6, s5, 7) << endl;


    return 0;
}
