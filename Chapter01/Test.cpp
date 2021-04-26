// 测试文件
// Created by TimeM on 2021/4/25 0025.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void outputFile();
void inputFile(string usr_name);

int main()
{
    string str;
    cout << "Please input your name:\n";
    cin >> str;
    if (str.length() > 1)
        cout << "Hello, " << str;
    else cout << "Error!";

    return 0;
}

void outputFile()
{
    ofstream outfile("seq_data.txt", ios_base::app);
    string usr_name = "timem";
    int num_tries = 2, num_right = 1;
    if (!outfile)
    {
        cerr << "Oops! Unable to save session data!\n";
    } else
    {
        outfile << usr_name << ' '
                << num_tries << ' '
                << num_right << endl;
    }
}

void inputFile(string usr_name)
{
    ifstream infile("seq_data.txt");
    if (!infile)
    {
        cerr << "Oops! Unable to save session data!\n";
    } else
    {
        string name;
        int nt, nc;
        while (infile >> name)
        {
            infile >> nt >> nc;
            if (name == usr_name)
            {
                cout << "Welcome back, " << usr_name
                     << "\n Your current score is " << nc
                     << " out of " << nt << "\nGood Luck!\n";
            }
        }
    }
}
