#include <iostream>
#include <fstream>
int main() {
    std::ifstream fin("shell.in");
    std::ofstream fout("shell.out");
    int n; fin >> n;
    bool shells[3];
    int game[n][3];
    for (int a=0; a<n; a++) {
        fin >> game[a][0] >> game[a][1] >> game[a][2];
    }
    bool temp;
    int score = 0;
    for (int a=0; a<3; a++) {
        int s = 0;
        shells[0] = false; shells[1] = false; shells[2] = false;
        shells[a] = true;
        for (auto i: game) {
            temp = shells[i[0]-1];
            shells[i[0]-1] = shells[i[1]-1];
            shells[i[1]-1] = temp;
            if (shells[i[2]-1]) s++;
        }
        if (s > score) score = s;
    }
    fout << score << std::endl;
}
