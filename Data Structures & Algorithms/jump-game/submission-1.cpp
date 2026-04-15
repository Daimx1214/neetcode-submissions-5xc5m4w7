class Solution {
public:
    bool canJump(vector<int>& nums) {
        int point=0;

        for(int i=0; i<nums.size(); i++){
            if(i>point){
                return 0;
            }
            point = max(point, i+nums[i]);
        }
        return point>=nums.size()-1;
    }
};