#include <bits/stdc++.h>

using namespace std;

int Length(std::string a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    };
    return i;
}

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int sz1=Length(s);
    int sz2=Length(t);
    int equal=0;

    if(s.size()>t.size()){
        for(int i=0; i<s.size(); i++){
            if(s[i]==t[i]){
                equal++;
            }
            else{
                break;
            }
        }
    }
    else {
        for(int i=0; i<t.size(); i++){
            if(s[i]==t[i]){
                equal++;
            }
            else{
                break;
            }
        }
    }
    int Total = sz1-equal+sz2-equal;
    if(Total==k || k>=sz1+sz2 || Total==0 || 
    (Total<k&&(k%abs(sz1-sz2))%2==0&&abs(sz1-sz2)>1)
    ){
        return "Yes";
    }
    else return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
