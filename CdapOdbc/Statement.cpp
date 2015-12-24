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

#include "stdafx.h"
#include "Statement.h"
#include "Connection.h"

using namespace Cask::CdapOdbc;

void Cask::CdapOdbc::Statement::openQuery() {
}

void Cask::CdapOdbc::Statement::getNextResults() {
}

void Cask::CdapOdbc::Statement::fetchRow() {
}

Cask::CdapOdbc::Statement::Statement(Connection* connection, SQLHSTMT handle)
  : connection(connection)
  , handle(handle)
  , fetchSize(50)
  , currentRowIndex(0)
  , open(false) {
  assert(connection);
  assert(handle);
}

void Cask::CdapOdbc::Statement::addColumnBinding(const ColumnBinding& binding) {
  auto it = std::find_if(
    this->columnBindings.begin(),
    this->columnBindings.end(),
    [binding](auto& b) { return b.getColumnNumber() == binding.getColumnNumber(); });
  if (it != this->columnBindings.end()) {
    // Replace existing binding. 
    *it = binding;
  } else {
    // Add new binding. 
    this->columnBindings.push_back(binding);
  }
}

void Cask::CdapOdbc::Statement::removeColumnBinding(SQLUSMALLINT columnNumber) {
  auto it = std::find_if(
    this->columnBindings.begin(), 
    this->columnBindings.end(), 
    [columnNumber](auto& b) { return b.getColumnNumber() == columnNumber; });
  if (it == this->columnBindings.end()) {
    throw std::invalid_argument("columnNumber");
  }

  this->columnBindings.erase(it);
}

void Cask::CdapOdbc::Statement::getCatalogs() {
  this->queryHandle = this->connection->getExploreClient().getCatalogs();
}

void Cask::CdapOdbc::Statement::fetch() {
  if (this->open) {
    auto nextRow = this->connection->getExploreClient().getQueryResult(this->queryHandle, 1);
  }
}

void Cask::CdapOdbc::Statement::close() {
}
