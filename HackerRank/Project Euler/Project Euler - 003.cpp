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

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long long n;
        cin >> n;
        
        unsigned long long l;
        while(n%2==0){
            n/=2;
            l=2;
        }
            for(unsigned long long i=3; i<=sqrt(n); i++){
                while(n%i==0){
                    n/=i;
                }
                l=i;
            }
            if(n!=1){
                l=n;
            }
            std::cout<<l<<"\n";
    }
    return 0;
}



