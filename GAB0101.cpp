#include <bits/stdc++.h>
#define MAXN 110
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll N;
ll seq[MAXN];
vector<pll> pre;
vector<pll> cur;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    pre.resize(N);
    cur.resize(N);

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        seq[i] = a;
        pre[i] = {a, 0};
    }

    for (ll i = 2; i <= N; i++) {
        for (ll j = 0; j < N - i + 1; j++) {
            ll first = seq[j];
            ll last = seq[j + i - 1];

            //cout << first << " " << last << "a\n";

            if (first + pre[j + 1].s > last + pre[j].s) {
                cur[j] = {first + pre[j + 1].s, pre[j + 1].f};
            }
            else {
                cur[j] = {last + pre[j].s, pre[j].f};
            }
            //cout << cur[j].f << " " << cur[j].s << "   ";
        }
        //cout << "\n";
        pre = cur;
    }

    cout << cur[0].f << " " << cur[0].s << "\n";
	
	return 0;
}