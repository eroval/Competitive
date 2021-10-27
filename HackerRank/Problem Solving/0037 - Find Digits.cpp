#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    std::vector<int> arr;
    int tmp=n;
    while(tmp>0){
        arr.push_back(tmp%10);
        tmp/=10;
    }

    int cnt=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]!=0&&n%arr[i]==0){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}