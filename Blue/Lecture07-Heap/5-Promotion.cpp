#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long k;
    long long sum = 0;
    long long x;
    long long big, small;
    long long temp, index;
    priority_queue<long long> q_max, q_maxTemp;
    priority_queue<long long, vector<long long>, greater<long long>> q_min, q_minTemp;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        cin >> k;
        
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            q_max.push(x);
            q_min.push(x);
        }
        big = q_max.top();
        q_max.pop();
        small = q_min.top();
        q_min.pop();
        sum += (big - small);
        for (int k = 0; k < q_max.size(); k++)
        {
            temp = q_max.top();
            q_max.pop();
            if (temp != small)
            {
                q_maxTemp.push(temp);
            }
        }
        q_max = q_maxTemp;
        while(q_maxTemp.size()>0)
        {
            q_maxTemp.pop();
        }
        temp = 0;
        for (int k = 0; k < q_min.size(); k++)
        {
            temp = q_min.top();
            q_min.pop();
            if (temp != big)
            {
                q_minTemp.push(temp);
            }
        }
        q_min = q_minTemp;
        while(q_minTemp.size()>0)
        {
            q_minTemp.pop();
        }
    }
    cout << sum << endl;
    return 0;
}