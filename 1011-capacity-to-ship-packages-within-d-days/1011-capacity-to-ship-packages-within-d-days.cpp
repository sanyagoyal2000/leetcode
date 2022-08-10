class Solution {
    bool isCapacity(int n, long long mid, vector<int>& weights, int days)
    {
        long long Cday = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(weights[i] > mid) return false;
            if(sum + weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                Cday++;
                if(Cday > days) return false;
                sum = weights[i];
            }
        }
        return true;
    }
    int binarysearch(long long fst, long long snd, int days, int n, vector<int>& weights)
    {
        int ans = INT_MAX;
        while(fst <= snd)
        {
            int mid = (snd+fst)/2;
            if(isCapacity(n, mid, weights, days))
            {
                snd = mid-1;
                ans = mid;
            }
            else
                fst = mid+1;
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum = 0, n = weights.size();
        for(int &num : weights)
            sum += num;
        return binarysearch(0, sum, days, n, weights);
    }
};