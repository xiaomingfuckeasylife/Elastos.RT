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

#ifndef __ELASTOS_SECURITY_CCODESOURCE_H__
#define __ELASTOS_SECURITY_CCODESOURCE_H__

#include "_Elastos_Security_CCodeSource.h"
#include "elastos/security/Permission.h"

using Elastos::IO::ISerializable;
using Elastos::Net::IURL;

namespace Elastos {
namespace Security {

CarClass(CCodeSource)
    , public Object
    , public ICodeSource
    , public ISerializable
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ IURL* location,
        /* [in] */ ArrayOf<ICertificate*>* certs);

    CARAPI constructor(
        /* [in] */ IURL* location,
        /* [in] */ ArrayOf<ICodeSigner*>* signers);

    CARAPI GetCertificates(
        /* [out] */ ArrayOf<ICertificate*>** result);

    CARAPI GetCodeSigners(
        /* [out] */ ArrayOf<ICodeSigner*>** result);

    CARAPI GetLocation(
        /* [out] */ IURL** result);

    CARAPI Implies(
        /* [in] */ ICodeSource* cs,
        /* [out] */ Boolean* result);
};

}
}

#endif // __ELASTOS_SECURITY_CCODESOURCE_H__
