/*
* Copyright © 2015 Cask Data, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may not
* use this file except in compliance with the License. You may obtain a copy of
* the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations under
* the License.
*/

#pragma once
#include "DataType.h"

namespace Cask {
	namespace CdapOdbc {

		/*
		 * Represents error or worning record element
		*/
		class SQLStatusElement {
		public:
			std::wstring code;
			std::wstring msg;
			void*		 binError;
			size_t       binErrorLen;

			/*
			 * Constructor
			*/
			SQLStatusElement(
				std::wstring code = L"\0",
				std::wstring msg = L"\0",
				void* binError = NULL,
				size_t buffLength = 0) :
				code(code), msg(msg), binError(NULL), binErrorLen(0) {};
			// TODO hanle binError buffer in Constructor/Destructor

			/*
			 * Destructor
			*/
			~SQLStatusElement() {};

		};

		class SQLStatus {
			std::list<SQLStatusElement> statusItems;
			std::wstring dummy = L"\0";

		public:

			/*
			 * Constructor
			 */
			SQLStatus();

			/*
			 * Destructor
			 */
			~SQLStatus() = default;

			/*
			 * Add new log error record in the storage
			 */
			void addMsg(std::wstring code, std::wstring msg, void* binError = NULL, size_t buffLength = 0);
			
			/*
			 * get count of records in storage
			 */
			SQLSMALLINT getRecCount();

			/*
			 * get error code for necord recNum, where 1 <= recNum <= getRecCount()
			 */
			std::wstring& getCode(SQLSMALLINT recNum);

			/*
			 * get error message for necord recNum, where 1 <= recNum <= getRecCount()
			 */
			std::wstring& getMessage(SQLSMALLINT recNum);

			/*
			 * Clear record storage
			 */
			void clear();
		};
	}
}
