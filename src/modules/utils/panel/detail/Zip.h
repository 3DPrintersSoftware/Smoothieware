#ifndef __ZIP_H__
#define __ZIP_H__

template<typename T1, typename T2>
class Zip
{
public:

	template <size_t N>
	Zip(T1(&t1)[N], T2(&t2)[N])
	:size(N), t1(t1), t2(t2)
	{}

	std::tuple<T1*, T2*> begin()
	{
		return std::tuple<T1*, T2*>(&(t1[0]), &(t2[0]));
	}

	std::tuple<T1*, T2*> end()
	{
		return std::tuple<T1*, T2*>(&(t1[size]), &(t2[size]));
	}

	std::tuple<T1&, T2&> operator[](size_t i)
	{
		return std::tuple<T1&, T2&>(t1[i % size], t2[i % size]);
	}

private:
	size_t size;
	T1 * const t1;
	T2 * const t2;
};

#endif // __ZIP_H__