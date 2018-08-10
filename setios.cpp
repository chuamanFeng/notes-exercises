▲ setprecision用法 
使用setprecision(n)可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。 
如果setprecision(n)与setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数。 
setiosflags(ios::fixed)是用定点方式表示实数，如果与setiosflags(ios::scientific)合用， 可以控制指数表示法的小数位数。

setiosflags(ios::scientific)//是用指数方式表示实数。
setiosflags(ios::fixed)// 固定的浮点显示
setiosflags(ios::scientific) //指数表示
setiosflags(ios::left) //左对齐
setiosflags(ios::right) //右对齐
setiosflags(ios::skipws) //忽略前导空白
setiosflags(ios::uppercase) //16进制数大写输出
setiosflags(ios::lowercase) //16进制小写输出
setiosflags(ios::showpoint)// 强制显示小数点
setiosflags(ios::showpos) //强制显示符号
1
10
例：

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
cout<<12345.0<<endl;//输出"12345"
cout<<setiosflags(ios::fixed)<<setprecision(3)<<1.2345<<endl;//输出"1.234"（遵循四舍六入五成双的原则，而不是四舍五入的原则）
cout<<resetiosflags(ios::fixed);//需要用resetiosflags()函数清除前面的输出格式！！！！
cout<<setiosflags(ios::scientific)<<12345.0<<endl;//输出"1.23e+004"
cout<<setprecision(3)<<12345.0<<endl;//输出"1.23e+004"（这里应该不用清除，因为输出格式和上一个相同）
return 0;
}
