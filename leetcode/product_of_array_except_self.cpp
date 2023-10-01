class Solution {
public:
    bool check_zero(vector<int> nums){
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) return true;
        }
        return false;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product = 1;
        int zero_nums = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                total_product = total_product * nums[i];
            }
            if (nums[i] == 0){
                zero_nums++;
            }
        }

        if (zero_nums == nums.size()) return nums;

        vector<int> result;

        if (nums.size() == 2 && zero_nums == 1){
            for (int i = 0; i < nums.size(); i++){
                result.push_back(nums[1 - i]);
            }
            return result;
        }

        if (zero_nums == nums.size() - 1 || zero_nums >= 2){
            for (int i = 0; i < nums.size(); i++){
                result.push_back(0);
            }
            return result;
        }

        if (check_zero(nums) == true){
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == 0){
                    result.push_back(total_product);
                }
                else{
                    result.push_back(0);
                }
            }
        }

        else{
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] != 0){
                    result.push_back(total_product / nums[i]);
                }
                else{
                    result.push_back(total_product);
                }    
            }
        }

        return result;
    }
};
