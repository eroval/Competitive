#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int d1, m1, y1;
    int d2, m2, y2;
    
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    
    if(y1>y2){
        std::cout<<10000<<"\n";
    }
    else if(y1==y2){
        if(m1>m2){
            std::cout<<(m1-m2)*500<<"\n";
        }
        else {
            if(d1>d2){
                std::cout<<(d1-d2)*15<<"\n";
            }
            else {
                std::cout<<0;
            }
        }
    }
    else {
        std::cout<<0<<'\n';
    }

    return 0; 
}
