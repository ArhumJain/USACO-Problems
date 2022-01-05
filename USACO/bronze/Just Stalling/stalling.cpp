#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N; cin >> N;
    int A[20], B[20];
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];
    long long answer = 1;
    sort(A, A+N);
    int topCount = 0, count = 0;
    for (int i=N-1; i>-1; i--) {
        count = 0;
        for (int a=0; a<N; a++) {
            if (A[i] <= B[a]) count++;
        }
        answer *= count-topCount;
        topCount++;
    }
    cout << answer << endl;
}