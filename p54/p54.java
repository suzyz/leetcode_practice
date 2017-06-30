import java.util.*;

public class p54 {
    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer>();
        int rowBegin=0,rowEnd=matrix.length-1;
        if(rowEnd<0) return ans;
        
        int colBegin=0,colEnd=matrix[0].length-1;

        while(rowBegin<=rowEnd && colBegin<=colEnd)
        {
        	for(int i=colBegin;i<=colEnd;i++)
        		ans.add(matrix[rowBegin][i]);
        	
        	for(int i=rowBegin+1;i<=rowEnd;i++)
        		ans.add(matrix[i][colEnd]);

        	if(rowBegin<rowEnd)
        		for(int i=colEnd-1;i>=colBegin;i--)
        			ans.add(matrix[rowEnd][i]);

        	if(colBegin<colEnd)
        		for(int i=rowEnd-1;i>=rowBegin+1;i--)
        			ans.add(matrix[i][colBegin]);

       		rowBegin++; rowEnd--;
       		colBegin++; colEnd--;
        }
        return ans;
    }
    public static void main(String[] args) {
    	int[][] matrix = new int[3][1];
    	matrix[0][0]=2;
    	matrix[1][0]=3;
    	matrix[2][0]=4;
    	List<Integer> ans=spiralOrder(matrix);
    	for(int i=0;i<ans.size();i++) System.out.println(ans.get(i));
    }
}
