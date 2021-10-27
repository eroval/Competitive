#include <bits/stdc++.h>

using namespace std;

/*
//This is actually WAY SLOWER even if I delete all the debugging tests and optimize
//So I decided to go for another approach without any rotation or mirroring
//and dynamic checking. Just precalculating and saving all the magic squares.

void RotateSquare(int arr[3][3]){
    std::vector<int> m;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m.push_back(arr[i][j]);
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[j][3-i-1] = m[i*3+j];
        }
    }
}

void MirrorSquare(int arr[3][3]){
    for(int i=0; i<3; i++){
        arr[i][0]^=arr[i][2];
        arr[i][2]^=arr[i][0];
        arr[i][0]^=arr[i][2];
    }
}

int formingMagicSquare(vector<vector<int>> s) {
    //there is only one original magic sqare
    //all the other ones are either rotations or reflections
    int n=3;
    int square[3][3] = {{8,1,6},{3,5,7},{4,9,2}};
    int TotalSum=0;
    std::vector<short int> cnt;
    for(int k=0; k<4; k++){



        int square2[3][3];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                square2[i][j] = square[i][j];
            }
        }
        MirrorSquare(square2);


        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                std::cout<<square[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                std::cout<<square2[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";





        cnt.push_back(0);
        cnt.push_back(0);

        for(int i=0; i<s.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(s[i][j]==square[i][j]){
                    cnt[cnt.size()-2]++;
                }
                else if(s[i][j]==square2[i][j]){
                    cnt.back()++;
                }
            }
        }

        RotateSquare(square);

    }
    
    for(int i=0; i<cnt.size(); i++){
        std::cout<<cnt[i]<<" ";
    }
    std::cout<<"\n\n";

    int max=cnt[0];
    int index=0;
    int counter=0;
    for(int i=0; i<cnt.size(); i++){
        if(cnt[i]>max){
            max=cnt[i];
            index=i;
        }
    }

    for(int i=0; i<cnt.size(); i++){
        if(cnt[i]==max){
            counter++;
        }
    }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                std::cout<<square[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";

    std::cout<<max<<std::endl<<index<<std::endl;
    bool mirror=false;
    for(int i=0; i<index; i++){
        if(i%2==0){
            MirrorSquare(square);
            mirror=true;
        }
        else {
            if(mirror){
                MirrorSquare(square);
                mirror=false;
            }
            RotateSquare(square);
        }
    }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                std::cout<<square[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            TotalSum += abs(s[i][j]-square[i][j]);
        }
    }
    //still have to do a check when the cnts are equal which just went too overboard on      the coding part so i left it as it is. Maybe some other time.
    return TotalSum;
}
*/

//ALSO this approach is way faster and easier, however it is hard-coded...
int formingMagicSquare(vector<vector<int>> s){
    vector<vector<vector<int>>> squares =
    {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{2,7,6},{9,5,1},{4,3,8}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}}
     };

    vector<int> Sums;
     for(int i=0; i<squares.size(); i++){
         int Sum=0;
         for(int j=0; j<s.size(); j++){
             for(int k=0; k<s.size(); k++){
                 Sum+=abs(s[j][k]-squares[i][j][k]);
             }
         }
         Sums.push_back(Sum);
     }
     int min=Sums[0];
     for(int i=1; i<Sums.size(); i++){
         if(min>Sums[i]){
             min=Sums[i];
         }
     }

     return min;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}