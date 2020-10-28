#include <iostream>
#include <string>
#include "ConsoleColor.h"

class setcolor
{
private:
	unsigned short m_attr;
public:
	explicit setcolor(unsigned short attr) : m_attr(attr) {}

	template<typename _CharT, typename _Traits>
	std::basic_ostream<_CharT, _Traits>& Apply(std::basic_ostream<_CharT, _Traits>& stm)
	{
		stm.flush();
		setConsoleColor(m_attr);
		return stm;
	}
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& stm, setcolor sc)
{
	return sc.Apply(stm);
}