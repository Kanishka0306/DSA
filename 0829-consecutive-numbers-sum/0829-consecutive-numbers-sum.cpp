class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count =0;
        for(long long k=1; 2*n >k*(k-1) ; k++){
            long long numerator = n- (k*(k-1)/2);
            if (numerator % k == 0) count++;
        }
        return count;
    }
};