#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");
    int n, k; fin >> n >> k;
    string word; int len = 0;
    fin >> word; len = word.size(); fout << word;
    for (int a=1; a<n; a++) {
        fin >> word;
        len += word.size();
        if (len > k) {
            len = word.size();
            fout << endl << word;
        } else fout << " " << word;
    }
}