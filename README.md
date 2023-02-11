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
time check types, name members, equals types kind members using  <br/>
type traits library C++11/C++14.

Developer can write less code and to be sure that code write correct.

```C++
#include "property.hpp"

class person {
public:
   person() = default;
   ~person() = default;

   SETTER_PRIM(int, id);
   SETTER_FLAG(bool, merried);
   SETTER_ENUM(human, type);

   SETTER_PTR(int, next);
   SETTER_ARR(std::string, address, 3);

   SETTER_OBJ_LR(std::string,  name);
   SETTER_OBJ_CLR(std::string, name);
   SETTER_OBJ_RR(std::string,  name);

   GETTER_PRIM(int, id);
   GETTER_FLAG(bool, merried);
   GETTER_ENUM(human, type);

   GETTER_OBJ_LR(std::string,  name);
   GETTER_OBJ_CLR(std::string, name);

   GETTER_PTR(int, next);
   GETTER_ARR(std::string, address);

private:
   int id;
   human type;

   std::string name;
   std::string address[5];

   bool merried;
   int* next;
};
```

Requirements:<br/>
Standard: C++14 <br/>
