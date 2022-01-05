// only solves like 7 test cases
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    int N, M, K; fin >> N >> M >> K;
    int socialOrder[M], positions[N] = {0};
    unordered_map<int, int> fixedPositions;
    for (int i=0; i<M; i++) fin >> socialOrder[i];
    int cow, pos;
    for (int i=0; i<K; i++) { 
        fin >> cow >> pos;
        positions[pos-1] = cow;
        fixedPositions[cow] = pos;
    }
    unordered_map<int, int>::iterator it;
    int continuePos = N-1;
    int i = M-1;
    for (int j=N-1; j>-1; j--) {
        if (i > -1) {
            if (positions[j]==0)
                if (fixedPositions[socialOrder[i]] != 0)
                {
                    j = fixedPositions[socialOrder[i]] - 1;
                    i--;
                }
                else if ((fixedPositions[socialOrder[i - 1]] != 0 && j > fixedPositions[socialOrder[i - 1]]-1) || fixedPositions[socialOrder[i - 1]] == 0 || i == 0)
                {
                    positions[j] = socialOrder[i];
                    i--;
                }
        } else break;
    }
    // for (int i=M-1; i > -1; i--) {
    //     for (int j=continuePos; j>-1; j--) {
    //         if (positions[j] == 0) {
    //             cout << socialOrder[i] << endl;
    //             int test = socialOrder[i];
    //             cout << test << endl;
    //             cout << fixedPositions[socialOrder[i]] << endl;
    //             cout << fixedPositions[socialOrder[i]] << endl;
    //             if (fixedPositions[socialOrder[i]] != 0) {
    //                 continuePos = fixedPositions[socialOrder[i]]-2;
    //                 break;
    //             }
    //             else if ((fixedPositions[socialOrder[i-1]] != 0 && j > fixedPositions[socialOrder[i-1]]) || fixedPositions[socialOrder[i-1]] == 0) {
    //                 positions[j] = socialOrder[i];
    //                 break;
    //             }
    //             // it = fixedPositions.find(socialOrder[i-1]);
    //             // if ((it != fixedPositions.end() && j > fixedPositions[socialOrder[i-1]]) || it == fixedPositions.end()) {
    //             //     positions[j] = socialOrder[i];
    //             //     break;
    //             // } else continue; 
    //         }
    //     }
    // }
    for (int i=0; i<N-1; i++) if (positions[i]==1) { fout << i+1 << endl; return 0;}
    for (int i=0; i<N-1; i++) if (positions[i]==0) { fout << i+1 << endl; break; }
}