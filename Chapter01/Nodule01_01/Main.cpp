// 小结：1.1 如何撰写 C++ 程序
// Created by TimeM on 2021/4/25 0025.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first_name;
    string last_name;
    cout << "Please enter your first name: ";
    cin >> first_name;
    cout << "Please enter your last name: ";
    cin >> last_name;
    cout << '\n'
         << "Hello, "
         << first_name + " " + last_name
         << " ... and goodbye!\n";

    return 0;
}

