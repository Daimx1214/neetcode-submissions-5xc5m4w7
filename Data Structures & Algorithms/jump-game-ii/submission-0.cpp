class Solution {
public:
    int jump(vector<int>& nums){
        int point=0, count=0, end=0;
        
        for(int i=0; i<nums.size()-1; i++){
            point = max(point, i+nums[i]);

            if(i == end){
                count++;
                end = point;
            }
        }
        return count;
    }
};
