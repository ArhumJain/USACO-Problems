#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    unordered_map<string, int> zodiac = {{"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7},
                            {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}, {"Ox", 12}};
    unordered_map<string, pair<string, int>> yearDiffs = {{"Bessie", make_pair("Ox", 0)}};
    for (int a=0; a<N; a++) {
        string cowA, cowB;
        string relativeTime;
        string year;
        cin >> cowA; cin.ignore(9); cin >> relativeTime >> year; cin.ignore(10); cin >> cowB;
        if (relativeTime == "previous") {
            yearDiffs[cowA].second = yearDiffs[cowB].second + (zodiac[yearDiffs[cowB].first]%12)+(12-zodiac[year]);
        } else if (relativeTime == "next") {
            yearDiffs[cowA].second = yearDiffs[cowB].second - (12-zodiac[yearDiffs[cowB].first]) + zodiac[year]%12;
        }
        yearDiffs[cowA].first = year;
    }
    cout << abs(yearDiffs["Elsie"].second) << endl;
}