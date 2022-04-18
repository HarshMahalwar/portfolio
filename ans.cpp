#include <bits/stdc++.h>

#define ll long long int
#define qw priority_queue<int>
#define qwd priority_queue<int, vector<int>, greater<int>>
#define pp pair<int, int>
#define func                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

class Solution
{
public:
    void levelor(TreeNode *root, map<int, map<int, multiset<int>>> &m)
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(1, 1)));
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto t = q.front().first;
                q.pop();
                int x = t.second.first, y = t.first.second;
                m[x][y].insert(t -> val);
                if(t -> left)
                    q.push(make_pair(t -> left, make_pair(x - 1, y + 1)));
                if(t -> right)
                    q.push(make_pair(t -> right, make_pair(x + 1, y + 1)));
            }
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> a;
        if (!root)
            return a;
        map<int, map<int, multiset<int>>> m;
        levelor(root, m);
        for(auto it: m){
            vector<int> a1;
            for(auto p: it.second)
                a1.insert(a1.end(), p.second.begin(), p.second.end());
            a.push_back(a1);
        }
        return a;
    }

};

void solve()
{
}

int main()
{
    func
        test
    {
        solve();
    }
    return 0;
}