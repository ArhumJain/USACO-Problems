#include <iostream>
#include <fstream>
int main() {
    std::ifstream fin("sleepy.in");
    std::ofstream fout("sleepy.out");
    int n; fin >> n;
    int cows[100];
    int c = 0;
    for (int a=0; a<n; a++) fin >> cows[a];
    for (int a=n-1; a>-1; a--) {
        if (cows[a] > cows[a-1]) c++;
        else break;
    }
    fout << n-1-c << std::endl;
}