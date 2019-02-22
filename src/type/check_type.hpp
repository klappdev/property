#ifndef CHECK_TYPE_HPP_
#define CHECK_TYPE_HPP_

/* check if type is pointer to function */
template<class>
struct is_function_pointer : std::false_type { };

template<class Ret, class... Args>
struct is_function_pointer<Ret(*)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_function_pointer<Ret(*)(Args...,...)> : std::true_type {};

/* check if type is lvalue reference to function */
template<class>
struct is_function_lvalue_reference : std::false_type { };

template<class Ret, class... Args>
struct is_function_lvalue_reference<Ret(&)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_function_lvalue_reference<Ret(&)(Args...,...)> : std::true_type {};

/* check if type is rvalue reference to function */
template<class>
struct is_function_rvalue_reference : std::false_type { };

template<class Ret, class... Args>
struct is_function_rvalue_reference<Ret(&&)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_function_rvalue_reference<Ret(&&)(Args...,...)> : std::true_type {};

/* check if type is pointer to array */
template<class T>
struct is_array_pointer : std::false_type {};

template<class T, std::size_t N>
struct is_array_pointer<T (*)[N]> : std::true_type {};

/* check if type is lvalue reference to array */
template<class T>
struct is_array_lvalue_reference : std::false_type {};

template<class T, std::size_t N>
struct is_array_lvalue_reference<T (&)[N]> : std::true_type {};

/* check if type is rvalue reference to array */
template<class T>
struct is_array_rvalue_reference : std::false_type {};

template<class T, std::size_t N>
struct is_array_rvalue_reference<T (&&)[N]> : std::true_type {};


#endif /* CHECK_TYPE_HPP_ */
