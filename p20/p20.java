public class Solution {
    public boolean isValid(String s) {
        int top=0;
        char[] stack = new char[s.length()+1];
        for(int i=0;i<s.length();i++)
        {
            switch(s.charAt(i))
            {
                case '(': stack[top]='('; top++;  break;
                case '[': stack[top]='['; top++; break;
                case '{': stack[top]='{'; top++; break;
                case ')': 
                    if(top==0 || stack[top-1]!='(') return false;
                    top--; break;
                case ']':
                    if(top==0 || stack[top-1]!='[') return false;
                    top--; break;
                case '}':
                    if(top==0 || stack[top-1]!='{') return false;
                    top--; break;
            }
        }
        if(top==0) return true;
        else return false;
    }
}