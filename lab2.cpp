// 虚基类(验证)
// 验证虚基类的编译/执行机制、内存空间占用
#include<iostream>  
using namespace std;  

class A  //大小为4  
{  
public:  
    int a;
    A(int x){
        a = x;
        cout << "A constructed." << endl;
    }
};  
class B :virtual public A  //大小为12，变量a,b共8字节，虚基类表指针4  
{  
public:  
    int b;
    B(int x, int y):A(x){
        b = y;
        cout << "B constructed" << endl;
    }
};
class C :virtual public A //与B一样12
{
public:  
    int c;
    C(int x, int y):A(x){
        c=y;
        cout << "C constructed." << endl;
    }
};  
class D :public B, public C //24,变量a,b,c,d共16，B的虚基类指针4，C的虚基类指针4，16+4+4=24bytes
{
public:
    int d;
    // D(int x, int y, int z, int j):B(x, y), C(x, z), A(x){
    D(int x, int y, int z, int j):B(y, y), C(x, z), A(x)
    {
        d = j;
        cout << "D constructed." << endl;
    }
};

int main()  
{  
    // A a(1);
    // B b(1, 2);  
    // C c(1, 3);  
    D d(100, 2, 3, 4);  
    // cout << sizeof(a) << endl;  
    // cout << sizeof(b) << endl;  
    // cout << sizeof(c) << endl;  
    cout << sizeof(d) << endl;
    cout << d.a << endl;
    system("pause");  
    return 0;  
}  