class Solution {
public:
    bool isPalindrome(string s) {
        string concat = "";

        // Getting all alphanumeric characters into a string
        for (int i = 0; i < s.length(); i++){
            if (iswalnum(s[i])){
                concat.push_back(s[i]);
            }
        }

        // Converting upper case to lower case
        transform(concat.begin(), concat.end(), concat.begin(), ::tolower);
        
        for (int k = 0; k < concat.length() / 2; k++){
            if (concat[k] != concat[concat.length() - 1 - k]){
                return false;
            }
        }
        return true;
    }
};
