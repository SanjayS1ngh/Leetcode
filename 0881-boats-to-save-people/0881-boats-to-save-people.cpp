class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=n-1;
        int ans=0;
        int j=0;
        while(j<=i){
            if(people[i]+people[j]<=limit){
                ans++;
                i--;
                j++;
            }
            else{
                i--;
                ans++;
            }
        }
        return ans;
    }
};