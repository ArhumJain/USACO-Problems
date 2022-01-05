#include <iostream>
#include <fstream>
using namespace std;
int coords[100][2];
int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int N; fin >> N;
    int maxArea = 1;
    for (int i=0; i<N; i++) {
        fin >> coords[i][0] >> coords[i][1];
    }
    for (int c1=0; c1<N; c1++) {
        for (int c2=0; c2<N; c2++){
            if (c1 == c2) continue;
            if (coords[c1][0] == coords[c2][0]) {
                for (int c3=0; c3<N; c3++){
                    if (c2==c3) continue;
                    if (coords[c2][1]==coords[c3][1]) {
                        int area = abs(coords[c1][1]-coords[c2][1])*abs(coords[c2][0]-coords[c3][0]);
                        if (area > maxArea) maxArea = area;
                    }
                }
            }
        }
    }
    fout << maxArea << endl;
}