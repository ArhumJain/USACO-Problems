#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    vector<vector<int>> field(2001, vector<int>(2001, 0));
    int N; fin >> N;
    int patterns[101][2];
    for (int a=0; a<N; a++) {
        char direction; fin >> direction;
        patterns[a][0] = direction;
        fin >> patterns[a][1];
    }
    int xPos = 1000, yPos = 1000;
    int time = 0; 
    int answer = 1001;
    for (int a=0; a<N; a++) { 
        int dY = 0, dX = 0;
        if (patterns[a][0] == 'N') dY = 1;
        else if (patterns[a][0] == 'S') dY = -1;
        else if (patterns[a][0] == 'E') dX = 1;
        else if (patterns[a][0] == 'W') dX = -1;
        for (int i=0; i<patterns[a][1]; i++) {
            time++;
            xPos += dX; yPos += dY;
            if (field[yPos][xPos] > 0) {
                if (time - field[yPos][xPos] < answer) answer = time - field[yPos][xPos];
            }
            field[yPos][xPos] = time;
        }
    }
    if (answer >= 1001) {
        fout << -1 << endl;
    } else {
        fout << answer << endl;
    }

}