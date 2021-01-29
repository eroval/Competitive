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


int main()
{
  unsigned int t;
  std::cin >> t;
  for(int i=0; i<t; i++){
    unsigned long long n;
    std::cin >> n;

    unsigned long long sum = 0;
    unsigned long long a = 1;
    unsigned long long b = 2;

    while (b <= n)
    {
      if (b % 2 == 0)
        sum += b;

      unsigned long long next = a + b;
      a = b;
      b = next;
    }

    std::cout << sum << std::endl;
  }
  return 0;
}