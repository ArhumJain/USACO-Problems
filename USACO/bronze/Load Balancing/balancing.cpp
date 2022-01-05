#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int N, B; fin >> N >> B;
    int cowCoords[101][2];
    int xIntervals[N];
    int yIntervals[N];
    for (int a=0; a<N; a++) {
        fin >> cowCoords[a][0] >> cowCoords[a][1];
        xIntervals[a] = cowCoords[a][0]+1;
        yIntervals[a] = cowCoords[a][1]+1;
    }
    int quads[4];
    int minMax = 999999999;
    for (int x: xIntervals) {
        for (int y: yIntervals) {
            for (int a=0; a<4; a++) quads[a] = 0;
            for (int cow=0; cow<N; cow++) {
                if (cowCoords[cow][0] >= x) {
                    if (cowCoords[cow][1] >= y) {
                        quads[0]++;
                    } else {
                        quads[1]++;
                    }
                } else {
                    if (cowCoords[cow][1] >= y) {
                        quads[2]++;
                    } else {
                        quads[3]++;
                    }
                }
            }
            int maximum = max(max(quads[0], quads[1]), max(quads[2], quads[3]));
            if (maximum < minMax) minMax = maximum;
        }
    }
    fout << minMax << endl;
}