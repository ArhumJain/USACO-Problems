#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int N, M; fin >> N >> M;
    string spotty[N], plain[N];
    for (int i=0; i<N; i++) fin >> spotty[i];
    for (int i=0; i<N; i++) fin >> plain[i];
    int potentialColumns = 0;
    for (int a=0; a<M; a++) {
        for (auto b: spotty) {
            for (auto c: plain) {
                if (b[a] == c[a]) goto out1;
            }
        }
        potentialColumns++;
        out1:
            continue;
    }
    fout << potentialColumns << endl;
}