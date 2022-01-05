#include <iostream>
#include <fstream>
using namespace std;
int grid[1001][1001] = {{0}};
int main() {
    int N; cin >> N;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int comfortableCount = 0;
    for (int a=0; a<N; a++) {
        int x, y;
        cin >> y >> x;
        grid[y][x] += 1;
        int adjacentCount = 0;
        for (auto direction: directions) {
            if ((y+direction[0] >= 0 && y+direction[0] <= 1000) && (x+direction[1] >= 0 && x+direction[1] <= 1000)) {
                if (grid[y+direction[0]][x+direction[1]] > 0) {
                    grid[direction[0]+y][direction[1]+x]++;
                    adjacentCount++;
                    if (grid[direction[0]+y][direction[1]+x] == 4) {
                        comfortableCount++;
                    } else if (grid[direction[0]+y][direction[1]+x] > 4) {
                        comfortableCount--;
                    }
                    
                }
            }
        }
        grid[y][x] += adjacentCount;
        if (adjacentCount == 4) comfortableCount++;
        else if (adjacentCount == 5) comfortableCount--;
        cout << comfortableCount << endl;
    }
}