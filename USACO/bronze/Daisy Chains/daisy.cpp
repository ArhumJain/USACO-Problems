#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int flowers[101];
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    int c = n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = flowers[i];
        for (int j = i+1; j < n; j++) {
            sum += flowers[j];
            if (sum % (j+1-i) == 0) {
                for (int k = i; k < j+1; k++) {
                    if (flowers[k] == sum/(j+1-i)) {
                        c++; break;
                    } 
                }
            }
        }
    }
    cout << c << endl;
}