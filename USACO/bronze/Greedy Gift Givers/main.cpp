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
void test(){
    cout << 2%3 << endl;
}
int main()
{
    int np;
    int count = 0;

    map<string, int> distribution;
    ifstream f("D:\\Programming\\Algorithms\\USACO\\bronze\\Greedy Gift Givers\\gift1.in");

    char snp;

    f >> snp;
    f.ignore();
    count++;
    np = snp - '0';

    string line;
    int n = np;
    while (!f.eof())
    {
        string person;
        vector<string> values; 
        int money;
        int nPeople;
        while(getline(f, line))
        {

            if (n == np && (count - np) <= 0)
            {
                distribution[line] = 0; 
            }
            if (count > n){
                if (count%n == 1) person = line;
                else if (count%n == 2)
                {
                    values = split(&line);
                    money = stoi(values[0]);
                    nPeople = stoi(values[1]);
                    n = nPeople;
                    cout << money << " " << nPeople << endl;
                    count = 0;
                }
            }
            // else if ()
            count++;
        }   
        
    }
    for (auto i: distribution)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
