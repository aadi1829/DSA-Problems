#include<bits/stdc++.h>
using namespace std;

class Bird{
public:
  int age;
  string color;
  int weight;
  int numberOfLegs;
  
  Bird(int age,string color,int weight,int numberOfLegs){
      cout<<"Bird Parameterized Constructor is called"<<endl;
      this->age = age;
      this->color = color;
      this->weight = weight;
      this->numberOfLegs = numberOfLegs;
  }
  
  Bird(){
      cout<<"Parent constructor is called"<<endl;
  }
  
  void fly(){
      cout<<"Bird is flying"<<endl;
  }
  
  void drink(){
      cout<<"Bird is drinking water";
  }
};

class Sparrow : private Bird{
    public:
    int height;
    // Sparrow(int age,int weight,int numberOfLegs, string color){
    //     cout<<"Sparrow contructor is called"<<endl;
    //     this->age = age;
    //     this->weight = weight;
    //     this->color = color;
    //     this->numberOfLegs = numberOfLegs;
    // }
    
    Sparrow(int age,string color,int weight, int numberOfLegs, int height) : Bird(age,color,weight,numberOfLegs){
        cout<<"Sparrow Parameterized constructor called"<<endl;
        this->height = height;
    }
    
    // void display(){
    //     cout<<"age is "<<this->age<<endl;
    // }
    
    void display(){ //ye variable toh public and protected dono usme access ho rha hai
        cout<<"age is "<<age<<endl;
    }
    
    // int getAge(){
    //     return this->age;
    // }
    
        
    int getAge(){//for protected
        return age;
    }
    
    void grassing(){
        cout<<"Sparrow is Grassing"<<endl;
    }
};

class Peigon : public Bird{
    public:
    void guttering(){
        cout<<"Peigon is Guttering"<<endl;
    }
};

int main(){
    
    
    // Sparrow s1;
    // s1.grassing();
    // s1.fly();
    // s1.drink();
    
    Sparrow s1(3, "brown", 2, 1, 2);
    cout<<s1.getAge()<<endl;
    s1.display();

    // cout<<s1.age<<endl;
    // cout<<s1.color<<endl;
    
    cout<<endl;
    
    Peigon p;
    p.guttering();
    p.fly();
    p.drink(); 
    
    
    
    
    
    
    
    
    
    
    return 0;
}