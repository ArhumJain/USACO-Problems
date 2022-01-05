#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    char circle[52];
    unordered_map<char, pair<int, int>> crossPoints;
    for (int i = 0; i < 52; i++) {
        fin >> circle[i];
        if (crossPoints[circle[i]].first == 0) {
            crossPoints[circle[i]].first = i+1;
        } else {
            crossPoints[circle[i]].second = i+1;
        }
    }
    int count = 0;
    for (char a=65; a<91; a++) {
        for (char b=65; b<91; b++) {
            if (a == b) continue;
            if (((crossPoints[a].first > crossPoints[b].first && crossPoints[a].first < crossPoints[b].second) && crossPoints[a].second > crossPoints[b].second) ) {
                count++;
            }
        }
    }
    fout << count << endl;
}