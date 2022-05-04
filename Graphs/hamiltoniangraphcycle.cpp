#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define n 4
void add(int i,int j,int a[n][n])
{
    a[i][j]=1;
    a[j][i]=1;
}
int main()
{
    int k=0;
    int a[n][n]={0};
    add(0,1,a);
    add(1,0,a);
    add(1,2,a);
    add(2,1,a);
    add(3,1,a);
    add(1,3,a);
    //add(2,3,a);
    //add(3,2,a);
    bool valid=false;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i);
    }
    do{
    k=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(a[v[i]][v[i+1]]==0)
        {   
            k=-1;
            break;
        }
       
    }
     if(k==0)
        {
            for(int j=0;j<n;j++)
            {
                valid=true;
                cout<<v[j]<<" ";
            }
            cout<<v[0];
            cout<<endl;
        }
    }while(next_permutation(v.begin(),v.end()));
if(!valid) cout<<"Hamiltonian Path/Cycle doesn't exist"<<endl;
}