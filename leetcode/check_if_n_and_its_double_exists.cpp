class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> even;
        int check_zero = 0;
        for (int n = 0; n < arr.size(); n++){
            if (arr[n] == 0) {
                check_zero++;
            }
        }
        if (check_zero >= 2) return true;

        for (int i = 0; i < arr.size(); i++){
            if (arr[i] % 2 == 0 && arr[i] != 0){
                even.push_back(arr[i] / 2);
            }
        }

        if (even.size() == 0) return false;
        for (int k = 0; k < even.size(); k++){
            for (int m = 0; m < arr.size(); m++){
                if (arr[m] == even[k]) return true;
            }
        }

        return false;
    }
};
