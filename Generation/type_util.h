#ifndef TYPE_UTIL_H
#define TYPE_UTIL_H


#include <type_traits>




// Utility trait : is_streamable<t>::value
template <typename T>
class is_streamable
{
	template <typename U>
	static auto test(U const * u) -> decltype(std::cout << *u) {}
	static auto test(...) -> std::false_type {}

public:
	static const bool value{ !std::is_same<decltype(test(static_cast<T*>(nullptr))), std::false_type>::value };
};

//// Utility trait : is_mult_operator_available<t>::value
//template <typename TleftOp, typename TrightOp>
//class is_mult_operator_available
//{
//	template <typename U, typename V>
//	static auto test(U const * u, V const * v) -> decltype(u->operator*(*v)) {} // ??? ne fonctionne pas pour les opérateur in-class???
//	template <typename U, typename V>
//	static auto test(U const * u, V const * v) -> decltype(*u * *v) {}
//	static auto test(...) -> std::false_type {}
//
//public:
//	static const bool value{ !std::is_same<decltype(test(static_cast<TleftOp*>(nullptr), static_cast<TrightOp*>(nullptr))), std::false_type>::value };
//};



template <typename Container>
class container_traits
{
	template <typename C>
	static auto test_begin(C const * c) -> decltype(c->begin()) {}
	static auto test_begin(...) -> std::false_type {}
	template <typename C>
	static auto test_end(C const * c) -> decltype(c->end()) {}
	static auto test_end(...) -> std::false_type {}
	template <typename C>
	static auto test_value_type(C const * c) -> typename C::value_type {}
	static auto test_value_type(...) -> std::false_type {}
	template <typename C>
	static auto test_size(C const * c) -> decltype(c->size()) {}
	static auto test_size(...) -> std::false_type {}

public:
	using value_type = decltype(test_value_type(static_cast<Container*>(nullptr)));
	static const bool has_begin{ !std::is_same<decltype(test_begin(static_cast<Container*>(nullptr))), std::false_type>::value };
	static const bool has_end{ !std::is_same<decltype(test_end(static_cast<Container*>(nullptr))), std::false_type>::value };
	static const bool has_begin_end{ has_begin && has_end };
	static const bool has_value_type{ !std::is_same<decltype(test_value_type(static_cast<Container*>(nullptr))), std::false_type>::value };
	static const bool has_size{ !std::is_same<decltype(test_size(static_cast<Container*>(nullptr))), std::false_type>::value };
	static const bool is_conform{ has_begin_end && has_value_type && has_size }; // to improve!
};




template <typename t>
inline constexpr
int polarity(t v, std::false_type is_signed) {
	return v == t{} ? 0 : 1;
}

template <typename t>
inline constexpr
int polarity(t v, std::true_type is_signed) {
	return v == t{} ? 0 : (v < t{} ? -1 : 1);
}

template <typename t>
inline constexpr
int polarity(t v) {
	return polarity(v, std::is_signed<t>());
}

template <typename t>
inline constexpr
bool similarPolarity(t v1, t v2) {
	int p1{ polarity(v1) };
	int p2{ polarity(v2) };
	return p1 == p2 || p1 == 0 || p2 == 0;
}


#endif // TYPE_UTIL_H
