#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll intervals[MAXN];
ll N;
ll ans[MAXN] = {0};

void solve(ll i, ll right, ll complexity) {
    if (i == N) {
        ans[complexity]++; 
        return;
    }
    //taking
    if (intervals[i].f > right) {
        solve(i + 1, intervals[i].s, complexity + 1);
    }
    else { 
        solve(i + 1, max(right, intervals[i].s), complexity);
    }

    //not taking
    solve(i + 1, right, complexity);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "intervals";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> intervals[i].f >> intervals[i].s;
    }

    sort(intervals, intervals + N);

    solve(0, 0, 0);

    ll sum = 0;
    for (ll i = 1; i <= N; i++) {
        //cout << ans[i] << " ";
        sum += i * ans[i];
    }
    //cout << "\n";

    cout << sum << "\n";
	
	return 0;
}