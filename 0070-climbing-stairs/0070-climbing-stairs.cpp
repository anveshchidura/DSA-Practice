class Solution {
public:

    
int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int prev1 = 1;
    int prev2 = 1;
    int curr = NULL;
    for(int i =2; i<=n;i++){
        curr = prev1 + prev2;
        int temp = prev1;
        prev1 = curr ;
        prev2 = temp;
    }
    
    return curr;
}
}

;