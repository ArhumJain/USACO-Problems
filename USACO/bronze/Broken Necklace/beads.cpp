#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void test() {
    int arr[100] = {0};

    arr[97] = 5;
    cout << int('r')-97 << endl;
    cout << arr['a'] << endl;
    
}
int main() {
    test();
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int n;
    string bead;
    map<char, int> count = {{'r', 0}, {'b', 0}};

    fin >> n >> bead;
    bead += bead;

    // int red = 0;
    // int blue = 0;
    int curr;
    int count = 0;
    char prev;
    if (bead[0] == 'w'){
        prev = bead[1] == 'r' ? 'r' : 'b';

        count[bead[1]] += 1;
    }
    for (int i = 1; i < (n*2); i++) {
        cout << i << endl;
    }
    cout << n << endl;
    cout << bead << endl;
}