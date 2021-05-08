[首页](../README.md)

### 练习 2.1
&emsp;&emsp;先前的 main() 只让用户输入一个位置值，然后便结束程序。如果用户想取得两个甚至更多元素值，
他必须执行这个程序两次或多次。请改写 main()，使它允许用户不断输入位置值，直到用户希望停止为止。

### 解答 2.1
> 代码片段：
> ```c++
> int main()
> {
>     int index, result;
>
>     while (true) {
>         cout << "Please input a number that bigger than 0, and letter than 1025（input other to exit）:" << endl;
>         cin >> index;
>         if (fibon_elem_better(index, result))
>         {
>             cout << "The " << index << " index of Fibonacci is " << result << " .\n";
>             print_sequence(index);
>         } else
>         {
>             break;
>             cout << "The index is out of range!\n";
>         }
>     }
>
> }
> ```