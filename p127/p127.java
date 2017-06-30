import java.util.*;

public class p127 {

	public static int mybfs(String beginWord, String endWord, List<String> wordList)
	{
		if(wordList.contains(endWord)==false) return 0;

		int n = beginWord.length();
		Queue<String> q = new LinkedList<String>();
		Set<String> used = new HashSet<String>();
		Set<String> dict = new HashSet<String>();

		for(int i=0;i<wordList.size();i++)
			dict.add(wordList.get(i));

		int dist=0;
		q.offer(beginWord);

		while(q.size()>0)
		{
			int now = q.size();
			for(int j=0;j<now;j++)
			{
				String head=q.poll();
				if(head==null) return 0;

				char[] tmp=head.toCharArray();
				for(int i=0;i<n;i++)
				{
					char k=tmp[i];
					for(char c='a';c<='z';c++)
						if(c!=k)
						{
							tmp[i]=c;
							String tmp2 = String.valueOf(tmp);
							if(tmp2.equals(endWord)) return dist+2;

							if(dict.contains(tmp2))
							{
								if(!used.contains(tmp2))
								{
									used.add(tmp2);
									q.offer(tmp2);
								}
							}
						}

					tmp[i]=k;
				}
			}
			
			dist++;
		}
		
		return 0;
	}

	public static boolean convertible(String a,String b)
	{
		int t=0;
		for(int i=0;i<a.length();i++)
			if(a.charAt(i)!=b.charAt(i))
			{
				t++;
				if(t>1) return false;
			}
		if(t==1) return true;
		else return false;
	}

    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int n = wordList.size(),goal=-1;
        int[] dist = new int[n+2];
        boolean[][] conv = new boolean[n+2][n+2];

        for(int i=0;i<n;i++)
        	if(wordList.get(i).equals(endWord))
        		{ goal=i; break;}

        if(goal==-1) return 0;

        boolean[] used = new boolean[n+2];

        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        		if(j!=i)
	        		if(convertible(wordList.get(i),wordList.get(j)))
	        			conv[i][j]=conv[j][i]=true;

        	if(convertible(wordList.get(i),beginWord))
        		dist[i]=1;
        	else
        		dist[i]=-1;
        	
        	used[i]=false;
        }

        //dijkstra

        used[n]=true;
        for(int i=0;i<=n;i++)
        {
        	int mind=Integer.MAX_VALUE;
        	int best=-1;
        	for(int j=0;j<n;j++)
        		if((!used[j]) && dist[j]!=-1 && dist[j]<mind)
        		{
        			best=j;
        			mind=dist[j];
        		}

        	if(best<0) break;
        	used[best]=true;

        	for(int j=0;j<n;j++)
        		if((!used[j]) && conv[best][j])
        		{
        			if(dist[j]==-1 || dist[j]>dist[best]+1)
        				dist[j]=dist[best]+1;
        		}
        }

        if(dist[goal]<0) return 0;
        else return dist[goal]+1;
    }
    public static int floyd(String beginWord, String endWord, List<String> wordList) {
        int n = wordList.size(),goal=-1;
        int[][] dist = new int[n+1][n+1];

        for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++)
        		for(int k=0;k<n;k++)
        			dist[i][j]=-1;

        for(int i=0;i<n;i++)
        	if(wordList.get(i).equals(endWord))
        		{ goal=i; break;}

        if(goal==-1) return 0;

        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        		if(j!=i)
	        		if(convertible(wordList.get(i),wordList.get(j)))
	        			dist[i][j]=dist[j][i]=1;
	        		else
	        			dist[i][j]=dist[j][i]=-1;

        	if(convertible(wordList.get(i),beginWord))
        	{
        		dist[i][n]=dist[n][i]=1;
        	}
        	else
        		dist[i][n]=dist[n][i]=-1;
        }

        for(int i=0;i<=n;i++)
        	for(int j=0;j<=n;j++)
        		if(j!=i && dist[i][j]!=-1)
        			for(int k=0;k<=n;k++)
        				if(k!=i && k!=j && dist[j][k]!=-1)
        					if(dist[i][k]==-1 || dist[i][k]>dist[i][j]+dist[j][k])
        						dist[i][k]=dist[i][j]+dist[j][k];

        return dist[n][goal];
    }

    public static void main(String[] args) {
    	
    	List<String> l = new ArrayList<String>(Arrays.asList(
"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"));
    	String s1 = "cet";
    	String s2 = "ism";
    	/*
    	List<String> l = new ArrayList<String>(Arrays.asList("hot","dot","dog","lot","log","cog"));
    	String s1="hit";
    	String s2="cog";*/
    	System.out.println("ans:"+ladderLength(s1,s2,l));
    	System.out.println("ans2:"+floyd(s1,s2,l));
    	System.out.println("ans3:"+mybfs(s1,s2,l));
    }
}