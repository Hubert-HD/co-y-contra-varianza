public class Main {
  public static void main(String[] args) {
    X myX = new X();
    Y myY = new Y();
    B myImplementsB = new ImplementsB();
    C myImplementsC = new ImplementsC();

    myY.receive(myImplementsB); // print: recibido tipo B desde Y
    myY.receive(myImplementsC); // print: recibido tipo B desde Y

    B myB1 = myX.create(); // print: crea tipo B desde X
    C myB2 = myX.create(); // error: incompatible types: B cannot be converted to C
  }
}

public interface A {
  public abstract void methodA();
}

public interface B extends A{
  public abstract void methodB(); 
}

public interface C extends B {
  public abstract void methodC(); 
}

class X {
  public void receive(B param) {
    System.out.println("recibido tipo B desde X");
  }

  public B create() {
    System.out.println("crea tipo B desde X");
    return new ImplementsB();
  }
}

class Y extends X {
  @Override
  public void receive(B param) {
    System.out.println("recibido tipo B desde Y");
  }

  @Override
  public B create() {
    System.out.println("crea tipo C desde Y");
    return new ImplementsC();
  }
}

class ImplementsA implements A {
  public void methodA() {
    System.out.println("methodA desde ImplementsA");
  }
}

class ImplementsB implements B {
  public void methodA() {
    System.out.println("methodA desde ImplementsB");
  }
  
  public void methodB() {
    System.out.println("methodB desde ImplementsB");
  }
}

class ImplementsC implements C {
  public void methodA() {
    System.out.println("methodA desde ImplementsC");
  }
  
  public void methodB() {
    System.out.println("methodB desde ImplementsC");
  }

  public void methodC() {
    System.out.println("methodC desde ImplementsC");
  }
}