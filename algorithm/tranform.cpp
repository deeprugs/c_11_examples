// transform has 2 flavors.
// unary and binary transform

// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

int op_increase (int i) { return ++i; }

int main () 
{
  std::vector<int> foo;
  std::vector<int> bar;

  // set some values:
  for (int i=1; i<6; i++)
    foo.push_back (i*10);                         // foo: 10 20 30 40 50

  // This line will ensure that foo and bar are the same sizes.
  bar.resize(foo.size());                         // allocate space

  // unary transform
  std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);
                                                  // bar: 11 21 31 41 51

  // binary transforms : std::plus adds together its two arguments:
  std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
                                                  // foo: 21 41 61 81 101
  // foo contains: 21 41 61 81 101
  std::cout << "foo contains:";
  for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

#if 1
  // Sudeep : We can also use a lambda function here.
  std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(),[](int a, int b){return a+b;}); 
#endif 

  //foo contains: 32 62 92 122 152
  std::cout << "foo contains:";
  for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
