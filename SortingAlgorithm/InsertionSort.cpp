#include <iostream>
#include <stdlib.h>
#include <array>
using namespace std;

int main(){
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i]=i+1;
    }
    clock_t start,end;
    start = clock();
    for (int i = 1; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // while (j>=0 && arr[j]>key)//Non Decreasing 
        while (j>=0 && arr[j]<key)//Non Increasing
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken<<endl;
    cout<<double(CLOCKS_PER_SEC);
    // for(int i:arr){
    //     cout<<i<<" ";
    // }
    
    return 0;
}