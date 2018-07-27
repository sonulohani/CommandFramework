/*
* CommandFramework
*
* Copyright (C) 2018-2019 Sonu Lohani
*
*    Distributed under the Boost Software License, Version 1.0.
*    (See accompanying file LICENSE_1_0.txt or copy at
*    http://www.boost.org/LICENSE_1_0.txt)
*/

#include "UndoCommand.h"

namespace CommandFramework
{
	UndoCommand::UndoCommand(ICommand * pCommand)
	{
		m_pUndoCommandStack.push(pCommand);
	}

	UndoCommand::UndoCommand(std::initializer_list<ICommand*> initializer_list)
	{
		for (const auto &pCommand : initializer_list)
		{
			m_pUndoCommandStack.push(pCommand);
		}
	}

	UndoCommand::~UndoCommand()
	{}

	void UndoCommand::pushCommand(ICommand *pCommand)
	{
		m_pUndoCommandStack.push(pCommand);
	}

	void UndoCommand::undo()
	{
		if (m_pUndoCommandStack.empty())
		{
			throw NoUndoCommandException();
		}

		auto pCommand = m_pUndoCommandStack.top();

		if (pCommand == nullptr)
		{
			throw NullPointerException();
		}

		pCommand->execute();
		m_pUndoCommandStack.pop();
	}
}