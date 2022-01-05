#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int N; cin >> N;
    char lineup[50001];
    for (int a=0; a<N; a++) {
        cin >> lineup[a];
    }
    long long throwOut = 0;
    char front;
    char back;
    for (int a=3; a<N+1; a++) {
        long long hCount = 0;
        long long gCount = 0;
        back = lineup[0];
        front = lineup[a-1];
        for (int b=0; b<a; b++) {
            if (lineup[b]=='G') gCount++;
            else hCount++;
        }
        for (int b=a; b<N; b++) {
            if (hCount == 1 || gCount == 1) throwOut++;
            front = lineup[b];
            back = lineup[b-(a-1)];
            if (front == 'G') gCount++;
            else hCount++;
            if (lineup[b-a] == 'G') gCount--;
            else hCount--;
        }
        if (hCount == 1 || gCount == 1) throwOut++;
    }
    cout << throwOut << endl;
}