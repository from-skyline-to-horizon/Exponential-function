// 次幂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
double result[5] = { 0 };
double fastPower(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }

    double temp = fastPower(base, exponent / 2);
    if (exponent % 2 == 0) {
        return temp * temp;
    }
    else {
        return base * temp * temp;
    }
}
double my_pwr(double x, int n) {
    if (n == 0)return(1.0);
    if (n == 1)return(x);
    double y = my_pwr(x, n >> 1);
    if (n & 1) {
        return(y * y * x);
    }
    else {
        return(y * y);
    }
}
double root_n(double x, int n) {
    double x0=1;
    double x1;
    double y;
    while (1) {
        y = my_pwr(x0, n - 1);
        x1 = x0 - (x0 * y - x) / (n * y);
        x0 = x1;
        if (fabs(my_pwr(x0, n) - x) < 1e-6)break;
    }
    return(x0);
}
int main() {
    double x; // 输入底数
    double a ; // 输入指数
    cin >> x >> a;
    int c = (int)(a);//指数的整数部分
    double d = a - c;//指数的小数部分
     result[0] = fastPower(x, c);//计算指数整数部分的值    
     //int int_d = (int)(d * 65536);
     //
     for (int  i = 1; i <= 4; i++)
     {
         int d2 = d * pow(2, i*4);//取四位小数
         double e = pow(x, d2);//整数计算
         for (int j = 1; j <=i; j++)
         {
             e = root_n(e, 16);
         }
         result[i] = e;//求根号返回小数并储存
         d = d - (double)(d2) / pow(2, i*4);//去除已经计算过的部分
     }
     //
     double sum = 1;
     for (int i = 0; i < 5; i++)
     {
         sum = sum * result[i];
     }
     cout << "the result is: " << sum << endl;
     cout << pow(x, a);
    return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
