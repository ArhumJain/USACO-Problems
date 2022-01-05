#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int N; cin >> N;
    for (int a = 0; a<N; a++) {
        string path; cin >> path;
        string first, last;
        int yPos = 0, maxYPos = -9999999;
        char currDir;
        bool topHeight = false;;
        bool clockwise;
        for (auto i: path) {
            if (i == 'N') {
                yPos++;
                if (yPos > maxYPos)  {
                    maxYPos = yPos;
                    topHeight = true;
                } else {
                    topHeight = false;
                }

            } else if (i == 'S') {
                yPos--;
            }
            else if (i == 'E' && topHeight) {
                clockwise = true;
                topHeight = false;
            }
            else if (i == 'W' && topHeight) {
                clockwise = false;
                topHeight = false;
            }
        }
    }
}