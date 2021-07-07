#include <iostream>
#include <vector>
#include <string>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    int charIndex = 0;
    if (strs.size() == 1) return strs[0];
    else if (strs.size() != 0)
    {
        while (true)
        {
            char commonChar = strs[0][charIndex];
            for (auto str: strs)
            {
                if (str[charIndex] != commonChar)
                {
                    return result;
                }
            }
            result += commonChar;
            charIndex++;
        }
    }
    return result == "\x00" ? "" : result;
}
int main()
{
    vector<string> words = {"", ""};

    string prefix = longestCommonPrefix(words);
    cout << prefix << endl;
}