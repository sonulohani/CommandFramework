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

#include "UndoCommand.h"

namespace CommandFramework
{
	class UndoRedoCommand : public UndoCommand
	{
	public:
		explicit UndoRedoCommand();

		explicit UndoRedoCommand(ICommand *pCommand);

		explicit UndoRedoCommand(std::initializer_list<ICommand *> initializer_list);

		virtual ~UndoRedoCommand();

		virtual void redo();

		virtual void undo() override;
	private:
		std::stack<ICommand *> m_pRedoCommandStack;
	};
}