
-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

LRU Cache
Difficulty: HardAccuracy: 18.44%Submissions: 168K+Points: 8
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

PUT x y: sets the value of the key x with value y
GET x: gets the key of x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.
Examples:

Input: cap = 2, Q = 2, Queries = [["PUT", 1, 2], ["GET", 1]]
Output: [2]
Explanation: Cache Size = 2
["PUT", 1, 2] will insert the key-value pair (1, 2) in the cache,
["GET", 1] will print the value corresponding to Key 1, ie 2.
Input: cap = 2, Q = 8, Queries = [["PUT", 1, 2], ["PUT", 2, 3], ["PUT", 1, 5], ["PUT", 4, 5], ["PUT", 6, 7], ["GET", 4], ["PUT", 1, 2], ["GET", 3]]
Output: [5, -1]
Explanation: Cache Size = 2
["PUT", 1, 2] will insert the pair (1,2) in the cache.
["PUT", 2, 3] will insert the pair (2,3) in the cache: 1->2, 2->3(the most recently used one is kept at the rightmost position) 
["PUT", 1, 5] will replace the value of 1 from 2 to 5 : 2 -> 3, 1 -> 5
["PUT", 4, 5] : 1 -> 5, 4 -> 5 (Cache size is 2, hence we delete the least recently used key-value pair)
["PUT", 6, 7] : 4 -> 5, 6 -> 7 
["GET", 4] : Prints 5 (The cache now looks like 6 -> 7, 4->5)
["PUT", 1, 2] : 4 -> 5, 1 -> 2  (Cache size is 2, hence we delete the least recently used key-value pair)
["GET", 3] : No key value pair having key = 3. Hence, -1 is printed.
Constraints:
1 <= cap <= 103
1 <= Q <= 105
1 <= x, y <= 104


class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache; // Key to Node mapping
    Node *head, *tail;              // Pointers to LRU (head) and MRU (tail)

    void removeNode(Node *node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next; // If node is head

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev; // If node is tail
    }

    void addToTail(Node *node) {
        node->prev = tail;
        node->next = nullptr;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node; // If list was empty
    }

public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1; // Key not found
        Node *node = cache[key];
        removeNode(node); // Move accessed node to tail
        addToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->val = value; // Update value
            removeNode(node); // Move updated node to tail
            addToTail(node);
        } else {
            if (cache.size() == capacity) { // If at capacity, remove LRU
                cache.erase(head->key);
                removeNode(head);
            }
            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            addToTail(newNode);
        }
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 27 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


