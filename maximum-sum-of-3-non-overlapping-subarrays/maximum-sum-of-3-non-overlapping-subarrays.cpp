class Solution {
public:
   int memo[20000][4];
vector<int> ret;
int dp(int i,int n,int k,vector<int>& arr)
{
	if(!n)
		return 0;
	if(i>=arr.size())
	{
		if(n)
			return INT_MIN;
		else return 0;
	}
	else if(memo[i][n]!=-1)
		return memo[i][n];
	else
	{
		int taken=0,not_taken=0;
		not_taken=dp(i+1,n,k,arr);
		taken=arr[i]+dp(k+i,n-1,k,arr);
		return memo[i][n]=max(taken,not_taken);
	}
}
void dfs(int i,int n,int k,vector<int>& arr)
{
	if(!n)
		return;
	else
	{
		int taken=0,not_taken=0;
		taken=arr[i]+dp(i+k,n-1,k,arr);
		not_taken=dp(i+1,n,k,arr);
		if(taken>=not_taken)
		{
			ret.push_back(i);
			dfs(i+k,n-1,k,arr);
		}
		else
			dfs(i+1,n,k,arr);
	}
}
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
{
	vector<int> arr(nums.size()-k+1);
	int sum=0,j=0;
	for(int i=0;i<k;++i)
		sum+=nums[i];
	arr[j++]=sum;
	for(int i=k;i<nums.size();++i)
	{
		sum-=nums[i-k];
		sum+=nums[i];
		arr[j++]=sum;
	}
	memset(memo,-1,sizeof(memo));
	dp(0,3,k,arr);  
	dfs(0,3,k,arr);
	return ret;
}
    
    
    /* vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>pref(n);
        vector<int>prefr(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        prefr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefr[i]=prefr[i+1]+nums[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            
            if(i<k){
                sum+=nums[i];
                left[i]=sum;
            }
           else{
            sum+=nums[i]-nums[i-k];   
            left[i]=max(left[i-1],sum);
           }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            
            if(i+k>=n){
                sum+=nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+k]; 
            right[i]=max(right[i+1],sum);
            }
        }
        
        //mid->start=k;
        //mid->end=n-k-1;
        int maxS=0;
        int mid=-1;
        int l=-1;
        int r=-1;
        for(int i=k;i<=n-2*k;i++){
            if(maxS<(left[i-1]+right[i+k]+pref[i+k-1]-pref[i-1])){
                maxS=left[i-1]+right[i+k]+pref[i+k-1]-pref[i-1];
                mid=i;
            }
        }
        int leftS=left[mid-1];
        int rightS=right[mid+k];
        for(int i=k-1;i<mid;i++){
            
            if(pref[i]-((i-k)>=0?pref[i-k]:0)==leftS){
                l=i-k+1;
                break;
            }
        }
    
    for(int i=mid+(2*k)-1;i<n;i++){
            
                if((pref[i]-pref[i-k])==rightS){
                r=i-k+1;
                break;
            
        }
    }    
    
    vector<int>ans(3,0);
        ans[0]=l;
        ans[1]=mid;
        ans[2]=r;
        return ans;
    }*/
    
};