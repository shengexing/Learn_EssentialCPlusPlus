// 测试文件
// Created by TimeM on 2021/4/25 0025.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int line_size = 8;
    int cnt = 8;

    string a_string = "test_string";
    cout << a_string
         << (cnt % line_size ? ' ' : '\n');
}

