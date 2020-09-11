#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "12345";

    // object from the class stringstream
    stringstream geek(s);

    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;

    // Now the variable x holds the value 12345
    cout << "Value of x : " << x << endl;


    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 geek";

    int myint1 = stoi(str1);
    int myint2 = stoi(str2);
    int myint3 = stoi(str3);

    cout << "stoi(\"" << str1 << "\") is "
         << myint1 << '\n';
    cout << "stoi(\"" << str2 << "\") is "
         << myint2 << '\n';
    cout << "stoi(\"" << str3 << "\") is "
         << myint3 << '\n';

    return 0;
}

// https://www.educative.io/edpresso/how-to-convert-a-string-to-an-int-in-cpp