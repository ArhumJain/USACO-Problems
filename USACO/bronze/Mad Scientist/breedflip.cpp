#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int N; fin >> N;
    char A[N], B[N];
    for (int a=0; a<N; a++) fin >> A[a];
    for (int a=0; a<N; a++) fin >> B[a];
    int count = 0;
    int currCount = 0;
    for (int a=0; a<N; a++) {
        if (B[a] != A[a]) currCount++;
        else {
            if (currCount>0) count++;
            currCount = 0;
        }
    }
    if (currCount > 0) count++;
    fout << count << endl;
}