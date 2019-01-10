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
#include "ICommand.h"
#include <functional>

namespace CommandFramework {
	template <typename Func = std::function<void()>>
	class BasicCommand : public ICommand {
	public:
		BasicCommand(const Func &func) : m_func(func) {}

		virtual void execute() override { m_func(); }

	private:
		Func m_func;
	};
} // namespace CommandFramework
