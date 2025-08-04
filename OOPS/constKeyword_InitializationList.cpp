#include <iostream>
using namespace std;


class abc{
  public:
  mutable int x; //1.agr mai x ko yha mutable declare krdu//used for debugging
  int *y;
  const int z; //a.suppose kro maine z ko const se initialize krdiya
  
//   abc(int _x,int _y){
//       x = _x;
//       y = new int(_y);
//   }

//   abc(int _x,int _y){
//       x = _x;
//       y = new int(_y);
//         z = _z; //b. old constructor mai z ko value assign nhi kr paunga after declaring it const
//   }


//INITIALIZATION LIST
    // abc(int _x,int _y) : x(_x),y(new int(_y)){
    //     cout<<"initialization constructor called"<<endl;
    // };
    
//Why we use Initialization list:-> it is a new moden way
//c. but mai is new moden constructor mai ye kaam kr skta hu
    abc(int _x,int _y,int _z) : x(_x),y(new int(_y)),z(_z){
        cout<<"value of z "<<this->z<<endl;
        cout<<"initialization constructor called"<<endl;
    };
  
  int getX() const
  {  
      this->x = 50;//2.toh mai x ko const function ke andr override kr skta hun
      return this->x;
      
  }
  
  void setX(int x) { this->x = x;}
  
  int getY() const
  { 
      return *y;
      
  }
  void setY(int val){
      *y = val;
  }
  
};
//object a koi bhi aisa function call nhi kr skta jo ki non-constant ho, sare const function hi aapko call krne pdenge
void print(const abc&a){//is function ke ande a obj modify nhi ho skta
    cout<<a.getX()<<" "<<a.getY()<<" "; 
}

int main() {
    
    abc a(1,2,3);
    
    print(a);
    
 
    return 0;
}