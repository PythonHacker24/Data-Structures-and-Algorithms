class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        // Finding the smallest size string in the vector
        int min = INT_MAX;
        int min_index = 0;
        for (int i = 0; i < strs.size(); i++){
            string test = strs[i];
            if (test.length() < min){
                min = test.length();
                min_index = i;
            }
        }


        /*
        // For edge case where min = 1;
        char test = (char)strs[min_index];
        if (min == 1){
            for (int i = 0; i < strs.size(); i++){
                if (strs[i][0] != test){
                    return "";
                }
            }
            return test;
        }
        */

        // Running the iterations for the vector of strings
        string solution = "";
        for (int k = 0; k < min; k++){
            char alpha = strs[0][k];
            for (int i = 1; i < strs.size(); i++){
                if (strs[i][k] != alpha){
                    return solution;
                }
            }
            solution.push_back(alpha);
        }
        return solution;
    }
};
