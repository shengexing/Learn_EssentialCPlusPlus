// 小结：2.4 使用局部静态对象
// Created by TimeM on 2021/5/8 0008.
//

#include <iostream>
#include <vector>

using namespace std;

const vector<int>* fibon_seq(int);

int main()
{
    fibon_seq(24);
    fibon_seq(3);
    fibon_seq(8);
    return 0;
}

const vector<int>* fibon_seq(int size)
{
    const int max_size = 1024;
    static vector<int> elems;

    if (size <= 0 || size > max_size)
    {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can't fulfill request.\n";
        return 0;
    }

    /*
     * 如果 size 等于或小于 elems.size()，就不必计算了......
     */
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
