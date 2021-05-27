[首页](../README.md)

### 练习 1.1
&emsp;&emsp;将先前介绍的main（）程序依样画葫芦地输入。
你可以直接输入程序代码，或是从网络上下载。
本书前言已经告诉你如何获得书中范例程序的源程序以及习题解答。试着在你的系统上编译并执行这个程序。

### 解答 1.1
> 运行结果如下图所示：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-49-28.png)

### 练习 1.2
> 将 string 头文件注释掉：  
> // include <string>

&emsp;&emsp;重新编译这个程序，看看会发生什么事。
然后取消对 string 头文件的注释，再将下一行注释：
> // using namespace std;

&emsp;&emsp;又会发生什么事情？

### 解答 1.2
> (1) 去掉 string 的引用，程序编译不会出错。  
> std::istream 和 std::ostream 都有 std::ios_base 这个基类。  
> std::ios_base 的成员函数 getloc 以值返回 std::locale （要求定义可见）。  
> std::locale 的成员函数 name 以值返回 std::string （要求定义可见）。  
> 所以包含 <iostream> 后能使用 std::string 应该是确定的，不过不一定等价于包含 <string> 。
>
> 使用 gcc -M Main.cpp 可以查看 Main.cpp 引入了哪些头文件：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-20-52.png)
>
> (2) 去掉 using namespace std; 程序编译出错，不能识别 string, cin, cout  
> 报错信息如下：  
> <img src="https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-41-29.png" width="80%">

### 练习 1.3
&emsp;&emsp;将函数名 mian() 改为 my_main()，然后重新编译。有什么结果？

### 解答 1.3
> 修改函数名后，没有 main() 函数入口，编译出错，报错信息如下：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-58-46.png)

### 练习 1.4
&emsp;&emsp;试着扩充这个程序的内容：  
（1）要求用户同时输入名字（first name）和姓氏（last name）;  
（2）修改输出结果，同时打印姓氏和名字。

### 解答 1.4
> 修改代码如下：
> ```c++
> #include <iostream>
> #include <string>
>
> using namespace std;
> 
> int main()
> {
>     string first_name;
>     string last_name;
>     cout << "Please enter your first name: ";
>     cin >> first_name;
>     cout << "Please enter your last name: ";
>     cin >> last_name;
>     cout << '\n'
>          << "Hello, "
>          << first_name + " " + last_name
>          << " ... and goodbye!\n";
>
>     return 0;
> }
> ```
> 运行结果如下：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_10-11-14.png)

### 练习 1.5
&emsp;&emsp;编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。
如果用户的确输入了有效名称，就响应一些信息。请以两种方式实现：第一种使用C-style字符串，第二种使用string对象。

### 解答 1.5
> 方式一：  
> 代码片段：
> ```c++
> #include <stdio.h>
> #include <string.h>
>
> int main()
> {
>     char str[20];
>     printf("Please input your name:\n");
>     scanf("%s", str);
>     size_t len = strlen(str);
>     if (len > 1)
>         printf("Hello, %s", str);
>     else printf("Error!");
>
>    return 0;
> }
> ```
> 运行结果：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-27_01-08-11.png)
>
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-27_01-12-28.png)
>
>
> 方式二：  
> 代码片段：
> ```c++
> #include <iostream>
> #include <string>
>
> using namespace std;
> 
> int main()
> {
>     string str;
>     cout << "Please input your name:\n";
>     cin >> str;
>     if (str.length() > 1)
>         cout << "Hello, " << str;
>     else cout << "Error!";
>
>     return 0;
> }
> ```
> 运行结果：（和方式一相同）

### 练习 1.6
&emsp;&emsp;编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到放到 array 及 vector，
然后遍历这两种容器，求取数值总和。将总和及平均值输出至标准输出设备。

### 解答 1.6
> 代码片段：
> ```c++
> #include <iostream>
> #include <vector>
>
> using namespace std;
> 
> int main()
> {
>     // 01. 声明变量
>     int seq_size = 10;
>     int seq_array[seq_size];
>     vector<int> seq_vector(seq_size);
>
>     // 02. 变量赋值
>     int i = 0;
>     cout << "Please enter a string of numbers (max size is 10), separated by a space:" << endl;
>     while (cin >> seq_array[i++])
>     {
>         seq_vector[i - 1] = seq_array[i - 1];
>         if (cin.get() == '\n')
>             break;
>     }
>
>     // 03. 求和，求均值
>     int sum = 0;
>     double avg = 0.0;
>     int count = i;
>     while (i--)
>         sum += seq_vector[i];
>     avg = sum/count;
>     cout << "The numbers of sum is " << sum << ", avg is " << avg << endl;
>
>     return 0;
> }
> ```
> 运行结果：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-27_09-40-31.png)

### 练习 1.7
&emsp;&emsp;使用你最称手的编辑工具，输入两行（或更多）文字并存盘。然后编写一个程序，打开该文本文件，
将其中每个字都读取到一个 vector<string> 对象中。遍历该 vector，将内容显示到 cout。然后利用泛型算法 sort()，
对所有文字排序：
```c++
#include <algorithm>
sort( container.begin(), container.end() );
```
&emsp;&emsp;再将排序后的结果输出到另一个文件。

### 解答 1.7
> 代码片段：
> ```c++
> #include <iostream>
> #include <string>
> #include <vector>
> #include <fstream>
> #include <algorithm>
>
> using namespace std;
>
> // 降序比较大小
> bool cmp(string a, string b) {
> return a > b;
> }
>
> int main()
> {
>     // 01. 定义变量
>     vector<string> seq_str(100);
>
>     // 02. 打开源文件
>     ifstream infile("source.txt");
>
>     // 03. 读取文件
>     int i = 0;
>     if (infile.is_open())
>     {
>         while (!infile.eof())
>             getline(infile, seq_str[i++]);
>     } else cerr << "Oops! Unable to save session data!\n";
>
>     // 04. 关闭文件
>     infile.close();
>
>     // 05. 排序
>     sort(seq_str.begin(), seq_str.end(), cmp);
>
>     // 06. 输出排序结果
>     cout << "The result of sort is:\n";
>     ofstream outfile("target.txt", ios_base::app);
>     if (outfile.is_open())
>     {
>         while (i > 0)
>         {
>             cout << seq_str[--i] << "\t";
>             outfile << seq_str[i] << "\t";
>         }
>     } else cerr << "Oops! Unable to save session data!\n";
>     outfile << endl;
>     outfile.close();
>
>     return 0;
> }
> ```
> 运行结果：
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-27_10-40-17.png)
> 
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-27_10-42-06.png)

### 练习 1.8
&emsp;&emsp;1.4 节的 switch 语句让我们得以根据用户答错的次数提供不同的安慰语句。请以 array 存储四种不同的字符串信息，
并以用户答错次数作为 array 的索引值，以此方式来显示安慰语句。

### 解答 1.8
> 代码片段：
> ```c++
> string seq_str[4] = {
>     "Come on, you can continue.",
>     "Don't worry, you can continue.",
>     "Be careful, you can continue.",
>     "Don't be sad, you can go on."};
> usr_tried++; // 总次数加一
> if (usr_guess == elem_seq[cur_tuple + 2])
>     usr_right++; // 猜对次数加一
>     cout << "Very good. Yes, "
>          << elem_seq[cur_tuple + 2]
>          << " is the next element in the "
>          << seq_names[cur_tuple/3] << " sequence.\n";
> else
> {
>     switch(usr_tried)
>     {
>         case 1:
>               cout << seq_str[0] << endl;
>               break;
>         case 2:
>               cout << seq_str[1] << endl;
>               break;
>         case 3:
>               cout << seq_str[2] << endl;
>               break;
>         default:
>               cout << seq_str[3] << endl;
>               break;
>     }
> };
> ```
