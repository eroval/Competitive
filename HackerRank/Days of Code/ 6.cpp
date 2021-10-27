#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned l;
    std::cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::string s;
    for (unsigned i = 0; i < l; i++) {
        std::getline(cin, s);
        for (unsigned j = 0; j < s.length(); j += 2) {
            std::cout << s[j];
        }
        std::cout << " ";
        for (unsigned j = 1; j < s.length(); j += 2) {
            std::cout << s[j];
        }
        std::cout << std::endl;
    }
    return 0;
}
