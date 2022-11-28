//2018 December Silver #2

#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

typedef long long ll;

struct Cow {
    ll a, t, seniority;
};

bool cmp(Cow& a, Cow& b) {
    return a.seniority < b.seniority;
}

Cow cows[MAXN];
ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convention2";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
    for (ll i = 0; i < N; i++) {
        Cow c;
        cin >> c.a >> c.t;
        c.seniority = -i;
        cows[i] = c;
    }

    sort(cows, cows + N, [](auto& c, auto& d) {
        return c.a < d.a;
    });

    ll time = cows[0].a;
    ll ci = 0;

    priority_queue<Cow, vector<Cow>, decltype(&cmp)> pq(cmp); 

    while (ci < N && cows[ci].a == time) {
        pq.push(cows[ci]);
        ci++;
    }

    ll ans = 0;

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        ll wait = time - curr.a;

        ans = max(wait, ans);

        time += curr.t;
        //cout << time << " " << ci << " " << N << "\n";

        while (ci < N && cows[ci].a <= time) {
            pq.push(cows[ci]);
            ci++;
        }
    }

    cout << ans << "\n";

	return 0;
}