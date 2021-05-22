class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> hashMap;
        
        while (true)
        {
            int sum = 0;
			while (n != 0)
            {
                int rest = n % 10;
                sum += pow(rest, 2);
                n = n / 10;
            }
            
            if (sum == 1) 
                return true;

            if (hashMap.find(sum) == hashMap.end()) // 못찾으면 
            {
                n = sum;
                hashMap.insert({ sum, true });
                continue;
            }                
            else 
                return false;
        }
    }
};
