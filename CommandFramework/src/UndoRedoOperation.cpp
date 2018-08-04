/*
 * CommandFramework
 *
 * Copyright (C) 2018-2019 Sonu Lohani
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */

#include "UndoRedoOperation.h"
#include "ICommand.h"

namespace CommandFramework {
UndoRedoOperation::UndoRedoOperation() : UndoOperation() {}
UndoRedoOperation::UndoRedoOperation(ICommand *pCommand)
    : UndoOperation(pCommand) {}

UndoRedoOperation::UndoRedoOperation(
    std::initializer_list<ICommand *> initializer_list)
    : UndoOperation(initializer_list) {}

UndoRedoOperation::~UndoRedoOperation() {}

void UndoRedoOperation::redo() {
  if (m_pRedoCommandStack.empty()) {
    throw NoRedoCommandException();
  }
  auto pCommand = m_pRedoCommandStack.top();
  pCommand->execute();
  m_pUndoCommandStack.push(pCommand);
}

void UndoRedoOperation::undo() {
  auto pCommand = m_pUndoCommandStack.top();
  UndoOperation::undo();
  m_pRedoCommandStack.push(pCommand);
}
} // namespace CommandFramework
