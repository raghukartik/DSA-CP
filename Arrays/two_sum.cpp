#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    vector<int> v1;
    for(int j=0;j<5;j++){
        v1.emplace_back(2*j);
    }
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    


    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout<<endl;

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }

    v.insert(v.begin() + 5, 69);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    v.insert(v.begin(),v1.begin(),v1.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    v.erase(v.begin()+5,v.begin()+9);
}