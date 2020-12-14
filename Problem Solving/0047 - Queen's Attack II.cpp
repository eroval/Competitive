#include <bits/stdc++.h>

using namespace std;
/*
Custom Input:
5 16
3 3
1 1
1 3
1 5
2 2
2 3
2 4
3 1
3 2
3 4
3 5
4 2
4 3
4 4
5 1
5 3
5 5
*/



// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int arr[8][2];
    // arr[0] - horizontal bigger
    // arr[1] - horizontal smaller
    // arr[2] - vertical bigger
    // arr[3] - vertical smaller
    // arr[4] - diagonal horizontal+ bigger
    // arr[5] - diagonal horizontal+ smaller
    // arr[6] - diagonal horizontal- bigger
    // arr[7] - diagonal horizontal- smaller 
    for(int i=0; i<8; i++){
        arr[i][0]=0;
        arr[i][1]=0;
    }
    for(unsigned int i=0; i<obstacles.size(); i++){
        if(obstacles[i][0]==r_q){
            if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[0][1]-c_q)){
                arr[0][0]=obstacles[i][0];
                arr[0][1]=obstacles[i][1];
            }
            else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[1][1])){
                arr[1][0]=obstacles[i][0];
                arr[1][1]=obstacles[i][1];
            }
        }
        else if(obstacles[i][1]==c_q){
            if(obstacles[i][0]>r_q&&abs(obstacles[i][0]-r_q)<abs(arr[2][0]-r_q)){
                arr[2][0]=obstacles[i][0];
                arr[2][1]=obstacles[i][1];
            }
            else if(obstacles[i][0]<r_q&&abs(r_q-obstacles[i][0])<abs(r_q-arr[3][0])){
                arr[3][0]=obstacles[i][0];
                arr[3][1]=obstacles[i][1];
            }
        }
        else if(abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
        {
            if(obstacles[i][0]>r_q){
                if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[4][1]-c_q))
                {
                    arr[4][0]=obstacles[i][0];
                    arr[4][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[5][1]))
                {
                    arr[5][0]=obstacles[i][0];
                    arr[5][1]=obstacles[i][1];    
                }
            }
            else {
                if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[6][1]-c_q))
                {
                    arr[6][0]=obstacles[i][0];
                    arr[6][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[7][1]))
                {
                    arr[7][0]=obstacles[i][0];
                    arr[7][1]=obstacles[i][1];    
                }
            }
        }
    }
    // arr[0] - horizontal bigger
    // arr[1] - horizontal smaller
    // arr[2] - vertical bigger
    // arr[3] - vertical smaller
    // arr[4] - diagonal horizontal+ bigger
    // arr[5] - diagonal horizontal+ smaller
    // arr[6] - diagonal horizontal- bigger
    // arr[7] - diagonal horizontal- smaller 
    for(int i=0; i<8; i++){
        std::cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
    }
    int Sum=(n-1)*2+(2*n-2-abs(r_q-c_q)-abs(r_q+c_q-n-1));
    std::cout<<Sum<<"\n";
    int d1=0,d2=0,d3=0,d4=0;
    if(arr[0][0]!=0&&arr[0][1]!=0){
    Sum-=(n-arr[0][1]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[1][0]!=0&&arr[1][1]!=0){
    Sum-=arr[1][1];
    }
    std::cout<<Sum<<"\n";
    if(arr[2][0]!=0&&arr[2][1]!=0){
    Sum-=(n-arr[2][0]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[3][0]!=0&&arr[3][1]!=0){
    Sum-=arr[3][0];
    }
    /*
    std::cout<<Sum<<"\n";
    if(arr[4][0]!=0&&arr[4][1]!=0){
    Sum-=(n-arr[4][1]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[5][0]!=0&&arr[5][1]!=0){
    Sum-=arr[5][1];
    }
    std::cout<<Sum<<"\n";
    if(arr[6][0]!=0&&arr[6][1]!=0){
    Sum-=(n-arr[6][1]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[7][0]!=0&&arr[7][1]!=0){
    Sum-=arr[7][1];
    }
    std::cout<<Sum<<"\n";
    */
    if(arr[4][0]!=0&&arr[4][1]!=0){
        d1=arr[4][1]-c_q-1;
        std::cout<<"d1 = "<<d1<<"\n";
    Sum-=(n-abs(r_q-c_q)-d1);
    }
    std::cout<<Sum<<"\n";
    if(arr[5][0]!=0&&arr[5][1]!=0){
        d2=c_q-arr[5][1]-1;
        std::cout<<"d2 = "<<d2<<"\n";
    Sum-=(n-abs(r_q-c_q)-d2);
    }
    std::cout<<Sum<<"\n";
    if(arr[6][0]!=0&&arr[6][1]!=0){
        d3=arr[6][1]-c_q-1;
        std::cout<<"d3 = "<<d3<<"\n";
    Sum-=((n-abs(r_q+c_q-n-1))-d3);
    }
    std::cout<<Sum<<"\n";
    if(arr[7][0]!=0&&arr[7][1]!=0){
        d4=c_q-arr[7][1]-1;
        std::cout<<"d4 = "<<d4<<"\n";
    Sum-=((n-abs(r_q+c_q-n-1))-d4);
    }
    std::cout<<Sum<<"\n";
    return Sum;
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




//SOLUTION 2 - which I have yet to finish. The goal is to have everything run only on pure maths
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int arr[8][2];
    // arr[0] - horizontal bigger
    // arr[1] - horizontal smaller
    // arr[2] - vertical bigger
    // arr[3] - vertical smaller
    // arr[4] - diagonal horizontal+ bigger
    // arr[5] - diagonal horizontal+ smaller
    // arr[6] - diagonal horizontal- bigger
    // arr[7] - diagonal horizontal- smaller 
    for(int i=0; i<8; i++){
        arr[i][0]=0;
        arr[i][1]=0;
    }
    for(unsigned int i=0; i<obstacles.size(); i++){
        if(obstacles[i][0]==r_q){
            if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[0][1]-c_q)){
                arr[0][0]=obstacles[i][0];
                arr[0][1]=obstacles[i][1];
            }
            else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[1][1])){
                arr[1][0]=obstacles[i][0];
                arr[1][1]=obstacles[i][1];
            }
        }
        else if(obstacles[i][1]==c_q){
            if(obstacles[i][0]>r_q&&abs(obstacles[i][0]-r_q)<abs(arr[2][0]-r_q)){
                arr[2][0]=obstacles[i][0];
                arr[2][1]=obstacles[i][1];
            }
            else if(obstacles[i][0]<r_q&&abs(r_q-obstacles[i][0])<abs(r_q-arr[3][0])){
                arr[3][0]=obstacles[i][0];
                arr[3][1]=obstacles[i][1];
            }
        }
        else if(abs(obstacles[i][0]-r_q)==abs(obstacles[i][1]-c_q))
        {
            if(obstacles[i][0]>r_q){
                if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[4][1]-c_q))
                {
                    arr[4][0]=obstacles[i][0];
                    arr[4][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[5][1]))
                {
                    arr[5][0]=obstacles[i][0];
                    arr[5][1]=obstacles[i][1];    
                }
            }
            else {
                if(obstacles[i][1]>c_q&&abs(obstacles[i][1]-c_q)<abs(arr[6][1]-c_q))
                {
                    arr[6][0]=obstacles[i][0];
                    arr[6][1]=obstacles[i][1];
                }
                else if(obstacles[i][1]<c_q&&abs(c_q-obstacles[i][1])<abs(c_q-arr[7][1]))
                {
                    arr[7][0]=obstacles[i][0];
                    arr[7][1]=obstacles[i][1];    
                }
            }
        }
    }
    // arr[0] - horizontal bigger
    // arr[1] - horizontal smaller
    // arr[2] - vertical bigger
    // arr[3] - vertical smaller
    // arr[4] - diagonal horizontal+ bigger
    // arr[5] - diagonal horizontal+ smaller
    // arr[6] - diagonal horizontal- bigger
    // arr[7] - diagonal horizontal- smaller 
    for(int i=0; i<8; i++){
        std::cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
    }
    
    
    
    int Sum=(n-1)*2;
    int dSum=2*n-2-abs(r_q-c_q)-abs(r_q+c_q-n-1);
    int d1=0,d2=0,d3=0,d4=0;
    
    std::cout<<Sum<<"\n";
    if(arr[0][0]!=0&&arr[0][1]!=0){
    Sum-=(n-arr[0][1]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[1][0]!=0&&arr[1][1]!=0){
    Sum-=(arr[1][1]);
    }
    std::cout<<Sum<<"\n";
    if(arr[2][0]!=0&&arr[2][1]!=0){
    Sum-=(n-arr[2][0]+1);
    }
    std::cout<<Sum<<"\n";
    if(arr[3][0]!=0&&arr[3][1]!=0){
    Sum-=(arr[3][0]);
    }

    int i=1;
    int x=r_q+i;
    int y=c_q+i;
    bool a1=true, a2=true, a3=true, a4=true;
    while(i<r_q&&i<c_q&&x<n&&y<n){
        if(arr[4][0]!=x&&arr[4][1]!=y&&a1){
            d1++;
        }
        else a1=false;
        if(arr[5][0]!=x&&arr[5][1]!=y-i&&a2){
            d2++;
        }
        else a2=false;
        if(arr[6][0]!=x-i&&arr[6][1]!=y&&a3){
            d3++;
        }
        else a3=false;
        if(arr[7][0]!=x-i&&arr[7][1]!=y-i&&a4){
            d4++;
        }
        else a4=false;
        
        i++;
        x++;
        y++;
    }
    std::cout<<"d1 = "<<d1<<" d2 = "<<d2<<" d3 = "<<d3<<" d4 = "<<d4<<"\n";
    dSum=d1+d2+d3+d4;
    std::cout<<dSum<<"\n";
    Sum+=dSum;
    std::cout<<Sum<<"\n";
    return Sum;
}
*/    



//SOLUTION 3
//Another Solution Coppied from some guy in the discussion thread
//I have to optimize my code above and technically it is still not finished,
int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
    
    // distance to edges 
    int tSpan = n-rQueen;
    int lSpan = cQueen-1;
    int bSpan = rQueen-1; 
    int rSpan = n-cQueen; 
    // distance to corners
    int blSpan = min (cQueen, rQueen) -1; 
    int brSpan = min (rQueen-1, n-cQueen);
    int tlSpan = min (n-rQueen, abs(1-cQueen));
    int trSpan = n - max(cQueen, rQueen);
    
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        if (rObstacle == rQueen) // in the same row
        {
            if (cObstacle > cQueen)
                rSpan = min (rSpan, cObstacle-cQueen-1); 
            if (cObstacle < cQueen)
                lSpan = min (lSpan, cQueen-cObstacle-1); 
        }
        if (cObstacle == cQueen) // in the same column
        {
            if (rObstacle > rQueen) 
                tSpan = min (tSpan, rObstacle-rQueen-1);
            if (rObstacle < rQueen)
                bSpan = min (bSpan, rQueen-rObstacle-1);
        }
        if (abs(cQueen-cObstacle) == abs(rQueen-rObstacle)) // in the same diagonal
        {
            if  (rObstacle > rQueen){ // Higher part. 
                if  (cObstacle < cQueen) // left
                    tlSpan = min(tlSpan, rObstacle-rQueen-1);
                if  (cObstacle > cQueen) // right
                    trSpan = min(trSpan, cObstacle-cQueen-1);
            }        
            if  (rObstacle < rQueen){ // Lower part
                if  (cObstacle < cQueen) // left
                    blSpan = min(blSpan, cQueen-cObstacle-1);               
                if  (cObstacle > cQueen) // right
                    brSpan = min(brSpan, cObstacle-cQueen-1);              
          }
        }
    }

    cout << tSpan+rSpan+bSpan+lSpan+blSpan+brSpan+trSpan+tlSpan; 
    return 0;
}