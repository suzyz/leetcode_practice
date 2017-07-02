public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int [n][n];
        int colBegin=0,colEnd=n-1,rowBegin=0,rowEnd=n-1,num=1;
        while(colBegin<=colEnd && rowBegin<=rowEnd)
        {
        	for(int i=colBegin;i<=colEnd;i++)
        	{
        		ans[rowBegin][i]=num;
        		num++;
        	}
        	if(colBegin==colEnd) break;

        	for(int i=rowBegin+1;i<=rowEnd;i++)
        	{
        		ans[i][colEnd]=num;
        		num++;
        	}
        	
        	for(int i=colEnd-1;i>=colBegin;i--)
        	{
        		ans[rowEnd][i]=num;
        		num++;
        	}

        	for(int i=rowEnd-1;i>rowBegin;i--)
        	{
        		ans[i][colBegin]=num;
        		num++;
        	}

        	colBegin++; colEnd--;
        	rowBegin++; rowEnd--;
        }
        return ans;
    }
}
