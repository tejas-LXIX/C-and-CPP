#include<iostream>
using namespace std;

class Tejas
{
protected:
    int skills;
public:
    virtual int setSkillValue()
    {
        cout<<"tattiiiiii"; /*doesnt get executed because this function is overwritten by the Anshul and Chut setSkillValue() functions.*/
    }
};

class Anshul:public Tejas
{
    int setSkillValue()
    {
        skills=-57;
        cout<<"Anshul sucks "<<skills<<"\n";
    }
};

class Chut:public Tejas
{
    int setSkillValue()
    {
        skills=100;
        cout<<"chut "<<skills<<"\n";
    }
};

int main()
{
    Anshul A;
    Chut B;
    Tejas *pointer1=&A;
    Tejas *pointer2=&B;
    pointer1->setSkillValue();
    pointer2->setSkillValue();
}
