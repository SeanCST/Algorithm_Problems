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