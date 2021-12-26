#include <iostream>
#include <vector>

using namespace std;

int min3(int a, int b, int c)
{
    if(a <= b)
    {
        if(a <= c)
        {
            return a;
        }
        return c;
    }
    if(b <= c)
    {
        return b;
    }
    return c;
}

int min2(int a, int b)
{
    if(a <= b)
    {
        return a;
    }

    return b;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int> > D;
    D.resize(s1.size() + 1);
    for(int i = 0; i <= s1.size(); i++)
    {
        D[i].resize(s2.size() + 1);
    }
    for(int i = 0; i <= s1.size(); i++)
    {
        D[i][0] = i;
    }
    for(int j = 1; j <= s2.size(); j++)
    {
        D[0][j] = j;
    }

    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            bool m = s1[i - 1] == s2[j - 1];
            D[i][j] = min3(D[i][j - 1] + 1, D[i - 1][j] + 1, D[i - 1][j - 1] + !m);
        }
    }

    cout << D[s1.size()][s2.size()] << endl;


    return 0;
}
