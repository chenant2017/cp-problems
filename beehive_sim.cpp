#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> A; //attractiveness force
vector<vector<int>> visited; //how many times each cell is visited
vector<vector<int>> flowers; //number of flowers
vector<vector<vector<int>>> C; //crowdedness; how many bees in each cell at each point in time

int N, M, F; //rows, columns, number of flowers
int B, T, Ft;  //bees, time, max flowers per trip 
// int Cmax; //max crowdedness at a cell
double P; //seasonality constant
int di[] = {0, 0, 0, -1, 1};
int dj[] = {0, -1, 1, 0, 0};

double random_double(double min, double max) {
    return min + ((double) rand()/RAND_MAX) * (max - min);
}

double v_index(int t, int i, int j) { //visiting index
    return A[i][j] / (C[t][i][j] + 1);
}

double p_index(int t, int i, int j) { //pollination index
    return 1;
}

double a_index(double a, double dist) { //attractivness index
    return a / pow(dist + 1, P);
}

void fill_A(int i, int j, double a) {
    for (int i2 = 0; i2 < N; i2++) {
        for (int j2 = 0; j2 < M; j2++) {
            double dist = sqrt(pow(i2 - i, 2) + pow(j2 - j, 2));
            A[i2][j2] += a_index(a, dist);
        }
    }
}

vector<double> get_probs(int i, int j) {
    vector<double> probs;
    
    probs.clear(); 
    probs.push_back(A[i][j]);

    int i2, j2;
    for (int d = 1; d < 5; d++) {
        i2 = i + di[d];
        j2 = j + dj[d];
        if (0 <= i2 && i2 < N &&
            0 <= j2 && j2 < M) {
            probs.push_back(probs[d - 1] + A[i2][j2]);
        }
        else {
            probs.push_back(probs[d - 1]);
        }
    }

    return probs;
}

void simulate(int hivei, int hivej) {
    int i = hivei;
    int j = hivej;
    int pollinated = 0;
    vector<double> probs;

    for (int t = 0; t < T; t++) {
        visited[i][j]++;
        C[t][i][j]++;
        pollinated += flowers[i][j];

        if (pollinated >= Ft) return;

        probs = get_probs(i, j);

        double rd = random_double(0, probs[4]);
        
        int move;
        for (int p = 0; p < 5; p++) {
            if (rd <= probs[p]) {
                move = p;
                break;
            }
        }

        i += di[move];
        j += dj[move];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    srand(time(NULL)); //initialize random seed
	
	string fname = "sim";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> P;
    cin >> F >> B >> T;
    cin >> Ft;
    A.resize(N, vector<double>(M, 0));
    visited.resize(N, vector<int>(M, 0));
    flowers.resize(N, vector<int>(M, 0));
    C.resize(T, vector<vector<int>>(N, vector<int>(M, 0)));

    //initialize matrix A
	int i, j;
    double a;
	for (int f = 0; f < F; f++) {
		cin >> i >> j >> a;
        flowers[i][j] = a;
        fill_A(i, j, a);
	}

    //simulate each bee's route
    for (int s = 0; s < B; s++) {
        simulate(N/2 + 1, M/2 + 1);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << visited[i][j] << ", ";
        }
        cout << "\n";
    }

	return 0;
}