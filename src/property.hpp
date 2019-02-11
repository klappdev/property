#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_

#include <type_traits>

/**
 * Macro create setter for primitive type
 * @param type - primitive type
 * @param name - name field
 */
#define SETTER_PRIM(type, name)					\
	void set_##name(type value)	{			\
		static_assert(std::is_fundamental<type>::value, \
					  "only primitive types");\
		this->name = value;				\
	}

/**
 * Macro create setter for boolean type
 * @param type - boolean type
 * @param name - name field
 */
#define SETTER_FLAG(type, name)					\
	void set_##name(type value)	{			\
		static_assert(std::is_same<type, bool>::value,  \
					  "only bool type");	\
		this->name = value;				\
	}

/**
 * Macro create setter for object type
 * with lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_LR(type, name)				\
	void set_##name(type& value)	{			\
		static_assert(std::is_class<type>::value ||	\
				      std::is_union<type>::value,\
				      "only class types");	\
		this->name = value;				\
	}

/**
 * Macro create setter for object type
 * with const lvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CLR(type, name)					\
	void set_##name(const type& value)	{			\
		static_assert(std::is_class<type>::value ||	        \
					  std::is_union<type>::value, 	\
					  "only class types");		\
		this->name = value;					\
	}

/**
 * Macro create setter for object type
 * with rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_RR(type, name)					\
	void set_##name(type&& value)	{				\
		static_assert(std::is_class<type>::value ||	        \
					  std::is_union<type>::value, 	\
					  "only class types");		\
		this->name = std::move(value);				\
	}

/**
 * Macro create setter for object type
 * with const rvalue parameter
 * @param type - object type
 * @param name - name field
 */
#define SETTER_OBJ_CRR(type, name)					\
	void set_##name(const type&& value)	{			\
		static_assert(std::is_class<type>::value ||	        \
					  std::is_union<type>::value, 	\
					  "only class types");		\
		this->name = std::move(value);				\
	}

/**
 * Macro create setter for pointer type
 * @param type - pointer type
 * @param name - name field
 */
#define SETTER_PTR(type, name)						 \
	void set_##name(type* value)	{				 \
		static_assert(std::is_pointer<type*>::value,		 \
					  "only pointer types");	 \
		static_assert(std::is_pointer<decltype(name)>::value,    \
					  "variable must be pointer");	 \
		this->name = value;					 \
	}

/**
 * Macro create setter for array type
 * @param type - array type
 * @param name - name field
 * @param length - length array
 */
#define SETTER_ARR(type, array, length)								\
	void set_##name(type (&new_array)[length]) {						\
		static_assert(std::is_same<std::remove_all_extents_t< 				\
                                  decltype(array)>,       		                        \
								  type>::value,	              	\
							  "types arrays must be same");	  	\
		static_assert(std::is_array<type[]>::value, 					\
					  "only array types");					\
		static_assert(std::is_array<decltype(array)>::value,				\
					  "variable must be array");			 	\
		for (int i = 0; i < length; i++) {						\
			this->array[i] = new_array[i];		              			\
		}										\
	}

/**
 * Macro create getter for primitive type
 * @param type - primitive type
 * @param name - name field
 */
#define GETTER_PRIM(type, name) 					\
	type get_##name() const { 					\
		static_assert(std::is_fundamental<type>::value, 	\
					  "only primitive types");	\
		return name; 						\
	}

/**
 * Macro create getter for boolean type
 * @param type - boolean type
 * @param name - name field
 */
#define GETTER_FLAG(type, name) 				\
	type is_##name() const { 				\
		static_assert(std::is_same<type, bool>::value,  \
					  "only bool type");	\
		return name; 					\
	}

/**
 * Macro create getter for object type
 * with lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_LR(type, name) 					\
	type& get_##name()  { 						\
		static_assert(std::is_class<type>::value ||		\
					  std::is_union<type>::value, 	\
					  "only class types");		\
	    return name; 						\
	}

/**
 * Macro create getter for object type
 * with const lvalue return value
 * @param type - object type
 * @param name - name field
 */
#define GETTER_OBJ_CLR(type, name) 					\
	const type& get_##name() const { 				\
		static_assert(std::is_class<type>::value ||		\
					  std::is_union<type>::value, 	\
					  "only class types");		\
	    return name; 						\
	}

/**
 * Macro create getter for pointer type
 * with pointer return value
 * @param type - pointer type
 * @param name - name field
 */
#define GETTER_PTR(type, name)						 \
	type* get_##name()	{					 \
		static_assert(std::is_pointer<type*>::value,		 \
					  "only pointer types");	 \
		static_assert(std::is_pointer<decltype(name)>::value,    \
					  "variable must be pointer");	 \
		return name; 						 \
	}

/**
 * Macro create getter for array type
 * with pointer return value
 * @param type - array type
 * @param name - name field
 */
#define GETTER_ARR(type, name) 						\
	type* get_##name() { 						\
		static_assert(std::is_array<type[]>::value,		\
					  "only array types");		\
		static_assert(std::is_array<decltype(name)>::value, 	\
					  "variable must be array");	\
	    return name; 						\
	}


#endif /* PROPERTY_HPP_ */
