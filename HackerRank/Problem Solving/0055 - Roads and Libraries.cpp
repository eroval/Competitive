//*Note: the C++ DOESN'T work because the required output can't be handled even by long long (spend frikin hours wondering why it didn't work...)
//check out the python version for full working implementation

//Non the less this c++ has two "working" implementations.

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */


// IMPLEMENTATION #1
bool filledMask(std::map<int,bool>& boolMask){
    for(auto x : boolMask){
        if(!x.second){
            return false;
        }
    }
    return true;
}

int findMaxCity(std::map<int, std::vector<int>>& matrix, std::map<int, bool>& boolMask){
    int maxCity;
    //initialize city
    for(auto x : boolMask){
        if(!x.second){
            maxCity=x.first;
            break;
        }
    }
    
    //find the maximum city currently univisited
    for(auto x : matrix){
        if(!boolMask[x.first]&&x.second.size()>matrix[maxCity].size()){
            maxCity=x.first;
        }
    }
    return maxCity;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib<=c_road){
        return c_lib*n;
    }
    else{
        std::map<int, std::vector<int>> adjMatrix;
        std::map<int,bool> boolMask;
        for(int i=0; i<cities.size(); i++){
            adjMatrix[cities[i][0]].push_back(cities[i][1]);
            adjMatrix[cities[i][1]].push_back(cities[i][0]);
            boolMask[cities[i][0]]=false;
            boolMask[cities[i][1]]=false;
        }
        
        for(auto x : adjMatrix){
            std::cout<<x.first<<": ";
            for(int i=0; i<x.second.size(); i++){
                std::cout<<x.second[i]<<" ";
            }
            std::cout<<"\n";
        }
        
        int maxCity = adjMatrix.begin()->first;
        long long Sum=0;
        std::queue<int> keys;
        
        while(!filledMask(boolMask)){
            maxCity = findMaxCity(adjMatrix, boolMask);
            Sum+=c_lib;
            keys.push(maxCity);
            boolMask[maxCity]=true;
            while(!keys.empty()){
                int tmp;
                for(int i=0; i<adjMatrix[keys.front()].size(); i++){
                    tmp = adjMatrix[keys.front()][i];
                    if(!boolMask[tmp]){
                        keys.push(tmp);
                        boolMask[tmp]=true;
                        Sum+=c_road;
                    }
                }
                keys.pop();
            }
        }
        
        if(n>boolMask.size()){
            Sum+=(n-boolMask.size())*c_lib;
        }
        
        return Sum;
    }
}



//Implementation #2
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib<=c_road){
        return c_lib*n;
    }
    else{
        std::map< long long , std::vector<long>> cityMatrix;
        std::map< long long , bool> visited;
        
        
        for( long long  i=0; i<cities.size(); i++){
            long long  rootCity = cities[i][0];
            long long  connectedCity = cities[i][1];
            cityMatrix[rootCity].push_back(connectedCity);
            cityMatrix[connectedCity].push_back(rootCity);
            visited[rootCity]=false;
            visited[connectedCity]=false;
        }
        
        for(auto cityNode : cityMatrix){
            std::cout<<cityNode.first<<": ";
            for( long long  i=0; i<cityNode.second.size(); i++){
                std::cout<<cityNode.second[i]<<" ";
            }
            std::cout<<"\n";
        }
        
        long long Sum = c_lib*(n-cityMatrix.size());
        
        for(auto cityNode : cityMatrix){
            if(!visited[cityNode.first]){
                Sum+=c_lib;
                visited[cityNode.first]=true;
            }
            for( long long  i=0; i<cityNode.second.size(); i++){
                if(!visited[cityNode.second[i]]){
                    Sum+=c_road;
                    visited[cityNode.second[i]]=true;
                }
            }
        }
        return Sum;
    }
}
        

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        long n = stoi(first_multiple_input[0]);

        long m = stoi(first_multiple_input[1]);

        long c_lib = stoi(first_multiple_input[2]);

        long c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
