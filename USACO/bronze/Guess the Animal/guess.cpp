#include <iostream>
#include <fstream>
int main() {
    std::ifstream fin("guess.in");
    std::ofstream fout("guess.out");
    int n; fin >> n;
    std::string animals[n][100];
    int k[n];
    for (int a=0; a<n; a++) {
        fin.ignore(20, ' ');
        fin >> k[a];
        for (int b=0; b<k[a]; b++) fin >> animals[a][b];
    }
    int max = 1;
    for (int a=0; a<n; a++) {
        for (int b=a+1; b<n; b++) {
            int common = 1;
            for (int c=0; c<k[a]; c++) {
                for (int d=0; d<k[b]; d++) {
                    if (animals[a][c]==animals[b][d]) common++;
                }
            }
            if (common > max) max = common;
        }
    }
    fout << max << std::endl;
}