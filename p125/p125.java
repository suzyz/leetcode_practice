public class p125 {
	public boolean isValid(char c)
	{
		if(c>='a' && c<='z') return true;
		if(c>='A' && c<='Z') return true;
		if(c>='0' && c<='9') return true;
		return false;
	}
	public boolean isSame(char a,char b)
	{
		if(a>='0' && a<='0') return a==b;
		if(a<='Z') a+=32;
		if(b<='Z') b+=32;
		return a==b;
	}
    public boolean isPalindrome(String s) {
        int n=s.length();
        int head=0,tail=n-1;
        while(head<tail)
        {
        	while(!isValid(s.charAt(head)) && head<tail) head++;
        	while(!isValid(s.charAt(tail)) && head<tail) tail--;
        	if(!isSame(s.charAt(head),s.charAt(tail))) return false;
        	head++;
        	tail--;
        }
        return true;
    }
}