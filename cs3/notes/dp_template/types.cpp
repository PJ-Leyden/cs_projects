// demonstrates class access modifiers
// Mikhail Nesterenko
// 1/28/2014

class A {
public:
  int x_;
protected:
  int y_;
private:
  int z_;
};

class B : public A {
  // x_ is public
  // y_ is protected
  // z_ is not accessible from B
};

class C : protected A {
  // x_ is protected
  // y_ is protected
  // z_ is not accessible from C
};

class D : private A {
  // x_ is private
  // y_ is private
  // z_ is not accessible from D
};
