// basically solved but not really, was running out of time so had to move on to next problem!
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int bales[101];
int temp[101];
int blast(int t, int pos, int direction){
    int explodedBales = 0;
    for(int a=1;; a++) {
        a = a * direction;
        if (bales[pos+a] <= temp[pos]+(t+1)*direction && bales[pos+a] != 0) {
            explodedBales++;
            bales[pos+a] = 0;
        } else break;
    }
    if (explodedBales==0) return 0;
    else {
        for (int a=pos+(1*direction); a<pos+(explodedBales+1)*direction; a += 1 * direction) {
            explodedBales += blast(t+1, a, direction);
        }
        return explodedBales;
    }
}
int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N; fin >> N;
    for (int i=0; i < N; i++) {
        fin >> bales[i];
        temp[i] = bales[i];
    }
    sort(bales, bales+N);
    sort(temp, temp+N);
    // cout << blast(0, N/2-0.5, 1) << endl;
    // cout << blast(0, N/2-0.5, -1) << endl;
    fout << blast(0, N/2-0.5, 1) + blast(0, N/2-0.5, -1) + 1<< endl;
}