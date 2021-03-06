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

#ifndef __ELASTOS_SECURITY_CSIGNATUREHELPER_H__
#define __ELASTOS_SECURITY_CSIGNATUREHELPER_H__

#include "elastos/core/Singleton.h"
#include "_Elastos_Security_CSignatureHelper.h"

using Elastos::Security::IProvider;

namespace Elastos {
namespace Security {

CarClass(CSignatureHelper)
    , public Singleton
    , public ISignatureHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI GetInstance(
        /* [in] */ const String& algorithm,
        /* [out] */ ISignature** instance);

    CARAPI GetInstance(
        /* [in] */ const String& algorithm,
        /* [in] */ const String& provider,
        /* [out] */ ISignature** instance);

    CARAPI GetInstance(
        /* [in] */ const String& algorithm,
        /* [in] */ IProvider* provider,
        /* [out] */ ISignature** instance);
};

} // namespace Security
} // namespace Elastos

#endif // __ELASTOS_SECURITY_CSIGNATUREHELPER_H__
