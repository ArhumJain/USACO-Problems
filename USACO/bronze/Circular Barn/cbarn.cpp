#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cbarn.in");   
    ofstream fout("cbarn.out");

    int N; fin >> N;
    int rooms[1000];
    for (int i = 0; i < N; i++) {
        fin >> rooms[i];
    }
 ;   int minDistance = 999999999;
    for (int i = 0; i < N; i++) {
        int distance = 0;
        int doorPasses = 1;
        int currRoom = i+1 < N ? i+1 : 0;
        while (currRoom != i) {
            distance += rooms[currRoom] * doorPasses;
            if (currRoom + 1 == N) currRoom = 0;
            else currRoom++;
            doorPasses++;
        }
        if (distance < minDistance) minDistance = distance;
    }
    fout << minDistance << endl; 
}