#include <bits/stdc++.h>
#include <math.h>
#include <string>   

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    std::string text;
    int size=s.size();
    int space=sqrt(size);
    int shift;
    
    if(space!=sqrt(size)){
        shift=space+1;
    }
    else {
        shift=space;
        space-=1;
    }
    
    for(int i=0; i<=space; i++){
        for(int j=0; j<shift; j++){
            if(i+shift*j<size){
            if(s[i+shift*j]!=' '){
                text+=s[i+shift*j];
            }
            else text+=s[i+shift*j+1];
            }
        }
        text+=' ';
    }
    
    return text;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
