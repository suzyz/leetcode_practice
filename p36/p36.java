public class p36 {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            	if(board[i][j]=='.' || (board[i][j]>='0' && board[i][j]<='9'))
            		continue;
            	else
            		return false;

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<8;j++)
 			{
            	if(board[i][j]!='.')
            		for(int k=j+1;k<9;k++)
            			if(board[i][j]==board[i][k])
            				return false;

            	if(board[j][i]!='.')
            		for(int k=j+1;k<9;k++)
            			if(board[j][i]==board[k][i])
            				return false;
 			}
        }
        for(int i=0;i<9;i+=3)
        	for(int j=0;j<9;j+=3)
        	{
        		boolean[] used=new boolean[10];
        		for(int k=0;k<3;k++)
        			for(int p=0;p<3;p++)
        			if(board[i+k][j+p]!='.')
        			{
        				if(used[board[i+k][j+p]-'0']) return false;
        				used[board[i+k][j+p]-'0']=true;
        			}
        	}

        return true;
    }
}