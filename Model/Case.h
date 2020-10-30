#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case
{

public:
	enum class Type{ vide, un, deux, trois, quatre, cinq, six, sept, huit, mine, boom };
	enum class State{ close, open, flag};

	bool m_isFlag = 0;

	Type m_type;
	State m_state;

	Case(Type type, State state, bool isFlag);
	void modifyCase(Type type, State state, bool isFlag);

};

#endif // !CASE_H_INCLUDED




