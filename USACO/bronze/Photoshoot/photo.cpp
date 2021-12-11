#include <iostream>
#include <fstream>
#include <unordered_map>
int main() {
    std::ifstream fin("photo.in");
    std::ofstream fout("photo.out");
    int n; fin >> n;
    int b[n];
    int perm[n+1];
    for (int a=0; a<n; a++) fin >> b[a];
    for (int a=1; a<b[0]; a++) {
        perm[0] = a;
        std::unordered_map<int, int> frequency;
        for (int c=1; c<n; c++) {
            perm[c] = b[c-1] - perm[c-1];
            frequency[perm[c]] += 1;
            if (frequency[perm[c]] > 1 || perm[c] <= 0) goto out;
        }
        break;
        out: continue;
    }
    for (int a=0; a<n-1; a++) fout << perm[a] << " ";
    fout << perm[n-1] << std::endl;
}
