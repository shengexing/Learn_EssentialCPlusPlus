//
// Created by TimeM on 2021/5/27 0027.
//

#ifndef LEARN_ESSENTIALCPLUSPLUS_NUMSEQ_H
#define LEARN_ESSENTIALCPLUSPLUS_NUMSEQ_H

#include <vector>
#include <iostream>

using namespace std;

void display(char, ostream &);
void display(int, ostream &);
void display(const string &, ostream &);
void display(const string &, int num, ostream &);
void display(const string &, int num1, int num2, ostream &);

bool is_size_ok(int);

const vector<int> *fibon_seq(int);
const vector<int> *lucas_seq(int);
const vector<int> *pell_seq(int);
const vector<int> *triang_seq(int);
const vector<int> *square_seq(int);
const vector<int> *pent_seq(int);
bool seq_elem(int, int&, const vector<int>* (*)(int));

const int seq_cnt = 6;
extern const vector<int>* (*seq_array[seq_cnt])(int);

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
 * 设置为 inline 函数
 * @param pos
 * @param elem
 * @return
 */
inline bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = 0)
{
    if (!seq_ptr)
    {
        display("Internal Error: seq_ptr is set to null!", cout);
        elem = 0;
        return false;
    }

    const vector<int> *pseq = seq_ptr(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    display("The pseq is: ", *pseq, cout);
    elem = (*pseq)[pos - 1];
    return true;
}

#endif //LEARN_ESSENTIALCPLUSPLUS_NUMSEQ_H
