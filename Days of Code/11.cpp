#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

       cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //int maxSum=0;
    int max[16];
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            int Sum=0;
            for (int k = j - 1; k < j + 2; k++) {
                    Sum += arr[i - 1][k];
            }
            Sum += arr[i][j];
            for (int k = j - 1; k < j + 2; k++) {
                    Sum += arr[i + 1][k];
            }
            /*
            if(Sum>maxSum){
                maxSum=Sum;
            }
            */
            max[4*(i-1)+j-1]=Sum;
        }
    }
    int maxSum=max[0];
    for(int i=1; i<16; i++){
        if(max[i]>maxSum){
            maxSum=max[i];
        }
    }
    std::cout<<maxSum<<std::endl;

    return 0;
}
