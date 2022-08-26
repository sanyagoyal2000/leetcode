class MyHashMap {
public:
    MyHashMap() {
        buckets = new list<pair<int, int>>[bucket_size];
    }
    
    void put(int key, int value) {
        auto it = find(key);
        if (it != end(buckets[hash(key)])) {
            it->second = value;
            return;
        }
        buckets[hash(key)].push_back({key, value});
        total_elements++;
        rehashIfNeeded();
    }
    
    int get(int key) {
        auto it = find(key);
        return it != end(buckets[hash(key)]) ? it->second : -1;
    }
    
    void remove(int key) {
        auto it = find(key);
        if (it != end(buckets[hash(key)])) {
            buckets[hash(key)].erase(it);
            total_elements--;
        }
    }
private:
    list<pair<int, int>> *buckets;
    int bucket_size = 1;
    int total_elements = 0;
    float max_load_factor = 1.0;
    
    int hash(unsigned int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x % bucket_size;
    }
    
    list<pair<int, int>>::iterator find(int key) {
        int hashed_key = hash(key);
        for (auto it = begin(buckets[hashed_key]); it != end(buckets[hashed_key]); it++) {
