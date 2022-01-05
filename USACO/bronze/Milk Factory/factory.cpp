#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;
int N;
unordered_map<int, int> walkways;
bool explore(int target, int start) {
    if (start == target) return true;
    if (walkways[start] == 0) return false;
    return explore(target, walkways[start]);
}
int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");
    fin >> N;
    int a;
    for (int i=0; i<N-1; i++) {
        fin >> a;
        fin >> walkways[a];
        walkways[walkways[a]];
    }
    int maxStation = -1;
    unordered_map<int, int> loopCopy = walkways;
    for (auto walkway: loopCopy) {
        for (auto walkway_: loopCopy) {
            if (!(explore(walkway.first, walkway_.first))) goto out;
        }
        if (walkway.first > maxStation) maxStation = walkway.first;
        out:
            continue;
    }
    fout << maxStation << endl;
}