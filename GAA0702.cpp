#include <bits/stdc++.h>
#define MAX 50010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;

struct Square {
    ll cx, cy;
    ll x1, x2, y1, y2;

    Square(ll x, ll y) {
        cx = x;
        cy = y;
        x1 = x - K / 2;
        x2 = x + K / 2;
        y1 = y - K / 2;
        y2 = y + K / 2;
    }

    Square():Square(0, 0){}
};

Square squares[MAX];
vector<pll> xs;
set<ll> activex;
set<pll> ys;
ll ans = 0;
pll ans_sq;

void update(ll x) {
    //cout << "update " << x << "\n";

    set<ll> activey;

    for (auto i: ys) {
        ll y, j;
        tie(y, j) = i;

        if (activey.find(j) == activey.end()) {
            activey.insert(j);
            //cout << j << " y\n";
            if (activey.size() > 2) {
                //cout << "ans -1\n";
                ans = -1;
                return;
            }
        }
        else {
            activey.erase(j);
            //cout << "-" << j << " y\n";
            if (activey.size() == 1) {
                ll ayb = *activey.begin();

                ll height = squares[j].y2 - squares[ayb].y1;
                ll width = min(squares[j].x2, squares[ayb].x2) - x;

                if (height * width != 0) {
                    if (ans == 0) {
                        ans = height * width;
                        ans_sq = {min(j, ayb), max(j, ayb)};
                        //cout << "ans " << ans << "\n";
                    }
                    else {
                        if (pll({min(j, ayb), max(j, ayb)}) != ans_sq) {
                            ans = -1;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0702";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        Square sq = Square(x, y);
        squares[i] = sq;

        xs.push_back({sq.x1, i});
        xs.push_back({sq.x2, i});
    }

    sort(xs.begin(), xs.end());

    for (ll i = 0; i < xs.size(); i++) {
        ll x, j;
        tie(x, j) = xs[i];

        if (activex.find(j) == activex.end()) {
            activex.insert(j);
            ys.insert({squares[j].y1, j});
            ys.insert({squares[j].y2, j});
            //cout << j << " x\n";
            update(x);
        }
        else {
            //cout << "-" << j << " x\n";
            activex.erase(j);
            ys.erase({squares[j].y1, j});
            ys.erase({squares[j].y2, j});
        }
    }

    cout << ans << "\n";
	
	return 0;
}