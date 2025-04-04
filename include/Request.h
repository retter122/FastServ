#pragma once

#include "datatypes/RequestType.h"

#include <stdint.h>
#include <map.h>
#include <ostream>


namespace Request {
	Request get_request(std::map<std::string, std::string> _headers);

	Request send_request(RequestType _req_type, std::map<std::string, std::string> _headers);
}