// 小结：2.8 函数指针带来更大的弹性
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
    out << num << endl;
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
 * 使用模板函数
 * @tparam elemType
 * @param msg
 * @param vec
 * @param out
 */
template <typename elemType> void display(const string &msg, const vector<elemType> &vec, ostream &out = cout)
{
    out << msg;
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        elemType t = vec[ix];
        out << t << ' ';
    }
    out << endl;
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

const vector<int> *fibon_seq(int);
const vector<int> *lucas_seq(int);
const vector<int> *pell_seq(int);
const vector<int> *triang_seq(int);
const vector<int> *square_seq(int);
const vector<int> *pent_seq(int);
bool seq_elem(int, int&, const vector<int>* (*)(int));

/**
 * 计算 Fibonacci 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *fibon_seq(int size)
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
 * 计算 Lucas 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *lucas_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
        {
            elems.push_back(1);
        } else if (ix == 1)
        {
            elems.push_back(3);
        } else
        {
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
    }

    return &elems;
}

/**
 * 计算 Pell 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *pell_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
        {
            elems.push_back(1);
        } else if (ix == 1)
        {
            elems.push_back(2);
        } else
        {
            elems.push_back(2*elems[ix - 1] + elems[ix - 2]);
        }
    }

    return &elems;
}

/**
 * 计算 Triangular 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *triang_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
        {
            elems.push_back(1);
        } else
        {
            elems.push_back(elems[ix - 1] + ix + 1);
        }
    }

    return &elems;
}

/**
 * 计算 Square 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *square_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        int i = ix + 1;
        elems.push_back(i*i);
    }

    return &elems;
}

/**
 * 计算 Pentagonal 数列中的 size 个元素，并返回持有这些元素的静态容器的地址
 * @param size
 * @return
 */
const vector<int> *pent_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
    {
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0)
        {
            elems.push_back(1);
        } else if (ix == 1)
        {
            elems.push_back(5);
        } else
        {
            elems.push_back(2*elems[ix - 1] - elems[ix - 2] + 3);
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
inline bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = 0)
{
    if (!seq_ptr)
    {
        display("Internal Error: seq_ptr is set to null!");
        elem = 0;
        return false;
    }

    const vector<int> *pseq = seq_ptr(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    display("The pseq is: ", *pseq);
    elem = (*pseq)[pos - 1];
    return true;
}

int main()
{
    int size = 10, elem;
    // seq_array 是一个数组，内放函数指针
    const vector<int>* (*seq_array[])(int) = {fibon_seq, lucas_seq, pell_seq, triang_seq, square_seq, pent_seq};
    // ns_type 是一个枚举，0~5
    enum ns_type {
        ns_fibon, ns_lucas, ns_pell, ns_triang, ns_square, ns_pent
    };
    if (seq_elem(size, elem, seq_array[ns_fibon]))
    {
        display(elem);
    }
    for (int i = 1; i < 6; ++i)
    {
        if (seq_elem(size, elem, seq_array[i]))
        {
            display(elem);
        }
    }
    return 0;
}
