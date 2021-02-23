#include <iostream>
//Namespaces are basically used to separate variables,functions of the same signature(same name and parameters). This prevents ambiguity.

//using namespace std; // example of using directive. brings all std namespace members into current scope(which is the global scope here)

using std::cout; //FIRST example of using declaration. brings one specific namespace member into current scope(which is also the global scope here)

namespace Apple{
    int x=75,y=35,z=77;
    void func()
    {
        cout<<"this is a Apple func ";
    }
}
namespace Orange{
    void func(){
        cout<<"this is an orange func ";
    }
}
int z=68986;

class Base{
    public:
        void fun(){
            cout<<"fun function hai ye\n";
        }
};
class Derived:private Base{ //inheriting privately. this means f is a private member function in Derived class.
    public:
        void g(){
            using namespace std; //local scope. CANNOT BE DONE IN CLASS SCOPE.
            cout<<"Local scope of namespace std using directive\n";
        }
        void h(){
            using std::cout; //local scope. CANNOT BE DONE IN CLASS SCOPE.
            cout<<"Local scope of std::cout using declaration\n";
        }
        //using std::cout; wont work because not allowed in class scope.
        using Base::fun; //SECOND example of using declaration.CAN ONLY BE DONE IN CLASS SCOPE. Brings a member from base class to current class' scope.
        //it brings the function f from parent class into current class with PUBLIC ACCESS.
};

int main()
{
    int x=67;
    using namespace Apple; //brings all namespace members into current scope,so that we can use them without qualifier in front of them.
     //If you don't do this, then you can access x using Apple::x
    func(); //this wont work if you include namespace Orange too. ambiguous hoga. this is why namespaces are used,to separate same name members
    using namespace std;//more than one namespaces CAN be used simultaneously.
    cout<<x<<" "<<y<<endl;//<<z; //x=67 is output because local scope x is given priority over namespace and global variables. z is ambiguous because global as well as namespace z exists
    Derived obj;
    obj.fun(); //this wont work if you dont write using Base::fun; this is because fun is initially private in the Derived class because of private inheritance.
}