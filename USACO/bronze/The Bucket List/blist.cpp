#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int n;
    int c = 0;
    int b = 0;
    map<int, int> bucketCounts;
    fin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> bA;
        pair<int, int> bB;
        fin >> bA.first >> bB.first >> bA.second;
        bB.second = -bA.second;
        bucketCounts.insert(bA); bucketCounts.insert(bB);
    }
    for (auto i: bucketCounts) {
        c += i.second;
        if (c > b) b = c;
    }
    fout << b << std::endl;
}