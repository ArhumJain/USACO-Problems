#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<char, pair<int, int>>> cows;
    vector<pair<int, int>> intersections;
    vector<pair<int, pair<int, int>>> stops;

    for (int i = 0; i < n; i++) {
        pair<char, pair<int, int>> cow;
        cin >> cow.first >> cow.second.first >> cow.second.second;
        stops.push_back(make_pair(-1, make_pair(cow.second.first, cow.second.second)));
    }

    for (int i = 0; i < cows.size(); i++) {
        for (int j = i+1; i < cows.size(); j++) {
            if (cows[i].first == 'E' && cows[j].first == 'N') {
                if (cows[j].second.first > cows[i].second.first) {

                }
            } else if (cows[i].first == 'N' && cows[j].first == 'E') {
                if (cows[j].second.second > cows[i].second.second) {
                    
                }
            }
        }
    }


    // cout << cows[0].first << " " << cows[0].second.first << " " << cows[0].second.second;
    // cout << cows[1].first << " " << cows[1].second.first << " " << cows[1].second.second;

    return 0;
}