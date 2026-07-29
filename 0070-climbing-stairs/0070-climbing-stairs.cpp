class Solution {
public:
    vector<int> t;
    int solve (int n ){
        if (n==0 || n==1) return 1;

        if (t[n] != -1) return t[n];  // 2 LINES FOR MEMOIZATION 

        t[n] = solve(n-1) + solve(n-2);
        return t[n];
    }
    int climbStairs(int n) {
        t.resize(n+1 , -1);
        return solve(n);
    }
};