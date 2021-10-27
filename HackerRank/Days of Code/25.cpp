#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {    
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int size;
        std::cin >> size;
        if (size > 5) {
            int k = ((size + 1) / 6);
            k = k * 6 + pow(-1, ((size / 3) % 2) + 2);
            if (k == size) {
                bool prm = true;
                for (int i = 2; i <= sqrt(size); i++) {
                    if (size % i == 0) {
                        prm = false;
                        break;
                    }
                }
                if (prm) {
                    std::cout << "Prime\n";
                }
                else std::cout << "Not prime\n";
            }
            else cout << "Not prime" << endl;
        }
        else if (size == 3 || size == 5 || size == 2) {
            cout << "Prime" << endl;
        }
        else if (size == 1 || size == 4) { cout << "Not prime" << endl; }
    }
    return 0;
}
