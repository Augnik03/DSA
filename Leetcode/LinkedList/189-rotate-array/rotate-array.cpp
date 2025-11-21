class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0,n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        // for(int count = 0; count<k; count++){   NOT OPTIMAL O(n*k)
        //     int last = nums[n-1];
        //     int i = n-1;
        //     for(i = n-1; i>0; i--){
        //         nums[i] = nums[i-1];
        //     }
        //     nums[0] = last;
        // }
    }
};