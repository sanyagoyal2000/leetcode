struct Node{
    Node *list[2];
    bool flag=-1;
    
    Node *get(int n){
        return list[n];
    }
    void put(int n,Node*node){
        list[n]=node;
    }
    bool containsKey(int n){
        return list[n]!=NULL;
    }
};

class Trie{
    private:
    Node *root;
    
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
    
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,t.findMax(nums[i]));
        }
        return ans;
    }
};