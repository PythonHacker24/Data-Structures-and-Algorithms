class Solution {
public:
    int mySqrt(int x) {
        long pointer1 = 0;
        long pointer2 = 1;
        while(true){
            long square1 = pointer1 * pointer1;
            long square2 = pointer2 * pointer2;
            if (x == square1) return pointer1;
            if (x == square2) return pointer2;
            if (x > square1 && x < square2) return pointer1;

            pointer1++;
            pointer2++;
        }
    }
};
