#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Graph{
int V;
list<int> *adj;
public:
Graph(int V){
this->V=V;
adj=new list<int>[V];
}
void addEdge(int u,int v){
    adj[u].push_back(v);
}
void Toposort(){
    vector<int> in_degree(V,0);
    vector<int> topo_sort;
    queue<int> q;
    int cnt=0;
    for(int u=0;u<V;u++){
        list<int>::iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++){
            in_degree[*itr]++;
        }
    }
    for(int i=0;i<V;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
   while(!q.empty()){
       int u=q.front();
       q.pop();
       topo_sort.push_back(u);
       list<int>::iterator itr;
       for(itr=adj[u].begin();itr!=adj[u].end();itr++){
           if(in_degree[*itr]!=0){
               in_degree[*itr]--;
               if(in_degree[*itr]==0){
                   q.push(*itr);
               }
           }
       }
       cnt++;
   }
   if(cnt!=V){
       cout<<"there is a cycle in graph topological sort not possible"<<endl;
   }
   for(int i=0;i<topo_sort.size();i++){
       cout<<topo_sort[i]<<" ";
   }
   cout<<endl;
}
};
int main(){
     Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Following is a Topological Sort of\n";
    g.Toposort();
    return 0;
}