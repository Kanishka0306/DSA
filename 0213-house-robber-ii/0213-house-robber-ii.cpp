class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& dp)
    {
        if(i == 0)
            return nums[0];
        if(i < 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int pick = nums[i] + solve(i-2, nums, dp);
        int notPick = solve(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> arr1, arr2;

        for(int i = 0; i < n; i++)
        {
            if(i != 0)
                arr1.push_back(nums[i]);

            if(i != n-1)
                arr2.push_back(nums[i]);
        }

        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);

        int ans1 = solve(arr1.size()-1, arr1, dp1);
        int ans2 = solve(arr2.size()-1, arr2, dp2);

        return max(ans1, ans2);
    }
};