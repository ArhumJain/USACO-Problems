#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k, n;
    fin >> k >> n;
    int rankings[k][n];
    for (int a = 0; a < k; a++) {
        for (int b = 0; b < n; b++) {
            fin >> rankings[a][b];
        }
    }
    int count = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a+1; b < n; b++) {
            int x, y;
            for (int c = 1; c < k; c++) {
                for (int d = 0; d < n; d++) {
                    if (rankings[c][d]==rankings[0][a]) x = d;
                    else if (rankings[c][d]==rankings[0][b]) y = d;
                }
                if (x > y) goto out; 
            }
            count++; 
            out:
                continue;
        }
    }
    fout << count << endl;
}