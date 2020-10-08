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
    vector<int> arr(k);
    for(int i=0; i<s.size(); i++){
        arr[s[i]%k]++;
    }

    for(int i=0; i<arr.size(); i++){
        std::cout<<arr[i]<<"\n";
    }

    int Sum=0;

    for(int i=0; i<(arr.size()-1)/2; i++){
        if(arr[i+1]>arr[arr.size()-i-1]){
            Sum+=arr[i+1];
        }
        else Sum+=arr[arr.size()-i-1];
    }

    if(arr[0]>0){
        Sum++;
    }

    if(k%2==0&&arr[k/2]>0){
        Sum++;
    }
    
    return Sum;
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




/*
STUCK CODE: ....




int nonDivisibleSubset(int k, vector<int> s) {
    int cnt=s.size();
    //vector<int> arr = s;
    //bool check=true;
    
    vector<int> arr2(s.size());
    for(long unsigned i=0; i<s.size(); i++){
        for(long unsigned j=i+1; j<s.size(); j++){
            if((s[i]+s[j])%k==0){
                arr2[i]++;
                arr2[j]++;
            }
        }
    }

        for(int i=0; i<arr2.size(); i++){
            std::cout<<arr2[i]<<" ";
        }
        std::cout<<"\n";

    bool check=true;
    while(check){
        check=false;
        int max=arr2[0];
        long unsigned index=0;
        for(long unsigned i=1; i<arr2.size(); i++){
            if(max<arr2[i]){
                max = arr2[i];
                index=i;
            }
        }
        if(max>0){
            --cnt;
            arr2.erase(arr2.begin()+index);
            for(long unsigned i=0; i<arr2.size(); i++){
                arr2[i]--;
                if(arr2[i]>=0){
                    check=true;
                }
            }
        }
        else if(max==0){
            bool enter=true;
            for(long unsigned i=0; i<arr2.size(); i++){
                if(arr2[i]==0){
                    for(int j=0; j<i; j++){
                        if(arr2[i]==arr2[j]){
                            enter=false;
                            break;
                        }
                    }
                    for(int j=i+1; j<arr2.size(); j++){
                        if(arr2[i]==arr2[j]){
                            enter=false;
                            break;
                        }
                    }
                }
            }
            if(enter){
            --cnt;
            arr2.erase(arr2.begin()+index);
            check=true;
            }
        }

        for(int i=0; i<arr2.size(); i++){
            std::cout<<arr2[i]<<" ";
        }
        std::cout<<"\n";
        std::cout<<max<<"\n";
    }



    
/*
    while(check){
        check=false;
        int* arr2 = new int[arr.size()]{};
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if((arr[i]+arr[j])%k==0){
                    check=true;
                    arr2[i]++;
                    arr2[j]++;
                }
            }
        }

        if(check){
            int max = arr2[0];
            int index=0;
            for(int i=0; i<arr.size(); i++){
                if(max<arr2[i]){
                    max=arr2[i];
                    index=i;
                }
            }
            --cnt;
            arr.erase(arr.begin() + index);
        }
        delete[] arr2;
    }
    return cnt;
*/



//return cnt;
//}





/*
int nonDivisibleSubset(int k, vector<int> s){
    if(k==1||k==0){
        return 1;
    }
    for(long unsigned i=0; i<s.size(); i++){
        s[i]%=k;
    }
    vector<int> harr;

    harr.push_back(s[0]);
    harr.push_back(1);

    //find how many times each element is found
    for(long unsigned  i=1; i<s.size(); i++){
        bool enter=true;
        for(long unsigned j=0; j<harr.size(); j+=2){
            if(s[i]==harr[j]){
                harr[j+1]++;
                enter=false;
            }
        }
        if(enter){
            harr.push_back(s[i]);
            harr.push_back(1);
        }
    }

    //print Histogram Array
    for(int i=0; i<harr.size(); i+=2){
        std::cout<<harr[i]<<" : "<<harr[i+1]<<"\n";
    }

    int cnt=0;
    for(int i=0; i<harr.size(); i+=2){
        bool enter=true;
        for(int j=i+2; j<harr.size(); j+=2){
            if(harr[i]+harr[j]==k){
                if(harr[i+1]>harr[j+1]){
                    cnt+=harr[i+1];
                }
                else cnt+=harr[j+1];
                enter=false;
            }
        }
        if(enter){
            cnt+=harr[i+1];
        }
        else {
            i+=2;
        }
    }

    return cnt;    
}
*/