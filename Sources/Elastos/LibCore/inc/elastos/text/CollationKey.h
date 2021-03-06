//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_TEXT_COLLATIONKEY_H__
#define __ELASTOS_TEXT_COLLATIONKEY_H__

#include "Elastos.CoreLibrary.Text.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::Object;

namespace Elastos {
namespace Text {

class CollationKey
    : public Object
    , public ICollationKey
    , public IComparable
{
public:
    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ const String& source);

    virtual CARAPI CompareTo(
        /* [in] */ IInterface* value,
        /* [out] */ Int32* result) = 0;

    virtual CARAPI GetSourceString(
        /* [out] */ String* sourceString);

    virtual CARAPI ToByteArray(
        /* [out, callee] */ ArrayOf<Byte>** array) = 0;


protected:
    CollationKey();

    virtual ~CollationKey();

private:
    String mSource;
};

} // namespace Text
} // namespace Elastos

#endif //__ELASTOS_TEXT_COLLATIONKEY_H__
