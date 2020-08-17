#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
     if(n/2>=p){
         return p==1?0:p/2;
     }
     else {
         if(n%2!=0){
             return n-p-1 == 0 ? 0: (n-p)/2;
         }
         else {
             return n-p-1==0?1:(n-p)/2;
         }
     }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
