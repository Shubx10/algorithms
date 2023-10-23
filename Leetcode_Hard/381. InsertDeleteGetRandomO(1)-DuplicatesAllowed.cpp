class RandomizedCollection {
    unordered_map<int, unordered_set<int>> mp;
    vector<int> v;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size() - 1);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int ind = *mp[val].begin();
            mp[val].erase(ind);
            int last_val = v.back();
            mp[last_val].insert(ind);
            mp[last_val].erase(v.size() - 1);
            swap(v[ind], v[v.size() - 1]);
            v.pop_back();
            if(mp[val].size() == 0) mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};
