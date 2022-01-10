#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
bool came_before(int color1, int color2);
int painting[10][10];
int N = 0;
void getBoundingBox(int color, int (&arr)[4], int N) {
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            if (painting[y][x] == color) {
                arr[0] = min(y, arr[0]);
                arr[1] = max(y, arr[1]);
                arr[2] = min(x, arr[2]);
                arr[3] = max(x, arr[3]);
            }
        }
    }
}
bool intersect(int (&rect1)[4], int (&rect2)[4]) {
    if (rect1[0] > rect2[1] || rect1[1] < rect2[0] || rect1[2] > rect2[3] || rect1[3] < rect2[2]) return false;
    else return true;
}
int came_before(int color1, int color2, int N) {
    int top = 0, bottom = N, left = 0, right = N;
    int color1Bound[4] = {N, 0, N, 0};
    int color2Bound[4] = {N, 0, N, 0};
    getBoundingBox(color1, color1Bound, N);
    getBoundingBox(color2, color2Bound, N);
    if (intersect(color1Bound, color2Bound)) {
        for (int a=0; a<N; a++) {
            for (int b=0; b<N; b++) {
                if (a >= color1Bound[0] && a <= color1Bound[1] && b >= color1Bound[2] && b <= color1Bound[3]) {
                    if (painting[a][b] == color2) return 0;
                }
            }
        }
    } else {
        return 1;
    }
    return 2;
}

int main() {
    ifstream fin("art.in");
    ofstream fout("art.out");
    int N; fin >> N;
    bool colors[9] = {false};
    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            char color;
            fin >> color;
            if (color != '0') {
                painting[a][b] = color - '0';
                colors[painting[a][b]-1] = true;
            }
        }
    }
    int firstCount = 0;
    for (int a=0; a<9; a++) {
        if (colors[a]) {
            bool cameFirst = true;
            for (int b=0; b<9; b++) {
                if (a != b && colors[b]) {
                    if (came_before(a+1, b+1, N) == 2) {
                        cameFirst = false;
                        break;
                    }
                }
            }
            if (cameFirst) {
                firstCount++;
            }
        }
    }
    fout << firstCount << endl;

}