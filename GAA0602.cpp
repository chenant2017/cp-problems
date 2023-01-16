#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N;
ll colors[MAX];
ll state[MAX];
ll layers[MAX];
ll last[MAX];

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAA0602";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> colors[i];
        last[colors[i]] = i;
    }

    ll la = 0;
    bool works = true;
    stack<ll> s;

    for (ll i = 1; i <= N; i++) {
        if (colors[i] == 0) {
            while (!s.empty()) {
                state[s.top()]++;
                assert(state[s.top()] == 2);
                //cout << "pop " << s.top() << "\n";
                s.pop();
            }
            la = 0;
            layers[i] = la;
        }
        else {
            if (state[colors[i]] == 0) {
                //cout << "push " << colors[i] << " " << i << "\n";
                s.push(colors[i]);
                state[colors[i]]++;
                //cout << state[s.top()] << " as\n";
                assert(state[s.top()] == 1);
                la++;
                layers[i] = la;

                if (last[colors[i]] == i) {
                    state[s.top()]++;
                    //cout << "pop " << s.top() << "\n";
                    s.pop();
                    la--;
                }
            }
            else if (state[colors[i]] == 1) {
                while (s.top() != colors[i]) {
                    state[s.top()]++;
                    //cout << state[s.top()] << " asdf\n";
                    assert(state[s.top()] == 2);
                    //cout << "pop " << s.top() << "\n";
                    s.pop();
                    la--;
                }

                layers[i] = la;

                if (last[colors[i]] == i) {
                    state[s.top()]++;
                    //cout << "pop " << s.top() << "\n";
                    s.pop();
                    la--;
                }
            }
            else {
                works = false;
                break;
            }
        }
        //cout << layers[i] << "\n";
    }

    if (works) {
        cout << *max_element(layers + 1, layers + N + 1) << "\n";
    }
    else {
        cout << "-1\n";
    }
	
	return 0;
}