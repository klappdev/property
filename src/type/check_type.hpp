#ifndef CHECK_TYPE_HPP_
#define CHECK_TYPE_HPP_

/* aliases for pointer and reference to function */
template <typename Ret>
using func_ptr_t = Ret (*)();

template <typename Ret>
using func_lvref_t = Ret (&)();

template <typename Ret>
using func_rvref_t = Ret (&&)();

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

/* pointer to function */
template<class>
struct is_pointer_to_function : std::false_type { };

template<class Ret, class... Args>
struct is_pointer_to_function<Ret(*)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_pointer_to_function<Ret(*)(Args...,...)> : std::true_type {};

template<class Ret>
struct remove_pointer_to_function { using type = Ret; };

template<class Ret, class... Args>
struct remove_pointer_to_function<Ret(*)(Args...)> { using type = Ret; };

template<class Ret, class... Args>
struct remove_pointer_to_function<Ret(*)(Args...,...)> { using type = Ret; };

template<class Ret>
using remove_pointer_to_function_t = typename remove_pointer_to_function<Ret>::type;

/* lvalue reference to function */
template<class>
struct is_lvalue_reference_to_function : std::false_type { };

template<class Ret, class... Args>
struct is_lvalue_reference_to_function<Ret(&)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_lvalue_reference_to_function<Ret(&)(Args...,...)> : std::true_type {};

template<class Ret>
struct remove_lvalue_reference_to_function { using type = Ret; };

template<class Ret, class... Args>
struct remove_lvalue_reference_to_function<Ret(&)(Args...)> { using type = Ret; };

template<class Ret, class... Args>
struct remove_lvalue_reference_to_function<Ret(&)(Args...,...)> { using type = Ret; };

template<class Ret>
using remove_lvalue_reference_to_function_t = typename remove_lvalue_reference_to_function<Ret>::type;

/* rvalue reference to function */
template<class>
struct is_rvalue_reference_to_function : std::false_type { };

template<class Ret, class... Args>
struct is_rvalue_reference_to_function<Ret(&&)(Args...)> : std::true_type {};

template<class Ret, class... Args>
struct is_rvalue_reference_to_function<Ret(&&)(Args...,...)> : std::true_type {};

template<class Ret>
struct remove_rvalue_reference_to_function { using type = Ret; };

template<class Ret, class... Args>
struct remove_rvalue_reference_to_function<Ret(&&)(Args...)> { using type = Ret; };

template<class Ret, class... Args>
struct remove_rvalue_reference_to_function<Ret(&&)(Args...,...)> { using type = Ret; };

template<class Ret>
using remove_rvalue_reference_to_function_t = typename remove_rvalue_reference_to_function<Ret>::type;

/* pointer to array */
template<class T>
struct is_pointer_to_array : std::false_type {};

template<class T, std::size_t N>
struct is_pointer_to_array<T (*)[N]> : std::true_type {};

template<class T>
struct remove_pointer_to_array { using type = T; };

template<class T, std::size_t N>
struct remove_pointer_to_array<T (*)[N]> { using type = T; };

template<class T>
using remove_pointer_to_array_t = typename remove_pointer_to_array<T>::type;

/* lvalue reference to array */
template<class T>
struct is_lvalue_reference_to_array : std::false_type {};

template<class T, std::size_t N>
struct is_lvalue_reference_to_array<T (&)[N]> : std::true_type {};

template<class T>
struct remove_lvalue_reference_to_array { using type = T; };

template<class T, std::size_t N>
struct remove_lvalue_reference_to_array<T (&)[N]> { using type = T; };

template<class T>
using remove_lvalue_reference_to_array_t = typename remove_lvalue_reference_to_array<T>::type;

/* rvalue reference to array */
template<class T>
struct is_rvalue_reference_to_array : std::false_type {};

template<class T, std::size_t N>
struct is_rvalue_reference_to_array<T (&&)[N]> : std::true_type {};

template<class T>
struct remove_rvalue_reference_to_array { using type = T; };

template<class T, std::size_t N>
struct remove_rvalue_reference_to_array<T (&&)[N]> { using type = T; };

template<class T>
using remove_rvalue_reference_to_array_t = typename remove_rvalue_reference_to_array<T>::type;

#endif /* CHECK_TYPE_HPP_ */
