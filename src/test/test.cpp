#include <iostream>
#include <string>

#include "../property.hpp"
#include "../type/check_type.hpp"

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

class address {
public:
	address() = default;
   ~address() = default;

    address(std::string&& city) : city(std::move(city)) {}

	SETTER_OBJ_VAL(std::string, city);
	SETTER_OBJ_CLR(std::string, street);

	GETTER_OBJ_LR_LRQ(std::string, city);
	GETTER_OBJ_RR_RRQ(std::string, city);
	GETTER_OBJ_CLR_CLRQ(std::string, street);

private:
	std::string city;
	std::string street;
	int number;
};

class reference {
public:
	reference() : lvref(init), rvref("Europe") {}
	reference(std::string&& rvref) : lvref(init), rvref(std::move(rvref)) {}
	~reference() {}

	SETTER_REF_LV(std::string, lvref);
	SETTER_REF_RV(std::string, rvref);

	GETTER_REF_LV(std::string, lvref);
	GETTER_REF_RV_RRQ(std::string, rvref);

private:
	string init = "init-value";
	string& lvref;
	string&& rvref;
};


static void test_person() {
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

	cout << endl;
}

static void test_address() {
	address addr;

	/* 1 */
	addr.set_city("Warsaw");
	cout << "field city: " << addr.get_city() << endl;

	std::string another_city = "Paris";
	addr.get_city() = another_city;
	cout << "change field city: " << addr.get_city() << endl;

	/* 2 */
	std::string street = "Sent-Trudent";
	addr.set_street(street);
	cout << "field street: " << addr.get_street() << endl;

	/* 3 */
	std::string&& city = address("Berlin").get_city();
	cout << "field street: " << city << endl;
}


static void test_reference() {
	reference ref;

	/* 1 */
	string name = "Jonny";
	ref.set_lvref(name);
	cout << "field lvref: " << ref.get_lvref() << endl;

	/* 2 */
	string nick_name = "JJ";
	ref.set_lvref(nick_name);
	cout << "field clvref: " << ref.get_lvref() << endl;

	/* 3 */
	cout << "field rvref: " << reference("Asia").get_rvref() << endl;
}



int main(int argc, char **argv) {
	cout << "Test property library" << endl;

	test_person();
	test_address();
	test_reference();
}





