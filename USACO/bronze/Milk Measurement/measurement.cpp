#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int n; fin >> n;
    int output[3] = {7,7,7};
    int change[100] = {0};
    int cow[100] = {0};
    int d; string c;
    for (int a=0; a<n; a++) {
        fin >> d >> c >> change[d-1];
        if (c=="Bessie") cow[d-1] = 0;
        else if (c=="Elsie") cow[d-1] = 1;
        else cow[d-1] = 2;
    }
    int count = 0; int topScore = 0;
    int ranking[3] = {-1, -1, -1};int prevRanking[3];
    for (int day=0; day<100; day++) {
        if (change[day]!=0) {
            for (int a=0; a<3; a++) prevRanking[a] = ranking[a];
            output[cow[day]] += change[day];
            topScore = max(output[0], max(output[1], output[2]));
            for (int a=0; a<3; a++) {
                if (output[a]==topScore) ranking[a] = a;
                else ranking[a] = -1;
            }
            for (int a=0; a<3; a++) {
                if (ranking[a]!=prevRanking[a]) {
                    count++;
                    break;
                }
            }
        }
    }
    fout << count << endl;
}