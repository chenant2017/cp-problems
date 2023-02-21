#include <bits/stdc++.h>
#define MAX 5010
using namespace std;

typedef long long ll;

ll N, M;
ll A[MAX];
ll B[MAX];
ll ans[MAX * 2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "211203";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        A[a]++;
        B[b]++;
    }

    for (ll i = 0; i <= M; i++) {
        for (ll j = 0; j <= M; j++) {
            ans[i + j] += A[i] * A[j];
            ans[i + j + 1] -= B[i] * B[j];
        }
    }

    for (ll i = 1; i <= 2 * M; i++) {
        ans[i] += ans[i - 1];
    }

    for (ll i = 0; i <= 2 * M; i++) {
        cout << ans[i] << "\n";
    }
	
	return 0;
}