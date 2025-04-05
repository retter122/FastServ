#pragma once

#include <stdint.h>
#include <map>

#include "datatypes/RequestType.h"
#include "datatypes/FastServType.h"


namespace Request {
	char* construct_get_request(std::string _URL, std::map<std::string, std::string> _headers);

	Request send_get(std::string _URL, std::map<std::string, std::string> _headers);
	Request send_post(std::string _URL);
	Request send_put(std::string _URL);
	Request send_head(std::string _URL);
	Request send_delete(std::string _URL);
	Request send_update(std::string _URL);

	Request send_request(RequestType _req_type, std::string _URL, std::map<std::string, std::string> _headers);
}