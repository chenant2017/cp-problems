#include <bits/stdc++.h>
#define MAXN 2010

using namespace std;

typedef long long ll;

ll N, A, B;
ll pos[MAXN];

double dp[MAXN];
ll start[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0401";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> A >> B;

    for (ll i = 0; i < N; i++) {
        cin >> pos[i];
    }

    sort(pos, pos + N);

    dp[0] = A;
    start[0] = pos[0];

    for (ll i = 1; i < N; i++) {
        double poss1 = A;
        double r1 = ((double) start[i - 1] + pos[i - 1]) / 2;
        double r2 = ((double) start[i - 1] + pos[i]) / 2;
        double poss2 = B * (r2 - r1);

        if (poss1 < poss2) {
            dp[i] = poss1;
            start[i] = pos[i];
        }
        else {
            dp[i] = poss2;
            start[i] = start[i - 1];
        }

        dp[i] += dp[i - 1];
    }

    cout << (ll) dp[N - 1];

    if (dp[N - 1] > (ll) dp[N - 1]) {
        cout << ".5";
    }

    cout << "\n";

	
	return 0;
}