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

#include "UndoOperation.h"

namespace CommandFramework {
	class ICommand;

	class UndoRedoOperation : public UndoOperation {
	public:
		explicit UndoRedoOperation();

		explicit UndoRedoOperation(ICommand *pCommand);

		explicit UndoRedoOperation(
			std::initializer_list<ICommand *> initializer_list);

		virtual ~UndoRedoOperation() override;

		virtual void redo();

		virtual void undo() override;

		virtual void clear() override;

		void clearRedo();

	private:
		std::stack<ICommand *> m_pRedoCommandStack;
	};
} // namespace CommandFramework
