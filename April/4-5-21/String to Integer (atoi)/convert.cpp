#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;  

int myAtoi(string s)
{
     
    map<char, int> charToNumber = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},  {'7', 7}, {'8', 8},  {'9', 9}};
    bool isNegative = false;
    bool signDetermined = false; 
    double result = 0;
    bool leadingCharactersProcessed = false;
    int charactersToErase = 0;
    int digitCount = 0;
    string processedString = s;
    for (auto character: processedString)
    {
        if (!leadingCharactersProcessed)
        {
            if (character == ' ') charactersToErase++;
            else if (character == '-' && !signDetermined){ 
                isNegative = true;
                signDetermined = true;
                charactersToErase++;
            }
            else if ((character == '+' || character != '+') && signDetermined == false){ 
                charactersToErase++;
                signDetermined = true;
            }
            else if (character == '0' && leadingCharactersProcessed == false && signDetermined) charactersToErase++;
            else if(charToNumber.count(character) == 0) return 0;
            
            if (charToNumber[character] != 0 || character == '0'){
                leadingCharactersProcessed = true;
            }
        } 
        if (leadingCharactersProcessed) {
            if (charToNumber[character] == 0 && character != '0') break;
            else digitCount++;           
        }
    }
    processedString.erase(0, charactersToErase);
    for (int i = 0; i < digitCount; i++)
    {
        char digit = processedString[i];
        double decimalPlace = pow(10, digitCount-i-1);
        result += charToNumber[digit]*decimalPlace;
    }
    if (isNegative) result = -result;
    if (result > 2147483647) result = 2147483647;
    else if (result < -2147483648) result = -2147483648;
    return result;
}
int main()
{
    map<char, int> charToNumber = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},  {'7', 7}, {'8', 8},  {'9', 9}};
    cout << myAtoi("42") << endl;
}