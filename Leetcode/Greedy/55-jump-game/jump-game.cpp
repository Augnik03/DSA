class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        for(int i=0; i<n; i++){
            if(i > jumps) return false;
            jumps = max(jumps, i + nums[i]);
        }
        return true;
    }
};