#include "Exception.h"

namespace CommandFramework
{
	char const * NullPointerException::what() const
	{
		return m_message.c_str();
	}

	char const * NoUndoCommandException::what() const
	{
		return  m_message.c_str();
	}

	char const * NotImplementedException::what() const
	{
		return m_message.c_str();
	}
}
