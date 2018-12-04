class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = num, sum = 0;
            while (tmp) {
                sum += tmp%10;
                tmp /= 10;
            }
            
            num = sum;
        }
        
        return num;
    }
};