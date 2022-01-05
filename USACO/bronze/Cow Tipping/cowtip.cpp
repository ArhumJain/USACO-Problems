#include <iostream>
#include <fstream>
using namespace std;
int N;
char grid[100][100];
void flip(int xA, int yA) {
    for (int y = 0; y<yA+1; y++) {
        for (int x = 0; x<xA+1; x++) {
            if (grid[y][x] == '1') grid[y][x] = '0';
            else grid[y][x] = '1';
        }
    }
}
int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    int count;
    fin >> N;
    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            fin >> grid[a][b];
        }
    }
    for (int y=N-1; y>-1; y--) {
        for (int x=N-1; x>-1; x--) {
            if (grid[y][x] == '1') {
                flip(x, y);
                count++;
            }
        }
    }
    fout << count << endl;

}