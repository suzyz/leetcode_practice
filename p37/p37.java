public class p37 {
	public static void solveSudoku(char[][] board)
	{
		mySolve(board);
	}
	public static boolean mySolve(char[][] board)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				if(board[i][j]=='.')
				{
					for(char k='1';k<='9';k++)
						if(isAvailable(board,i,j,k))
						{
							board[i][j]=k;
							if(mySolve(board)) return true;
							else board[i][j]='.';
						}

					return false;
				}

		return true;
	}

	public static boolean isAvailable(char[][] board,int x,int y,char cur)
	{
		for(int i=0;i<9;i++)
		{
			if(board[x][i]!='.' && board[x][i]==cur) return false;
			if(board[i][y]!='.' && board[i][y]==cur) return false;

			if(board[(x/3)*3+i/3][(y/3)*3+i%3]!='.' && board[(x/3)*3+i/3][(y/3)*3+i%3]==cur)
					return false;			
		}

		return true;
	}












	public static boolean mySolve2(char[][] board,boolean[][] nrow,boolean[][] ncol,boolean[][] ngrid)
	{
	    for(int i=0;i<9;i++)
	        for(int j=0;j<9;j++)
	        	if(board[i][j]=='.')
	        	{
	        		int grid=(i/3)*3+j/3;
	         		for(int k=1;k<=9;k++)
	        		{
	        			if(nrow[i][k] || ncol[j][k] || ngrid[grid][k]) continue;
	        			board[i][j]=(char)(k+'0');
	        			nrow[i][k]=ncol[j][k]=ngrid[grid][k]=true;

	        			if(mySolve2(board,nrow,ncol,ngrid))
	        				return true;
	        			else
	        			{
	        				board[i][j]='.'; /* This is necessary. 
	        									If there is no suitable k found,
	        									the procedure would return false and,
	        									leave the board[i][j] as the last k tried. */
	        				nrow[i][k]=ncol[j][k]=ngrid[grid][k]=false;
	        			}
	        			
	        		}
	        		return false;
	        	}

	    return true;
	}

    public static void solveSudoku2(char[][] board) {
    	boolean[][] nrow=new boolean[10][10];
    	boolean[][] ncol=new boolean[10][10];
    	boolean[][] ngrid=new boolean[10][10];

    	for(int i=0;i<9;i++)
        	for(int j=0;j<9;j++)
        		if(board[i][j]!='.')
	        	{
	        		int tmp=board[i][j]-'0';
	        		nrow[i][tmp]=ncol[j][tmp]=ngrid[(i/3)*3+j/3][tmp]=true;
	        	}

        boolean ans=mySolve2(board,nrow,ncol,ngrid);
    	System.out.println("ans:"+ans);
    }

    public static void main(String[] args) {

    	char[][] board=new char[9][9];
    	for(int i=0;i<9;i++)
        	for(int j=0;j<9;j++) board[i][j]='.';

    	board[0][2]='9';board[0][3]='7';board[0][4]='4'; board[0][5]='8';
    	board[1][0]='7';
    	board[2][1]='2';board[2][3]='1';board[2][5]='9';
    	board[3][2]='7';board[3][6]='2';board[3][7]='4';
    	board[4][1]='6';board[4][2]='4';board[4][4]='1';board[4][6]='5';board[4][7]='9';
    	board[5][1]='9';board[5][2]='8';board[5][6]='3';
    	board[6][3]='8';board[6][5]='3';board[6][7]='2';
    	board[7][8]='6';
    	board[8][3]='2';board[8][4]='7';board[8][5]='5';board[8][6]='9';

    	solveSudoku2(board);

    	for(int i=0;i<9;i++)
    	{
        	for(int j=0;j<9;j++)
        		System.out.printf("%c ",board[i][j]);
        	System.out.printf("\n");
    	}
    }
}
