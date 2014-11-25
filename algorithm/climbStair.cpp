/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
// DP : d(i) = d(i-1) + d(i-2)
    int climbStairs(int n) {
        // write your code here
        if(n == 1 || n == 2)
            return n;
        
        int a = 1, b = 2, c;
        for(int i = 3; i <= n; ++i){
            c = a+b;
            a = b;
            b = c;
        }
        
        return c;   
    }