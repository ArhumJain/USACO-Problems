#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n;
    fin >> n;
    vector<int> ids(n);
    vector<int> a(n);
    int ai;
    for (int i = 0; i < n; i++) { 
        fin >> ai; 
        a[ai-1] = i;
    }
    for (int i = 0; i < n; i++) fin >> ids[i];
    vector<int> temp;
    for (int i = 0; i < 3; i++) {
        temp = ids;
        for (int j = 0; j < n; j++) {
            ids[a[j]] = temp[j];
        }
    }
    for (int i = 0; i < n; i++) fout << ids[i] << endl;
}