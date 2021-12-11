#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec(7, 0);
    for (int i = 0; i < 7; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    cout << vec[0] << " " << vec[1] << " " << vec[6] - vec[0] - vec[1] << endl;
}