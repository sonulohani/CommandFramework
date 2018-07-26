#pragma once

#include "ICommand.h"
#include "BasicCommand.h"
#include "Exception.h"
#include <stack>
#include <initializer_list>

namespace CommandFramework
{
	template<typename RetType = void, typename... Args>
	class UndoCommand : public ICommand<RetType, Args...>
	{
	public:
		explicit UndoCommand() = default;

		explicit UndoCommand(ICommand<RetType, Args...> *pCommand)
		{
			pushCommand(pCommand);
		}

		explicit UndoCommand(std::initializer_list<ICommand<RetType, Args...>> initializer_list)
		{
			for (const auto &command : initializer_list)
			{
				pushCommand(pCommand);
			}
		}

		virtual void undo() override
		{
			if (m_pUndoCommandStack.empty())
			{
				throw NoUndoCommandException();
			}

			auto command = m_pUndoCommandStack.top();

			if (command == nullptr)
			{
				throw NullPointerException();
			}

			command->execute();
			m_pUndoCommandStack.pop();
		}

		void pushCommand(ICommand<RetType, Args...> *pCommand) {
			m_pUndoCommandStack.push(pCommand);
		}

	private:
		virtual void redo() override { throw NotImplementedException(); };

		virtual void execute() override { throw NotImplementedException(); };

	private:
		std::stack<ICommand<RetType, Args...> *> m_pUndoCommandStack;
	};
}