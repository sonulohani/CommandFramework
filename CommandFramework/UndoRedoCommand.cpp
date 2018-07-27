/*
* CommandFramework
*
* Copyright (C) 2018-2019 Sonu Lohani
*
*    Distributed under the Boost Software License, Version 1.0.
*    (See accompanying file LICENSE_1_0.txt or copy at
*    http://www.boost.org/LICENSE_1_0.txt)
*/

#include "UndoRedoCommand.h"

namespace CommandFramework 
{
	UndoRedoCommand::UndoRedoCommand() : 
		UndoCommand()
	{
	}
	UndoRedoCommand::UndoRedoCommand(ICommand *pCommand) :
		UndoCommand(pCommand)
	{}

	UndoRedoCommand::UndoRedoCommand(std::initializer_list<ICommand *> initializer_list) : 
		UndoCommand(initializer_list)
	{}

	UndoRedoCommand::~UndoRedoCommand()
	{}

	void UndoRedoCommand::redo()
	{
		if (m_pRedoCommandStack.empty())
		{
			throw NoRedoCommandException();
		}
		auto pCommand = m_pRedoCommandStack.top();
		pCommand->execute();
		m_pUndoCommandStack.push(pCommand);
	}

	void UndoRedoCommand::undo()
	{
		auto pCommand = m_pUndoCommandStack.top();
		UndoCommand::undo();
		m_pRedoCommandStack.push(pCommand);
	}
}
