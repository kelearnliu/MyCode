#include <iostream>
#include <vector>
#include <string>
using namespace std;

size_t solve(size_t a, size_t b, size_t& x, size_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    size_t xx, yy;
    size_t res = solve(a, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return res;
}
size_t calc(size_t a, size_t b) {
    size_t x, y;
    solve(a, b, x, y);
    x = (x % b + b) % b;
    return x;

}
void t1()
{
    size_t a, b;
    cin >> a >> b;
    size_t x = calc(a, b);
    cout << x << endl;
}
#define MAX 1000

size_t calc(string num1, string num2, vector<int>& sum)
{
    int i,j,len,len1,len2;
    vector<int> a(MAX+10,0);
    vector<int> b(MAX+10,0);
    vector<int> c(MAX*2+10,0);
    len1 = num1.size();
    for(j=0,i=len1-1;i>=0;i--)
        a[j++]=num1[i]-'0';

    len2 = num2.size();
    for(j=0,i=len2-1;i>=0;i--)
    {
        b[j++]=num2[i]-'0';
    }

    for(i =0;i<len2;i++)
    {
        for(j=0;j<len1;j++)
        {
            c[i+j]+=b[i]*a[j];
        }
    }

    for(i=0;i<MAX*2;i++)
    {
        if(c[i]>=0)
        {
            c[i+1] += c[i]/10;
            c[i]%=10;
        }
    }
    for(i = MAX*2; c[i]==0 && i>=0;i--)
    {
        len=i+1;
    }

    for(;i>=0;i--)
    {
        sum[i]=c[i];
    }
    return len;

}
void t2()
{
    vector<int> sum(MAX*2+10,0);
    string num1,num2;
    cin>>num1>>num2;
    size_t len = calc(num1,num2,sum);
    for(int i=len-1;i>=0;i--)
        cout<<sum[i];
    cout<<endl;
}

std::string multiplyLargeNumbers(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();

    // 创建一个结果字符串并初始化为0
    std::string result(len1 + len2, '0');

    // 从右向左逐位相乘
    for (int i = len2 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len1 - 1; j >= 0; j--) {
            //result[i + j + 1] - '0' 这是表示原来所在位的值
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            cout<<"i: "<<i<<"j: "<<j<<"product: "<<product<<"carry: "<<carry<<endl;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }

    // 去掉前导零
    size_t startPos = result.find_first_not_of('0');
    if (startPos != std::string::npos) {
        return result.substr(startPos);
    }
    return "0"; // 如果结果为0，返回"0"
}
void t3()
{
    string num1="123456789";
    string num2="345678999";
    cout<< stoll(num1)* stoi(num2)<<endl;
    cout<<multiplyLargeNumbers(num1,num2);
}
int main() {
//    t1();
//    t2();
        t3();
}
// 64 位输出请用 printf("%lld")