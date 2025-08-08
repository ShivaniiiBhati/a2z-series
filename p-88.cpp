#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*this is the solution for leetcode problem merge two sorted arrays ,without extra space
  if nums1={1,2,3,0,0,0} last zeroes are for the elements of nums2 array*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        while( left >=0 && right <n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                right++ , left--;
            }else break;

        }
        sort(nums1.begin(),nums1.begin() +m);
        sort(nums2.begin(),nums2.begin() +n);

        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
    }
};