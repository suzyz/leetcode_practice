public class p48 {
    public void rotate(int[][] matrix) {
    	int n=matrix.length,tmp;

        for(int i=0;i<n-1;i++)
        	for(int j=i+1;j<n;j++)
        	{
        		tmp=matrix[i][j];
        		matrix[i][j]=matrix[j][i];
        		matrix[j][i]=tmp;
        	}

        for(int i=0;i<n/2;i++)
        	for(int j=0;j<n;j++)
        	{
        		tmp=matrix[j][i];
        		matrix[j][i]=matrix[j][n-1-i];
        		matrix[j][n-1-i]=tmp;
        	}
    }
}
