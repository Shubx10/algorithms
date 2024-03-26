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
