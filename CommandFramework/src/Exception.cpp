/*
* CommandFramework
*
* Copyright (C) 2018-2019 Sonu Lohani
*
*    Distributed under the Boost Software License, Version 1.0.
*    (See accompanying file LICENSE_1_0.txt or copy at
*    http://www.boost.org/LICENSE_1_0.txt)
*/

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

	char const* NoRedoCommandException::what() const
	{
		return m_message.c_str();
	}

}
