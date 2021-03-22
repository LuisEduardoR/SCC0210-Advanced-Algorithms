# include <iostream>
# include <vector>

using namespace std;

int n, t;

vector<int> dur;

vector<int> best_tracks;
int best;

vector<int> cur_tracks;
int cur;

int len;

void solve() {

    if (cur > best && cur <= n) {

        // Updates best.
        best_tracks.clear();
        for(auto it = cur_tracks.begin(); it != cur_tracks.end(); it++) {
            best_tracks.push_back(*it);
        }

        best = cur;

    }
    
    if (cur > n) {

        return;

    } else if (len < t) {

        int v = dur[len];

        // Pega.
        cur += v;
        cur_tracks.push_back(v);
        len++;

        solve();
        
        cur -= v;
        cur_tracks.pop_back();
        len--;

        // Nao pega.
        len++;
        solve();
        len--;

        return;

    }

}

int main(void) {


    while(cin >> n >> t) {

        int temp;

        dur.clear();
        best_tracks.clear();
        cur_tracks.clear();

        best = -1;
        cur = 0;
        len = 0;

        for(int i = 0; i < t; i++) {

            cin >> temp;
            dur.push_back(temp);

        }

        solve();

        for(auto it = best_tracks.begin(); it != best_tracks.end(); it++) {
            cout << *it << ' ';
        }

        cout << "sum:" << best << endl;

    }
}