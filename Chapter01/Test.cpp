// 测试文件
// Created by TimeM on 2021/4/25 0025.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// 降序比较大小
bool cmp(string a, string b) {
    return a > b;
}

int main()
{
    // 01. 定义变量
    vector<string> seq_str(100);

    // 02. 打开源文件
    ifstream infile("source.txt");

    // 03. 读取文件
    int i = 0;
    if (infile.is_open())
    {
        while (!infile.eof())
            getline(infile, seq_str[i++]);
    } else cerr << "Oops! Unable to save session data!\n";

    // 04. 关闭文件
    infile.close();

    // 05. 排序
    sort(seq_str.begin(), seq_str.end(), cmp);

    // 06. 输出排序结果
    cout << "The result of sort is:\n";
    ofstream outfile("target.txt", ios_base::app);
    if (outfile.is_open())
    {
        while (i > 0)
        {
            cout << seq_str[--i] << "\t";
            outfile << seq_str[i] << "\t";
        }
    } else cerr << "Oops! Unable to save session data!\n";
    outfile << endl;
    outfile.close();

    return 0;
}
