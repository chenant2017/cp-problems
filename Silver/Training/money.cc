/*
ID: chenant1
LANG: C
TASK: money
*/

#include <stdio.h>
#define getint(i) scanf("%d", &i)

long long f[10001];

int main(void)
{
	int n, m;
	int i, j, k, t;
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	getint(n);
	getint(m);
	f[0] = 1;
	for(i = 1; i <= n; i++){
		getint(t);
		for(j = t; j <= m; j++){
			f[j] += f[j - t];
		}
	}
	printf("%lld\n", f[m]);
	return 0;
}