class Solution {
public:
    string reverseWords(string s) {
        string str="";
        stack<string> st;
        s+=' ';

        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(str.size()!=0){
                    st.push(str);
                    str="";
                }
            }
            else{
                str+=s[i];
            }
        }

        while(st.size()){
            str+=st.top();
            st.pop();
            if(st.size())
                str+=' ';
        }

        return str;
    }
};