#include<iostream>
using namespace std;

class Enemy
{
protected:
    int attackpower;
public:
    void setAttackPower(int x)
        {
            attackpower=x;
        }
};

class Ninja:public Enemy
{public:
    void attack()
    {
        cout<<"i am a ninja "<<attackpower;
    }
};

class Monster:public Enemy
{
public:
    void attack()
    {
        cout<<"\ni am a monster "<<attackpower;
    }
};

int main()
{
    Ninja n;
    Monster m;
    Ninja *enemy1=&n;
    Monster *enemy2=&m;
    enemy1->setAttackPower(35);
    enemy2->setAttackPower(97);
    enemy1->attack();
    enemy2->attack();
}
