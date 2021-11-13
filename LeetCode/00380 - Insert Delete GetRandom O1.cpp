class RandomizedSet {
public:
    std::unordered_map<int, char> keys;
    
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(keys.find(val)!=keys.end()){
            return false;
        }
        keys[val]='i';
        return true;
    }
    
    bool remove(int val) {
        auto it = keys.find(val);
        if(it!=keys.end()){
            keys.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto item = keys.begin();
        std::advance( item, rand()%keys.size());
        return item->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */