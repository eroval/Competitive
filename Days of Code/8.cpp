#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    std::string name;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    map<std::string, int> m;
    for (unsigned i = 0; i < n; i++) {
        std::cin>>name;
        unsigned phone;
        std::cin >> phone;
        m[name]=phone;
    }
   while(std::cin>>name) {
        if (m[name] == 0) { std::cout << "Not found" << std::endl; }
        else {
            std::cout << name << "=" << m[name]<<std::endl;
        }
    }
    return 0;
}
