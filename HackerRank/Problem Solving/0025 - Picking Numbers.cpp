#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

//This one's testcases were wrong. In the description it was said that it was always expecting the max abs difference of 1
//Actually turns out if an element is alone it is still countable towards the maximum subarray???(makes no sense)
int pickingNumbers(vector<int> a) {
    vector<int> cnt;
    cnt.push_back(a[0]);
    for(int i=1; i<a.size(); i++){
        bool enter=true;
        for(int j=0; j<cnt.size(); j++){
            if(a[i]==cnt[j]){
                enter=false;
            }
        }
        if(enter){
            cnt.push_back(a[i]);
        }
    }
    std::stable_sort(cnt.begin(),cnt.end());
    int sz=cnt.size();
    for(int i=0; i<sz; i++){
        int counter=0;
        for(int j=0; j<a.size(); j++){
            if(cnt[i]==a[j]){
                counter++;
            }
        }
        cnt.push_back(counter);
    }
    
    int max;
    if(sz==1){
        max= cnt[1];
        return max;
    }
    else if(sz>1) {
        max=0;

        for(int i=0; i<sz; i++){
            std::cout<<cnt[i]<<" : "<<cnt[sz+i]<<"\n"; 
        }

        for(int i=0; i<sz-1; i++){
            if((abs(cnt[i]-cnt[i+1])==1&&cnt[sz+i]+cnt[sz+i+1]>max)){
                max=cnt[sz+i]+cnt[sz+i+1];
            }
        }

        for(int i=0; i<sz; i++){
            if(cnt[sz+i]>max){
                max=cnt[sz+i];
            }
        }
    return max;
    }
    else return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
