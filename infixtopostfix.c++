#include <bits/stdc++.h>
using namespace std;

map<char, int> precedence;
void makePrecedenceMap();
string intopost(string infix){
    string postfix;
    stack<char>st;

    for(char c: infix){
        if(c>='0' and c<='9'){
            postfix.push_back(c);
        }
        else{
            
            if(c=='(' or st.empty()){
                st.push(c);
                continue;
            }
            if(c==')'){
                while(st.top()!='('){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
                continue;
            }
            
            if(precedence[c]<=precedence[st.top()]){
                while(precedence[c]<=precedence[st.top()]){
                    postfix.push_back(st.top());
                    cout<<st.top()<<endl;
                    st.pop();
                    if(st.empty())  break;
                }
            }
            st.push(c);
            //cout<<postfix<<endl;
            
        }
        
    }

    while(!st.empty()){
        
        postfix.push_back(st.top());
        st.pop();
    }
    
    return postfix;
}

int main(){

    makePrecedenceMap();
    string input;
    cin>>input;
    string ans = intopost(input);
    cout<<ans<<endl;

}

void makePrecedenceMap(){
    char arr[] ={'+', '-', '*', '/', '^'};
    precedence.insert({arr[0], 1});
    precedence.insert({arr[1], 1});
    precedence.insert({arr[2], 2});
    precedence.insert({arr[3], 2});
    precedence.insert({arr[4], 3});
}