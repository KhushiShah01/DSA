class Solution{

  public:
	int minDifference(int arr[], int n)  { 
     // fill the dp array
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=sum;i++){
	        dp[0][i]=false;
	    }
	    for(int i=0;i<=n;i++){
	        dp[i][0]=true;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
    	        dp[i][j] = dp[i-1][j];
    	        if (arr[i-1]<=j){
    	            dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
    	        }
	        }
	    }
	    
	    int diff = INT_MAX;
	    
    // traverse the last row of the dp array
	    for(int j=0;j<=sum/2;j++){
	        if(dp[n][j]==true){
	            int first = j;
	            int second = sum-j;
	            if(diff>abs(first-second)){
	                diff = abs(first-second);
	            }
	        }
	    }
	    
	    return diff;
	    
	} 
};


// OR

// changing the loop in the end for traversing to get the minimum diff. using while loop select the first element while going left from sum/2 which is true. 
// Calculate the difference then. This would give the least result.

class Solution2{

  public:
	int minDifference2(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=sum;i++){
	        dp[0][i]=false;
	    }
	    for(int i=0;i<=n;i++){
	        dp[i][0]=true;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
    	        dp[i][j] = dp[i-1][j];
    	        if (arr[i-1]<=j){
    	            dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
    	        }
	        }
	    }
	    
	    int diff;
	    
	    int j = sum/2;
	    while(j>=0){
	        if (dp[n][j] == true){
	            diff = abs(j-(sum-j));
	            break;
	        }
	        j--;
	    }
	    return diff;
	    
	} 
};
