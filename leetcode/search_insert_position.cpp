class Solution {
public:
    /*
    int binarySearch(int pointer1; int pointer2; int target){
        int i = pointer1;
        int j = pointer2;
        if ()
    }
    */

    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        if (target < nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();
        if (target == nums[0]) return 0;
        if (target == nums[nums.size() - 1]) return nums.size() - 1;

        while (i + 1 != j){
            if (nums[i] == target) return i;
            if (nums[j] == target) return j;

            int mid_pointer = (i + j) / 2;
            if (nums[mid_pointer] == target) return mid_pointer;
            if (target < nums[mid_pointer]){
                j = mid_pointer;
            }
            if (target > nums[mid_pointer]){
                i = mid_pointer;
            }
        }

        int pointer_1 = 0;
        int pointer_2 = 1;
        while (pointer_2 != nums.size()){
            if (target > nums[pointer_1] && target < nums[pointer_2]) return pointer_2;
            pointer_1++;
            pointer_2++;
        }
        return nums.size();
    }
};
