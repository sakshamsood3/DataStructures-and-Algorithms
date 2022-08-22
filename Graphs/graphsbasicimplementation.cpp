#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    vector<int> adjUD[n+1];
    vector<int> adjD[n+1];
    cout<<"Enter No. of nodes and edges"<<" ";
    cin>>n>>m;
    cout<<n<<m<<" ";
    cout<<"Enter m edges"<<endl;
    //for Undirected Graph
    int u,v;
    for(int i=0;i<m;i++){
        cout<<"Enter edge from a-b:";
        cin>>u>>v;
        cout<<u<<v<<" ";
        adjUD[u].push_back(v);
        adjUD[v].push_back(u);
    }
    
    //For Directed Graph
    for(int i=0;i<m;i++){
        cout<<"Enter edge from a-b:";
        cin>>u>>v;
        adjD[u].push_back(v);
    }
    
    return 0;
}