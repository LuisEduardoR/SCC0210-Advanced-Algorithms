# include <iostream>
# include <vector>

using namespace std;

vector<int> monsters;

int main(void) {

    int n, p, q;
    
    int res;

    cin >> n >> p >> q;

    for(int i = 0; i < n; i++) {

        int temp;
        cin >> temp;
        monsters.push_back(temp);

    }

    while(!monsters.empty()) {

        for(auto it = monsters.begin(); it != monsters.end(); it++) {

            cout << *it << ' ';

        }

        cout << endl;

        int boss = -1;
        int bossLife = -1;
        for(size_t i = 0; i < monsters.size(); i++) {

            if(monsters[i] > bossLife) {
                bossLife = monsters[i];
                boss = i;
            }

        }

        int axe = bossLife / p;

        monsters[boss] -= axe * p;
        if(monsters[boss] <= 0) {
            monsters.erase(monsters.begin() + boss);
            boss = -1;
        }

        for(size_t i = 0; i < monsters.size(); i++) {

            if(i != boss) {
                monsters[i] -= q * axe;
                if(monsters[boss] <= 0)
                    monsters.erase(monsters.begin() + i);

            }
        }

        res++;
    }

    cout << res << endl;
    
}