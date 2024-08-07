class Solution {
public:
    string one[19] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string ten[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string recur(int n){
        if(n >= 1000000000){
            return recur(n / 1000000000) + " Billion" + recur(n % 1000000000);
        }
        if(n >= 1000000){
            return recur(n / 1000000) + " Million" + recur(n % 1000000);
        }
        if(n >= 1000){
            return recur(n / 1000) + " Thousand" + recur(n % 1000);
        }
        if(n >= 100){
            return recur(n / 100)+ " Hundred" + recur(n % 100);
        }
        if(n >= 20){
            return " " + ten[n / 10 - 2] + recur(n % 10);
        }
        if(n >= 1){
            return " " + one[n - 1];
        }
        return "";
    }
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        return recur(num).substr(1);
    }
};
