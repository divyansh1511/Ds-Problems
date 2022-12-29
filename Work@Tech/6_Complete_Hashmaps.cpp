#include <bits/stdc++.h>
using namespace std;

int getIdenticalTwinsCount(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
        {
            ans += (mp[arr[i]] - 1);
        }
    }
    return ans;
}

vector<int> primesUptoN(int n)
{
    bool isPrime[n + 1];
    for (int i = 2; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            if (isPrime[i] == true)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> answer;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            answer.push_back(i);
        }
    }
    return answer;
}

vector<vector<int>> fourSum(vector<int> &A, int target)
{
    sort(A.begin(), A.end());
    vector<vector<int>> v;
    int n = A.size();
    for (int i = 0; i < n - 4; i++)
    {
        if (i > 0 && A[i] == A[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n - 3; j++)
        {
            if (j > i + 1 && A[j] == A[j - 1])
            {
                continue;
            }
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                int sum = A[i] + A[j] + A[k] + A[l];
                if (sum == target)
                {
                    if (!v.empty() && A[i] == v.back()[0] && A[j] == v.back()[1] && A[k] == v.back()[2] && A[l] == v.back()[3])
                    {
                        continue;
                    }
                    v.push_back({A[i], A[j], A[k], A[l]});
                    k++;
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return v;
}

int longestConsecutiveSequence(vector<int> &A) {
	sort (A.begin(), A.end());
	int currentMaxSequence = 1;
	int ans = 1;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] - A[i - 1] > 1) {
			currentMaxSequence = 1;
		} else {
			if (A[i] - A[i - 1] == 1) {
				currentMaxSequence++;
			}
		}
		ans = max (ans, currentMaxSequence);

	}
	return ans;
}

int longestSubstringWithoutRepeat(string s) {
	vector<int> v(256 , -1);
	int len = 0;
	int i = 0 , j = 0;
	int n = s.length();
	while(j < n){
		if(v[s[j]] != -1){
			i = max(v[s[j]] + 1, i);
		}
		v[s[j]] = j;
		len = max(len , j-i+1);
		j++;
	}
	return len;
}

vector<int> distintNumbersInWindow(vector<int> &A, int k) {
	unordered_map<int,int> mp;
	for(int i=0;i<k;i++){
		mp[A[i]]++;
	}
	vector<int> v;
	v.push_back(mp.size());
	for(int i=k;i<A.size();i++){
		mp[A[i-k]]--;
		if(mp[A[i-k]] == 0){
			mp.erase(A[i-k]);
		}
		mp[A[i]]++;
		v.push_back(mp.size());
	}
	return v;
}

int numSubarrayWithXOR(vector<int> &A, int target) {
	int n = A.size();
	int xorr = 0 , ans = 0;
	unordered_map<int,int> mp;
	for(int i=0;i<A.size();i++){
		xorr ^= A[i];
		int t = xorr ^ target;
		ans += mp[t];
		if(xorr == target){
			ans++;
		}
		mp[xorr]++;
	}
	return ans;
}

int longestSubstringWithKUniqueCharacters(string s, int k) {
	int n = s.length();
	int hashChar[n][26];
	memset(hashChar, 0, sizeof(hashChar));
	unordered_set<char> distinct(s.begin(), s.end());
	for(int i = 0; i < n; i++) {
		hashChar[i][s[i] - 'a']++;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 26; j++) {
			hashChar[i][j] += hashChar[i - 1][j];
		}
	}
	auto query = [&] (int l, int r) {
		int cnt = 0;
		for(int i = 0; i < 26; i++) {
			if(l == 0) {
				cnt += hashChar[r][i] > 0;
			}
			else {
				cnt += (hashChar[r][i] - hashChar[l - 1][i]) > 0;
			}
		}
		return cnt;
	};
	if(distinct.size() < k) {
		return -1;
	}
	else {
		int left = 0, right = 0, answer = 0;
		while(right < n && left <= right) {
			if(query(left, right) <= k) {
				if(query(left, right) == k) {
					answer = max(answer, right - left + 1);
				}
				right++;
			}
			else {
				left++;
			}
		}
		return answer;
	}
}

class Node {
public:
	int value;
	int key;
	Node* next;
	Node* prev;
	
    Node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};
class LRUCache {
	Node* head = NULL;
    Node* tail = NULL;
    unordered_map<int, Node*> keyToNode;
    int capacity;
	
	void moveToHead(Node* n) {
        if (head == n) {
            return;
        }
        Node* prev = n->prev;
        Node* next = n->next;
        if (n == tail) {
            tail = prev;
        }
        prev->next = n->next;
        if (next != NULL) {
            next->prev = prev;
        }
		
        n->prev = NULL;
        n->next = head;
        head->prev = n;
        head = n;
    }
	
public:
    LRUCache(int capacity) {
		keyToNode.clear();
        this->capacity = capacity;
    }
    
    int get(int key) {
		if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        Node* n = keyToNode[key];        
        moveToHead(n);
        return head->value;
    }    
	
    void add(int key, int value) {
		if (keyToNode.find(key) != keyToNode.end()) {
            Node* n = keyToNode[key];
            n->value = value;      
            moveToHead(n);
        } else {
            if (keyToNode.size() == capacity) {
                Node* last = tail;
                tail = tail->prev;
                
                if (tail != NULL) {
                    tail->next = NULL;
                } else {
                    head = NULL;
                }
                keyToNode.erase(last->key);
            }
            Node* n = new Node(key, value);
            if (head == NULL) {
                tail = n;
            } else {
                n->next = head;
                head->prev = n; 
            }
            head = n;
            keyToNode[key] = n;
        }
    }
};

int main()
{
}