// leetcode 494

// create 2 subsets s1 and s2, s1 (all +ve and s2 all -ve). sum(s1) - sum(s2) = target
// since s2 is all -ve we take the - outside and add all s2 values.
// s1-s2 = target and s1+s2 = sum => s1 = (target+sum)/2, which is a constant
// this is then reduxed to the problem of counting all possible ways we can create a subset whose sum = s1

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        int n = nums.size();
        // s1-s2 = target and s1+s2 = sum => s1= (target+sum)/2
        int s1 = (sum+target)/2;
        // finding the number of ways create a subset with sum = s1;

        if(sum<target||(sum+target)%2!=0)
            return 0;

        int dp[n+1][s1+1];

        for(int j=0;j<=s1;j++){
            dp[0][j] = 0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=s1;j++){
                if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][s1];
    }
};
