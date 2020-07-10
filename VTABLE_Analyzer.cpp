using namespace std;
#include<iostream>
class Base
{
    public:
    int i,j;                        //characteristics
    virtual void fun()              //Defination
    {
        cout<<"base fun\n";
    }
    virtual void gun()              //Defination
    {8
        cout<<"base gun\n";
    }
    void sun()                      //Defination
    {
        cout<<"base sun\n";
    }
};
class Derived:public Base           //single level inheritance
{
    public:
    int x,y;                        //characteristics
    void fun()                      //Overriding
    {
        cout<<"derived fun\n";
    }
    void sun()                      //Redefination
    {
        cout<<"derived sun\n";
    }
    virtual void run()              //Defination
    {
        cout<<"derived run\n";
    }
};
int main()
{
    Base bobj;
    Derived dobj;
    cout<<sizeof(bobj)<<"\n"<<sizeof(dobj)<<"\n";
    
    long int *op=(long int *)(&dobj);
    cout<<"base address of bobj is:"<<op<<"\n";

    long int *vptr=(long int *)(*op);
    cout<<"address of vtable is:"<<vptr<<"\n"; 

    void (*fp)();
    fp=(void(*)())(*vptr);
    fp();
    fp=(void(*)())(*(vptr+1));
    fp();
    fp=(void(*)())(*(vptr+2));
    fp();
    return 0;
}