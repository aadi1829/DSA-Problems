#include<iostream>
using namespace std;

class Vector{
  int x;
  int y;
  
//   Vector(int x,int y){
//       this->x = x;
//       this->y = y;
//   }
  public:
  Vector(int x,int y): x(x),y(y){}
  
  
  //Operator Overloading
  
  void operator+(const Vector&obj){
      this->x  = this->x + obj.x;
      this->y = this->y + obj.y;
  }
  
  void operator-(const Vector&obj){
      this->x  = this->x - obj.x;
      this->y = this->y - obj.y;
  }
  
    Vector& operator++() {
        this->x++;
        this->y++;
        return *this;
    }
  
  
  void display(){
      cout<<"value of x "<<this->x<<endl;
      cout<<"value of y "<<this->y<<endl;
  }
  
};


int main(){
    Vector v1(2,4);
    Vector v2(4,8);
    
    v1.display();
    v2.display();
    
    v1 + v2;
    
    v1.display();
    v1 - v2;
    v1.display();
    
    ++v1;
    v1.display();
    
    return 0;
}