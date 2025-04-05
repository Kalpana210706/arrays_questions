#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr,int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int secondLargest(vector<int> &a,int n){
    int largest = a[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i]< largest && a[i]>slargest){
            slargest = a[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> &a,int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i = 1;i<n;i++){
        if(a[i]<smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]!= smallest && a[i]<ssmallest){
            ssmallest = a[i];
        }
    }

}
vector<int> getSecondOrderElements(int n,vector<int> a){
    int slargest = secondLargest(a,n);
    int ssmallest = secondSmallest(a,n);
    return {slargest,ssmallest};
}

//O(n)-->time complexity
int isSorted(int n,vector<int> a){
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int removeDuplicates(vector<int> &arr,int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!= arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

void leftRotate(int arr[],int n,int d){
    d =d%n;

    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for(int i =d;i<n;i++){
        arr[i-d] = arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i]= temp[i-(n-d)];
    }
}

//can also the above by
//reverse(a,a+d)
//reverse(a+d,a+n)
//reverse(a,a+n)

void leftRotatee(int arr[],int n,int d){
reverse(arr,arr+d);
reverse(arr+d,arr+n);
reverse(arr,arr+n);
}

void reverse(int arr[],int start,int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

//brute force approach to move all zeros 
vector<int> moveZeros(int n,vector<int> a){
    //step-1
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i]!= 0){
            temp.push_back(a[i]);
        }
    }
    //step-2
    int nz = temp.size();
    for(int i=0;i,nz;i++){
        a[i]=temp[i];
    }

    //step-3
    for(int i = nz;i<n;i++){
        a[i] = 0;
    }

    return a;
}

//optimal solution to move all the zeros (which we need to tell to the interviewer)
vector<int> moveZeross(int n,vector<int> a){
    int j= -1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j = i;
            break;
        }
    }
    // no non zero numbers
    if(j== -1) return a;

    for(int i = j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }

    return a;
}

int linearSearch(int n,int num,vector<int> &arr){
    for(int i=0;i<num;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

//union of two sorted arrays
vector<int> sortedArray(vector<int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(a[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

//intersection of two sorted arrays
//brute force
vector<int> findArrayIntersection(vector<int> &A,int n,vector<int> &B,int m){
    vector<int> ans;
    int vis[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==B[j] && vis[j]==0){
                ans.push_back(A[i]);
                vis[j]=1;
                break;
            }
            if(B[j]>A[i]) break;
        }

        
    }
    return ans;
}

//optimal
//time complexity-->O(n1+n2)
//space complexity-->O(1)
vector<int> findArrayIntersectionn(vector<int> &A,int n,vector<int> &B,int m){
    int i=0;int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

