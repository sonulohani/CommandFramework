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

#include "ICommand.h"
#include "Exception.h"
#include <stack>
#include <initializer_list>

namespace CommandFramework
{
	class UndoCommand : public ICommand
	{
	public:
		explicit UndoCommand() = default;

		explicit UndoCommand(ICommand *pCommand);

		explicit UndoCommand(std::initializer_list<ICommand *> initializer_list);

		virtual ~UndoCommand();

		void pushCommand(ICommand *pCommand);

		virtual void undo();

	private:
		virtual void execute() override {}

	protected:
		std::stack<ICommand *> m_pUndoCommandStack;
	};
}