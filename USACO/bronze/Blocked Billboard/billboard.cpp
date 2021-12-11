#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int rectangles[3][2][2];
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                fin >> rectangles[a][b][c];
            }
        }
    }
    int area = 0;
    int width, height;
    int iwidth, iheight;
    for (int a = 0; a < 2; a++) {
        iwidth = max(0, min(rectangles[a][1][0], rectangles[2][1][0]) - max(rectangles[a][0][0], rectangles[2][0][0]));
        iheight = max(0, min(rectangles[a][1][1], rectangles[2][1][1]) - max(rectangles[a][0][1], rectangles[2][0][1]));
        width = (rectangles[a][1][0] - rectangles[a][0][0]);     
        height = (rectangles[a][1][1] - rectangles[a][0][1]);
        area += (width * height) - (iwidth*iheight);
    }
    fout << area << endl;
}

