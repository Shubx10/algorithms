## 🚀Decimal to Binary
```cpp
// TC = O(log n)
// SC = O(1)
string decimalToBinary(int n){
    if(n == 0) return "0";
    string str = "";
    while(n){
        if(n & 1){
            str += '1';
        }else{
            str += '0';
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
```

## 🚀Binary to Decimal
```cpp
// TC = O(log n)
// SC = O(1)
int binaryToDecimal(int n){
    int dec_value = 0;
    int base = 1;
    while(n){
        int last_digit = n % 10;
        n = n / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}
```

## 🚀Check whether kth bit is set or not
```cpp
// TC = O(1)
// SC = O(1)
bool checkKthBit(int n, int k){
    return (n & (1 << k)) != 0;
}
```
```cpp
// TC = O(1)
// SC = O(1)
bool checkKthBit(int n, int k){
    return ((n >> k) & 1) != 0;
}
```

## 🚀Set kth bit
```cpp
// TC = O(1)
// SC = O(1)
int setKthBit(int n, int k){
    return (n | (1 << k));
}
```

## 🚀Clear kth bit
```cpp
// TC = O(1)
// SC = O(1)
int clearKthBit(int n, int k){
    return (n & (~(1 << k)));
}
```

## 🚀Toggle kth bit
```cpp
// TC = O(1)
// SC = O(1)
int toggleKthBit(int n, int k){
    return (n ^ (1 << k));
}
```

## 🚀Clear rightmost set bit
```cpp
// TC = O(1)
// SC = O(1)
int clearRightmostBit(int n){
    return (n & (n - 1));
}
```

## 🚀Power of two
```cpp
// TC = O(1)
// SC = O(1)
bool isPowerOfTwo(int n){
    return (n & (n - 1)) == 0;
}
```

## 🚀Count set bits
```cpp
// TC = O(log n)
// SC = O(1)
int countSetBits(int n){
    int cnt = 0;
    while(n){
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}
```
