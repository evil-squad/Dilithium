/**
 * @file Argument.hpp
 * @author Minmin Gong
 *
 * @section DESCRIPTION
 *
 * This source file is part of Dilithium
 * For the latest info, see https://github.com/gongminmin/Dilithium
 *
 * @section LICENSE
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Minmin Gong. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _DILITHIUM_ARGUMENT_HPP
#define _DILITHIUM_ARGUMENT_HPP

#pragma once

#include <Dilithium/Value.hpp>

namespace Dilithium
{
	class Function;

	class Argument : public Value
	{
		typedef Function ParentType;

		template <typename NodeType>
		friend void AddToSymbolTableList(NodeType*, typename NodeType::ParentType*);
		template <typename NodeType>
		friend void RemoveFromSymbolTableList(NodeType*);

	public:
		explicit Argument(Type* ty, std::string_view name = "");
		~Argument();

		Function const * Parent() const
		{
			return parent_;
		}
		Function* Parent()
		{
			return parent_;
		}

		static bool classof(Value const * v)
		{
			return v->GetValueId() == ArgumentVal;
		}

	private:
		void Parent(Function* parent)
		{
			parent_ = parent;
		}

	private:
		Function* parent_;

		// DILITHIUM_NOT_IMPLEMENTED
	};
}

#endif		// _DILITHIUM_ARGUMENT_HPP
