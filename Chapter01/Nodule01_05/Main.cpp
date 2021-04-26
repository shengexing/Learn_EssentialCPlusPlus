// 小结：1.5 如何运行 Array 和 Vector
// Created by TimeM on 2021/4/26 0026.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // 数列个数
    const int max_seq = 6;
    // 所有数列名称
    string seq_names[max_seq] = {
            "Fibonacci",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal"
    };

    // 所有元素个数
    const int seq_size = 18;
    // 数组类型数列
    int elem_vals[seq_size] = {
            1, 2, 3, // Fibonacci
            3, 4, 7, // Lucas
            2, 5, 12, // Pell
            3, 6, 10, // Triangular
            4, 9, 16, // Square
            5, 12, 22 // Pentagonal
    };
    // 向量类型数列（以 elem_vals 的值来初始化 elem_seq）
    vector<int> elem_seq(elem_vals, elem_vals + seq_size);

    int cur_tuple = 0; // 初始化为第一个数列（Fibonacci）
    bool next_seq = true; // 显示下一组数列
    int usr_guess; // 用户猜的数字
    char usr_rsp; // 是否继续
    while (next_seq == true && cur_tuple < seq_size)
    {
        cout << "The first two elements of the sequence are: "
             << elem_seq[cur_tuple] << ", "
             << elem_seq[cur_tuple + 1]
             << "\nWhat is the next element?\n";
        cin >> usr_guess;

        if (usr_guess == elem_seq[cur_tuple + 2])
            cout << "Very good. Yes, "
                 << elem_seq[cur_tuple + 2]
                 << " is the next element in the "
                 << seq_names[cur_tuple/3] << " sequence.\n";
        else cout << "You are wrong!\n";

        cout << "Enter \'N\' to exit, others to continue:" << endl;
        cin >> usr_rsp;
        if (usr_rsp == 'N' || usr_rsp == 'n')
            next_seq = false;
        else cur_tuple += 3;
    }
}

