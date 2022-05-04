#include<iostream>
#include<algorithm>
using namespace std;
class Job{
    public:
    char jobid;
    int deadline;
    int profit;
};
bool sort_dv(Job a,Job b){
    return a.profit>b.profit;
}
int main(){
    int n;
    cout<<"Enter the number of jobs"<<endl;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter job id"<<endl;
        cin>>arr[i].jobid;
        cout<<"Enter the deadline of the job"<<endl;
        cin>>arr[i].deadline;
        cout<<"Enter the profit associated with the job"<<endl;
        cin>>arr[i].profit;
    }
    sort(arr,arr+n,sort_dv);
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++){
        slot[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    int max_profit=0;
    for(int i=0;i<n;i++){
        if(slot[i]==true){
            cout<<arr[result[i]].jobid<<" ";
            max_profit+=arr[result[i]].profit;
        }
    }
    cout<<endl;
    cout<<max_profit<<endl;
 return 0;   
}
