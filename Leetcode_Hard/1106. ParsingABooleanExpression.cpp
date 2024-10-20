class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> op, rest;
        for(int i = 0; i < n; ++i){
            if(expression[i] == ','){
                continue;
            }else if(expression[i] == '!' || expression[i] == '|' || expression[i] == '&'){
                op.push(expression[i]);
            }else if(expression[i] == '(' || expression[i] == 't' || expression[i] == 'f'){
                rest.push(expression[i]);
            }else{
                if(op.empty()) return rest.top();
                char oper = op.top();
                op.pop();
                bool ans = rest.top() == 'f' ? false : true;
                rest.pop();
                if(oper == '&'){
                    while(!rest.empty() && rest.top() != '('){
                        ans &= rest.top() == 'f' ? false : true;
                        rest.pop();
                    }
                }else if(oper == '|'){
                    while(!rest.empty() && rest.top() != '('){
                        ans |= rest.top() == 'f' ? false : true;
                        rest.pop();
                    }
                }else if(oper == '!'){
                    ans = !ans;
                }
                rest.pop();
                rest.push(ans == false ? 'f' : 't');
            }
        }
        return rest.top() == 't' ? true : false;;
    }
};
