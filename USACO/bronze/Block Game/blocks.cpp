#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    int n; fin >> n;
    int frequency[26] = {0};
    string word;
    for (int a=0; a<n; a++) {
        int A[26] = {0}; int B[26] = {0};
        fin >> word;
        for (auto c: word) A[c-97] += 1;
        fin >> word;
        for (auto c: word) B[c-97] += 1;
        for (int b=0; b<26; b++) frequency[b] += max(A[b], B[b]);
        
    }

    for (int a=0; a<26; a++) fout << frequency[a] << endl;
}
