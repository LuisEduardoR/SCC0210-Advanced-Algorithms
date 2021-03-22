// UVA 11565 Simple Equations

#include <iostream>
#include <math.h>

using namespace std;

int main(void) {

    int n, a, b, c;

    cin >> n;
    for(int i = 0; i < n; i++) {

        cin >> a >> b >> c;

        int x, y, z;
        bool solved = false;
        for(x = -floor(sqrt(c)); x*x < c && !solved; x++) {
            for(y = -floor(sqrt(c)); y*y < c && !solved; y++) {

                z = a - x - y;

                if(x + y + z == a && x*y*z == b && x*x + y*y + z*z == c) {

                    cout << x << " " << y << " " << z << "\n";
                    solved = true;

                } 
            }
        }

        if(!solved)
            cout << "No solution.\n"; 

    }


    return 0;

}