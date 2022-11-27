#include <iostream>
using namespace std;

class A {
  public:
    virtual void methodA() = 0;
};

class B :public A{
  public:
    virtual void methodB() = 0;
};

class C :public B{
  public:
    virtual void methodC() = 0;
};

class ImplementsA :public A {
  public:
    void methodA() {
      cout << "methodA desde ImplementsA" << endl;
    }
};

class ImplementsB :public B {
  public:
    void methodA() {
      cout << "methodA desde ImplementsB" << endl;
    }
    void methodB() {
      cout << "methodB desde ImplementsB" << endl;
    }
};

class ImplementsC :public C {
  public:
    void methodA() {
      cout << "methodA desde ImplementsC" << endl;
    }
    
    void methodB() {
      cout << "methodB desde ImplementsC" << endl;
    }

    void methodC() {
      cout << "methodC desde ImplementsC" << endl;
    }
};

class X {
  public:
    void receive(B* param) {
      cout << "recibido tipo B desde X" << endl;
    }

    B* create() {
      cout << "crea tipo B desde X" << endl;
      return new ImplementsB();
    }
};

class Y :public X {
  public:
    void receive(B* param) {
      cout << "recibido tipo B desde Y" << endl;
    }

    B* create() {
      cout << "crea tipo C desde Y" << endl;
      return new ImplementsC();
    }
};

int main() {
  X* myX = new X();
  Y* myY = new Y();
  A* myImplementsA = new ImplementsA();
  B* myImplementsB = new ImplementsB();

  myY->receive(myImplementsA); // error: incompatible types: A* cannot be converted to B*
  myY->receive(myImplementsB); // print: recibido tipo B desde Y

  A* myB1 = myX->create(); // print: crea tipo B desde X
  B* myB2 = myX->create(); // print: crea tipo B desde X
}