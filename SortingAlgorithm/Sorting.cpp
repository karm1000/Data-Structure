#include <iostream>
using namespace std;

void insertion_sort(int *arr, int length){
    for (int i = 1; i < length ; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // while (j>=0 && arr[j]>key)//Non Decreasing 
        while (j>=0 && arr[j]>key)//Non Increasing
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
}

void quick_sort(int *a,int s,int e){
    if(s==e) return;

    int key = a[s];
    int up = s+1;
    int down = e;

    while(up<=down){
            
        while(key>=a[up] && up<=e)
            up++;
        
        while(key<a[down] && down>=s)
            down--;
        
        if(up<down){
            int temp = a[down];
            a[down]=a[up];
            a[up]=temp;
        }
    }

    int p = a[down];
    a[down] = key;
    a[s] = p;
    
    if(s!=down)quick_sort(a,s,down-1);
    if(e!=down)quick_sort(a,down+1,e);
}

void merge(int *a,int s,int m,int e){
    int indexOfX=0;
    int indexOfY=0;
    int sizeOfX =  m-s+1;
    int sizeOfY = e-m;
    int *x = new int[sizeOfX],*y=new int[sizeOfY];
    for(int n=0;n<m-s+1;n++){
        x[n]=a[s+n];
    }
    for(int n=0;n<e-m;n++){
        y[n]=a[m+1+n];
    }
    int n=s;
    
    while(indexOfX<sizeOfX && indexOfY<sizeOfY){
        if(x[indexOfX]>y[indexOfY]){
            a[n++] = y[indexOfY++];
        }else{
            a[n++] = x[indexOfX++];
        }
    }

    while(indexOfX<sizeOfX){
        a[n++] = x[indexOfX++];
    }

    while(indexOfY<sizeOfY){
        a[n++] = y[indexOfY++];
    }
}

void merge_sort(int *a,int s,int e){
    if(s==e)return;

    int mid = int((e-s)/2);
    mid += s;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    merge(a,s,mid,e);
}

void selection_sort(int *a,int length){
    for(int i=0;i<length;i++){
        int min = i;
        for(int j=i;j<length;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int* counting_sort(int *a,int length){
    int max=a[0];
    int *b = new int[length];

    for(int i=1;i<length;i++){
        if(a[i]>max){
            max = a[i];
        }
    }

    int *countArray = (int*)calloc(max+1,sizeof(int));
    int *indexArray = (int*)calloc(max+1,sizeof(int));

    for(int i=0;i<length;i++){
        countArray[a[i]]+=1;
    }

    for(int i=0;i<max+1;i++)cout<<countArray[i]<<" ";
    cout<<endl;

    for(int i=0;i<max+1;i++){
        indexArray[i] = (i==0?-1:indexArray[i-1])+countArray[i];
    }

    for(int i=0;i<max+1;i++)cout<<indexArray[i]<<" ";
    cout<<endl;

    for(int i=length-1;i>=0;i--){
        b[indexArray[a[i]]] = a[i];
        indexArray[a[i]]--;
    }

    return b;
}