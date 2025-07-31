#include <iostream>
#include <string>
using namespace std;

/*variable lifecycle
// 1.init
// 2.copy
3.destroy*/

class Student{
  public:
  int id;
  string name;
  int *v;
  
  Student(){
      cout<<"Default Constructor Called"<<endl;
  }
  //getter and setter
  Student(const Student &obj){//for best practice, write const infront of argument , so make it read only to prevent from hackers
    //   if there is not const
      
    //   obj.name = "Aashish"<<endl; //koi object ko modify na krde usse bchne ke liye we use const keyword
      cout<<"Copy constructor called"<<endl;
      this->id = obj.id;
      this->name = obj.name;
      this->v = new int(*(obj.v)); //for deep copy Allocate new memory and copy value
}
    
  
  Student(int id,string name){
      cout<<"Parameterized Constructor Called"<<endl;
      this->id = id;
      this->name = name;
      this->v = new int(20);
  }
  
  void sleep(){
      cout<<"Student is sleeping";
  }
  
  
  //if you do not write dtor, compiler will handle it
  //compiler wala destructor hr baar safe nhi hai
  
//suppose mai object bnate time v ko heap se memory allocate krdi but agr mai default destructor ke throught object delete hota hai,toh memory leka hota hai
//qki object toh delete hogya but jo v ke liye memory heap se allocate ki thi wo delete nhi hui thats why hm apna khudka destructor likhte hai taki jo bhi memory hmne assign ki hai object creation ke time pr heap se, use hm delete krpaye when object is going to be desroyed
  ~Student(){
      cout<<"Destructor is Called"<<endl;
      delete v;
  }
};

int main() {
    
    // Student *s = new Student(1,"aaditya");
    Student s1(1,"Aaditya");
    Student s2 = s1;
    cout<<s1.name<<endl;
    cout<<s2.name<<endl;
    cout<<*(s1.v)<<endl;
    cout<<*(s2.v)<<endl;
    
    *(s2.v) = 40;//Set the value at the pointer
    cout<<*(s2.v)<<endl;
    cout<<*(s1.v)<<endl;
    
    // Student s2; //isline tk isko nhi pta tha ki aage is object ko kisi aur object ki values assign ho jayengi thats why default constructor called ho gya tha
    // s2 = s1;
    // cout<<s1.name<<endl;
    // cout<<s2.name<<endl;
    
    // delete s;
    
    // cout<<s->name<<endl;
    
    return 0;
}