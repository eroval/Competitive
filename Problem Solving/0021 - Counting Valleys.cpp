#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int Sum=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i]=='D'){
            Sum-=n;
        }
        else Sum+=n;
        if(Sum==0&&s[i]=='U'){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}