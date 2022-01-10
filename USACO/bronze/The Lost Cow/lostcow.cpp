#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y; fin >> x >> y;
    y -= x; x=0;
    int currX = x;
    int currChange = 1;
    int factor = 1;
    int totalDistance = 0;
    while (1) {
        if ((y < 0 && currChange * factor <= y) || (y > 0 && currChange * factor >= y)) {
            totalDistance += abs(currX - x) + abs(x-y);
            break;
        } else {
            totalDistance += abs(currX - x) + currChange;      
            currX = currChange * factor;
            currChange *= 2;
            factor *= -1;
        }
    }
    fout << totalDistance << endl;
}