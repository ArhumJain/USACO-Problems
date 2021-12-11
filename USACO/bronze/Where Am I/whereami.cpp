#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n;
    string homes;
    fin >> n >> homes;
    int k = 1;
    while (true) {
        set<string> subsets;
        for (int a = 0; a < n; a++) {
            string substr = homes.substr(a, k);
            if (subsets.count(substr) == 0) {
                subsets.insert(substr);
            } else {
                k++;
                a = -1;
                subsets.clear();
            }
        }
        break;
    }
    fout << k << endl;
}