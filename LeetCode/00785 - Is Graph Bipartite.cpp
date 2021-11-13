class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> color(graph.size(), 0);
        std::queue<int> nodes;
        nodes.push(0);
        
        for(int i=0; i<graph.size(); i++){
            if(color[i]==0){
                nodes.push(i);
                color[i]=1;
                while(!nodes.empty()){
                    for(auto it : graph[nodes.front()]){
                        if(color[it]==0){
                            nodes.push(it);
                            color[it]= -color[nodes.front()];
                        }
                        else if(color[it]==color[nodes.front()]){
                            return false;
                        }
                    }
                    nodes.pop();
                }
            }
        }
        return true;
    }
};