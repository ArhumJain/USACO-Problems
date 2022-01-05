#include <iostream>
using namespace std;
int T;
int N, K;
char grid[52][52];
int distinctPaths(int x, int y, int turnsCount, char prevTurn) {
    if (x == N || y == N || turnsCount > K) return 0;
    else if (x == N-1 && y == N-1) return 1;
    int paths = 0;
    if (grid[y][x+1] == '.') {
        paths += distinctPaths(x+1, y, (prevTurn == 'R' || prevTurn == ' ' ? turnsCount : turnsCount+1), 'R');
    } 
    if (grid[y+1][x] == '.') {
        paths += distinctPaths(x, y+1, (prevTurn == 'D' || prevTurn == ' ' ? turnsCount : turnsCount+1), 'D');
    }
    return paths;

}
int main() {
    cin >> T;
    int paths;
    for (int a=0; a<T; a++) {
        cin >> N >> K;
        paths = 0;
        for (int b=0; b<N; b++) {
            for (int c=0; c<N; c++) {
                cin >> grid[b][c];
            }
        }

        paths += distinctPaths(0, 0, 0, ' ');
        cout << paths << endl;
    }
}