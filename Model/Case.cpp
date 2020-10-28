#include "Case.h"



Case::Case(Type type, State state,bool isFlag, int pos_x, int pos_y) {

	m_type = type;
	m_state = state;
	m_isFlag = isFlag;
	m_pos_x = pos_x;
	m_pos_y = pos_y;
}
void Case::modifyCase(Type type,State state, bool isFlag, int pos_x, int pos_y) {

	m_type = type;
	m_state = state;
	m_isFlag = isFlag;
	m_pos_x = pos_x;
	m_pos_y = pos_y;

}