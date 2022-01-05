#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int N; fin >> N;
    vector<pair<int, int>> cows;
    pair<int, int> cow;
    for (int i = 0; i < N; i++) {
        fin >> cow.first >> cow.second;
        cows.push_back(cow);
    }
    sort(cows.begin(), cows.end());
    int time = 0;
    for (int i = 0; i < N; i++) {
        if (cows[i].first > time) {
            time = cows[i].first;
        }
        time += cows[i].second;
    }
    fout << time << endl;
}