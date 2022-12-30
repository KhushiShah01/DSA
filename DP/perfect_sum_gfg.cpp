class Solution{
    #include<math.h>

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int dp[n+1][sum+1];
        for(int i=0;i<=sum;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
          // j starts from 0 because the array can have th enumber 0 which would lead to having to update the col0, ie, col0 won't be 1 for all rows
            for(int j=0;j<=sum;j++){
                if (arr[i-1]>j)
                {
                    dp[i][j] = dp[i-1][j]%1000000007;
                }
                else
                {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%1000000007;
                }
            }
        }
        return dp[n][sum]%1000000007;
	}
	  
};

