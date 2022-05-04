#include<iostream>
#include<algorithm>
using namespace std;
class Activity{
    public:
    int start;
    int finish;
};
bool sort_act(Activity a,Activity b){
    return a.finish<b.finish;
}
int main(){
    int n;
    cin>>n;
    Activity arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter start time "<<endl;
        cin>>arr[i].start;
        cout<<"Enter finish time"<<endl;
        cin>>arr[i].finish;
    }
    sort(arr,arr+n,sort_act);
    int i=0;
    cout<<"The following activities are selected"<<endl;
    cout<<arr[i].start<<"-"<<arr[i].finish<<" ";
    for(int j=0;j<n;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].start<<"-"<<arr[j].finish<<" ";
            i=j;
        }
    }
    return 0;
}
