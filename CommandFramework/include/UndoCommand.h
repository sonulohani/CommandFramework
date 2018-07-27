/*
* CommandFramework
*
* Copyright (C) 2018-2019 Sonu Lohani
*
*    Distributed under the Boost Software License, Version 1.0.
*    (See accompanying file LICENSE_1_0.txt or copy at
*    http://www.boost.org/LICENSE_1_0.txt)
*/

#pragma once

#include "Exception.h"
#include <stack>
#include <initializer_list>

namespace CommandFramework
{
	class ICommand;

	class UndoCommand
	{
	public:
		explicit UndoCommand() = default;

		explicit UndoCommand(ICommand *pCommand);

		explicit UndoCommand(std::initializer_list<ICommand *> initializer_list);

		virtual ~UndoCommand();

		void pushCommand(ICommand *pCommand);

		virtual void undo();

	protected:
		std::stack<ICommand *> m_pUndoCommandStack;
	};
}