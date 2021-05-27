// 小结：2.3 提供默认参数值
// Created by TimeM on 2021/5/8 0008.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * 显示数组元素
 * @param vec
 * @param os
 */
void display(const vector<int> &vec, ostream &os = cout)
{
    for (int ix = 0; ix < vec.size(); ++ix) {
        os << vec[ix] << ' ';
    }
    os << endl;
}

/**
 * 交换两个元素的值
 * @param val1
 * @param val2
 */
void swap(int val1, int val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * 交换两个元素的值
 * 以 reference 的方式来声明 val1 和 val2，那么，swap() 内对这两个参数的改变，
 * 会反映到传入 swap() 的实际对象身上。
 * @param val1
 * @param val2
 */
void swap3(int & val1, int & val2)
{
    /*
     * 请注意，swap() 的函数代码并没有任何改变 —— 唯一改变的是
     * swap() 的参数和传入 swap() 的对象之间的关系。
     */
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * 冒泡排序
 * @param vec
 * @param ofil 第一个有默认值的参数右边的参数都必须有默认值
 */
void bubble_sort(vector<int> &vec, ofstream *ofil = 0)
{
    for (int ix = 0; ix < vec.size(); ++ix) {
        for (int jx = ix + 1; jx < vec.size(); ++jx) {
            if (vec[ix] > vec[jx]) {
                // 调试用的输出信息
                if (ofil != 0) {
                    (*ofil) << "about to call swap!"
                         << " ix: " << ix << " jx: " << jx << '\t'
                         << " swapping: " << vec[ix]
                         << " with " << vec[jx] << endl;
                }
                swap3(vec[ix], vec[jx]);
            }
        }
    }
}

int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);

    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);

    cout << "vector after sort: ";
    display(vec);
}
