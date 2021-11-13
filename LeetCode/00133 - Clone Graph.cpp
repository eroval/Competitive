class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        std::unordered_map<int, Node*> keys;
        std::queue<Node*> nodes;
        nodes.push(node);
        
        keys[node->val] = new Node(node->val, node->neighbors);
        
        while(!nodes.empty()){
            if(nodes.front()!=nullptr){
                for(int i=0; i<nodes.front()->neighbors.size(); i++){
                    if(keys.find(nodes.front()->neighbors[i]->val)==keys.end()){
                        keys[nodes.front()->neighbors[i]->val] = new Node(nodes.front()->neighbors[i]->val, nodes.front()->neighbors[i]->neighbors);
                        keys[nodes.front()->val]->neighbors[i] = keys[nodes.front()->neighbors[i]->val];
                        nodes.push(nodes.front()->neighbors[i]);
                    }
                    else {
                        keys[nodes.front()->val]->neighbors[i] = keys[nodes.front()->neighbors[i]->val];
                    }
                }
            }
            nodes.pop();
        }
        return keys[node->val];
    }                                                                           
};