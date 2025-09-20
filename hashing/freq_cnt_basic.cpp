#include <bits/stdc++.h>

using namespace std;


/*
Hashing - A technique used to store the numbers with their frequencies in easy manner 


Question :- You are given an array of size “n” ;
you are also given “Q” queries for each of the query 
please tell how many times a given number occurs in the array 
*/
int32_t main(){

    int n;
    cin>>n; // size of arr

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i]; // arr inpt
    }

    int q;
    cin>>q; // no. of queries u wana find

    for(int i=0;i<q;i++){
        int num;
        cin>>num; // inpt the query
        int cnt = 0;

        for(int j=0;j<n;j++){
        if(arr[j] == num){
            cnt++;
        }



    }
        cout<< cnt<<"\n"; 


    }





    return 0;
}