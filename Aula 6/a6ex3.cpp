/*

integer division between a dividend n and a divisor d yields a quotient q and a remainder r. 
q is the integer which maximizes q ∗ d such that q ∗ d ≤ n and r = n − q ∗ d.
For any set of integers there is an integer d such that each of the
given integers when divided by d leaves the same remainder.

Input:
Each line of input contains a sequence of nonzero integer numbers
separated by a space. The last number on each line is 0 and this
number does not belong to the sequence. There will be at least 2 and
no more than 1000 numbers in a sequence; not all numbers occuring
in a sequence are equal. The last line of input contains a single 0
and this line should not be processed.

Output:
For each line of input, output the largest integer which when divided into each of the input integers
leaves the same remainder.

Sample Input:
701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0

Sample Output?
179
3
3

*/

# include <iostream>
# include <vector>

using namespace std;

int abs(int n) {

    if (n > 0)
        return n;
    
    return -n;

}

int max_2(int a, int b) {

    if(a > b)
        return a;

    return b;

}

int true_remainder(int n, int d) {

    if(n >= 0) {

        return n % d;

    } else if(abs(n) % d == 0) {

        return 0;    
        
    }else {

        int q = n / d;
        q--;

        return n - (q * d);

    }

}

int main(void) {

    int t = -1;
    while(true){
    
        cin >> t;
        if(t == 0)
            break;

        vector<int> numbers;    

        
        while(t != 0) {

            numbers.push_back(t);

            cin >> t;

        }

        int max = -0x3f3f3f3f;
        int min = 0x3f3f3f3f;
        for(size_t i = 0; i < numbers.size(); i++) {
            if(numbers[i] > max)
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];
        }

        int l_rem = -0x3f3f3f3f;
        
        for(int i = 1; i <= max_2(abs(max-min), max); i++) {
        
            if(i == 0)
                continue;

            //cout << i << ":";

            int rem = -0x3f3f3f3f;
            for(size_t j = 0; j < numbers.size(); j++) {

                if(rem == -0x3f3f3f3f)
                    rem = true_remainder(numbers[j], i);
                else if(rem != true_remainder(numbers[j], i)) {
                    rem = -0x3f3f3f3f;
                    break;
                }

                //cout << rem << " /" << numbers[j] << " ";

            }
            
            //cout << endl;

            if(rem != -0x3f3f3f3f && i > l_rem)
                l_rem = i;
        
        }

        cout << l_rem << endl;

    }

    return 0;
}