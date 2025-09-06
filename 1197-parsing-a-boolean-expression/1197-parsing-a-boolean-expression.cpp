class Solution {
public:
    bool parseBoolExpr(string e) {
        if(e.length()==1){
            if(e[0]=='f'){
                return 0;
            }
            else{
                return 1;
            }
        }
        stack<char>s;
        stack<char>s1;
        char curr=e[0];
        for(char i:e){
            if(i==')'){
                char temp=s1.top();
                s1.pop();
                bool ans=0;
                
                if(s.top()=='f'){
                    ans=0;
                }
                else{
                    ans=1;
                }
                s.pop();
                
                
                if(temp=='|'){
                    while(s.top()!='('){
                        char t=s.top();
                        s.pop();
                        if(t=='t'){
                            ans=1;
                        }
                    }
                }
                else if(temp=='&'){
                    while(s.top()!='('){
                        char t=s.top();
                        s.pop();
                        if(t=='f'){
                            ans=0;
                        }
                    }
                }
                else{
                    ans=!(ans);
                }
                s.pop();
                if(ans){
                    s.push('t');
                }
                else{
                    s.push('f');
                }

            }
            else if(i=='(' || i=='t' || i=='f'){
                s.push(i);
            }
            else if(i!=','){
                s1.push(i);
            }
        }
        if(s.top()=='t'){
            return true;
        }
        return false;
    }
};