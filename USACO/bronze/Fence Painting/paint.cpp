#include <fstream>
int main() {
    std::ifstream fin("paint.in");
    std::ofstream fout("paint.out");
    int a, b, c, d; fin >> a >> b >> c >> d;
    int interval = (b-a) + (d-c);
    if (!(std::min(b, d) < std::max(a, c))) interval -= (std::min(b, d) - std::max(a, c));
    fout << interval << std::endl;

}
