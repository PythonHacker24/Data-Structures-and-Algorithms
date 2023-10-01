class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;
        int size = nums.size();
        k = k % size;
        for (int i = size - k; i < size; i++){
            result.push_back(nums[i]);
        }
        for (int i = 0; i < size - k; i++){
            result.push_back(nums[i]);
        }
        for (int i = 0; i < result.size(); i++){
            nums[i] = result[i];
        }
    }
};
