#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id){
    // write your code here
    // base case
    if(n == 0)
        return;
    
    // rec case
    toh(n-1, t1id, t3id, t2id);     // faith A -> C using B
    cout << n << "[" << t1id << "->" << t2id << "]" << endl;    // Expectation A -> B using C - main motive
    toh(n-1, t3id, t2id, t1id);     // faith C -> B using A
}

int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
  }