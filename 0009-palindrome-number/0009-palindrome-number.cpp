class Solution {
public:
    bool isPalindrome(int n) {
        int revnum = 0;
        int temp = n;
        if (n < 0) {
    return false;
}
        while (n!=0){
            int ld = n%10;
            if (revnum > INT_MAX/10 || revnum < INT_MIN/10){
                return false;
            }
            revnum = ( revnum * 10 )+ ld;
            n=n/10;

        }
        if (revnum == temp){
            return true ;}
        else return false ;
        }

        
    
};