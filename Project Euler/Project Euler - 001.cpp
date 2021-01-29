#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unsigned long long sum(unsigned long long n)
{
  return n * (n + 1) / 2;
}


int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        std::cin >> n;
        n -= 1;

        unsigned long long sum5 = 5 * sum(n/5);
        unsigned long long sum3 = 3 * sum(n/3);
        unsigned long long sum15 = 15 * sum(n/15);
        std::cout << sum3 + sum5 - sum15 << std::endl;
    }
    return 0;
}
