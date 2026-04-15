class Solution {
public:
    bool canJump(vector<int>& nums) {
        int point = 0;

        for(int i=0; i<nums.size(); i++){
            if(i>point){
                return false;
            }
            else if(i<=point){
                point = max(point, i+nums[i]);
            }

            if(point>=nums.size()){
                return true;
            }
        }
        return true;
    }
};
