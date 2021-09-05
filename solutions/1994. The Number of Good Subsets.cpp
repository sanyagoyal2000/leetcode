        for(auto x: nums){
            
            int num = 0, k=0;
            int flag = 1;
            
            for(auto j: primes){
​
                int cnt = 0;
                while(x%j == 0){
                    x/=j;
                    cnt++;
                    if(cnt>1) break;
                }
                
                if(cnt > 1)
                { 
                    flag = 0;
                    break;
                }
                
                if(cnt == 1)
                    num = num | (1<<k);
                
                ++k;
            }
            
            if(flag == 0) continue;
            
            if(num == 0) { 
                ones++;
                continue;
            }
            
            cache[num]++;
            if(cache[num] > 1) continue;
            
            V.push_back(num);
        }
        
        vector<vector<int>> dp(V.size(), vector<int> (1024, -1));
        
        int ans = goodSubsets(0,0,V,dp,cache);
        ans = mul(binary_exponentiation(2, ones),ans);
        
        return ans;
    }
};
