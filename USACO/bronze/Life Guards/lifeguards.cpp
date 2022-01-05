#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int N; fin >> N;
    pair<int, int> shift;
    pair<int, int> shifts[100];
    for (int i=0; i<N; i++) {
        fin >> shift.first >> shift.second;
        shifts[i] = shift;
    }
    sort(shifts, shifts+N);
    int skip = 0;
    int maxTime = -1000, maxPoint = -1000, currTime;
    for (int i=0; i<N; i++) {
        currTime = 0;
        maxPoint = -1000;
        for (int j=0; j<N; j++) {
            if (j != i) {
                if (shifts[j].first < maxPoint) currTime += shifts[j].second-maxPoint;
                else currTime += shifts[j].second - shifts[j].first;
                maxPoint = shifts[j].second;
            }
        }
        if (currTime > maxTime) maxTime = currTime;
    }
    fout << maxTime << endl;
}