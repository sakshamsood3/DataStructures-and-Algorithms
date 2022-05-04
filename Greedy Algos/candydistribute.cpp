#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=7;
    int arr[n]={1,1,7,3,4,2,1};
    int min_candy=0;
    sort(arr,arr+n);
    int prev_candy=1;
    int curr_candy;
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[i]==arr[j]){
            curr_candy=prev_candy;
            min_candy+=curr_candy;
        }
        else{
            prev_candy++;
            curr_candy=prev_candy;
            min_candy+=curr_candy;
        }
    }
    cout << min_candy << endl;
    return 0;
}
