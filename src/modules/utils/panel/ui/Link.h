#ifndef __LINK_H__
#define __LINK_H__

#include "Group.h"
#include "LinkBase.h"
#include "boost/variant/variant.hpp"

namespace ui
{
//typedef LinkBase<Group, CompositeItem> ILink;
using Condition = bool(*)(void);
using ILink = LinkBase<Group, CompositeItem>;

template <size_t number_of_conditions>
struct MultiLink : ILink
{

struct Target
{
	Condition condition;
	ContainerType& container;
	size_t index;
};

virtual ElementType & get() const
{
	Target const & target = _get();
	return target.container[target.index];
}

virtual ContainerType & group() const
{
	_get().container;
}

virtual size_t index() const
{
	_get().index;
}

private:
Target const & _get() const
{
	for(auto& target: targets)
	{
		if(target.condition())
		{
			return target; // maybe hash?
		}
	}
	return targets.back();
}

std::array<Target, number_of_conditions> targets;

};

} // namespace ui

#endif // __LINK_H__