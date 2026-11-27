class Solution {
public:
    int dp[1001][1501];
    int solve(vector<vector<int>>&items,int n,int budget,int &cheap,vector<int>&copies){
        if(n==0){
            return budget/cheap;
        }
        if(dp[n][budget]!=-1)return dp[n][budget];
        int take=0;
        int skip=0;
        if(budget>=items[n-1][1]){
            take=1+solve(items,n-1,budget-items[n-1][1],cheap,copies)+copies[n-1];
        }
        skip=solve(items,n-1,budget,cheap,copies);
        return dp[n][budget]= max(skip,take);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int cheap=INT_MAX;
        int n=items.size();
        vector<int>copies(n,0);
        for(int i=0;i<n;i++){
            int copy=0;
            for(int j=0;j<n;j++){
                if(j!=i&&items[j][0]%items[i][0]==0)copy++;
            }
            cheap=min(cheap,items[i][1]);
            copies[i]=copy;
        }
        memset(dp,-1,sizeof(dp));
        return solve(items,n,budget,cheap,copies);


    }
};