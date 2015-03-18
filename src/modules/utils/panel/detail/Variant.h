#ifndef __UI_VARIANT_H__

namespace ui
{
namespace detail
{

template <typename ...Ts>
union storage;
 
template <typename T, typename ...Ts>
union storage<T, Ts...> 
{
	nullvariant_t nullvariant;
	T head;
	storage<Ts...> tail;
};
 
template <>
union storage<> {
	nullvariant_t nullvariant;
};

} // namespace detail
} // namespace ui

#endif // __UI_VARIANT_H__