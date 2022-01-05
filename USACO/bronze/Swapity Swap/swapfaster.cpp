
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int N, K; fin >> N >> K;
    int A1, A2; fin >> A1 >> A2;
    int B1, B2; fin >> B1 >> B2;
    vector<int> order;
    for (int i=0; i<N; i++) {
        order.push_back(i+1);
    }
    vector<vector<int>> loop;
    reverse(order.begin() + (A1 - 1), order.begin() + (A2));
    reverse(order.begin() + (B1 - 1), order.begin() + (B2));
    loop.push_back(order);
    for (int i=1;; i++) {
        reverse(order.begin()+(A1-1), order.begin()+(A2));
        reverse(order.begin()+(B1-1), order.begin()+(B2));
        loop.push_back(order);
        for (int j=0; j<N; j++) {
            if (loop[0][j] != order[j]) goto out;
        }
        break;
        out:
            continue;
    }
    for (int i=0; i<N; i++) fout << loop[(7%loop.size())-1][i] << endl;

}