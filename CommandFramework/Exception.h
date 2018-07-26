#pragma once

#include <exception>
#include <string>

namespace CommandFramework
{
	class NullPointerException : public std::exception
	{
	public:
		char const* what() const override;

	private:
		std::string m_message = "Null Pointer Exception";
	};

	class NoUndoCommandException : public std::exception
	{
	public:
		char const* what() const override;

	private:
		std::string m_message = "NoUndo Command Exception";
	};

	class NotImplementedException : public std::exception
	{
	public:
		char const* what() const override;

	private:
		std::string m_message = "Not Implemented Exception";
	};
}