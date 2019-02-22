#include <iostream>
#include <string>

#include "property.hpp"

using namespace std;

class person {
public:
	person() = default;
   ~person() = default;

   SETTER_PRIM(int, id);
   SETTER_FLAG(bool, merried);

   SETTER_PTR(int, next);
   SETTER_ARR(std::string, address, 3);

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

	person p;

	/* 1 */
	p.set_id(5);
	cout << "field id: " << p.get_id() << endl;

	/* 2 */
	p.set_merried(true);
	cout << "field merried: " << p.is_merried() << endl;

	/* 3 */
	int next = 2;
	p.set_next(&next);
	cout << "field merried: " << *p.get_next() << endl;

	/* 4 */
	string address[3];
	address[0] = "New York";
	address[1] = "Avenue";
	address[2] = "9";

	p.set_address(address);

	for (int i = 0; i < 3; i++) {
		cout << "field address: " << p.get_address()[i] << endl;
	}

	/* 5 */
	string name = "John";
	p.set_name(name);
	cout << "field name: " << p.get_name() << endl;

	/* 6 */
	p.set_name("Jenny");
	cout << "field name: " << p.get_name() << endl;



}





