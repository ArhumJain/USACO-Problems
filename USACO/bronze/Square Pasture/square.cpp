#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
	ifstream fin("square.in");
	ofstream fout("square.out");

	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int area;
	int width;
	int length;	

	width = max(x2,x4) - min(x1,x3);
	length = max(y2,y4) - min(y1,y3); 

	fout << (width > length ? width*width : length * length);
	return 0;
}