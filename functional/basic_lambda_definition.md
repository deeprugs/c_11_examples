## Simple definition of lambda.

Check this link and this answer


Consider the definition of the below lambda. 
[ capture_list ]( argument_list ) -> return_type { code }

This basically expands into the following 

```
struct some_anonymous_type {
  // capture_list turned into member variables
  some_anonymous_type( /* capture_list turned into arguments */ ):
    /* member variables initialized */
  {}
  return_type operator()( argument_list ) const {
    code
  }
};
```



