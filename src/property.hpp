#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_

#include <type_traits>

#include "type/check_type.hpp"

/**
 * Macro create setter for primitive type
 * @param type - primitive type
 * @param name - name field
 */
#define SETTER_PRIM(type, name)										\
	void set_##name(type value)	{									\
		static_assert(std::is_fundamental<type>::value, 			\
					  "only primitive types");						\
		static_assert(std::is_fundamental<decltype(name)>::value,	\
					  "variable must be primitive");				\
		this->name = value;											\
	}

/**
 * Macro create setter for boolean type
 * @param type - boolean type
 * @param name - name field
 */
#define SETTER_FLAG(type, name)							\
	void set_##name(type value)	{						\
		static_assert(std::is_same<type, bool>::value,  \
					  "only bool type");			    \
		this->name = value;								\
	}

/**
 * Macro create setter for object type
 * by value
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_VAL(type, name)								\
	void set_##name(type value)	{								\
		static_assert(std::is_class<type>::value ||				\
				      std::is_union<type>::value, 				\
				      "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = value;										\
	}

/**
 * Macro create setter for object type
 * with lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_LR(type, name)								\
	void set_##name(type& value)	{							\
		static_assert(std::is_class<type>::value ||				\
				      std::is_union<type>::value, 				\
				      "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = value;										\
	}

/**
 * Macro create setter for object type
 * with volatile lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_VLR(type, name)								\
	void set_##name(volatile type& value)	{					\
		static_assert(std::is_class<type>::value ||				\
				      std::is_union<type>::value, 				\
				      "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = value;										\
	}

/**
 * Macro create setter for object type
 * with const lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CLR(type, name)								\
	void set_##name(const type& value)	{						\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = value;										\
	}

/**
 * Macro create setter for object type
 * with const volatile lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CVLR(type, name)								\
	void set_##name(const volatile type& value)	{				\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = value;										\
	}



/**
 * Macro create setter for object type
 * with rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_RR(type, name)								\
	void set_##name(type&& value)	{							\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = std::move(value);							\
	}

/**
 * Macro create setter for object type
 * with volatile rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_VRR(type, name)								\
	void set_##name(volatile type&& value)	{					\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = std::move(value);							\
	}

/**
 * Macro create setter for object type
 * with const rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CRR(type, name)								\
	void set_##name(const type&& value)	{						\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = std::move(value);							\
	}

/**
 * Macro create setter for object type
 * with const volatile rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CVRR(type, name)								\
	void set_##name(const volatile type&& value)	{			\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
		this->name = std::move(value);							\
	}

/**
 * Macro create setter for lvalue reference type
 * @param type - lvalue reference type
 * @param name - name field
 */
#define SETTER_REF_LV(type, name)							 			\
	void set_##name(type& value)	{						 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		this->name = value;									 			\
	}

/**
 * Macro create setter for const lvalue reference type
 * @param type - const lvalue reference type
 * @param name - name field
 */
#define SETTER_REF_CLV(type, name)							 			\
	void set_##name(const type& value)	{						 		\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		this->name = value;									 			\
	}

/**
 * Macro create setter for rvalue reference type
 * @param type - rvalue reference type
 * @param name - name field
 */
#define SETTER_REF_RV(type, name)							 			\
	void set_##name(type&& value)	{						 			\
		static_assert(std::is_rvalue_reference<type&&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_rvalue_reference<decltype(name)>::value,	\
					  "variable must be rvalue reference");	 			\
		this->name = std::move(value);	 					 			\
	}

/**
 * Macro create setter for enum type
 * @param type - enum type
 * @param name - name field
 */
#define SETTER_ENUM(type, name)								\
	void set_##name(type value)	{							\
		static_assert(std::is_enum<type>::value, 			\
					  "only enum types");					\
		static_assert(std::is_enum<decltype(name)>::value,	\
					  "variable must be enum");				\
		this->name = value;									\
	}

/**
 * Macro create setter for pointer type
 * @param type - pointer type
 * @param name - name field
 */
#define SETTER_PTR(type, name)								 \
	void set_##name(type* value)	{						 \
		static_assert(std::is_pointer<type*>::value,		 \
					  "only pointer types");				 \
		static_assert(std::is_pointer<decltype(name)>::value,\
					  "variable must be pointer");			 \
		this->name = value;									 \
	}

/**
 * Macro create setter for array type
 * @param type - array type
 * @param name - name field
 * @param length - length array
 */
#define SETTER_ARR(type, array, length)							\
	void set_##array(type (&new_array)[length]) {				\
		static_assert(std::is_same<std::remove_all_extents_t< 	\
                                  decltype(array)>,       		\
								  type>::value,	              	\
							  "types arrays must be same");	  	\
		static_assert(std::is_array<type[]>::value, 			\
					  "only array types");						\
		static_assert(std::is_array<decltype(array)>::value,	\
					  "variable must be array");			 	\
		for (int i = 0; i < length; i++) {						\
			this->array[i] = new_array[i];		              	\
		}											            \
	}

/**
 * Macro create setter for pointer to array type
 * @param type - pointer to array type
 * @param name - name field
 * @param length - length array
 */
#define SETTER_PTR_TO_ARR(type, array, length)						\
	void set_##array(type (*new_array)[length]) {					\
		static_assert(is_array_pointer<type(*)[length]>::value,		\
                      "only pointer to array types");				\
		static_assert(is_array_pointer<decltype(array)>::value,		\
					  "variable must be pointer to array");		 	\
		this->array = new_array;					            	\
	}

/**
 * Macro create setter for pointer to function type
 * @param type - pointer to function type
 * @param name - name field
 */
#define SETTER_PTR_TO_FUNC(type, func)									\
	void set_##func(type (*new_func)()) {								\
		static_assert(is_function_pointer<type(*)()>::value,			\
                      "only pointer to function types");				\
		static_assert(is_function_pointer<decltype(func)>::value,		\
					  "variable must be pointer to function");			\
		this->func = new_func;					            			\
	}

/**
 * Macro create getter for primitive type
 * @param type - primitive type
 * @param name - name field
 */
#define GETTER_PRIM(type, name) 									\
	type get_##name() const { 										\
		static_assert(std::is_fundamental<type>::value, 			\
					  "only primitive types");						\
		static_assert(std::is_fundamental<decltype(name)>::value,	\
					  "variable must be primitive");				\
		return name; 												\
	}

/**
 * Macro create getter for boolean type
 * @param type - boolean type
 * @param name - name field
 */
#define GETTER_FLAG(type, name) 						\
	type is_##name() const { 							\
		static_assert(std::is_same<type, bool>::value,  \
					  "only bool type");			    \
		return name; 									\
	}

/**
 * Macro create getter for object type
 * which return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_VAL(type, name) 								\
	type get_##name()  { 										\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type
 * with lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_LR(type, name) 								\
	type& get_##name()  { 										\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type
 * with volatile lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_VLR(type, name) 								\
	volatile type& get_##name()  { 								\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type
 * with const lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_CLR(type, name) 								\
	const type& get_##name() const { 							\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type
 * with const volatile lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_CVLR(type, name) 							\
	const volatile type& get_##name() const { 					\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type with lvalue
 * return value and qualifier for lvalue object
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_LR_LRQ(type, name)    						\
	type& get_##name() & { 										\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type with lvalue
 * return value and volatile qualifier for lvalue object
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_VLR_VLRQ(type, name)    						\
	volatile type& get_##name() volatile & { 					\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type with lvalue
 * return value and const qualifier for lvalue object
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_CLR_CLRQ(type, name) 						\
	const type& get_##name() const & { 							\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type with lvalue
 * return value and const volatile qualifier for lvalue object
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_CVLR_CVLRQ(type, name) 						\
	const volatile type& get_##name() const volatile & {		\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return name; 											\
	}

/**
 * Macro create getter for object type with rvalue
 * return value and qualifier for rvalue object
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_RR_RRQ(type, name) 							\
	type&& get_##name() && { 									\
		static_assert(std::is_class<type>::value ||				\
					  std::is_union<type>::value, 				\
					  "only class types");						\
		static_assert(std::is_class<decltype(name)>::value ||	\
					  std::is_union<decltype(name)>::value,		\
					  "variable must be class");				\
	    return std::move(name);									\
	}

/**
 * Macro create getter for lvalue reference type
 * with return lvalue reference
 * @param type - lvalue reference type
 * @param name - name field
 */
#define GETTER_REF_LV(type, name)							 			\
	type& get_##name()	{						 			 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for lvalue reference type
 * with return volatile lvalue reference
 * @param type - lvalue reference type
 * @param name - name field
 */
#define GETTER_REF_VLV(type, name)							 			\
	volatile type& get_##name()	{				 			 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for const lvalue reference type
 * with return const lvalue reference
 * @param type - reference type
 * @param name - name field
 */
#define GETTER_REF_CLV(type, name)							 			\
	const type& get_##name()	{							 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for const lvalue reference type
 * with return const volatile lvalue reference
 * @param type - reference type
 * @param name - name field
 */
#define GETTER_REF_CVLV(type, name)							 			\
	const volatile type& get_##name()	{					 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for lvalue reference type
 * with return lvalue reference and qualifier for
 * lvalue object
 * @param type - lvalue reference type
 * @param name - name field
 */
#define GETTER_REF_LV_LRQ(type, name)						 			\
	type& get_##name() & {						 			 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for lvalue reference type
 * with return value lvalue reference and qualifier
 * for volatile lvalue object
 * @param type - lvalue reference type
 * @param name - name field
 */
#define GETTER_REF_VLV_VLRQ(type, name)						 			\
	volatile type& get_##name() volatile & {	 			 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for const lvalue reference type
 * with return const lvalue reference and qualifier for
 * const lvalue object
 * @param type - reference type
 * @param name - name field
 */
#define GETTER_REF_CLV_CLRQ(type, name)						 			\
	const type& get_##name() const & {						 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}

/**
 * Macro create getter for const volatile lvalue reference type
 * with return const volatile lvalue reference and qualifier for
 * const lvalue object
 * @param type - reference type
 * @param name - name field
 */
#define GETTER_REF_CVLV_CVLRQ(type, name)						 		\
	const volatile type& get_##name() const volatile & {	 			\
		static_assert(std::is_lvalue_reference<type&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_lvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return name; 							 			 			\
	}


/**
 * Macro create getter for rvalue reference type
 * with return rvalue reference and qualifier for
 * rvalue object
 * @param type - reference type
 * @param name - name field
 */
#define GETTER_REF_RV_RRQ(type, name)						 			\
	type&& get_##name() &&	{							 				\
		static_assert(std::is_rvalue_reference<type&&>::value,		 	\
					  "only reference types");				 			\
		static_assert(std::is_rvalue_reference<decltype(name)>::value,	\
					  "variable must be lvalue reference");	 			\
		return std::move(name); 							 			\
	}

/**
 * Macro create getter for enum type
 * @param type - enum type
 * @param name - name field
 */
#define GETTER_ENUM(type, name) 							\
	type get_##name() const { 								\
		static_assert(std::is_enum<type>::value, 			\
					  "only enum types");					\
		static_assert(std::is_enum<decltype(name)>::value,	\
					  "variable must be enum");				\
		return name; 										\
	}

/**
 * Macro create getter for pointer type
 * with return pointer
 * @param type - pointer type
 * @param name - name field
 */
#define GETTER_PTR(type, name)								 \
	type* get_##name()	{						 			 \
		static_assert(std::is_pointer<type*>::value,		 \
					  "only pointer types");				 \
		static_assert(std::is_pointer<decltype(name)>::value,\
					  "variable must be pointer");			 \
		return name; 							 			 \
	}

/**
 * Macro create getter for array type
 * with pointer return value
 * @param type - array type
 * @param name - name field
 */
#define GETTER_ARR(type, name) 								\
	type* get_##name() { 									\
		static_assert(std::is_array<type[]>::value,			\
					  "only array types");					\
		static_assert(std::is_array<decltype(name)>::value, \
					  "variable must be array");			\
	    return name; 										\
	}

/**
 * Macro create getter for pointer to array type
 * with pointer to array return value
 * @param type - pointer to array type
 * @param name - name field
 */
#define GETTER_PTR_TO_ARR(type, array, length)						\
	arr_ptr_t<type, length> get_##array() {							\
		static_assert(is_array_pointer<type(*)[length]>::value,		\
                      "only pointer to array types");				\
		static_assert(is_array_pointer<decltype(array)>::value,		\
					  "variable must be pointer to array");		 	\
		return array;								            	\
	}

/**
 * Macro create getter for lvalue reference to array type
 * with lvalue reference to array return value
 * @param type - lvalue reference to array type
 * @param name - name field
 */
#define GETTER_LVREF_TO_ARR(type, array, length)							\
	arr_lvref_t<type, length> get_##array() {								\
		static_assert(is_array_lvalue_reference<type(&)[length]>::value,	\
                      "only lvalue reference to array types");				\
		static_assert(is_array_lvalue_reference<decltype(array)>::value,	\
					  "variable must be lvalue reference to array");		\
		return array;								            			\
	}

/**
 * Macro create getter for pointer to function type
 * with pointer to function return value
 * @param type - pointer to function type
 * @param name - name field
 */
#define GETTER_PTR_TO_FUNC(type, func)									\
	func_ptr_t<type> get_##func() {										\
		static_assert(is_function_pointer<type(*)()>::value,			\
                      "only pointer to function types");				\
		static_assert(is_function_pointer<decltype(func)>::value,		\
					  "variable must be pointer to function");	 		\
		return func;								            		\
	}

/**
 * Macro create getter for lvalue reference to function type
 * with lvalue reference to function return value
 * @param type - lvalue reference to function type
 * @param name - name field
 */
#define GETTER_LVREF_TO_FUNC(type, func)									\
	func_lvref_t<type> get_##func() {										\
		static_assert(is_function_lvalue_reference<type(&)()>::value,		\
                      "only lvalue reference to function types");			\
		static_assert(is_function_lvalue_reference<decltype(func)>::value,	\
					  "variable must be lvalue reference to function");		\
		return func;								            			\
	}

#endif /* PROPERTY_HPP_ */
