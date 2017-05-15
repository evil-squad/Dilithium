/**
 * @file Constants.cpp
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

#include <Dilithium/Dilithium.hpp>
#include <Dilithium/Casting.hpp>
#include <Dilithium/Constants.hpp>
#include <Dilithium/DerivedType.hpp>
#include <Dilithium/LLVMContext.hpp>
#include "LLVMContextImpl.hpp"

namespace Dilithium 
{
	Constant* ConstantInt::Get(Type* ty, uint64_t v, bool is_signed)
	{
		Constant* ret = Get(cast<IntegerType>(ty->ScalarType()), v, is_signed);
		VectorType* vty = dyn_cast<VectorType>(ty);
		if (vty)
		{
			return ConstantVector::GetSplat(vty->NumElements(), ret);
		}
		else
		{
			return ret;
		}
	}

	ConstantInt* ConstantInt::Get(IntegerType* ty, uint64_t v, bool is_signed)
	{
		DILITHIUM_UNUSED(ty);
		DILITHIUM_UNUSED(v);
		DILITHIUM_UNUSED(is_signed);
		DILITHIUM_NOT_IMPLEMENTED;
	}


	Constant* ConstantVector::Get(ArrayRef<Constant*> elems)
	{
		DILITHIUM_UNUSED(elems);
		DILITHIUM_NOT_IMPLEMENTED;
	}

	Constant* ConstantVector::GetSplat(uint32_t num_elem, Constant* elem)
	{
		DILITHIUM_UNUSED(num_elem);
		DILITHIUM_UNUSED(elem);
		DILITHIUM_NOT_IMPLEMENTED;
	}


	UndefValue* UndefValue::Get(Type* ty)
	{
		DILITHIUM_UNUSED(ty);
		DILITHIUM_NOT_IMPLEMENTED;
	}
}