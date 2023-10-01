class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                result.push_back(nums[i]);
            }
        }

        nums.clear();
        for (int k = 0; k < result.size(); k++){
            nums.push_back(result[k]);
        }

        return nums.size();
    }
};
