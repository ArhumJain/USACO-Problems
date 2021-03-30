#include <iostream>
#include <vector>
using namespace std;


void reverseString(vector<char>& s) {
    vector<char> reverse;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        reverse.push_back(s[i]);
    }
    s = reverse;
}
int main()
{
    vector <char> characters = {'a','b','c'};
    reverseString(characters);
}