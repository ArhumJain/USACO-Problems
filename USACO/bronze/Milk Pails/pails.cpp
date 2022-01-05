#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int X, Y, M; fin >> X >> Y >> M;
    int maxFill = -999999999;
    for (int a = 0; a<(M/Y)+1; a++) {
        int fill = Y * a;
        for (int b=0;; b++) {
            if (fill+X > M)  {
                if (fill > maxFill) maxFill = fill;
                break;
            }
            fill += X;
        }
    }
    fout << maxFill << endl;
}
