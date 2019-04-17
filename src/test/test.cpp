#include <iostream>
#include <string>

#include "../property.hpp"

using namespace std;

enum class human { MALE, FEMALE };
enum class pc { INTEL, AMD };

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

class computer {
public:
	constexpr computer() :
	id(0), type(pc::INTEL),
	modern(false), next(nullptr) {};

   SETTER_PRIM_CEXS(int, id);
   SETTER_FLAG_CEXS(bool, modern);
//   SETTER_ENUM(pc, type);
//
//   SETTER_PTR(int, next);
//
   GETTER_PRIM_CEXS(int, id);
   GETTER_FLAG_CEXS(bool, modern);
//   GETTER_ENUM(pc, type);
//
//   GETTER_PTR(int, next);

private:
	int id;
	pc type;

	bool modern;
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


class smart_array {
public:
	 smart_array() : arr_ptr(&arr_val), arr_lvref(arr_val), arr_rvref(std::move(arr_val)) {}
	~smart_array() {}

	SETTER_PTR_TO_ARR(int, arr_ptr, 3);

	GETTER_PTR_TO_ARR(int, arr_ptr, 3);
	GETTER_LVREF_TO_ARR(int, arr_lvref, 3);
	GETTER_RVREF_TO_ARR(int, arr_rvref, 3);
private:
	int (*arr_ptr)[3];
	int (&arr_lvref)[3];
	int (&&arr_rvref)[3];

	int arr_val[3] = { 5, 10, 15};
};

int smart_func() { return 0xCAFEBABE; };

class smart_function {
public:
	smart_function() : func_ptr(&smart_func), func_lvref(smart_func), func_rvref(std::move(smart_func)) {}
	~smart_function() {}

	SETTER_PTR_TO_FUNC(int, func_ptr);

	GETTER_PTR_TO_FUNC(int, func_ptr);
	GETTER_LVREF_TO_FUNC(int, func_lvref);
	GETTER_RVREF_TO_FUNC(int, func_rvref);
private:
	int (*func_ptr)();
	int (&func_lvref)();
	int (&&func_rvref)();
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

static void test_computer() {
	constexpr computer p;

	/* 1 */
	p.set_id(5);
	cout << "field id: " << p.get_id() << endl;

	/* 2 */
	p.set_modern(true);
	cout << "field modern: " << p.is_modern() << endl;
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

static void test_smart_array() {
	smart_array sa;

	/* 1 */
	int first[3] = { 1, 2, 3 };
	sa.set_arr_ptr(&first);

	for (int item : *sa.get_arr_ptr()) {
		cout << "item arr_ptr: " << item << endl;
	}

	/* 2 */
	for (int item : sa.get_arr_lvref()) {
		cout << "item arr_lvref: " << item << endl;
	}

	/* 3 */
	for (int item : sa.get_arr_rvref()) {
		cout << "item arr_rvref: " << item << endl;
	}
}

static void test_smart_function() {
	smart_function sf;

	/* 1 */
	sf.set_func_ptr(&smart_func);
	cout << "ret func_ptr: " << std::hex << sf.get_func_ptr()() << endl;

	/* 2 */
	cout << "ret func_lvref: " << std::hex << sf.get_func_lvref()() << endl;

	/* 3 */
	cout << "ret func_rvref: " << std::hex << sf.get_func_rvref()() << endl;
}

static void test_enum() {
	person p;
	human type = human::FEMALE;

	p.set_type(type);
	p.get_type();

}

int main(int argc, char **argv) {
	cout << "Test property library" << endl;

	test_person();
	test_computer();
	test_address();
	test_reference();
	test_smart_array();
	test_smart_function();
	test_enum();
}





