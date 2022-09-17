#include <iostream>
#include "../Implementations/Node.hpp"

using namespace std;

class BucketSort{
    Node a[10];
    int n=10;//Number of bucket;
    public:
    void BucketSortArray(int arr[],int size){
        for(int i=0;i<size;i++){
            insert_in_bucket(arr[i]);
        }
        int index=0;
        int n=0;
        while(!bucketEmpty()){
            if(a[n].link==NULL) n++;
            else{
                arr[index++]=a[n].popFirst();
            }
        }    
    }

    bool bucketEmpty(){
        for(int i=0;i<10;i++){
            if(a[i].link != NULL){
                return false;
            }
        }
        return true;
    }

    void insert_in_bucket(int x){
        int r = range_of(x);
        a[r].insertSorted(x);
    }

    int range_of(int x){
        if(x>0 && x<10) return 0;
        else if(x>9 && x<20) return 1;
        else if(x>19 && x<30) return 2;
        else if(x>29 && x<40) return 3;
        else if(x>39 && x<50) return 4;
        else if(x>49 && x<60) return 5;
        else if(x>59 && x<70) return 6;
        else if(x>69 && x<80) return 7;
        else if(x>79 && x<90) return 8;
        else if(x>89 && x<100) return 9;
    } 
};

int main(){

    BucketSort s;
    int a[]={1,55,77,9,6,42,3,5,6,7,4,6,4,64,23,18,7,48,4,4,5,1,2,3,5,6,9,4,61,10,98,49,84,4,6};
    int size = sizeof(a)/sizeof(a[0]);
    s.BucketSortArray(a,size);

    cout<<"a = ";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b[]={99,98,97,96,95,94,93,92,91,8,80,78,9,2,6,5,4,5,3,66,3,66,45,65,23,56,48,32,14};
    int sizeb = sizeof(b)/sizeof(b[0]);

    s.BucketSortArray(b,sizeb);
    cout<<"b = ";
    for(int i=0;i<sizeb;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}