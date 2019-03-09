class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *pNode = root;
        int length = 0;
        while(pNode != NULL) {
            length++;
            pNode = pNode->next;
        }
        int mod = length % k; // 长段的数目
        int size = length / k; // 短段的长度

        vector<ListNode *> res;
        pNode = root;
        for(int i = 0; i < k; i++) {
            res.push_back(pNode);
            int curSize = size + (mod-- > 0 ? 1 : 0);
            for(int j = 0; j < curSize - 1; j++) {
                pNode = pNode->next;
            }
            
            if(pNode != NULL) {
                ListNode *next = pNode->next;
                pNode->next = NULL;
                pNode = next;
            }
        }
        
        return res;
    }
};


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *pNode = root;
        int length = 0;
        while(pNode != NULL) {
            length++;
            pNode = pNode->next;
        }
        int shortSeg = length / k; // 每段最短长度
        int longSeg = shortSeg + 1; // 每段最长长度
        int longCount = 0, shortCount = 0;
        for(shortCount = 0; shortCount <= k; shortCount++) {
            longCount = k - shortCount;
            if(longSeg * longCount + shortSeg * shortCount == length) {
                break;
            }
        }
        vector<ListNode*> res;
        for(int i = 0; i < longCount; i++) {
            pNode = root;
            for(int j = 1; j < longSeg; j++) {
                pNode = pNode->next;
            }
            ListNode *temp = pNode->next;
            pNode->next = NULL;
            res.push_back(root);
            root = temp;
        }
        for(int i = 0; i < shortCount; i++) {
            pNode = root;
            for(int j = 1; j < shortSeg; j++) {
                pNode = pNode->next;
            }
            ListNode *temp = NULL;
            if(pNode != NULL) {
                temp = pNode->next;
                pNode->next = NULL;
                res.push_back(root);
            } else {
                res.push_back(NULL);
            }
            root = temp;
        }
        
        return res;
    }
};