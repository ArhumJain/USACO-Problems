#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(int x)
{
    string stringInt = to_string(x);
    int stringIntLength = stringInt.length();
    for (int i = 0; i < stringIntLength; i++)
    {
        if(stringInt[i] != stringInt[stringIntLength - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool isIntPalindrome = isPalindrome(-121);
    cout << isIntPalindrome << endl;
}