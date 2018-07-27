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

namespace CommandFramework
{
	class ICommand
	{
	public:
		virtual void execute() = 0;
	};
}