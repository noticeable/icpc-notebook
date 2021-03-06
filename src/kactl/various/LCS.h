/**
 * Name: Longest common subsequence
 * Author: Håkan Terelius
 * Date: 2010-11-07
 * License: CC0
 * Description: Finds the longest common subsequence.
 * Status: Tested on hackerrank, the longest common subsequence
 * Time: $O(NM)$, where $N$ and $M$ are the lengths of the sequences.
 * Memory: $O(NM)$.
 */
#pragma once

template <class T> T lcs(const T &X, const T &Y) {
	int a = X.size(), b = Y.size();
	vector<vector<int>> dp(a+1, vector<int>(b+1));
	rep(i,1,a+1) rep(j,1,b+1)
		dp[i][j] = X[i-1]==Y[j-1] ? dp[i-1][j-1]+1 :
			max(dp[i][j-1],dp[i-1][j]);
	int len = dp[a][b];
	T ans(len,0);
	while(a && b)
		if(X[a-1]==Y[b-1]) ans[--len] = X[--a], --b;
		else if(dp[a][b-1]>dp[a-1][b]) --b;
		else --a;
	return ans;
}
