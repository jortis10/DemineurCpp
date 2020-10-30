#include "Case.h"



Case::Case(Type type, State state,bool isFlag) {

	m_type = type;
	m_state = state;
	m_isFlag = isFlag;
}
void Case::modifyCase(Type type,State state, bool isFlag) {

	m_type = type;
	m_state = state;
	m_isFlag = isFlag;

}