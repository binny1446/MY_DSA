class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, 0));
        
        for(int i=0;i<coins.size()+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i == 0)dp[i][j] = 0;
                if(j == 0)dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                if(i == 0)dp[i][j] = 0;
                if(j == 0)dp[i][j] = 1;
                
                else if(j>= coins[i-1]){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};