#include	<iostream>
#include	<vector>
#include	<stack>

using	namespace	std;

int	main()	{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	n;
	cin	>>	n;
	vector<int>v(n,	0);
	for	(int	i	=	0;i	<	n;i++)cin	>>	v[i];
	
	vector<int>dp(n,	1);
	vector<int>prv(n,	-1);

	for	(int	i	=	0;i	<	n;i++)	{
		for	(int	j	=	0;j	<	i;j++)	{
			if	(v[j]	>=	v[i])	continue;
			if	(dp[j]	+	1	<=	dp[i])	continue;
			
			dp[i]	=	dp[j]	+	1;
			prv[i]	=	j;
		}
	}


	int	idx	=	0;
	for	(int	i	=	0;i	<	n;i++)	{
		if	(dp[i]	<=	dp[idx])	continue;
		idx	=	i;
	}


	stack	<int>	stk;
	while	(idx	>=	0)	{
		stk.push(v[idx]);
		idx	=	prv[idx];
	}

	cout	<<	stk.size()	<<	'\n';
	while	(!stk.empty())	{
		cout	<<	stk.top()	<<	'	';
		stk.pop();
	}
}