#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int n; fin >> n;
    int lineup[100];
    int sortedLineup[100];
    for (int i=0; i<n; i++) {
        fin >> lineup[i];
        sortedLineup[i] = lineup[i];
    }
    sort(sortedLineup, sortedLineup+n);
    int swaps = -1;
    for (int i=0; i<n; i++) {
        if (sortedLineup[i] != lineup[i]) {
            swaps++;
        }
    }
    swaps = max(0, swaps);
    fout << swaps << endl;
}