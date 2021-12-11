#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int M, N, K;
    fin >> M >> N >> K;
    string output;
    for (int a=0; a<M; a++) {
        fin >> output;
        for (int b=0; b<K; b++) {
            for (char c: output) {
                for (int d=0; d<K; d++) fout << c;
            }
            fout << endl;
        }
    }

    
}