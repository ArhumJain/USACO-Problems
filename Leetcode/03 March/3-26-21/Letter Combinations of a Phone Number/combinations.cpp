#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void findCombinations(int index, vector<string> &letterGroups, vector<string> &combinations, string combination = "")
{
    for (auto letter: letterGroups[index])
    {
        int letterGroupsSizeLastIndex = letterGroups.size() - 1;
        if (index == letterGroupsSizeLastIndex)
        {
            combinations.push_back(combination + letter);
        }
        else
        {
            findCombinations(index + 1, letterGroups, combinations, combination + letter);
        }
    }
}
vector<string> solve(string digits) {
    map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                             {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterGroups = {};
    vector<string> combinations = {};
    if (!digits.empty())
    {
        for (auto digit: digits)
        {
            letterGroups.push_back(map[digit]);
        }
        findCombinations(0, letterGroups, combinations);
    }
    return combinations;        
}
int main()
{
    vector<string> combinations = solve("23");
    for (auto const combination: combinations)
    {
        cout << combination << endl;
    }
}