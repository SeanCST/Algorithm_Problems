class Solution {
        map<int, string> m1 = {
                                {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, 
                                {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {0, "Zero"}
                                };
        map<int, string> m2 = {
                                {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, 
                                {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
                                };                      
        map<int, string> m3 = {
                                {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, 
                                {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
                                }; 
public:
    string numberToWords(int n) {
        if(n == 0) {
            return m1[0];
        }
        vector<string>  res;
        // divide to three 3-digits numbers
        if(n / 1000000000) {
            vector<string> vec = wordsWithDigitsNumber(n / 1000000000);
            res.insert(res.end(), vec.begin(), vec.end());
            res.push_back("Billion");
            n = n % 1000000000;
        }

        if(n / 1000000) {
            vector<string> vec = wordsWithDigitsNumber(n / 1000000);
            res.insert(res.end(), vec.begin(), vec.end());
            res.push_back("Million");
            n = n % 1000000;
        }
        
        if(n / 1000) {
            vector<string> vec = wordsWithDigitsNumber(n / 1000);
            res.insert(res.end(), vec.begin(), vec.end());
            res.push_back("Thousand");
            n = n % 1000;
        }
        
        vector<string> vec = wordsWithDigitsNumber(n);
        res.insert(res.end(), vec.begin(), vec.end());

        string resStr;
        for(int i = 0; i < res.size(); i++) {
            resStr += res[i];
            if(i < res.size() - 1) {
                resStr += " ";
            }
        }

        return resStr;
    }

    vector<string> wordsWithDigitsNumber(int num) { 
        vector<string> res;       
        if(num >= 100) {
            res.push_back(m1[num / 100]);
            res.push_back("Hundred");
            num = num % 100; 
        }
        
        if(num >= 20) {
            res.push_back(m3[num / 10]);
            num = num % 10;
            if(num >= 1) {
                res.push_back(m1[num]);
            }
        } else if(num >= 10) {
            res.push_back(m2[num]);
        } else if(num >= 1) {
            res.push_back(m1[num]);
        }

        return res;
    }
};