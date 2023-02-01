#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int lists[100000];
    int n;
    cin >> n;
    string line;
    cin >> line;
    int pairCount = 0;
    int rightmostG = -1;
    int rightmostH = -1;
    int leftmostG = 9999999;
    int leftmostH = 9999999;
    for (int i=0; i<n; i++) {
        cin >> lists[i];
        if (line[i] == 'G' && i > rightmostG) rightmostG = i;
        if (line[i] == 'H' && i > rightmostH) rightmostH = i;

        if (line[i] == 'G' && i < leftmostG) leftmostG = i;
        if (line[i] == 'H' && i < leftmostH) leftmostH = i;
    }

    int allLeaderG = -1;
    int allLeaderH = -1;
    for (int i=0; i<n; i++) {
        if (line[i] == 'G' && i <= leftmostG && lists[i]-1 >= rightmostG) allLeaderG = i;
        else if (line[i] == 'H' && i <= leftmostH && lists[i]-1 >= rightmostH) allLeaderH = i;
    }
    if (allLeaderG != -1 && allLeaderH != -1) pairCount++;

    for (int i=0; i<n; i++) {
        if (allLeaderH != -1 && i != allLeaderG && line[i] == 'G' && i <= allLeaderH && lists[i]-1 >= allLeaderH) {
            pairCount++;
        }
        if (allLeaderG != -1 && i != allLeaderH && line[i] == 'H' && i <= allLeaderG && lists[i]-1 >= allLeaderG) {
            pairCount++;
        }
    }

    cout << pairCount << endl;
}