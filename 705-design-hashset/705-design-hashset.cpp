class MyHashSet {
public:
    int limit = pow(10,6)+1;
    vector<int> hashset;
    MyHashSet() {
        hashset=vector<int>(limit,false); // Empty hashset
    }
    
    void add(int key) {// set value at given key to True
      hashset[key]= true;
    }
    
    void remove(int key) { // To remove key from hashset set value at key to false
        hashset[key] =false;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */