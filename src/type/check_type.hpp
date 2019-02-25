#ifndef CHECK_TYPE_HPP_
#define CHECK_TYPE_HPP_

/* aliases for pointer and reference to function */
template <typename Ret>
using func_ptr_t = Ret (*)();

template <typename Ret>
using func_lvref_t = Ret (&)();

template <typename Ret>
using func_rvref_t = Ret (&&)();
#endif

#if 0
template <class Ret, class... Args>
using func_ptr_t = Ret (*)(Args...);

template <class Ret, class... Args>
using func_lvref_t = Ret (&)(Args...);

template <class Ret, class... Args>
using func_rvref_t = Ret (&&)(Args...);
#endif

/* aliases for pointer and reference to array */
template <typename T, int N>
using arr_ptr_t = T (*)[N];

template <typename T, int N>
using arr_lvref_t = T (&)[N];

template <typename T, int N>
using arr_rvref_t = T (&&)[N];

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
