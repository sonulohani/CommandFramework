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
#include <initializer_list>
#include <stack>

namespace CommandFramework {
	class ICommand;

	class UndoOperation {
	public:
		explicit UndoOperation() = default;

		explicit UndoOperation(ICommand *pCommand);

		explicit UndoOperation(std::initializer_list<ICommand *> initializer_list);

		virtual ~UndoOperation();

		void pushCommand(ICommand *pCommand);

		virtual void undo();

	protected:
		std::stack<ICommand *> m_pUndoCommandStack;
	};
} // namespace CommandFramework
