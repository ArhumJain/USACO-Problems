#include <iostream>
#include <vector>
int main() {
    int n; std::cin >> n;
    int O = 0, E = 0;
    int read;
    for (int a=0; a<n; a++) {
        std::cin >> read;
        if (read%2==0) E++;
        else O++;
    } 
    while (O > E) {
        O-=2;
        E++;
    }
    if (E>O+1) E = O+1;
    std::cout << E+O << std::endl;
}