/* This file illustrates the function of std::bind and std::function 

Basically the return value of std::bind is a std::function.
std::bind and std::placeholders can be used to hardcode some parameters of a function or change the order of
the parameters of a function etc. And this can be assigned to an std::function.

Check this out ::
https://stackoverflow.com/questions/9054774/difference-between-stdfunction-and-a-standard-function-pointer

A function pointer is the address of an actual function defined in C++. An std::function is a wrapper that can hold any type of callable object (objects that can be used like functions). A callable object is a struct or class which overrides the "()" operator.

struct FooFunctor
{
    void operator()(int i) {
        std::cout << i;
    }
};

// Since `FooFunctor` defines `operator()`, it can be used as a function
FooFunctor func;
std::function<void (int)> f(func);

Edit: Binding

Alongside std::function, you will also find std::bind. These two are very powerful tools when used together.

void func(int a, int b) {
    // Do something important
}

// Consider the case when you want one of the parameters of `func` to be fixed
// You can used `std::bind` to set a fixed value for a parameter; `bind` will
// return a function-like object that you can place inside of `std::function`.

std::function<void (int)> f = std::bind(func, _1, 5); 
In that example, the function object returned by bind takes the first parameter, _1, and passes it to func as the a parameter, and sets b to be the constant 5.


This is according to the stackoverflow answer :
https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-and-when-should-they-be-used

One of the main use of std::function and std::bind is as more generalized function pointers. 
You can use it to implement callback mechanism. 
	One of the popular scenario is that you have some function that is going to take long time to execute 
	but you don't want to wait for it to return then you can run that function on separate thread 
	and give it a function pointer that it will callback after it completes.

Here's a sample code for how to use this:
*/

#include <iostream>     // std::cout
#include <functional>   // std::function, std::negate

class MyClass {
private:
    //just shorthand to avoid long typing
    typedef std::function<void (float result)> TCallback;

    //this function takes long time
    void longRunningFunction(TCallback callback,float result)
    {
        //do some long running task
        //...
        //callback to return result
        callback(result);
    }

    //this function gets called by longRunningFunction after its done
    void afterCompleteCallback(float result)
    {
        std::cout << __func__;
        std::cout << result;
    }

public:
    int longRunningFunctionAsync()
    {
        //create callback - this equivalent of safe function pointer
        auto callback = std::bind(&MyClass::afterCompleteCallback, 
            this, std::placeholders::_1);

		float res = 5.0;
        //normally you want to start below function on seprate thread, 
        //but for illustration we will just do simple call
        longRunningFunction(callback,res);

		// Sudeep: This is probably what the thread does after calling the 
		// longRunningFunction in a separate thread.
		// Observe that the "auto callback" is a global.
		return 0;
    }
};

int main()
{
	MyClass c;

	c.longRunningFunctionAsync();

}
