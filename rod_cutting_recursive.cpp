#include <bits/stdc++.h>
using namespace std;




int rod_cutting(int lnt[],int price[],int len,int n){

    //base case (which is smallest possible valid value)
    if(len == 0 || n == 0){
        return 0;
    }
   
    //if the weight is less than or equal to length we simply accept it or reject it
    //then we choose maxm of accepted value or rejected value
    //in both case n is decreasing...first case length is decreasing also
    //if we reject the value it is fine ..we don'n want mutton as i am veg i don't again ask but i can ask multiple time for icecream that i love
    if(lnt[n-1] <= len){
        //we simply storing and returning the max value
        //if we accept it n will not decrease as we can again demands 
        return (max(price[n-1]+rod_cutting(lnt,price,len-lnt[n-1],n),rod_cutting(lnt,price,len,n-1)));
    }else if(lnt[n-1]>len){//this case we have to reject the value

         return (rod_cutting(lnt,price,len,n-1));
    }
}

int main(){
    int lnt[] = {1,2,3,4,5,6,7,8}; 
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int len = 8;
 
    int n = sizeof(price)/sizeof(price[0]);  
   

    cout<<rod_cutting(lnt,price,len,n)<<endl;
    return 0;
}
