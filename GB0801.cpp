#include <bits/stdc++.h>
#define MAXN 25010
using namespace std;

typedef long long ll;

ll M[MAXN];
ll B[MAXN];

ll N, X, Y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0801";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> X >> Y;

    for (ll i = 0; i < N; i++) {
        cin >> M[i];
        cin >> B[i];
    }

    sort(M, M + N);
    sort(B, B + N);

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (M[i] > B[i]) {
            ans += Y * (M[i] - B[i]);
        }
        else {
            ans += X * (B[i] - M[i]);
        }
    }

    cout << ans << "\n";
	
	return 0;
}