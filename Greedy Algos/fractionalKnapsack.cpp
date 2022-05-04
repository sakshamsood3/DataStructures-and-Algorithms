#include<iostream>
#include<algorithm>
using namespace std;
class item{
    public:
    int itemid;
    int profit;
    int weight;
};
bool sort_pv(item a,item b){
    double val1=(double)a.profit/a.weight;
    double val2=(double)b.profit/b.weight;
    return val1>val2;
}
int main(){
    int n;
    cout<<"Enter the number of items n"<<endl;
    cin>>n;
    item arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter item id"<<endl;
        cin>>arr[i].itemid;
        cout<<"Enter weight of the item"<<endl;
        cin>>arr[i].weight;
        cout<<"Enter profit of the item"<<endl;
        cin>>arr[i].profit;
    }
    int max_weight;
    cout<<"Enter maximum weight allowed"<<endl;
    cin>>max_weight;
    sort(arr,arr+n,sort_pv);
    int curr_weight=0;
    int total_profit=0;
    for(int i=0;i<n;i++){
        if(curr_weight+arr[i].weight<max_weight){
            total_profit+=arr[i].profit;
            curr_weight+=arr[i].weight;
            cout<<"Item with item id"<<arr[i].itemid<<" selected"<<endl;
        }
        else{
            total_profit+=((double)(max_weight-curr_weight)/arr[i].weight)*arr[i].profit;
            curr_weight=max_weight;
            cout<<"Item with item id"<<arr[i].itemid<<" selected"<<endl;
        }
    }
    cout<<"Total Profit "<<total_profit<<endl;
    return 0;
}
