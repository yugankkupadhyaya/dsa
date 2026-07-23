class Solution {
public:
    int jump(vector<int>& nums) {
        int currend=0;
        int farend=0;
        int jump =0;
        for(int i =0;i<nums.size()-1;i++){

            farend=max(farend,nums[i]+i);
//far end =5

            if(currend==i){
                jump++;//2
                currend =farend;//5
            }


        }return jump;
    }
};