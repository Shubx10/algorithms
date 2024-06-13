class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int num = 0, result = 0, sign = 1;
        for(int i = 0; i < n; ++i){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }else if(s[i] == '+'){
                result += num * sign;
                num = 0;
                sign = 1;
            }else if(s[i] == '-'){
                result += num * sign;
                num = 0;
                sign = -1;
            }else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result += num * sign;
                num = 0;
                result *= st.top(); //prev_sign
                st.pop();
                result += st.top(); //prev_result
                st.pop();
            }
        }
        result += num * sign;
        return result;
    }
};
