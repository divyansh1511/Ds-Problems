#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool check(int i, int j)
{
    return (i < 0 || j < 0 || i >= n || j >= m);
}

void SurroundedRegions(vector<vector<char>> &board)
{
    n = board.size(), m = board[0].size();
    queue<vector<int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O')
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        auto idx = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int i = dx[k] + idx[0];
            int j = dy[k] + idx[1];
            board[idx[0]][idx[1]] = 'k';
            if (!check(i, j) && board[i][j] == 'O')
            {
                q.push({i, j});
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 'k')
                board[i][j] = 'O';

            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int findMinFibonacciNumbers(int A)
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(1);
    while (pq.top() <= A)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int third = first + second;
        pq.push(first);
        pq.push(second);
        pq.push(third);
    }
    int sum = A;
    int count = 0;
    while (pq.size() > 0 && sum > 0)
    {
        if (pq.top() > sum)
            pq.pop();
        else
        {
            sum = sum - pq.top();
            count++;
        }
    }
    return count;
}

int WorldLadder1(string beginWord, string endWord, vector<string> &wordList) {
    if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        return 0;
    set<string> s;
    for(auto i:wordList)
        s.insert(i);
    queue<string> q;
    q.push(beginWord);
    int d=0;
    while(!q.empty())
    {
        d++;
        int n=q.size();
        while(n--)
        {
            string curr=q.front();
            q.pop();
            for(int i=0;i<curr.length();i++)
            {
                string tmp=curr;
                for(char c='a';c<='z';c++)
                {
                    tmp[i]=c;
                    if(tmp==curr)
                        continue;
                    if(tmp==endWord)
                        return d+1;
                    if(s.find(tmp)!=s.end())
                    {
                        q.push(tmp);
                        s.erase(tmp);
                    }
                }
            }
        }
    }
    return 0;
}


int main()
{
}