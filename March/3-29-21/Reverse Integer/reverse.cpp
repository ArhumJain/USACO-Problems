#include <iostream>
#include <string>
using namespace std;

// Bulky solution not ver good code :(
int reverse(int x)
{
    string xString = to_string(x);
    string reversedString = "";
    for (int i = xString.length() - 1; i > -1; i--)
    {
        if (xString[i] != '-')
        {
            reversedString.push_back(xString[i]);
        }
    }
    long long reversedInteger = stoi(reversedString);
    if (stoi(xString) < 0)
    {
        reversedInteger = reversedInteger*-1;
    }
    if (reversedInteger > 2147483647 || reversedInteger < -2147483648)
    {
        return 0;
    }
    else
    {
        return reversedInteger;
    }
}
int main()
{
    int reverseInt = reverse(123);
    cout << reverseInt << endl;
}