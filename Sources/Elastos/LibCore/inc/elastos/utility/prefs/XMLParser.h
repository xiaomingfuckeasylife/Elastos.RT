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

#ifndef __ELASTOS_UTILITY_PREFS_XMLPARSER_H__
#define __ELASTOS_UTILITY_PREFS_XMLPARSER_H__

#include "elastos/core/Object.h"

using Elastos::IO::IOutputStream;
using Elastos::IO::IInputStream;
using Elastos::IO::IFile;
using Elastos::IO::IBufferedWriter;
using Elastosx::Xml::Parsers::IDocumentBuilder;
using Org::W3c::Dom::IElement;
using Org::W3c::Dom::INodeList;

namespace Elastos {
namespace Utility {
namespace Prefs {

/**
 * Utility class for the Preferences import/export from XML file.
 */
class XMLParser
{
public:
    /***************************************************************************
     * utilities for Preferences export
     **************************************************************************/
    static CARAPI ExportPrefs(
        /* [in] */ IPreferences* prefs,
        /* [in] */ IOutputStream* stream,
        /* [in] */ Boolean withSubTree) /*throws IOException, BackingStoreException*/;

    /***************************************************************************
     * utilities for Preferences import
     **************************************************************************/
    static CARAPI ImportPrefs(
        /* [in] */ IInputStream* in) /*throws IOException, InvalidPreferencesFormatException */;

    /**
     * Returns the preferences from {@code xmlFile}. Returns empty properties if
     * any errors occur.
     */
    static CARAPI ReadXmlPreferences(
        /* [in] */ IFile* xmlFile,
        /* [out] */ IProperties** per);

    /**
     * Writes the preferences to {@code xmlFile}.
     */
    static CARAPI WriteXmlPreferences(
        /* [in] */ IFile* xmlFile,
        /* [in] */ IProperties* properties) /*throws IOException*/;

    CARAPI ToString(
        /* [out] */ String* info);

private:
    /*
     * init DOM builder
     */
    static CARAPI_(Boolean) StaticInit();

    static CARAPI ExportNode(
        /* [in] */ IStringTokenizer* ancestors,
        /* [in] */ IPreferences* prefs,
        /* [in] */ Boolean withSubTree,
        /* [in] */ IBufferedWriter* out) /*throws IOException, BackingStoreException*/;

    static CARAPI ExportSubTree(
        /* [in] */ IPreferences* prefs,
        /* [in] */ IBufferedWriter* out) /*throws BackingStoreException, IOException */;

    static CARAPI ExportEntries(
        /* [in] */ IPreferences* prefs,
        /* [in] */ IBufferedWriter* out) /*throws BackingStoreException, IOException*/;

    static CARAPI ExportEntries(
        /* [in] */ ArrayOf<String>* keys,
        /* [in] */ ArrayOf<String>* values,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushEndTag(
        /* [in] */ const String& tagName,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushEmptyElement(
        /* [in] */ const String& tagName,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushEmptyElement(
        /* [in] */ const String& tagName,
        /* [in] */ ArrayOf<String>* attrKeys,
        /* [in] */ ArrayOf<String>* attrValues,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushPairs(
        /* [in] */ ArrayOf<String>* attrKeys,
        /* [in] */ ArrayOf<String>* attrValues,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushIndent(
        /* [in] */ Int32 ind,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushStartTag(
        /* [in] */ const String& tagName,
        /* [in] */ ArrayOf<String>* attrKeys,
        /* [in] */ ArrayOf<String>* attrValues,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI FlushStartTag(
        /* [in] */ const String& tagName,
        /* [in] */ IBufferedWriter* out) /*throws IOException*/;

    static CARAPI_(String) HtmlEncode(
        /* [in] */ const String& s);

    static CARAPI LoadNode(
        /* [in] */ IPreferences* prefs,
        /* [in] */ IElement* node);

    // TODO dirty implementation of a method from javax.xml.xpath
    // should be replaced with a call to a good impl of this method
    static CARAPI_(AutoPtr<INodeList>) SelectNodeList(
        /* [in] */ IElement* documentElement,
        /* [in] */ const String& string);

private:
    XMLParser();
    XMLParser(const XMLParser&);

public:
    /*
     * Constant - the specified DTD URL
     */
    static const String PREFS_DTD_NAME;

    /*
     * Constant - the DTD string
     */
    static const String PREFS_DTD;;

    /*
     * Constant - the specified header
     */
    static const String HEADER;

    /*
     * Constant - the specified DOCTYPE
     */
    static const String DOCTYPE;

private:
    /*
     * Constant - used by FilePreferencesImpl, which is default implementation of Linux platform
     */
    static const String FILE_PREFS;

    /*
     * Constant - specify the DTD version
     */
    static const Float XML_VERSION;

    /*
     * DOM builder
     */
    static const AutoPtr<IDocumentBuilder> sBuilder;

    /*
     * specify the sIndent level
     */
    static Int32 sIndent;
    static Boolean sInit;
};

} // namespace Prefs
} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY__PREFS_XMLPARSER_H__
