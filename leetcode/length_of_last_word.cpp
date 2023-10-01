class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 1) return 1;
        int end_index;
        int space_index = INT_MAX;

        for (int i = s.length() - 1; i > 0; i--){
            if (s[i] != ' '){
                end_index = i;
                break;
            }
        }

        for (int i = end_index; i >= 0; i--){
            if (s[i] == ' '){
                space_index = i;
                break;
            }
        }

        if (space_index == INT_MAX){
            space_index = -1;
        }

        return end_index - space_index;
    }
};
