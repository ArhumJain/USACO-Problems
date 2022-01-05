#include <iostream>
#include <string>
using namespace std;
int main() {
    string cowphabet, hum; cin >> cowphabet >> hum;
    int alphabetCount = 0;
    for (int i=0; i<26; i++) {
        if (hum.size() == 0) break;
        else if (i==0) alphabetCount++;
        if (cowphabet[i] == hum[0]) hum.erase(0,1);
        if (i==25) i = -1;
    }
    cout << alphabetCount << endl;
}