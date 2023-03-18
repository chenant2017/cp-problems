#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
#define f first 
#define s second
typedef long long ll;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;

ll N;
plc cows[MAX];
vector<pll> intervals;
stack<pll> combined;

void get_intervals() {
    ll start = 0;
    ll prefix = 0;

    for (ll i = 0; i < N; i++) {
        if (cows[i].s == 'W') {
            prefix++;
        }
        else {
            prefix--;
        }

        if (prefix < 0) {
            prefix = 0;
            
            if (i - start > 0 && (i - start) % 2 == 0) {
                intervals.push_back({start, i});
                start = i;
            }
        }
    }

    if ((N - start) % 2 == 0) {
        intervals.push_back({start, N});
    }
    else {
        intervals.push_back({start, N - 1});
    }


    ll start = N - 1;
    ll prefix = N - 1;

    for (ll i = N - 1; i >= 0; i--) {
        if (cows[i].s == 'W') {
            prefix++;
        }
        else {
            prefix--;
        }

        if (prefix < 0) {
            prefix = 0;
            
            if (start - i > 0 && (start - i) % 2 == 0) {
                intervals.push_back({i, start});
                start = i;
            }
        }
    }


    if ((start + 1) % 2 == 0) {
        intervals.push_back({-1, start});
    }
    else {
        intervals.push_back({0, start});
    }
}

void get_combined() {
    sort(intervals.begin(), intervals.end());

    combined.push(intervals[0]);


    for (ll i = 1; i < intervals.size(); i++) {
        pll t = combined.top();

        if (t.s < intervals[i].f) {
            combined.push(intervals[i]);
        }
        else if (t.s < intervals[i].s) {
            t.s = intervals[i].s;
            combined.pop();
            combined.push(t);
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0702";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x; char c;
        cin >> x >> c;

        cows[i] = {x, c};
    }

    sort(cows, cows + N);

    get_intervals();

    get_combined();

    ll ans = 0;

    while (!combined.empty()) {
        pll t = combined.top();
        combined.pop();

        //cout << t.f << " " << t.s << " a\n";

        ans = max(ans, cows[t.s - 1].f - cows[t.f].f);
    }

    cout << ans << "\n";
	
	return 0;
}