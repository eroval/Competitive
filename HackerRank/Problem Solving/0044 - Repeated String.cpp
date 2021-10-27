#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='a'){
            cnt++;
        }
    }
    
    int Sum=0;
    for(int i=0; i<n%s.size(); i++){
        if(s[i]=='a'){
            Sum++;
        }
    }

    return cnt*(n/s.size()) + Sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
