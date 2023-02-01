
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
    int N, M;
    cin >> N >> M;

    vector<int> stalls(100, 0);
    map<int, int> stallRequirement;
    vector<vector<int>> cows;
    vector<vector<int>> conditioners;
    int s, t, c;
    int a, b, p, m;
    int cost = 0;

    for (int i=0; i<N; i++) {
        cin >> s >> t >> c;
        for (int i=s-1; i<t; i++) {
            stallRequirement[i] = c;
        }
        cows.push_back({s, t, c});
    }

    for (int i=0; i<M; i++) {
        cin >> a >> b >> p >> m;
        conditioners.push_back({a, b, p, m});
    }

    sort(conditioners.begin(), conditioners.end(), [] (vector<int> &a, vector<int> &b) {return a[3] > b[3];});
    int minCost = 999999999;
    do {
        int cost = 0;

        bool allSatisfied = false;
        vector<int> test = stalls;
        for (int i=0; i<M; i++) {
            if (allSatisfied) break;
            for (int k=conditioners[i][0]-1; k<conditioners[i][1]; k++) {
                test[k] += conditioners[i][2];
            }
            cost += conditioners[i][3];
            allSatisfied = true;
            for (int cow=0; cow<N; cow++) {
                for (int k=cows[cow][0]-1; k < cows[cow][1]; k++) {
                    if (test[k] < cows[cow][2]) {
                        allSatisfied = false;
                        goto next;
                    }
                }
            }
            next:
            continue;
        }
        minCost = min(cost, minCost);
    } while (next_permutation(conditioners.begin(), conditioners.end()));
    cout << minCost << endl;
}