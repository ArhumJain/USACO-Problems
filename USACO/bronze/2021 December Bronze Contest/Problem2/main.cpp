#include <iostream>
#include <fstream>
using namespace std;
void segmentize(int beginPos, int endPos);
int p[100];
int t[100];
int commandsCount = 0;
void equalizeSegment(int beginPos, int endPos, int maxChange, bool increase) {
    commandsCount += maxChange;
    for (int a=beginPos; a<endPos+1; a++) {
        t[a] += maxChange * (increase ? 1 : -1);
    }
    segmentize(beginPos, endPos);
}
bool shouldIncrease(int diff) {
    return diff < 0 ? true : false;
}
void segmentize(int beginPos, int endPos) {
    int segmentBeginPos = 0;
    int segmentSize = 0;
    int maxChange = 0;
    bool increase;
    for (int a=beginPos; a<endPos+1; a++) {
        if (segmentSize == 0 && t[a]!=p[a]) {
            increase = shouldIncrease(t[a]-p[a]);
            segmentBeginPos = a;
        }
        else if (t[a]==p[a] || shouldIncrease(t[a]-p[a]) != increase) {
            if (segmentSize > 0) equalizeSegment(segmentBeginPos, segmentBeginPos+segmentSize-1, maxChange, increase);
            segmentSize = 0;
            maxChange = 0;
            continue;
        }
        if (shouldIncrease(t[a]-p[a]) == increase) {
            if (abs(t[a]-p[a]) > maxChange) maxChange = abs(t[a]-p[a]);
            segmentSize++;
            if (a == endPos) {
                equalizeSegment(segmentBeginPos, segmentBeginPos+segmentSize-1, maxChange, increase);
            }
        }
    }
}
int main() {
    int N; cin >> N;
    for (int a=0; a<N; a++) cin >> p[a];
    for (int a=0; a<N; a++) cin >> t[a];
    segmentize(0, N);
    cout << commandsCount << endl;
}