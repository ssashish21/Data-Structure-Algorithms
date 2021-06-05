#include<iostream>
#include<stack>
using namespace std;

int precedence(char op){
    if(op == '+' || op == '-'){
        return 1;
    } else if(op == '*' || op == '/'){
        return 2;
    } else {
        return 0;
    }
}

pair<string,string> infixConversion(string exp){
    stack<string> prefix;
    stack<string> postfix;
    stack<char>   ops;

    for(int i = 0 ; i < exp.size() ; i++){
        char ch = exp[i];
        if(ch == '('){  
            ops.push(ch);
        } else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            string s(1 , ch);
            prefix.push(s);
            postfix.push(s);
        } else if(ch == ')'){

            while(ops.top() != '('){
                char op = ops.top();
                ops.pop();
                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = op + prev1 + prev2;
                prefix.push(prev);

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + op;
                postfix.push(postv);
            }
            ops.pop();

        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(ops.size() > 0 && ops.top() != '(' && precedence(ops.top()) >= precedence(ch)){
                char op = ops.top();
                ops.pop();
                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = op + prev1 + prev2;
                prefix.push(prev);

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + op;
                postfix.push(postv);
            }
            ops.push(ch);
        }
    }

    //In some cases stack is not empty
    while(ops.size() != 0){
        char op = ops.top();
        ops.pop();
        string prev2 = prefix.top();
        prefix.pop();
        string prev1 = prefix.top();
        prefix.pop();
        string prev = op + prev1 + prev2;
        prefix.push(prev);

        string postv2 = postfix.top();
        postfix.pop();
        string postv1 = postfix.top();
        postfix.pop();
        string postv = postv1 + postv2 + op;
        postfix.push(postv);
    }

    return {postfix.top() , prefix.top()};
}
int main(){
    string exp;
    getline(cin , exp);

    pair<string,string> res = infixConversion(exp);

    cout << res.first << endl;
    cout << res.second << endl;
}