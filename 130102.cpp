#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll intervals[MAX];
vector<pll> v;

ll one() {
    ll result = 0;

    set<ll> active;
    ll pre = -1e18;
    for (auto i: v) {
        if (active.size() == 1) {
            if (i.f != pre) {
                result += i.f - pre;
            }   
        }

        if (active.find(i.s) == active.end()) {
            active.insert(i.s);
        }
        else {
            active.erase(i.s);
        }

        pre = i.f;
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "paint";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    ll minx = 0, maxx = 0;
    ll pos = 0;

    for (ll i = 0; i < N; i++) {
        ll a; char d;
        cin >> a >> d;

        if (d == 'L') {
            intervals[i] = {pos - a, pos};
            pos -= a;
        }
        else {
            intervals[i] = {pos, pos + a};
            pos += a;
        }

        minx = min(minx, pos);
        maxx = max(maxx, pos);

        //cout << intervals[i].f << " " << intervals[i].s << "\n";
    }

    sort(intervals, intervals + N);

    for (ll i = 0; i < N; i++) {
        v.push_back({intervals[i].f, i});
        v.push_back({intervals[i].s, i});
    }
    sort(v.begin(), v.end());

    cout << maxx - minx - one() << "\n";
	
	return 0;
}