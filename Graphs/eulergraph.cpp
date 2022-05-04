#include<iostream>
#include<list>
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
    ~Graph(){
        delete []adj;
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int v,bool visited[]){
        visited[v]=true;
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]){
                DFS(*i,visited);
            }
        }
    }
    bool isConnected(){
        bool visited[V];
        int i;
        for(i=0;i<V;i++){
            visited[i]=false;
        }
        for(i=0;i<V;i++){
            if(adj[i].size()!=0) break;
        }
        if(i==V) return true;
        DFS(i,visited);
        for(int i=0;i<V;i++){
            if(visited[i]==false && adj[i].size()>0) return false;
        }
        return true;
    }
    int isEulerian(){
        if(isConnected()==false) return 0;
        int odd=0;
        for(int i=0;i<V;i++){
            if((adj[i].size()%2)!=0) odd++;
        }
        if(odd>2) return 0;
        if(odd==0) return 2;
        else return 1;
    }
    int DFScount(int v,bool visited[]){
        visited[v]=true;
        int count=1;
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(*i!=-1 && !visited[*i]){
                count+=DFScount(*i,visited);
            }
        }
        return count;
    }
    void removeEdge(int u,int v){
        list<int>::iterator pu=find(adj[u].begin(),adj[u].end(),v);
        *pu=-1;
        list<int>::iterator pv=find(adj[v].begin(),adj[v].end(),u);
        *pv=-1;
    }
    bool isValidEdge(int u,int v){
        int cnt=0;
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++)
            if(*i!=-1) cnt++;
        if(cnt==1) return true;
        bool visited[V];
        for(int j=0;j<V;j++){
            visited[j]=false;
        }
        int count1=DFScount(u,visited);
        removeEdge(u,v);
        for(int j=0;j<V;j++){
            visited[j]=false;
        }
        int count2=DFScount(u,visited);
        addEdge(u,v);
        return (count1>count2)?false:true;
    }
    void printEuler(int u){
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++){
            int v=*i;
            if(v!=-1 && isValidEdge(u,v)){
                cout<<u<<"->"<<v<<" ";
                removeEdge(u,v);
                printEuler(v);
            }
        }
    }
    void printEulerianTour(){
        int u=0;
        for(int i=0;i<V;i++){
            if((adj[i].size()%2)!=0){
                u=i;
                break;
            }
        }
        printEuler(u);
        cout<<endl;
    }
};
void test(Graph &g){
    int res=g.isEulerian();
    if(res==0){
        cout<<"Not a eulerian graph"<<endl;
    }
    else if(res==1){
        cout<<"Euler Path exists"<<endl;
        g.printEulerianTour();
    }
    else{
        cout<<"Euler Cycle exists"<<endl;
        g.printEulerianTour();
    }
}
int main(){
    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(3, 2);
    g3.addEdge(3, 1);
    g3.addEdge(2, 4);
    test(g3);
    return 0;
}