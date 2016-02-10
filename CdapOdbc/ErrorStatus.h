#pragma once
#include "DataType.h"

namespace Cask {
	namespace CdapOdbc {

		/*
		 * Represents error or worning record element
		*/
		class ErrorStatusElement {
		public:
			std::wstring code;
			std::wstring msg;
			void*		 binError;
			size_t       binErrorLen;

			/*
			 * Constructor
			*/
			ErrorStatusElement(
				std::wstring code = L"\0",
				std::wstring msg = L"\0",
				void* binError = NULL,
				size_t buffLength = 0) :
				code(code), msg(msg), binError(NULL), binErrorLen(0) {};
			// TODO hanle binError buffer in Constructor/Destructor

			/*
			 * Destructor
			*/
			~ErrorStatusElement() {};

		};

		class ErrorStatus {
			std::list<ErrorStatusElement> statusItems;
			std::wstring dummy = L"\0";

		public:

			/*
			 * Constructor
			 */
			ErrorStatus();

			/*
			 * Destructor
			 */
			~ErrorStatus() = default;

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
