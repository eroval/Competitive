#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    vector<vector<int>> newarr;
    std::stable_sort(arr.begin(), arr.end());

    newarr.push_back(vector<int>{arr[0],1});
    for(long unsigned int j=1; j<arr.size(); j++){
        if(arr[j]==newarr[0][0]){
            newarr[0][1]++;
        }
    }


    for(long unsigned int i=1; i<arr.size(); i++){
        bool enter=true;
        for(long unsigned int k=0; k<newarr.size(); k++){
            if(arr[i]==newarr[k][0]){
                enter=false;
                break;
            }
        }

        if(enter){
            std::vector<int> a;
            a.push_back(arr[i]);
            a.push_back(1);
            
            for(long unsigned int j=i+1; j<arr.size(); j++){
                if(arr[j]==a[0]){
                    a[1]++;
                }
            }
            newarr.push_back(a);
        }
    }

    int max=newarr[0][1];
    int minIndex=0;
    for(long unsigned int i=1; i<newarr.size(); i++){
        if(newarr[i][1]>max){
            max=newarr[i][1];
            minIndex=i;
        }
    }
    return newarr[minIndex][0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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
