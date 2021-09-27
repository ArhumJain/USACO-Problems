#include <iostream>
#include <map>

using namespace std;


int romanToInt(string s)
{
    map <char, int> charToInt = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    int index = 0;
    while (index < s.length()){
        if (charToInt[s[index]] < charToInt[s[index+1]])
        {
            result += charToInt[s[index+1]] - charToInt[s[index]];
            index += 2;
        }
        else
        {
            result += charToInt[s[index]];
            index++;
        } 
    }
    return result;
}
int main()
{
    cout << romanToInt("III") << endl;
}