#pragma once

#include "ICommand.h"
#include "Exception.h"
#include <functional>

namespace CommandFramework 
{

	template<typename RetType = void, typename... Args>
	class BasicCommand : public ICommand<RetType, Args...>
	{
		using Func = std::function<RetType(Args...)>;
	public:
		BasicCommand(const Func &func) :
			m_func(func)
		{
			execute();
		}

		virtual void undo() override { 
			throw NotImplementedException(); 
		};

		virtual void redo() override { 
			throw NotImplementedException(); 
		};

		virtual void execute() override {
			m_func(Args...);
		}

	private:
		Func m_func;
	};
}