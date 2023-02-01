#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>


using namespace std;

int main() {
    int N; cin >> N;
    string Q;
    for (int i=0; i<N; i++) {
        cin >> Q;
        int operations = 999;
        bool possible = false;
        for (int i=1; i<Q.size()-1; i++) {
            if (Q[i] == 'O') {
                int currOps = 0;
                if (Q[i-1] != 'M') currOps++;
                if (Q[i+1] != 'O') currOps++;
                currOps += Q.size()-3;
                operations = min(currOps, operations);
                possible = true;
            }
        }
        if (!possible) cout << -1 << endl;
        else cout << operations << endl;
    }
}