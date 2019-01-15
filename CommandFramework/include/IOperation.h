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

namespace CommandFramework {
	class ICommand;

	class IOperation {
	public:
		IOperation() = default;

		virtual ~IOperation() = default;

		virtual void clear() = 0;

		virtual void pushCommand(ICommand *pCommand) = 0;
	};
} // namespace CommandFramework
