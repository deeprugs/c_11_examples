#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

// To me, this is the most intuitive initialization of 
// vector.
vector<int> vec2 = { 10, 20, 30 };

int main()
{
	for (auto i: vec2)
	{
		cout<<i<<" ";
	}
	cout <<"\n";

   vector<double> v = { 1, 2, 3.456, 99.99 };

   // Sudeep: The syntax of for_each looks like a 
   // function with 3 arguments.  Observe the comma ,
   // that indicates that the begin iterator and the 
   // end iterator are separated by "," with the 
   // final argument being a lambda. It could also 
   // have a functor or function name. 
   for_each (v.begin(), v.end(), [](double x) { 
			cout<<"From the lambda. The x is the de-referenced iterator. :"<<x<<"\n"; 
   });

   list<pair<string,string>> languages = {
        {"CPP","Stroustrup"}, {"Richards","BCPL"}, {"Ritchie","C"}
    }; 
    map<vector<string>,vector<int>> years = {
        { {"Maurice","Vincent", "Wilkes"},{1913, 1945, 1951, 1967, 2000} },
        { {"Martin", "Ritchards"}, {1982, 2003, 2007} }, 
        { {"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004} }
    }; 

	return 0;
}
