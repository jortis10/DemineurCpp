#pragma once

#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case
{

public:
	enum class Type
	{
		vide,
		un,
		deux,
		trois,
		quatre,
		cinq,
		six,
		sept,
		huit,
		mine,
		boom
	};

	enum class State
	{
		close,
		open,
		flag
	};

	bool m_isFlag = 0;

	Type m_type = Type::vide;
	State m_state = State::close;
	int m_pos_x = -1;
	int m_pos_y = -1;

	Case(Type type, State state, bool isFlag, int pos_x, int pos_y);
	void modifyCase(Type type, State state, bool isFlag, int pos_x, int pos_y);

};




#endif // !CASE_H_INCLUDED




