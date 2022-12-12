//Silver 2021 December #1

#include <bits/stdc++.h>
#define MAX 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll K, M, N;
pll patches[MAX];
ll nhoj[MAX];
priority_queue<ll> tasties;

ll get_max_intersect(ll nhoj1, ll nhoj2, ll patch1, ll patch2) {
    vector<pll> endpoints;
    for (ll p = patch1; p <= patch2; p++) {
        ll r1 = patches[p].f - nhoj[nhoj1];
        ll r2 = nhoj[nhoj2] - patches[p].f;
        
        endpoints.push_back(pll({patches[p].f - min(r1, r2), patches[p].s}));
        endpoints.push_back(pll({patches[p].f + min(r1, r2), -patches[p].s}));
    }

    ll result = 0;
    ll sum = 0;
    sort(endpoints.begin(), endpoints.end());
    for (auto i: endpoints) {
        sum += i.s;
        result = max(sum, result);
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "closest";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> K >> M >> N;

    for (ll i = 0; i < K; i++) {
        cin >> patches[i].f >> patches[i].s; 
    }

    for (ll i = 0; i < M; i++) {
        cin >> nhoj[i];
    }

    sort(patches, patches + K);
    sort(nhoj, nhoj + M);

    ll j = 0;

    for (ll i = 0; i < M; i++) { //nhoj
        if (j >= K) break;
        if (nhoj[i] < patches[j].f) continue;

        ll j2 = j;
        ll total = 0;
        while (j2 < K && patches[j2].f < nhoj[i]) {
            total += patches[j2].s;
            j2++;
        }

        //cout << "cows " << i - 1 << " " << i << " patches " << j << " " << j2 << "\n";
        if (i == 0) {
            tasties.push(total);
            //cout << "total " << total << "\n";
        }
        else {
            ll max_intersect = get_max_intersect(i - 1, i, j, j2 - 1);
            tasties.push(max_intersect);
            tasties.push(total - max_intersect);
        }
        j = j2; //out of range
    }

    //MUST ADD RIGHTMOST PART OF PATCHES
    ll tasty = 0;
    //cout << j << " j\n";
    while (j < K) {
        tasty += patches[j].s; 
        j++;
    }
    //cout << tasty << "asdf\n";
    tasties.push(tasty);

    ll taken = 0;
    ll ans = 0;
    while (!tasties.empty() && taken < N) { 
        ans += tasties.top();
        //cout << tasties.top() << "\n";
        tasties.pop();
        taken++;
    }
    cout << ans << "\n";
	
	return 0;
}