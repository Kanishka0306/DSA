class Solution {
public: 
    int solve(int i , vector<int>& nums , vector<int> & dp){
        int n = nums.size();
        if(i==0) return nums[i]; //base condition 

        if(i<0) return 0;   //NO HOUSE LEFT 

        if(dp[i]!=-1) return dp[i];

        int pick = nums[i] + solve(i-2 ,nums , dp);
        int Notpick = solve(i-1 ,nums , dp);

        dp[i] = max(pick , Notpick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n , -1);

        return solve(n-1 , nums, dp);
    }
};