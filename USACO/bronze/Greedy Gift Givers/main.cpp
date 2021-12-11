/*
ID: arhumja1
LANG: C++
PROG: gift1
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

vector<string> split(string* s)
{
    vector<string> split;
    string segment = "";
    for (char i: (*s))
    {
        if (i != ' '){
            segment += i;
        }
        else
        {
            split.push_back(segment);
            segment = "";
        }
    }
    if (segment.length() > 0) split.push_back(segment);
    return split;
}
int main()
{
    
    ifstream in("gift1.in");
    ofstream out("gift1.out");
    
    map<string, int> distribution;

    int np;
    int count = 0;
    int n;
    string line;
    vector<string> insertionOrder;
    
    while (!in.eof())
    {
        string person;
        vector<string> values; 
        int money;
        int nPeople;
        while(getline(in, line))
        {
            if (np==0){
                np = stoi(line);
                n = np;
            }

            else if (n == np && (count - np) <= 0)
            {
                distribution[line] = 0; 
                insertionOrder.push_back(line);
            }
            else if (count-n == 1) person = line;
            else if (count-n == 2)
            {
                values = split(&line);
                money = stoi(values[0]);
                nPeople = stoi(values[1]);
                n = nPeople;
                if (money != 0 && nPeople != 0) distribution[person] -= (money-(money%nPeople));
                count = 0;
            }
            else {
                distribution[line] += (money/nPeople);
            }
            count++;
        }   
    }
    for (string i: insertionOrder)
    {
        out << i << " " << distribution[i] << "\n";
    }
    return 0;
}