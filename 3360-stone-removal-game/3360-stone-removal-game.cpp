class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=false;
        for(int i=10;i>0;i--){

            if(n-i<0){
                break;
            }
            n=n-i;
            alice=!alice;

        }
        return alice;
    }
};