#include <bits/stdc++.h>
#include <math.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unsigned sz = log2(n)+1;
    unsigned int c=0;
    unsigned int m=0;
    int * arr = new int [sz];

    arr[sz-1]=n%2;
     if(arr[sz-1]==1){
        c++;
        m=c;}

    n/=2;
    for(unsigned i=1; i<sz; i++){
        arr[sz-1-i]=n%2;
        n/=2;
        if(arr[sz-i-1]==1){
            c++;
        }
        else {
            if(c>m){
                m=c;
                c=0;
            }
            else c=0;
        }
    }
    if(c>m){m=c;};
    std::cout<<m;
    return 0;
}
