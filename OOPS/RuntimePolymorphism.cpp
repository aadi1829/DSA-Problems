#include<bits/stdc++.h>
using namespace std;

//with virtual keyword compiler compile time pr decide nhi krta ki ek particular object ka konsa function call krenge
//jb runtime pr object ko memory allocate hogi, tb decide hoga ki jis type ka object hai usi ka function call krna hai

// virtual helps in loose binding
//compiler done static binding at compile time

//Note:heap allcate hoti hai runtime pr
//and stack memory allocate hoti hai compile time pr
//virtual keyword ki help se compile time pr decision nhi liya jata hai
class Animal{
  public:
  virtual void sound(){
      cout<<"Animal is speaking"<<endl;
  }
  
  virtual ~Animal(){
      cout<<"Animal dtor called";
  }
};

class Dog : public Animal{
  public:
  void sound(){
      cout<<"Dog is barking"<<endl;
  }
    ~Dog(){
      cout<<"Dog dtor called"<<endl;
  }
};

class Cat:public Animal{
    public:
    void sound(){
        cout<<"Cat is Mewing"<<endl;
    }
   ~Cat(){
      cout<<"Cat dtor called";
  }
};

class Parrot:public Animal{
    public:
    void sound(){
        cout<<"Parrot is Mewing"<<endl;
    }
    ~Parrot(){
      cout<<"Parrot dtor called";
  }
};

//animal->sound()..is behaving as per required object allocated at runtime
void sound(Animal*animal){
    animal->sound(); //ye ek polymorphic statement hai, Animal different forms mai exist kr rhe hai
}

int main(){
    
    Animal*a1 = new Dog();//without virtual keyword, yha pr compileTime pr hi decide ho rha hai, ki jis bhi class ka pointer hai usi ka function call krna hai
    sound(a1);
    
    Animal*a2 = new Cat();
    sound(a2);
    
    Animal*a3 = new Parrot();
    sound(a3);
    
    Dog*d1 = new Dog();
    sound(d1);
    
    /* virtual ek trika hai --> decision ko runtime pr chhodne ka
    
    virtual ek trika hai late binding krne ka
    virtual compiler ko bolta hai things would not be taken seriously right now, it will be decided at runtime
    
    
    New Problem: without virtual destructor
    jb mai a1 ko delete kr rha tha, toh compile time pr hi decide ho rha tha ki ye animal destructor call hoga
    jisse age maine Dog object mai koi heap memory allocate ki hui hoti, toh wo delete hi nhi ho pati , qki dog ka destructor call hi nhi hua

    solution:with virtual destructor
    now, ab ye runtime pr decide hoga ki kiska destructor call hoga, so, phle dog ka destructor call hota hai, then Animal ka destructor call hota hai
    
    
    Virtual keyword ka use Hmesha Parent Class mai hota hai
    
*/
    
    delete a1;
    
    
    return 0;
}