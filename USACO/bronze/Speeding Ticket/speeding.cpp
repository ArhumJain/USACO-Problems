#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int miles[100];
    int limits[100];
    int N, M; fin >> N >> M;
    int mile, milePos = 0, limit;
    for (int i=0; i<N; i++) {
        fin >> mile >> limit;
        for (int j=milePos; j<mile+milePos; j++) {
            limits[j] = limit;
        }
        milePos += mile;
    }
    int max = 0;
    milePos = 0;
    for (int i=0; i<M; i++) {
        fin >> mile >> limit;
        for (int j=milePos; j<mile+milePos; j++) {
            if (limit > limits[j] && limit-limits[j] > max) max = limit-limits[j];
        }
        milePos += mile;
    }
    fout << max << endl;
}