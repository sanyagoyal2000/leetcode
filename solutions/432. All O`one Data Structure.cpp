        Node* node = head; 
        if (mp.find(key) != mp.end()) {
            node = mp[key]; 
            node->keys.erase(key); 
        }
        if (node->freq + 1 == node->next->freq) {
            node->next->keys.insert(key); 
            mp[key] = node->next; 
        } else {
            Node* newn = new Node({key}, node->freq+1, node, node->next); 
            mp[key] = node->next = node->next->prev = newn; 
        }
        
        if (node != head && node->keys.empty()) {
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            delete node; 
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        Node* node = mp[key]; 
        node->keys.erase(key); 
        if (node->freq == 1) {
            mp.erase(key);
        } else if (node->prev->freq + 1 == node->freq) {
            node->prev->keys.insert(key); 
            mp[key] = node->prev; 
        } else {
            Node* newn = new Node({key}, node->freq-1, node->prev, node); 
            mp[key] = node->prev = node->prev->next = newn;
        }
        if (node->keys.empty()) {
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            delete node; 
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return head != tail->prev ? *begin(tail->prev->keys) : ""; 
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return head->next != tail ? *begin(head->next->keys) : ""; 
    }
};
