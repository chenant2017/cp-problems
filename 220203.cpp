#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll T;
ll M, N, K;
ll file_to[MAXN];
ll last[MAXN];
bool filed[MAXN];
ll e1, e2;
ll f1, f2;

void expand() {
    ll size = 0;
    for (ll i = e1; i <= e2; i++) {
        if (!filed[i]) size++;
    }

    if (size == K) return;

    if (e2 < N) {
        while (e2 < N && size < K) {
            e2++;
            if (f1 <= file_to[e2] && file_to[e2] <= f2) {
                filed[e2] = true;
                //cout << "filed " << e2 << " a\n";
            }
            else if (!filed[e2]) {
                size++;
            }
        }
    }

    if (size < K) {
        if (e1 >= 0) {
            while (e1 >= 0 && size < K) {
                e1--;
                if (f1 <= file_to[e1] && file_to[e1] <= f2) {
                    filed[e1] = true;
                    //cout << "filed " << e1 << " b\n";
                }
                else if (!filed[e1]) {
                    size++;
                }
            }
        }
    }   
}

bool solve() {
    for (ll i = 0; i < N; i++) {
        filed[i] = false;
    }
    for (ll i = 0; i < N; i++) {
        last[file_to[i]] = i;
    }

    f1 = 1, f2 = K;
    e1 = 0;

    while (e1 < N - K + 1) {
        if (f1 <= file_to[e1] && file_to[e1] <= f2) {
            filed[e1] = true;
            //cout << "filed " << e1 << " c\n";
            e1++;
        }
        else break;
    }
    e2 = e1;

    if (e1 == N - K + 1) return true;

    for (f1 = 1; f1 < M - K + 1; f1++) {
        //cout << f1 << " " << "f1\n";
        f2 = f1 + K - 1;

        //cout << e1 << " " << e2 << "\n";
        
        expand();

        //cout << e1 << " " << e2 << "\n";

        ll count;
        do {
            count = 0;
            for (ll i = e1; i <= e2; i++) {
                if (!filed[i] && f1 <= file_to[i] && file_to[i] <= f2) {
                    filed[i] = true;
                    //cout << "filed " << i << " d\n";
                    count++;
                }
            }

            while (e1 < N && filed[e1]) {
                e1++;
            }

            expand();
            //cout << e1 << " " << e2 << "\n";
        } while (count > 0);

        while (e2 < last[f1]) {
            e1++;
            expand();
            //cout << e1 << " " << e2 << "\n";
        }
    }

    f2++;
    //cout << f1 << " " << f2 << "f1f2\n";
    bool result = true;
    for (ll i = 0; i < N; i++) {
        //cout << (filed[i] ? 1 : 0) << " ";
        if (!filed[i] && (file_to[i] < f1 || file_to[i] > f2)) {
            result = false;
            break;
        }
    }
    //cout << "\n";

    //cout << "\n\n";
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220203";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        for (ll i = 0; i < N; i++) {
            cin >> file_to[i];
        }

        if (solve()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
	
	return 0;
}