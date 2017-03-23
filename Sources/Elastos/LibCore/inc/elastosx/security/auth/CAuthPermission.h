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

#ifndef __ELASTOSX_SECURITY_AUTH_CAUTHPERMISSION_H__
#define __ELASTOSX_SECURITY_AUTH_CAUTHPERMISSION_H__

#include "_Elastosx_Security_Auth_CAuthPermission.h"
#include "BasicPermission.h"

using Elastos::Security::IPermissionCollection;
using Elastos::Security::IPermission;
using Elastos::Security::BasicPermission;

namespace Elastosx {
namespace Security {
namespace Auth {

CarClass(CAuthPermission)
    , public BasicPermission
    , public IAuthPermission
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    // @Override
    CARAPI GetActions(
        /* [out] */ String *actions);

    // @Override
    CARAPI Implies(
        /* [in] */ IPermission *permission,
        /* [out] */ Boolean *result);

    CARAPI constructor(
        /* [in] */ const String& name);

    CARAPI constructor(
        /* [in] */ const String& name,
        /* [in] */ const String& actions);
};

}
}
}

#endif // __ELASTOSX_SECURITY_AUTH_CAUTHPERMISSION_H__