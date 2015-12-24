/*
* Copyright � 2015 Cask Data, Inc.
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

namespace Cask {
  namespace CdapOdbc {
    class Connection;

    /**
    * Represents a SQL statement which can be executed to return some data.
    */
    class Statement {
      Connection* connection;
      SQLHSTMT handle;

      Statement(const Statement&) = delete;
      void operator=(const Statement&) = delete;

    public:

      /**
      * Creates a statement instance.
      */
      Statement(Connection* connection, SQLHSTMT handle);

      /**
      * Destructor.
      */
      ~Statement() = default;

      /**
      * Gets ODBC statement handle.
      */
      SQLHSTMT getHandle() const {
        return this->handle;
      }

      /**
       * Gets parent connection.
       */
      Connection* getConnection() const {
        return this->connection;
      }
    };
  }
}
