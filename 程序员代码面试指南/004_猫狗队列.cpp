/*
题目描述
实现一种猫狗队列的结构，要求如下：
1. 用户可以调用 add 方法将 cat 或者 dog 放入队列中
2. 用户可以调用 pollAll 方法将队列中的 cat 和 dog 按照进队列的先后顺序依次弹出
3. 用户可以调用 pollDog 方法将队列中的 dog 按照进队列的先后顺序依次弹出
4. 用户可以调用 pollCat 方法将队列中的 cat 按照进队列的先后顺序依次弹出
5. 用户可以调用 isEmpty 方法检查队列中是否还有 dog 或 cat
6. 用户可以调用 isDogEmpty 方法检查队列中是否还有 dog
7. 用户可以调用 isCatEmpty 方法检查队列中是否还有 cat

输入描述:
第一行输入一个整数 n 表示 用户的操作总次数。
以下 n行 每行表示用户的一次操作
每行的第一个参数为一个字符串 s，若 s = “add”， 则后面接着有 “cat x”（表示猫）或者“dog x”（表示狗），其中的 x 表示猫狗的编号。

输出描述:
对于每个操作：
若为 “add”，则不需要输出。
以下仅列举几个代表操作，其它类似的操作输出同理。
若为 “pollAll”，则将队列中的 cat 和 dog 按照进队列的先后顺序依次弹出。(FIFO)，格式见样例。
若为 "isEmpty"，则检查队列中是否还有 dog 或 cat， 为空则输出 “yes”， 否则输出 “no”。

示例1
输入
11
add cat 1
add dog 2
pollAll
isEmpty
add cat 5
isDogEmpty
pollCat
add dog 10
add cat 199
pollDog
pollAll

输出
cat 1
dog 2
yes
yes
cat 5
dog 10
cat 199

备注:
1 <= n <= 1000000
保证每个猫和狗的编号x都不相同且 1≤x≤1000000
保证没有不合法的操作
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Pet {
    private:
        string type;
    public:
        Pet(string ty) {
            type = ty;
        }
        Pet() {
        }
        string getPetType() {
            return type;
        }
};

class Dog : public Pet {
    public:
        Dog() : Pet("dog") {
        }
};

class Cat : public Pet {
    public:
        Cat() : Pet("cat") {
        }
};

class QueuePet {
    private:
        Pet pet;
        int count;
        int number;
    public:
        QueuePet(Pet p, int c, int num) {
            pet = p;
            count = c;
            number = num;
        }
        QueuePet() {
        }
        Pet getPet() {
            return pet;
        }
        int getCount() {
            return count;
        }
        string getQueuePetType() {
            return pet.getPetType();
        }
        int getNumber() {
            return number;
        }
};

class Solution {
    private:
        queue<QueuePet> dogQ, catQ;
        int count;
    public:
        void add(Pet p, int x) {
            QueuePet qPet = QueuePet(p, count++, x);
            if(p.getPetType() == "dog") {
                dogQ.push(qPet);
            } else if(p.getPetType() == "cat") {
                catQ.push(qPet);
            } else {
                throw runtime_error("Not a cat or dog.");
            }
        }
        void pollAll() {
            while (!dogQ.empty() || !catQ.empty()) {
                if (!dogQ.empty() && !catQ.empty()) {
                    QueuePet dog = dogQ.front();
                    QueuePet cat = catQ.front();
                    if(dog.getCount() < cat.getCount()) {
                        cout << "dog " << dog.getNumber() << endl;
                        dogQ.pop();
                    } else {
                        cout << "cat " << cat.getNumber() << endl;
                        catQ.pop();
                    }
                } else if(!catQ.empty()) {
                    QueuePet cat = catQ.front();
                    cout << "cat " << cat.getNumber() << endl;
                    catQ.pop();
                } else if(!dogQ.empty()) {
                    QueuePet dog = dogQ.front();
                    cout << "dog " << dog.getNumber() << endl;
                    dogQ.pop();
                }
            }
        }
        void pollDog() {
            while (!dogQ.empty()) {
                QueuePet dog = dogQ.front();
                cout << "dog " << dog.getNumber() << endl;
                dogQ.pop();
            }
        }
        void pollCat() {
            while (!catQ.empty()) {
                QueuePet cat = catQ.front();
                cout << "cat " << cat.getNumber() << endl;
                catQ.pop();
            }
        }
        void isEmpty() {
            if(catQ.empty() && dogQ.empty()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        void isDogEmpty() {
            if(dogQ.empty()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        void isCatEmpty() {
            if(catQ.empty()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
};

int main () {
    int n;
    cin >> n;
    string operation, kind;
    int x;
    Solution s;
    while(n--) {
        cin >> operation;
        if(operation == "add") {
            cin >> kind;
            cin >> x;
            if(kind == "dog") {
                Dog d;
                s.add(d, x);
            } else if(kind == "cat") {
                Cat c;
                s.add(c, x);
            } else {
                throw runtime_error("Not a cat or dog.");
            }
        } else if(operation == "pollAll") {
            s.pollAll();
        } else if(operation == "pollDog") {
            s.pollDog();
        } else if(operation == "pollCat") {
            s.pollCat();
        } else if(operation == "isEmpty") {
            s.isEmpty();
        } else if(operation == "isDogEmpty") {
            s.isDogEmpty();
        } else if(operation == "isCatEmpty") {
            s.isCatEmpty();
        }
    }
    
    return 0;
}

