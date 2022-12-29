#include <bits/stdc++.h>
using namespace std;

class stackusingarr
{
public:
    int *arr;
    int capacity;
    int lastelementindex;
    stackusingarr(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        lastelementindex = -1;
    }
    bool isempty()
    {
        return lastelementindex == -1;
    }
    int size()
    {
        return lastelementindex + 1;
    }
    int top()
    {
        if (lastelementindex == -1)
        {
            return -1;
        }
        return arr[lastelementindex];
    }
    void push(int element)
    {
        if (lastelementindex == capacity - 1)
        {
            int *newarr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = arr[i];
            }
            capacity *= 2;
            arr = newarr;
            delete newarr;
        }
        arr[++lastelementindex] = element;
    }
    void pop()
    {
        lastelementindex--;
    }
};

class Queue
{
public:
    int frontTrack, rear, currentSize;
    int capacity;
    vector<int> queue;
    Queue(int capacity)
    {
        this->capacity = capacity;
        frontTrack = this->currentSize = 0;
        rear = capacity - 1;
        queue.resize(this->capacity);
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    int size()
    {
        return currentSize;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return this->queue[this->frontTrack];
    }

    int back()
    {
        if (isEmpty())
        {
            return -1;
        }
        return this->queue[this->rear];
    }

    void push(int element)
    {
        if (currentSize == capacity)
        {
            return;
        }
        this->rear = (this->rear + 1) % this->capacity;
        this->queue[this->rear] = element;
        this->currentSize = (this->currentSize) + 1;
    }

    void pop()
    {
        this->frontTrack = (this->frontTrack + 1) % this->capacity;
        this->currentSize = this->currentSize - 1;
    }
};

class Queue
{
public:
    Stack *stack1;
    Stack *stack2;
    int capacity = 0;
    Queue(int capacity)
    {
        this->capacity = capacity;
        stack1 = new Stack(capacity);
        stack2 = new Stack(capacity);
    }

    bool isEmpty()
    {
        return stack1->isEmpty();
    }

    int size()
    {
        return stack1->size();
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        while (!isEmpty())
        {
            stack2->push(stack1->top());
            stack1->pop();
        }
        int x = stack2->top();
        while (!stack2->isEmpty())
        {
            stack1->push(stack2->top());
            stack2->pop();
        }
        return x;
    }
    int back()
    {
        if (isEmpty())
        {
            return -1;
        }
        return stack1->top();
    }
    void push(int element)
    {
        if (stack1->size() == capacity)
        {
            return;
        }
        stack1->push(element);
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        while (!isEmpty())
        {
            stack2->push(stack1->top());
            stack1->pop();
        }
        stack2->pop();
        while (!stack2->isEmpty())
        {
            stack1->push(stack2->top());
            stack2->pop();
        }
    }
};

class Stack
{
public:
    int capacity;
    Queue *queue;
    Stack(int capacity)
    {
        this->capacity = capacity;
        queue = new Queue(capacity);
    }
    bool isEmpty()
    {
        return queue->isEmpty();
    }

    int size()
    {
        return queue->size();
    }

    int top()
    {
        return queue->front();
    }

    void push(int element)
    {
        queue->push(element);
        for (int i = 1; i < queue->size(); i++)
        {
            queue->push(queue->front());
            queue->pop();
        }
    }

    void pop()
    {
        queue->pop();
    }
};

bool isBalancedParentheses(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        if (str[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '(')
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '[')
            {
                return false;
            }
        }
        else if (str[i] == '}')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '{')
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

class MinStack
{
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x)
    {
        s1.push(x);
        if (s2.empty() || s2.top() >= x)
        {
            s2.push(x);
        }
    }
    void pop()
    {
        int a = s1.top();
        s1.pop();
        if (!s2.empty() && s2.top() == a)
        {
            s2.pop();
        }
    }
    int top()
    {
        return s1.top();
    }
    int getMin()
    {
        return s2.top();
    }
};

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            st.push(stoi(tokens[i]));
            continue;
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (tokens[i] == "+")
            {
                st.push(a + b);
            }
            else if (tokens[i] == "-")
            {
                st.push(b - a);
            }
            else if (tokens[i] == "*")
            {
                st.push(a * b);
            }
            else
            {
                st.push(b / a);
            }
        }
    }
    return st.top();
}

vector<int> getNextGreaterElement(vector<int> &A)
{
    int n = A.size();
    vector<int> v(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && A[i] >= A[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            v[i] = -1;
        }
        else
        {
            v[i] = A[st.top()];
        }
        st.push(i);
    }
    return v;
}

int getDaysToRot(vector<vector<int> > &grid) {
	int days = 0;
	int tot = 0 , cnt = 0;
	int n = grid.size() , m = grid[0].size();
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] != 0){
				tot++;
			}
			if(grid[i][j] == 2){
				q.push({i , j});
			}
		}
	}
	int dx[] = {0 , 0 , -1 , 1};
	int dy[] = {1 , -1 , 0 , 0};
	while(!q.empty()){
		int k = q.size();
		cnt += k;
		while(k--){
			int x = q.front().first , y = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int nx = x + dx[i] , ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1){
					continue;
				}
				grid[nx][ny] = 2;
				q.push({nx , ny});
			}
		}
		if(!q.empty()){
			days++;
		}
	}
	return tot == cnt ? days : -1;
}

vector<int> maxSlidingWindow(vector<int> &A, int k) {
	deque<int> dq;
	vector<int> v;
	for(int i=0;i<A.size();i++){
		if(!dq.empty() && dq.front() == i-k){
			dq.pop_front();
		}
		while(!dq.empty() && A[dq.back()] < A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		if(i >= k-1){
			v.push_back(A[dq.front()]);
		}
	}
	return v;
}

int getLargestArea(vector<int> &heights) {
	stack<int> st;
	int ans = 0;
	heights.push_back(0);
	for(int i=0;i<heights.size();i++){
		while(!st.empty() && heights[st.top()] > heights[i]){
			int t = heights[st.top()];
			st.pop();
			int ran = st.empty() ? -1 : st.top();
			ans = max(ans , t*(i-ran-1));
		}
		st.push(i);
	}
	return ans;
}

int main()
{
}