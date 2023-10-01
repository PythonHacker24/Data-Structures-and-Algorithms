class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0) return false;
        string number = to_string(x);
        int limit = 0;

        if (number.length() % 2  == 0){
            limit = number.length() / 2;
        }
        if (number.length() % 2 != 0){
            limit = (number.length() / 2) - 1;
        }
        for (int i = 0; i <= limit; i++){
            if (number[i] != number[number.length() - 1 - i]) return false;
        }
        return true;
    }
};
