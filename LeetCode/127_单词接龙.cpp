class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> allWords(wordList.begin(), wordList.end());
        if(allWords.find(endWord) == allWords.end()) {
            return 0;
        }
        
        // 双向搜索，哪边相关联的少就先搜索那边
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int step = 1;

        while(!beginSet.empty()) {
            step++;
            unordered_set<string> tempSet;
            for(auto s : beginSet) {
                allWords.erase(s);
                for(int i = 0; i < s.length(); i++) {
                    string tempStr = s;
                    for(char c = 'a'; c <= 'z'; c++) {
                        tempStr[i] = c;
                        if(allWords.find(tempStr) == allWords.end()) {
                            continue;
                        }
                        if(endSet.find(tempStr) != endSet.end()) {
                            return step;
                        }
                        tempSet.insert(tempStr);
                    }
                }
            }

            if(tempSet.size() < endSet.size()) {
                beginSet = tempSet;
            } else {
                beginSet = endSet;
                endSet = tempSet;
            }
        }

        return 0;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.length();
        map<string, vector<string>> allComboDict;
        for(string word : wordList) {
            for(int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1, L - i - 1);
                vector<string> transformations;
                if(allComboDict.count(newWord) != 0) {
                    transformations = allComboDict[newWord];
                } 
                transformations.push_back(word);
                allComboDict[newWord] = transformations;
            }
        }

        queue<pair<string, int>> q;
        pair<string, int> beginPair(beginWord, 1);
        q.push(beginPair);

        map<string, bool> visited;
        visited[beginWord] = true;

        while(!q.empty()) {
            pair<string, int> frontPair = q.front();
            q.pop();
            string word = frontPair.first;
            int level = frontPair.second;
            for(int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1, L - i - 1);
                for(string adjacentWord : allComboDict[newWord]) {
                    if(adjacentWord == endWord) {
                        return level + 1;
                    }
                    if(!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        pair<string, int> curPair(adjacentWord, level + 1);
                        q.push(curPair);
                    }
                }
            }
        }

        return 0;
    }
};