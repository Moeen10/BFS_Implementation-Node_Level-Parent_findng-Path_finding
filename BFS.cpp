#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
bool check[N];
vector<int>v[N];
int level[N];
int parent[N];
void BFS(int u)
{
    check[u]=true;
    queue<int>q;
    q.push(u);
    parent[u]=-1;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        for(auto i : v[current])
        {
            if(check[i])continue;
            q.push(i);
            check[i]=true;
            level[i]=level[current]+1;
            parent[i]=current;
        }
    }
}


int main()
{
    int N,E;
    cin>>N>>E;
    for(int i=1;i<=E;i++){
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
int start,d;
cout<<"Select starting point :";
cin>>start;
cout<<"Select ending point :";
cin>>d;

    //BFS Complexity : O(N+E) N=Nodes,E=Edges
     BFS(start);
    cout<<"Distance Starting :"<<start<< ", from Destination "<<d<<" :"<<level[d]<<endl;
    cout<<endl;

    //Path Finding O(n)
    vector<int>path;
    int current=d;
    while(current!= -1){
            path.push_back(current);
            current = parent[current];
    }
    reverse(path.begin(),path.end());
    for(int i : path){
        cout<< i << " ";
    }


    // Level print;
    for(int i=1;i<=N;i++){
        cout<<i <<"er level hocche : "<<level[i]<< " " <<"And er parent hocche : "<<parent[i]<<endl;
    }

}
