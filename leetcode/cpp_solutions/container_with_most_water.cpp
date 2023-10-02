class Solution {
public:
    int maxArea(vector<int>& height) {
        int end = height.size() - 1;
        int start = 0;
        int max_area = 0;
        while (start < end){
            if (min(height[start], height[end]) * (end - start) > max_area){
                max_area = min(height[start], height[end]) * (end - start);
            }
            else if (height[start] >= height[end]){
                end--;
            }
            else if (height[end] > height[start]){
                start++;
            }
        }
        return max_area;
    }
};
