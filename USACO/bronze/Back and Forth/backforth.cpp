#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> amounts;
void simulate(vector<vector<int>> state, bool barn, int count, int amount) {
    if (count == 5) {
        amounts.insert(amount);
        return;
    }
    for (int a = 0; a < state[barn].size(); a++) {
        vector<vector<int>> nextState = state;
        int nextAmount = barn ? amount+nextState[barn][a] : amount-nextState[barn][a];
        nextState[!barn].push_back(nextState[barn][a]);
        nextState[barn].erase(next(nextState[barn].begin(), a));
        simulate(nextState, !barn, count+1, nextAmount);
    }
    return;
}
int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    vector<vector<int>> barns(2);
    int size; 
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 10; b++) {
            fin >> size;
            barns[a].push_back(size);
        }
    }
    simulate(barns, false, 1, 1000);
    fout << amounts.size() << std::endl;
}