// shared_ptr constructor example
#include <iostream>
#include <memory>

struct C {int* data;};

int main () {
  std::shared_ptr<int> p1;
  std::shared_ptr<int> p2 (nullptr);

  //Observe that p3 will be pointing to the new int.  
  std::shared_ptr<int> p3 (new int);

  // This is initialization with destructors. 
  std::shared_ptr<int> p4 (new int, std::default_delete<int>());
  std::shared_ptr<int> p5 (new int, [](int* p){delete p;}, std::allocator<int>());


  // Another way of declaring a shared_ptr is using the make_shared utility.
  auto another_shared_ptr = std::make_shared<int>(5);
  std::cout<< "This is another_shared_ptr :"<<*another_shared_ptr<<endl;

  //
  std::shared_ptr<int> p6 (p5);

  std::cout << "the first p6: " << p6.use_count() << '\n';
  std::cout << "p5: " << p5.use_count() << '\n';

#if 0
  // Sudeep : This is also legal. The use_count value will increase.
  // and p5,p6,p7 will all point to the same memory.
  std::shared_ptr<int> p7;
  p7 = p6;
  p6 = nullptr; // this will make p6 as nullptr and also decrease the reference count;
  std::cout << "Now moved into p7--- the second p6 usecount : " << p6.use_count() << '\n';
#else
  // Move whatever p6 was pointing to. 
  std::shared_ptr<int> p7 (std::move(p6));
  std::cout << "Now moved into p7--- the second p6 usecount : " << p6.use_count() << '\n';
#endif

  std::cout << "p5: " << p5.use_count() << '\n';
  std::cout << "p7: " << p7.use_count() << '\n';

  //What exactly are we trying to do here ?
  std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));

  std::shared_ptr<C> obj (new C);
  std::shared_ptr<int> p9 (obj, obj->data);

  std::cout << "use_count:\n";
  std::cout << "p1: " << p1.use_count() << '\n';
  std::cout << "p2: " << p2.use_count() << '\n';
  std::cout << "p3: " << p3.use_count() << '\n';
  std::cout << "p4: " << p4.use_count() << '\n';
  std::cout << "p5: " << p5.use_count() << '\n';
  std::cout << "p6: " << p6.use_count() << '\n';
  std::cout << "p7: " << p7.use_count() << '\n';
  std::cout << "p8: " << p8.use_count() << '\n';
  std::cout << "p9: " << p9.use_count() << '\n';
  return 0;
}
