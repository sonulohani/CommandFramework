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

#include <exception>
#include <string>

namespace CommandFramework {
	class NullPointerException : public std::exception {
	public:
		char const *what() const noexcept override;

	private:
		std::string m_message = "Null Pointer Exception";
	};

	class NoUndoCommandException : public std::exception {
	public:
		char const *what() const noexcept override;

	private:
		std::string m_message = "No Undo Command Exception";
	};

	class NoRedoCommandException : public std::exception {
	public:
		char const *what() const noexcept override;

	private:
		std::string m_message = "No Redo Command Exception";
	};

	class NotImplementedException : public std::exception {
	public:
		char const *what() const noexcept override;

	private:
		std::string m_message = "Not Implemented Exception";
	};
} // namespace CommandFramework
