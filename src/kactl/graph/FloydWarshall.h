/**
 * Name: Floyd--Warshall
 * Author: Simon Lindholm
 * Date: 2016-12-15
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
 * Description: Calculates all-pairs shortest path in a directed graph that might have negative edge distances.
 *  Input is an distance matrix $m$, where $m[i][j] = inf$ if $i$ and $j$ are not adjacent.
 *  As output, $m[i][j]$ is set to the shortest distance between $i$ and $j$,
 *  $inf$ if no path, or $-inf$ if the path goes through a negative-weight cycle.
 * Time: $O(N^3)$
 * Status: slightly tested
 */
#pragma once

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = m.size();
	rep(i,0,n) m[i][i] = min(m[i][i], {});
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}
