#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int arr[8][2];
    for(int i=0; i<8; i++){
        arr[i][0]=0;
        arr[i][1]=0;
    }
    for(unsigned int i=0; i<obstacles.size(); i++){
        if(obstacles[i][0]==r_q){
            if(obstacles[i][1]>c_q&&
            (abs(obstacles[i][1]-c_q)<abs(arr[0][1]-c_q)||
            (arr[0][0]==0&&arr[0][1]==0)
            )
            ){
                arr[0][0]=obstacles[i][0];
                arr[0][1]=obstacles[i][1];
            }
            else if(obstacles[i][1]<c_q&&
            (abs(c_q-obstacles[i][1])<abs(c_q-arr[1][1])
            ||(arr[1][0]==0&&arr[1][1]==0))){
                arr[1][0]=obstacles[i][0];
                arr[1][1]=obstacles[i][1];
            }
        }
        else if(obstacles[i][1]==c_q){
            if(obstacles[i][0]>r_q&&
            (abs(obstacles[i][0]-r_q)<abs(arr[2][0]-r_q)
            ||(arr[2][0]==0&&arr[2][1]==0))
            ){
                arr[2][0]=obstacles[i][0];
                arr[2][1]=obstacles[i][1];
            }
            else if(obstacles[i][0]<r_q&&
            (abs(r_q-obstacles[i][0])<abs(r_q-arr[3][0])||
            (arr[3][0]==0&&arr[3][1]==0))
            ){
                arr[3][0]=obstacles[i][0];
                arr[3][1]=obstacles[i][1];
            }
        }
        else if(abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
        {
            if(obstacles[i][0]>r_q){
                if(obstacles[i][1]>c_q&&
                (abs(obstacles[i][1]-c_q)<abs(arr[4][1]-c_q)
                ||(arr[4][0]==0&&arr[4][1]==0))
                )
                {
                    arr[4][0]=obstacles[i][0];
                    arr[4][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&
                (abs(c_q-obstacles[i][1])<abs(c_q-arr[5][1])||
                (arr[5][0]==0&&arr[5][1]==0))
                )
                {
                    arr[5][0]=obstacles[i][0];
                    arr[5][1]=obstacles[i][1];    
                }
            }
            else {
                if(obstacles[i][1]>c_q&&
                (abs(obstacles[i][1]-c_q)<abs(arr[6][1]-c_q)||
                (arr[6][0]==0&&arr[6][1]==0))
                )
                {
                    arr[6][0]=obstacles[i][0];
                    arr[6][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&
                (abs(c_q-obstacles[i][1])<abs(c_q-arr[7][1])
                ||(arr[7][0]==0&&arr[7][1]==0))
                )
                {
                    arr[7][0]=obstacles[i][0];
                    arr[7][1]=obstacles[i][1];    
                }
            }
        }
    }
    
    int Sum=(n-1)*2;
    
    int tright=n-max(c_q,r_q);
    int tleft=min(n-r_q,abs(1-c_q));
    int dright=min(r_q-1,n-c_q);
    int dleft=min(c_q,r_q)-1;
    if(arr[0][0]!=0&&arr[0][1]!=0){
    Sum-=(n-arr[0][1]+1);
    }
    if(arr[1][0]!=0&&arr[1][1]!=0){
    Sum-=arr[1][1];
    }
    if(arr[2][0]!=0&&arr[2][1]!=0){
    Sum-=(n-arr[2][0]+1);
    }
    if(arr[3][0]!=0&&arr[3][1]!=0){
    Sum-=arr[3][0];
    }
    if(arr[4][0]!=0&&arr[4][1]!=0){
        tright-=tright-(arr[4][1]-c_q-1);
    }
    if(arr[5][0]!=0&&arr[5][1]!=0){
        tleft-=tleft-(c_q-arr[5][1]-1);
    }
    if(arr[6][0]!=0&&arr[6][1]!=0){
        dright-=dright-(arr[6][1]-c_q-1);
    }
    if(arr[7][0]!=0&&arr[7][1]!=0){
        dleft-=dleft-(c_q-arr[7][1]-1);
    }
    return Sum+tright+tleft+dright+dleft;
}
    

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
