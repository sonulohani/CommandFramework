#pragma once

namespace CommandFramework
{
	template<typename RetType = void, typename... Args>
	class ICommand
	{
	public:
		virtual void undo() = 0;
		virtual void redo() = 0;
		virtual void execute() = 0;
	};
}