class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int curr=0;
        int n=tokens.size();
       int i=0;
       int j=n-1;
       while(i<n){
        if(power>=tokens[i]){
            power-=tokens[i];
            curr++;
            i++;
            ans=max(ans,curr);
        }else if(curr>0){
            power+=tokens[j];
            j--;
            curr--;
        }else{
            return ans;
        }
       }
        return ans;

    }
};