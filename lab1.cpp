#include<iostream>
using namespace std;

// 多继承的构造函数与析构函数(验证)

class B1
{
public:
	B1(int i)
	{
		b1 = i;
		cout << "consstructorB1." << i << endl;
	}
	void print()
	{
		cout << b1 << endl;
	}
	~B1()
	{
		cout << "destrustorB1." << endl;
	}
private:
	int b1;
};
class B2
{
public:
	B2(int i)
	{
		b2 = i;
		cout << "consructorB2." << i << endl;
	}
	void print()
	{
		cout << b2 << endl;
	
	}
	~B2()
	{
		cout << "destrustorB2." << endl;
	}
private:
	int b2;
};
class B3 
{
public:
	B3(int i)
	{
		b3 = i;
		cout << "constructorB3." << i << endl;
	}
	int getb3() 
	{
		return b3;
	}
	~B3()
	{
		cout << "destrustorB3." << endl;
	}
private:
	int b3;
};
class A :public B1, public B2
{
public:
	A(int i, int j, int k, int l) :B1(i), B2(j), bb(k)
	{
		a = l;
		cout << "constructorA." << l << endl;
	}
	void print()
	{
		B1::print();
		B2::print();

		cout << a << "," << bb.getb3() << endl;
	}
	~A()
	{
		cout << "destrustorA." << endl;
	}
private:
	int a;
	B3 bb;
};

void test(){
	A aa(1, 2, 3, 4);
	aa.print();
}
int  main()
{

	test();
    system("pause");
	return 0;
}