/*
Copyright (C) 2014 Declan Ireland <http://github.com/torndeco/extDB>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

#include <Poco/Data/Session.h>
#include <Poco/Data/SessionPool.h>

#include <cstdlib>
#include <iostream>

#include "abstract_ext.h"
#include "abstract_protocol.h"

#include "../sanitize.h"


class DB_BASIC: public AbstractProtocol
{
	public:
		bool init(AbstractExt *extension, const std::string init_str);
		void callProtocol(AbstractExt *extension, std::string input_str, std::string &result);
		
	private:
		bool isNumber(std::string &input_str);

		void getCharUID(Poco::Data::Session &db_session, std::string &steamid, std::string &result);
		void getOptionAll(Poco::Data::Session &db_session, std::string &table, std::string &result);
		
		void getOption(Poco::Data::Session &db_session, std::string &table, std::string &uid, std::string &option, std::string &result);
		void getCharOption(Poco::Data::Session &db_session, std::string &table, std::string &steamid, std::string &option, std::string &result);
		
		void setOption(Poco::Data::Session &db_session, std::string &table, std::string &uid, std::string &option, std::string value, std::string &result);
		void setCharOption(Poco::Data::Session &db_session, std::string &table, std::string &steamid, std::string &option, std::string value, std::string &result);
};
