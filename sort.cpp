#include<bits/stdc++.h>
using namespace std;

void mergee(vector<int>&arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void mergeisort(vector <int>&arr,int low,int high){
    if(low>=high) return;
    int mid=(low + high) / 2;
    mergeisort(arr,low,mid);
    mergeisort(arr,mid+1,high);
    mergee(arr,low,mid,high);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    mergeisort(arr, 0, n-1);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}