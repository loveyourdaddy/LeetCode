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
    // a * b = c로 나뉜다면 a < sqrt(c), b>sqrt(c)
    bool isPrime(int i) {
        for (int c = 2; c*c <= i; c++)
        {
            if (i % c == 0)
                return false;
        }
        return true;
    }
};


// one pass
    int countPrimes(int n) {
        int count{0};
        vector<bool> vect(n, true); 

        // 어차피 2 부터 셀꺼다 
        for (int i = 2; i * i < n; i++) {
            if (vect[i]) {
                // i^2 + i = i(i+1) 이니까 =+ i 한것은 전부 prime number가 아님.
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
