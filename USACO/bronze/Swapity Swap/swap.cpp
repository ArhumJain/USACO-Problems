// nice problem got the gist but time running out so gotta move on to next prob
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int N, K; fin >> N >> K;
    int A1, A2; fin >> A1 >> A2;
    int B1, B2; fin >> B1 >> B2;
    int cows[100];
    for (int i=0; i<N; i++) {
        cows[i] = i+1;
    }
    for (int i=0; i<K; i++) {
        reverse(cows+(A1-1), cows+(A2));
        reverse(cows+(B1-1), cows+(B2));
        for (int i=0; i<N; i++) cout << cows[i] << " ";
        cout << endl;
    }
    for (int i=0; i<N; i++) fout << cows[i] << endl;

}