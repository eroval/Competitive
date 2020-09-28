#include <bits/stdc++.h>

using namespace std;

int Length(std::string a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    };
    return i;
}


//WAY I
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

//WAY II
// Sometimes it's also easier to do the opposite(which I didn't think initially of, so I spent so much time on this exercise at the beggining)
//Function to find the length of a string
int Length(std::string a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    };
    return i;
}

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    //Length of the strings
    int sz1=Length(s);
    int sz2=Length(t);

    int equal=0;

    //Check which string to look at for equality(smaller is chosen)
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

    //Find the total number of characters to be filled in
    int Total = sz1-equal+sz2-equal;

    /* 1. If the Total number of characters is greater than the available then is 
    not possible.
    2. If the amount of characters minus the total number isn't divisible by two then it is obviously not possible (example aba, aba, 1 (total=0, but k=1 => cannot be 
        filled in)). 
    3. However 2* works ONLY WHEN ALSO k-Total-equal*2<0 because if we take
    for example aba aba 7. Then that should be possible because we can delete aba and
    then continue deleteion for one more time and then add 3 more characters.
    another example abcd, abcdefg, 7 (abcdefgh? OR abcd -> * -> abc? 
    (we have deleted 'abcd' and then had only 3 more characters to add - 'abd' )). 
    It simply isn't possible.
    */


    if(Total>k||(abs(k-Total)%2!=0&&k-Total-equal*2<0)){
        return "No";
    }
    else return "Yes";
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
