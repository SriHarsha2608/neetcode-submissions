class MyHashSet {
public:
    vector<vector<int>> table;
    int size = 10000;

    MyHashSet() {
        table.resize(size);    
    }
    
    int hash(int key)
    {
        return key % size;
    }
    void add(int key) {
        int index = hash(key);
        for(int num : table[index])
        {
            if(num == key)
            {
                return ;
            }
        }
        table[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        
        for(auto it =  table[index].begin(); it!= table[index].end(); it++)
        {
            if(*it == key)
            {
                table[index].erase(it);
                return ;
            }
        }
    }
    
    bool contains(int key) {
        int index = hash(key);
        for(int num : table[index])
        {
            if(num == key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */