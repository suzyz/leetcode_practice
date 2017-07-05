public class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[] col = new boolean[n];

        boolean flag;
        for(int i=0;i<m;i++)
        {
        	flag=false;
            for(int j=0;j<n;j++)
	            if(matrix[i][j]==0)	       
	            	col[j]=flag=true;

      		if(flag) for(int k=0;k<n;k++) matrix[i][k]=0;
        }

       	for(int j=0;j<n;j++)
       		if(col[j])
       			for(int i=0;i<m;i++)
       				matrix[i][j]=0;
    }
}