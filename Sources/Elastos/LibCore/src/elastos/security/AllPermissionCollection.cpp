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

#include "AllPermissionCollection.h"

namespace Elastos {
namespace Security {

ECode AllPermissionCollection::Add(
    /* [in] */ IPermission *permission)
{
    return NOERROR;
}

ECode AllPermissionCollection::GetElements(
    /* [out] */ IEnumeration **elems)
{
    *elems = NULL;
    return NOERROR;
}

ECode AllPermissionCollection::Implies(
    /* [in] */ IPermission *permission,
    /* [out] */ Boolean *ret)
{
    VALIDATE_NOT_NULL(ret)
    *ret = TRUE;
    return NOERROR;
}

} // namespace Security
} // namespace Elastos