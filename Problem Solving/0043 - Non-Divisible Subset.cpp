//WRONG UNDERSTANDING OF THE PROGRAM BUT SOLVED AN EVEN MORE AMAZING QUESTION
/*
    My way of understanding:
    Find the maximum subset of the elements of the array which's summation is not divisible by k
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    std::vector<int> set;
    set.push_back(s[0]);
    set.push_back(1);
    for(int i=1; i<s.size(); i++){
        bool flag=true;
        for(int j=0; j<set.size(); j+=2){
            if(s[i]==set[j]){
                flag=false;
                set[j+1]++;
            }
        }
        if(flag){
            set.push_back(s[i]);
            set.push_back(1);
        }
    }
    

    int szx = pow(set.size()/2,2) - 1;
    int szy = set.size()/2;
    int**arr = new int * [szx];

    for(int i=0; i<szx; i++){
        arr[i] = new int[szy+1]{};
    }


    for(int i=1; i<=szx; i++){
        int tmp=i;
        int j=0;
        int Sum=0;
        while(tmp>0){
            arr[i-1][szy-j-1] = tmp%2;
            if(arr[i-1][szy-j-1]==1){
                Sum+=set[(szy-j-1)*2];
            }
            j++;
            tmp/=2;
        }
        arr[i-1][szy] = Sum;
    }


/*
    for(int i=0; i<szx; i++){
        for(int j=0; j<szy+1; j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    for(int i=0; i<set.size(); i+=2){
        std::cout<<set[i]<<" : "<<set[i+1]<<"\n";
    }
    std::cout<<szx<<"\n";

*/

    int Sum=0;
    int cnt;
    for(int i=0; i<szx; i++){
        if(arr[i][szy]%k!=0&&arr[i][szy]>Sum){
            cnt=0;
            Sum=arr[i][szy];
            for(int j=0; j<=szy; j++){
                std::cout<<arr[i][j]<<" ";
                if(arr[i][j]==1){
                    cnt++;
                }
            }
            std::cout<<"\n";
        }
    }

    for(int i=0; i<szx; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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
