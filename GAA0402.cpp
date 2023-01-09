#include <bits/stdc++.h>
#define MAXN 75
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppll;

ll N, A, B;
string farm[MAXN];
ll shortest[MAXN][MAXN];
ll di[] = {0, 0, -1, 1};
ll dj[] = {1, -1, 0, 0};

ll dist(ll a1, ll b1, ll a2, ll b2) {
    if (farm[a1][b1] == farm[a2][b2]) {
        return A;
    }
    else {
        return B;
    }
}

ll test(ll a, ll b) {
    fill(shortest[0], shortest[0] + MAXN * MAXN, (ll)1e15);

    priority_queue<ppll> pq;
    shortest[a][b] = 0;
    pq.push({0, {a, b}});

    while (!pq.empty()) {
        auto curr = pq.top();
        ll i, j;
        tie(i, j) = curr.s;
        pq.pop();

        for (ll d = 0; d < 4; d++) {
            ll ni = i + di[d];
            ll nj = j + dj[d];

            if (ni >= 0 && ni < N &&
                nj >= 0 && nj < N) {
                if (shortest[ni][nj] > shortest[i][j] + dist(i, j, ni, nj)) {
                    shortest[ni][nj] = shortest[i][j] + dist(i, j, ni, nj);
                    pq.push({shortest[ni][nj], {ni, nj}});
                }
            }
        }
    }

    ll result = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            result = max(result, shortest[i][j]);
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0402";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> A >> B;

    for (ll i = 0; i < N; i++) {
        cin >> farm[i];
    }

    ll ans = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ans = max(ans, test(i, j));
        }
    }

    cout << ans << "\n";
	
	return 0;
}