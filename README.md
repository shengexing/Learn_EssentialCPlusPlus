# Learn_EssentialCPlusPlus
## 学习《Essential C++》
### 1. C++ 编程基础 Basic C++Programming ............... p17
#### 1.1 如何撰写 C++ 程序 ........................................................................ p18
<br/>

##### 练习 1.1
&emsp;&emsp;将先前介绍的main（）程序依样画葫芦地输入。
你可以直接输入程序代码，或是从网络上下载。
本书前言已经告诉你如何获得书中范例程序的源程序以及习题解答。试着在你的系统上编译并执行这个程序。

##### 解答 1.1
> 运行结果如下图所示：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-49-28.png)

##### 练习 1.2
> 将 string 头文件注释掉：  
> // include <string>

&emsp;&emsp;重新编译这个程序，看看会发生什么事。
然后取消对 string 头文件的注释，再将下一行注释：
> // using namespace std;

&emsp;&emsp;又会发生什么事情？

##### 解答 1.2
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

##### 练习 1.3
将函数名 mian() 改为 my_main()，然后重新编译。有什么结果？

##### 解答 1.3
> 修改函数名后，没有 main() 函数入口，编译出错，报错信息如下：  
> ![示例图片](https://timem-edu.oss-cn-chengdu.aliyuncs.com/github/Learn_EssentialCPlusPlus/Snipaste_2021-04-25_09-58-46.png)

##### 练习 1.4
试着扩充这个程序的内容：  
（1）要求用户同时输入名字（first name）和姓氏（last name）;  
（2）修改输出结果，同时打印姓氏和名字。

##### 解答 1.4
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
> 