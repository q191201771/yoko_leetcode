// Reverse bits of a given 32 bits unsigned integer.
//
// Example:
//
// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
//              return 964176192 represented in binary as 00111001011110000010100101000000.
// Follow up:
// If this function is called many times, how would you optimize it?



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      for (int i = 0; i < 16; i++) {
        int tmp = n & (0x1 << (32-i-1));
        (n & (0x1 << i)) ? (n |= (0x1 << (32-i-1))) : (n &= (~(0x1 << (32-i-1))));
        tmp ? (n |= (0x1 << i)) : (n &= (~(0x1 << i)));
      }
      return n;
    }
};
