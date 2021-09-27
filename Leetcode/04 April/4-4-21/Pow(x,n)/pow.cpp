#include <iostream>
#include <string>
using namespace std;    
double myPow(double x, int n) {
    double ans;
    bool flag = false;
    if (n < 0)
    {
        flag = true;
    }
    n = abs(n);
    if (n == 1 && flag == false)
    {
        return x;
    }
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1 || n == 0)
    {
        return 1;
    }
    double temp = myPow(x, n / 2);
    if (flag == false)
    {
        if (n % 2 == 0)
        {
            ans = temp * temp;
        }
        else
        {
            ans = temp * temp * x;
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            ans = 1 / (temp * temp);
        }
        else
        {
            ans = 1 / (temp * temp * x);
        }
    }
    return ans;

}
int main()
{
    cout << myPow(2, 3) << endl;
}