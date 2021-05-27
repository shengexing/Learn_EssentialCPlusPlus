// 小结：2.1 如何编写函数
// Created by TimeM on 2021/4/28 0028.
//
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * 函数声明：计算 pos 位置处的斐波拉契数列值
 * @return pos 位置处的斐波拉契数列值
 */
int fibon_elem(int);

/**
 * 函数声明：计算 pos 位置处的斐波拉契数列值（优化）
 * @return 是否成功返回
 */
bool fibon_elem_better(int, int &);

/**
 * 函数声明：打印 pos 位置前的斐波拉契数列值
 */
void print_sequence(int);

int main()
{
    int index, result;

    while (true) {
        cout << "Please input a number that bigger than 0, and letter than 1025 (input other to exit):" << endl;
        cin >> index;
        if (fibon_elem_better(index, result))
        {
            cout << "The " << index << " index of Fibonacci is " << result << " .\n";
            print_sequence(index);
        } else
        {
            break;
            cout << "The index is out of range!\n";
        }
    }

}

/**
 * 函数定义：计算 pos 位置处的斐波拉契数列值
 * @param pos 区间 [1, +∞] 内的整数
 * @return pos 位置处的斐波拉契数列值
 */
int fibon_elem(int pos)
{
    /*
     * 检查不合理的位置
     */
    if (pos <= 0)
    {
        // 异常退出，exit() 函数 来至 #include <cstdlib>
        exit(-1);
    }

    /*
     * Fibonacci 数列的第一个元素和第二个元素都是 1；接下来的每个元素都是前两个元素的和。
     *
     * elem：持有即将返回的值
     * n_2, n_1：持有前两个元素的值
     * pos：数列中的元素位置（由调用者指定）
     */
    int elem = 1; // elem 持有欲返回的值
    int n_2 = 1, n_1 = 1;
    for (int i = 0; i <= pos; ++i)
    {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }

    return elem;
}

/**
 * 函数定义：计算 pos 位置处的斐波拉契数列值（优化）
 * @param pos 区间 [1, +∞] 内的整数
 * @param elem pos 位置处的斐波拉契数列值的地址
 * @return 是否成功返回
 */
bool fibon_elem_better(int pos, int &elem)
{
    /*
     * 检查位置值是否合理
     */
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    // 位置值为 1 和 2 时，elem 的值为 1
    elem = 1;
    int n_2 = 1, n_1 = 1;

    for (int i = 3; i <= pos; ++i) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }

    return true;
}

/**
 * 函数定义：打印 pos 位置前的斐波拉契数列值
 * @param pos 区间 [1, +∞] 内的整数
 */
void print_sequence(int pos)
{
    cout << "The Fibonacci Sequence for " << pos << " position: \n\t";
    
    /*
     * 所有位置都会打印出 1 1，只有 pos == 1 除外
     */
    switch (pos) {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem, n_2 = 1, n_1 = 1;
    for (int i = 3; i <= pos; ++i) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
        // 一行打印 10 个元素
        cout << elem << (!(i%10) ? "\n\t" : " ");
    }
    cout << endl;
    // 结尾处隐式返回
}
