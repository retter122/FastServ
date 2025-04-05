#pragma once

#include <stdint.h>
#include <map>

#include "datatypes/RequestType.h"
#include "datatypes/FastServType.h"


namespace Request {
	char* construct_get_request(std::string _URL, std::map<std::string, std::string> _headers);

	Request send_get(FastServ::FastServSocket _socket, std::string _URL, std::map<std::string, std::string> _headers);
	Request send_post(FastServ::FastServSocket _socket, std::string _URL);
	Request send_put(FastServ::FastServSocket _socket, std::string _URL);
	Request send_head(FastServ::FastServSocket _socket, std::string _URL);
	Request send_delete(FastServ::FastServSocket _socket, std::string _URL);
	Request send_update(FastServ::FastServSocket _socket, std::string _URL);

	Request send_request(FastServ::FastServSocket _socket, RequestType _req_type, std::string _URL, std::map<std::string, std::string> _headers);
}