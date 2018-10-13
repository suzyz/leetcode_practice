class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        if (n < 2)
        	return dominoes;

        int i = 0;
        while (i < n && dominoes[i] == '.')
        	++i;

       	if (i >= n)
       		return dominoes;

       	if (dominoes[i] == 'L')
       		for (int t = 0; t < i; ++t)
       			dominoes[t] = 'L';

       	while (i < n)
       	{
       		int j = i+1;
       		while (j < n && dominoes[j] == '.')
       			++j;

       		if (j >= n)
       		{
       			if (dominoes[i] == 'R')
       				for (int t = i+1; t < n; ++t)
       					dominoes[t] = 'R';
       			break;
       		}

       		if (dominoes[j] == dominoes[i])
       		{
       			for (int t = i+1; t < j; ++t)
	       			dominoes[t] = dominoes[i];
       		} else
       			if (dominoes[i] == 'R')
       			{
       				int p = i+1, q = j-1;
       				while (p < q)
       				{
       					dominoes[p] = 'R';
       					dominoes[q] = 'L';
       					++p;
       					--q;
       				}
       			}

       		i = j;
       	}
       	
       	return dominoes;
    }
};