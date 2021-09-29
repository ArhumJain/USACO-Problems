/*
ID: arhumja1
LANG: C++
PROG: ride
*/
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;
int convert(string name)
{
    int product = 1;
    for (char i: name) 
    {
        product *= int(i) - 64;
    }
    return product%47;
}
int main()
{
    ifstream f("ride.in");
    ofstream o("ride.out");

    string comet;
    string group;
    
    f >> comet >> group;
    
    if(convert(comet) == convert(group)) o << "GO\n";
    else o << "STAY\n";
}