// TC = O(log n)
// SC = O(1)
class Solution{
public:
    int countSetBits(int n){
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
    int countBitsFlip(int a, int b){
        return countSetBits(a ^ b);
    }
};
