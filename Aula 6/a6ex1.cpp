// UVA 10235 Simply Emirp

#include <iostream>
#include <string>  

using namespace std;

bool is_prime(int p) {

    if(p == 2)
        return true;

    if(p == 1 || p % 2 == 0)
        return false;

    for(int i = 3; i*i <= p; i += 2)
        if(p % i == 0)
            return false;

    return true;

}

int invert_num(int a) {

    string s = to_string(a);
    string m;

    m.resize(s.size());

    int i = 0;
    int j = s.size() - 1;
    while(j >= 0) {

        m[i] = s[j];

        i++;
        j--;

    }

    m[i] = '\0';
    
    return stoi(m);

}

int main(void) {

    int n;
    while(cin >> n){
        
        if(is_prime(n)) {

            int m = invert_num(n);
            if(is_prime(m) && n != m)
                cout << n << " is emirp.\n";
            else
                cout << n << " is prime.\n";            

        } else
            cout << n << " is not prime.\n";        

    }
    
}