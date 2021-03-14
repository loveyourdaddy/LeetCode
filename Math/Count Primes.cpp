//brute force 
class Solution {
public:
    int countPrimes(int n) {
        vector<int> output;

        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                output.push_back(i);
            }            
        }           
        return output.size(); 
    }

    bool isPrime(int i) {
        for (int c = 2; c*c <= i; c++)
        {
            if (i % c == 0)
                return false;
        }
        return true;
    }
};


//
    int countPrimes(int n) {
        int count{0};
        vector<bool> vect(n, true); 

        for (int i = 2; i * i < n; i++) {
            if (vect[i]) {
                for (int j = i * i; j < n; j += i) {
                    vect[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++) {
            if (vect[i]) count++;
        }

        return count;
    }
