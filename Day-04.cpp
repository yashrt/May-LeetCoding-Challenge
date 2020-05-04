// A Binary number + it's complemnt = result's all bit are set to 1
// 101 + 010 = 111
// Number which are power of 2 minus 1 will have all bits set to 1
// 7 => 111, 15 =>1111 


class Solution {
public:
    int findComplement(int num) {
        
        // getting next power of 2
        int nextPowerof2 = log2(num) + 1;
        
        // getting number which is next power of 2
        int number  = pow(2, nextPowerof2);
        
        return (number-1)-num;
    }
};
