/*
ID: arhumja1
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("D:\\Programming\\Algorithms\\USACO\\bronze\\Broken Necklace\\beads.in");
    ofstream fout("beads.out");
    
    int n;
    char prev;
    int total = 1;
    int currCount = 0;
    int largest = 0;
    bool other = false;
    
    string bead;
    
    fin >> n >> bead;
    bead += bead;
     
    if (bead[0] == 'w') { prev = bead[1]; currCount += 1; }
    else { prev = bead[0]; currCount += 1; }

    for (int i = 1; i < n*2; i++) {
        if (bead[i] == 'w') total += 1; 
        else if (bead[i] == prev || (prev == 'w' && !other)) {
            prev = bead[i];
            currCount += 1;
            total += 1;
        }
        else if (bead[i] != prev && !other) {
            prev = bead[i];
            currCount = 1;
            total += 1;
            other = true;
        }
        else if (bead[i] != prev) {
            if (total > largest) largest = total;
            i -= currCount;
            prev = bead[i];
            currCount = 1;
            total = 1;
            other = false;
        }
    }
    
    cout << largest << "\n";
    // fout << largest << "\n";
}