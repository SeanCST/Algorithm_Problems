// 暴力解法
class Solution {
public:
    bool isPrime(int n) {
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) 
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int res = 0;
        if(n == 3) res += 1;
        if(n >= 4) res += 2;
        
        for(int i = 5; i < n; i++) {
            if(isPrime(i))
                res++;
        }
        
        return res;
    }
};


// 埃拉托斯特尼筛法 Sieve of Eratosthenes
class Solution {
public:
    
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for(int i = 2; i * i < n; i++)
        {
            if (isPrime[i] == true) {
                for(int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int res = 0;
        for(int i = 2; i < n; i++)
        {
            if (isPrime[i]) {
                res++;
            }
        }
        
        return res;
    }
};