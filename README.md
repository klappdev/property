# property
This is simple C++ header only library for generate<br/>
getters and setters for members class.

Library can generate getter and setter for such members:<br/>
    > primitive members<br/>
    > object lvalue and rvalue members<br/>
    > pointer members<br/>
    > array members<br/>

When generate getter, setter for members classes occur in compile<br/>
time check types, name members, kind members using type traits   <br/>
library C++11/C++14.

Developer can write less code and to be sure that code write correct.

```C++
#include "property.hpp"

using namespace std;

class person {
   person() = default;
   ~person() = default;

   SETTER_PRIM(int, id);
   SETTER_FLAG(bool, merried);

   SETTER_PTR(int, next);
   SETTER_ARR(std::string, address, 5);

   SETTER_OBJ_LR(std::string,  name);
   SETTER_OBJ_CLR(std::string, name);
   SETTER_OBJ_RR(std::string,  name);
   SETTER_OBJ_CRR(std::string, name);

   GETTER_PRIM(int, id);
   GETTER_FLAG(bool, merried);

   GETTER_OBJ_LR(std::string,  name);
   GETTER_OBJ_CLR(std::string, name);

   GETTER_PTR(int, next);
   GETTER_ARR(std::string, address);

private:
    int id;
    std::string name;
    std::string address[5];
    
    bool merried;
    int* next;
};
```

In future expects add getters and setters for reference type members<br/>
and reference-qualified member methods.

Requirements:<br/>
Standard: C++14 <br/>
library:  type_traits
