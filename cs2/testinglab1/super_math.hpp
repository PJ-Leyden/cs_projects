#ifndef SUPER_MATH_HPP
#define SUPER_MATH_HPP

namespace super_math
{
  /* 
     lhs = left hand side operator
     rhs = right hand side operator
  */

  // lhs + rhs
  int add(int lhs, int rhs);

  // lhs - rhs
  int subtract(int lhs, int rhs);

  // lhs / rhs
  double divide(double lhs, double rhs);

  // lhs == rhs
  bool equals(int lhs, int rhs);
  
  // lhs < rhs
  bool less_than(int lhs, int rhs);
}

#endif
