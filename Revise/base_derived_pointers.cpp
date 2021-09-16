// C++ program for function overriding

#include <bits/stdc++.h>
using namespace std;

class base
{
public:
	virtual void print ()
	{ cout<< "print base class" <<endl; }

	void show ()
	{ cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
	void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
	{ cout<< "print derived class" <<endl; }

	void show ()
	{ cout<< "show derived class" <<endl; }
};

//main function
int main()
{
	base *bptr;
	derived d;
	bptr = &d;
  	//base pointers can point to derived objects, but not vice-versa.
    
  	/*derived *x;   these three lines give ana error.
  	base y;
  	x=&y;*/

  	//inheritance,where the function in Derived overrides the function in base.
	d.print();
  	d.show();

	//virtual function, binded at runtime (Runtime polymorphism)
	bptr->print();  //will call the print function of the derived class since print is a virtual function in base class
	
	// Non-virtual function, binded at compile time
	bptr->show();   //will call the print function of the base class since the pointer is of "base" datatype.

    /*so, the output is:
    print derived class
    show derived class
    print derived class
    show base class */
	return 0;
}
