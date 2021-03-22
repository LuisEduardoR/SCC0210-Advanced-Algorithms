# include <iostream>
# include <vector>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    int num_2 = n / 2;

    if(n % 2 == 0) {

        cout << num_2 << endl;

        for(int i = 0; i < num_2 - 1; i++)
            cout << 2 << ' ';

        cout << 2 << endl;
        return 0;

    } else {

         cout << num_2 << endl;

        for(int i = 0; i < num_2 - 1; i++)
            cout << 2 << ' ';

        cout << 3 << endl;
        return 0;

    }
}