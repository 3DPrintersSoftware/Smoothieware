#ifndef __LINKBASE_H__
#define __LINKBASE_H__

#include <cstddef>
#include <functional>

namespace ui
{

template <typename ContainerType, typename ElementType>
struct LinkBase
{

LinkBase(size_t index = 0, ContainerType* group = nullptr)
:index(index), group(group)
{}

ElementType & operator*() const
{
	return &(this->get());
}

virtual ElementType & get() const
{
	return (*group)[index];
}

virtual ContainerType & group() const
{
	return &group;
}

virtual size_t index() const
{
	return index;
}

private:
	size_t index;
	ContainerType* group;
};

/*
bool always();
using Condition = bool(*)(void);

template <typename ContainerType>
struct LinkBase
{
	constexpr LinkBase(size_t index = 0, ContainerType* group = nullptr)
	:condition(always), index(index), group(group), index_false(index), group_false(group)
	{}

	constexpr LinkBase(Condition condition, size_t index = 0, ContainerType* group = nullptr, size_t index_false = 0, ContainerType* group_false = nullptr)
	:condition(condition), index(index), group(group), index_false(index_false), group_false(group_false)
	{}

	size_t get_index() const
	{
		if(condition())
		{
			return index;
		}
		else
		{
			
			return index_false;
		}
	}

	ContainerType * get_group() const
	{
		if(condition())
		{
			return group;
		}
		else
		{
			
			return group_false;
		}
	}

	typename ContainerType::ElementType & operator*() const
	{
		return &(this->get());
	}

	// CBFF
	typename ContainerType::ElementType * get() const
	{
		if(condition())
		{
			return &(*group)[index];
		}
		else
		{
			return &(*group_false)[index];
		}
	}

	// CBFF
	typename ContainerType::ElementType * fetch() const
	{
		return get();
	}

protected:
	Condition condition;
	size_t index;
	ContainerType* group;
	size_t index_false;
	ContainerType* group_false;
};*/

} // namespace ui

#endif // __LINKBASE_H__