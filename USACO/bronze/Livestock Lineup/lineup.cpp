// sheeeeeeeesh, a stupidly stupid solution that somehow works (spare me, im hungover from an episode of I CANT FREAKING DO USACO ARGHGHGHG):p
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    int n;
    fin >> n;
    string constraints[n][2];
    for (int i = 0; i < n; i++) {
        fin >> constraints[i][0];
        fin.ignore(23);
        fin >> constraints[i][1];
    }
    string answer[8] = {};
    do {
        for (int a = 0; a < 8; a++) {
            for (int b = 0; b < n; b++) {
                if (cows[a] == constraints[b][0]) {
                    if ((a > 0 && cows[a-1] == constraints[b][1]) || (a < 7 && cows[a+1] == constraints[b][1])) { 
                        continue;
                    } else {
                        goto out;
                    }
                }
            }
        }
        for (int a = 0; a < 8; a++) {
            if (cows[a] < answer[a] || answer[a] == "") {
                for (int b = 0; b < 8; b++) {
                    answer[b] = cows[b];
                }
                break;
            }
            else if (cows[a] == answer[a]) continue;
            else break;
        }
        out:
            continue;
    } while (next_permutation(cows, cows+8));
    for (auto i: answer) {
        fout << i << std::endl;
    }
}