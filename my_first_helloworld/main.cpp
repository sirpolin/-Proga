int x = 4;

class A{
int x;
public:
A(int n = 1);
virtual int f(int a = 0, int b = 0);
};

class B{
int x;
public:
B(int n = 2);
int f(int a = 0);
};

class C : public A, public B {
int x;
public: C(int n = 3);
int f(int a, int b = 0);
int g(A *p);
};

A *p;
C c;

int main() {
//p = &c;
//x = c.g(p);
////x = c.f();
//x = c.f(x);
//x = c.f(x, 1);
//x = p->f();
//x = p->f(x);
//x = p->f(x, 1);
return 3;
}
