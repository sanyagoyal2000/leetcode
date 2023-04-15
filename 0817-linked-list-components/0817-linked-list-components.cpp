/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void dfs(unordered_map<int,bool>&vis,unordered_map<int,vector<int>>&adj,int node,set<int>&s){
       vis[node]=true;
        for(auto nbr: adj[node]){
        if(vis[nbr]==false and s.find(nbr)!=s.end()){
                dfs(vis,adj,nbr,s);
            }
        }
    }
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        ListNode*temp=head;
        while(temp->next!=NULL){
            mp[temp->val].push_back(temp->next->val);
            mp[temp->next->val].push_back(temp->val);
            temp=temp->next;
        }
        set<int>s;
        unordered_map<int,bool>vis;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            vis[nums[i]]=false;
        }
        int cnt=0;
        for(auto ele:s){
            if(vis[ele]==false){
                cnt++;
                dfs(vis,mp,ele,s);
            }
        }
            
        return cnt;
    }
};