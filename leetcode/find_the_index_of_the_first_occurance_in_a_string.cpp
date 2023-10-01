class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++){
            if (haystack[i] == needle[0]){
                int check = 0;
                for (int k = 0; k < needle.size(); k++){
                    if (haystack[i + k] != needle[k]) break;
                    check++;
                }
                if (check == needle.size()) return i;
            }
        }
        return -1;
    }
};
