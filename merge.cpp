#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>&v,int l,int mid,int h){
    vector<int>temp;
    int left = l;
    int right = mid + 1;

    while(left<=mid && right<=h){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }

        else{
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid){
      temp.push_back(v[left]);
      left++;
    }

    while(right<=h){
        temp.push_back(v[right]);
        right++;
    }
    for(int i = l;i<=h;i++){
        v[i] = temp[i-l];
    }
}


void mergesort(vector<int>&v,int l,int h){
    if(l>=h) return;
    int mid = (l+h)/2;
    mergesort(v,l,mid);
    mergesort(v,mid+1,h);
    merge(v,l,mid,h); 
}

int main (){
    vector<int>v={4,1,3,9,7};
  
       
       mergesort(v,0,v.size()-1);
       for(int i = 0;i<v.size();i++){
        cout<<v[i];
       }



    return 0;
}