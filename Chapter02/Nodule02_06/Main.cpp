// 小结：2.6 提供重载函数
// Created by TimeM on 2021/5/9 0009.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 定义多个 display 函数，重载实现
 * @param ch
 * @param out
 */
void display(char ch, ostream &out = cout)
{
    out << ch;
}

void display(int num, ostream &out = cout)
{
    out << num;
}

void display(const string& str, ostream &out  = cout)
{
    out << str;
}

void display(const string& str, int num, ostream &out = cout)
{
    out << str << ", " << num;
}

void display(const string& str, int num1, int num2, ostream &out = cout)
{
    out << str << ", " << num1 << ", " << num2;
}

/**
 * 判断 size 是否合法
 * @param size
 * @return
 */
bool is_size_ok(int size)
{
    const int max_size = 1024;
    const string msg("Requested size is not supported");

    if (size <= 0 || size > max_size)
    {
        display(msg, cerr);
        return false;
    }
    return true;
}

/**
 * 计算 Fibonacci 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int>* fibon_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0 || ix == 1)
        {
            elems.push_back(1);
        } else
        {
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
    }

    return &elems;
}

/**
 * 设置为 inline 函数
 * @param pos
 * @param elem
 * @return
 */
inline bool fibon_elem(int pos, int &elem)
{
    const vector<int> *pseq = fibon_seq(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}

int main()
{
    int size = -1, elem;
    if (fibon_elem(size, elem))
    {
        display(elem);
    }
    return 0;
}
