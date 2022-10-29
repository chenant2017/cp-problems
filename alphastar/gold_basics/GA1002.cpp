#include <bits/stdc++.h>
#define f first 
#define MAXN 7510
#define s second
using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

ll N, K;
ll D[MAXN];
set<ll> visited;

int get_dist(ll a, ll b) {
    if (a > b) swap(a, b);
    return (2019201913 * a + 2019201949 * b) % 2019201997;
}

void prim(vector<ll>& result) {
    visited.insert(1);
    D[1] = 1;

    while (visited.size() < N) {
        ll mini;
        ll mind = 20192019998;
        for (ll i = 1; i <= N; i++) {
            if (D[i] != 0 && D[i] < mind) {
                mini = i;
                mind = D[i];
            }
        }

        visited.insert(mini);
        result.push_back(mind);
        if (mind == 2019201998) cout <<"hi\n";
        D[mini] = 0;

        for (ll i = 1; i <= N; i++) {
            ll dist = get_dist(i, mini);
            D[i] = min(dist, D[i]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "radio";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 1; i <= N; i++) {
        D[i] = 2019201998;
    }

    vector<ll> lengths;
    prim(lengths);

    sort(lengths.begin(), lengths.end(), greater<ll>());

    cout << lengths[K - 2] << "\n";
	
	return 0;
}