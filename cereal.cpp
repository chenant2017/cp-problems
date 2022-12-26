#include <bits/stdc++.h>
#define MAX 100010
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll choices[MAX]; // of each cow
vector<ll> chosen[MAX]; // by which cows
ll ptr[MAX] = {0};

bool give(ll cow, ll cereal) { // was cereal successfully given?

    ptr[cereal]++;

    while (ptr[cereal] < chosen[cereal].size() - 1) {
        ll cow2 = chosen[cereal][ptr[cereal]];
        ll choice1, choice2;
        tie(choice1, choice2) = choices[cow2];

        if (choice1 == cereal) {
            if (chosen[choice2][ptr[choice2]] == cow2) {
                return give(cow2, choice2);
            }
            else {
                return true;
            }
        }
        else {
            if (chosen[choice1][ptr[choice1]] == cow2) {
                ptr[cereal]++;
            }
            else {
                return true;
            }
        }
    }
    if (ptr[cereal] == chosen[cereal].size() - 1) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cereal";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= M; i++) {
        chosen[i].push_back(-1);
    }

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        choices[i] = {a, b};
        chosen[a].push_back(i);
        chosen[b].push_back(i);
    }

    for (ll i = 1; i <= M; i++) {
        chosen[i].push_back(-1);
    }
    
    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ll choice1, choice2;
        tie(choice1, choice2) = choices[i];
        if (ptr[choice1] == 0) {
            while (chosen[choice1][ptr[choice1]] != i) {
                ptr[choice1]++;
            }
            ans++;
        }
        else {
            if (ptr[choice2] == 0) {
                while (chosen[choice2][ptr[choice2]] != i) {
                    ptr[choice2]++;
                }
                ans++;
            }
        }
    }

    cout << ans << "\n";

    for (ll i = 0; i < N - 1; i++) {
        //cout << i << " i\n";
        if (!give(i, choices[i].f)) {
            ans--;
        }
        cout << ans << "\n";
    }
	
	return 0;
}