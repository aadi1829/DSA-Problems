#include<iostream>
#define PI 3.14
#define MAX(x, y) x > y ?x : y 

//code readble bn gya , code ki reusability bdh gyi
//sirf mai top mai change krdo, baki toh apne aap change ho jayega

using namespace std;

void circleArea(int r){
    cout<<"circle area is "<< PI*r*r<<endl;
}

void circlePerimeter(int r){
    cout<<"Circle Perimeter is "<< 2*PI*r<<endl;
}



int main(){
    
    circleArea(3);
    circlePerimeter(3);
    
    int a = 5;
    int b = 7;
    int c = MAX(5,7);
    cout<<c<<endl;
    
    /*
    compiler code ko compile krne se phle usko read krta hai and usi time pr wo preprocess krta hai code ko, 
    preprocessor ek tool hai compiler ka,
    wo jha bhi PI dekhega , usko uski value se replace krdega preprocess time mai */
    return 0;
}