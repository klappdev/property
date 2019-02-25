# property
This is simple C++ header only library for generate<br/>
getters and setters for members class.

Library can generate getter and setter for such members:<br/>

    > primitive members
    > object members   
    > enum members
    > array members
    > pointer members
    > reference members
    > pointer to array members
    > reference to array members
    > pointer to function members
    > reference to function members

When generate getter, setter for members classes occur in compile<br/>
time check types, name members, kind members using type traits   <br/>
library C++11/C++14.

Developer can write less code and to be sure that code write correct.

```C++
#include "property.hpp"

using namespace std;

class person {
public:
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
   
   SETTER_REF_LR(std::string, address);
   SETTER_REF_RR(std::string, address);

   GETTER_PRIM(int, id);
   GETTER_FLAG(bool, merried);

   GETTER_OBJ_LR(std::string,  name);
   GETTER_OBJ_CLR(std::string, name);
   
   GETTER_OBJ_LR_LRQ(std::string, name);
   GETTER_OBJ_CLR_CLRQ(std::string, name);
   GETTER_OBJ_RR_RRQ(std::string, name);
   
   GETTER_REF_LR(std::string,  address);
   GETTER_REF_CLR(std::string, address);

   GETTER_PTR(int, next);
   GETTER_ARR(std::string, address);

private:
    int id;
    std::string name;
    std::string address;
    std::string address[5];
    
    bool merried;
    int* next;
};
```

In future expects improve getters and setters for reference <br/>
and pointer to function with varidic arguments. <br/>

Requirements:<br/>
Standard: C++14 <br/>
library:  type_traits
