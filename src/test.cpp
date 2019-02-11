#include <iostream>

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


int main(int argc, char **argv) {
	cout << "Test property util" << endl;
}





