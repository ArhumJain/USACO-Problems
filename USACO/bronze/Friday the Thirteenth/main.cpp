/*
ID: arhumja1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int freq[7] = {0};
    int n;
    int d = 2;
    fin >> n;
    for (int y = 1900; y < 1900+n; y++) {
        for (int m = 0; m < 12; m++) {
            freq[(d+5)%7] += 1;
            if (m == 1) {
                if ((y%4 == 0 && y%100 != 0) || (y%400 == 0 && y%100 == 0)) d = (d+1)%7;
            } 
            else if (m == 3 || m == 5 || m == 8 || m == 10) d = (d+2)%7;
            else d = (d+3)%7;
        }
    }
    for (int i = 0; i < 6; i++) {
        fout << freq[i] << " ";
    }
    fout << freq[6] << "\n";
}