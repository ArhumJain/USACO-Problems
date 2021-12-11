#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
int main() {

	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

    int buckets[3][2];

    fin >> buckets[0][1] >> buckets[0][0] >> buckets[1][1] >> buckets[1][0] >> buckets[2][1] >> buckets[2][0];

    int transfer;

    for (int i = 0; i < 4; i++) {
        transfer = min(buckets[i%3][0], (buckets[(i+1)%3][1] - buckets[(i+1)%3][0]));
        buckets[(i+1)%3][0] += transfer;
        buckets[i%3][0] -= transfer; 
    }

    fout << buckets[0][0] << "\n" << buckets[1][0] << "\n" << buckets[2][0];
} 