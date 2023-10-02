class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int k = 0;
        int counter = 0;
        int result[m+n];
        while (i != m && k != n){
            if (nums1[i] <= nums2[k]){
                result[counter] = nums1[i];
                i++;
            }
            else{
                result[counter] = nums2[k];
                k++;
            }
            counter++;
        }

        while (i != m){
            result[counter] = nums1[i];
            counter++;
            i++;
        }
        while (k != n){
            result[counter] = nums2[k];
            counter++;
            k++;
        }

        for (int z = 0; z < m+n; z++){
            nums1[z] = result[z];
        }
    }
};
