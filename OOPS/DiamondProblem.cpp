//**********************DIAMOND PROBLEM*******************************
//compile time is faster than Runtime 
//compile time -> less logical
//Runtime time -> more logical
//virtual ki help se mai compile time pr decide nhi krta hu ki konsa walk method call kru jo teacher inherit krke laya hai class person se ya fir jo Reseracher inherit krke laya hai class Person se

//virtual runtime pr dekhega ki class Teacher and class Researcher dono Class person ko inherit kr rhe hai and iska mtlb person ka walk function bhi dono access kr skte hai

//Class Professor ---> class Teacher and class Reasearcher dono ko inherit krti hai

//so with the help of virtual , jb runtime pr dikhega ki teacher class and Researcher class dono person ka same walk function inherit kr rhi hai, toh wo runtime pr same copy dono ko share krdega, and p.walk() successfully execute ho jayega

//vitual ki help se mai same copy la pata hu




#include <iostream>
using namespace std;

class Person{
  public:
    void walk(){
        cout<<"walking"<<endl;
    }
};

class Researcher : virtual public Person{
    public:
    void research(){
        cout<<"Paper researching"<<endl;
    }
};

class Teacher : virtual public Person{
    public:
    void teach(){
        cout<<"Teaching"<<endl;
    }
};

//class Teacher and Reseracher dono class Person ko inherit kr rhe hai,and class professor in dono classes ko inherit kr rha hai ,toh iska mtlb Professor bhi ek trike se Person ko inherit kr rha hai (indirectly)

class Professor: public Teacher,public Researcher{
    public:
    void bore(){
        cout<<"Feel Boring"<<endl;
    }
};

int main() {
    // Write C++ code here
   
   Professor p;
   p.bore();
   p.teach();
   p.research();
   //p.walk();//is jgh ye confuse ho gya , qki ise nhi pta ki konsa walk method call krna hai, and ye sb compile time pr decide ho rha h
   
  //compile time pr jb code compile hua toh class person se class teacher ko bhi ek walk method mila inheritance se
  //and class Researcher ko bhi ek walk method mila class Person se inheritance ke through
  
  //and Professor undono ko inherit kr rha hai, but compile time pr hi Professor ka object confuse hogya ki konsa walk method call kru either class Teacher ka or class Researcher ka
  
  //thats why error aagya, qki wo compile pr decide hi nhi kr paya ki konsa walk method call krna hai
  
  
  //so there are TWO solutions;
//   1.Scope Resolution Operator(bekar solution)
    // p.Teacher::walk();
    // p.Researcher::walk();
   //successfully executed
   
// 2. using virtual keyword
p.walk();
  
    return 0;
}