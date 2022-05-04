#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define n 4
void add(int i,int j,int c,int a[n][n])
{
    a[i][j]=c;
    a[j][i]=c;
}
int main()
{
    int a[n][n]={0};
    add(0,1,10,a);
    add(0,3,20,a);
    add(0,2,15,a);
    add(1,3,25,a);
    add(1,2,35,a);
    add(2,3,30,a);
    
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i);
    }
    int min=INT_MAX;
    do{
        int sum=0;
        int k=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(a[v[i]][v[i+1]]==0)
            {
                k=-1;
                break;
            }
            else{
            sum+=a[v[i]][v[i+1]];
            }
        }
        if(a[v[n-1]][v[0]]==0)
        {
                k=-1;
        }
        else{
            sum+=a[v[n-1]][v[0]];
        }

        if(k==0)
        {
                if(min>sum)
                {
                    min=sum;
                }
        }

    }while(next_permutation(v.begin(),v.end()));
    cout<<min;



}