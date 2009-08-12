/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: sw=2 ts=2 sts=2
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is unicode functions code.
 *
 * The Initial Developer of the Original Code is
 * Mozilla Corporation. 
 * Portions created by the Initial Developer are Copyright (C) 2007
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Shawn Wilsher <me@shawnwilsher.com> (Original Author)
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef _mozStorageUnicodeFunctions_h_
#define _mozStorageUnicodeFunctions_h_

#include "sqlite3.h"
#include "nscore.h"

namespace StorageUnicodeFunctions {

  /**
   * Registers the functions with sqlite.
   *
   * @param aDB
   *        The database we'll be registering the functions with.
   * @return the sqlite status code.
   */
  NS_HIDDEN_(int) RegisterFunctions(sqlite3 *aDB);

  /**
   * Does the upper and lowercase conversions for the SQL functions upper() and
   * lower().
   *
   * @param p
   *        The sqlite_context that this function is being called on.
   * @param aArgc
   *        The number of arguments the function is being called with.
   * @param aArgv
   *        An array of the arguments the functions is being called with.
   */
  NS_HIDDEN_(void) caseFunction(sqlite3_context *p,
                                int aArgc,
                                sqlite3_value **aArgv);

  /**
   * Performs the LIKE comparison in sqlite.
   *
   * @param p
   *        The sqlite_context that this function is being called on.
   * @param aArgc
   *        The number of arguments the function is being called with.
   * @param aArgv
   *        An array of the arguments the functions is being called with.
   */
  NS_HIDDEN_(void) likeFunction(sqlite3_context *p,
                                int aArgc,
                                sqlite3_value **aArgv);
}

#endif // _mozStorageUnicodeFunctions_h_