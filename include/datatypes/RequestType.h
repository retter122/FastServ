#pragma once

#include <stdint.h>
#include <map>
#include <string>

#include "JsonType.h"


namespace Request {
	enum class RequestType { 
		GET, 
		POST, 
		PUT, 
		HEAD, 
		DEL, 
		UPDATE 
	};


	enum class StatusCode {
		CONTINUE = 							100,
		SWITCHING_PROTOCOLS = 				101,
		PROCESSING = 						102,
		EARLY_HINTS = 						103,
	
		OK = 								200,
		CREATED = 							201,
		ACCEPTED = 							202,
		NON_AUTHORITATIVE_INFORMATION = 	203,
		NO_CONTENT = 						204,
		RESET_CONTENT = 					205,
		PARTIAL_CONTENT = 					206,
		MULTI_STATUS = 						207,
		ALREADY_REPORTED = 					208,
		IM_USED = 							209,
	
		MULTIPLE_CHOISES = 					300,
		MOVED_PERMANENTLY = 				301,
		FOUND = 							302,
		SEE_OTHER = 						303,
		NOT_MODIFIED = 						304,
		USE_PROXY = 						305,
		RESERVED = 							306,
		TEMPORANY_REDIRECT = 				307,
		PERMANENT_REDIRECT = 				308,
	
		BAD_REQUEST = 						400,
		UNATHORIZED = 						401,
		PAYMENT_REDIRECT = 					402,
		FORBIDDEN = 						403,
		NOT_FOUND = 						404,
		NETHOD_NOT_ALLOWED = 				405,
		NOT_ACCEPTABLE = 					406,
		PROXY_AUTHENTICATION_REQUIRED =		407,
		REQUEST_TIMEOUT = 					408,
		CONFLICT = 							409,
		GONE = 								410,
		LENGTH_REQUIRED = 					411,
		PRECONDITION_FAILED = 				412,
		PAYLOAD_TOO_LARGE = 				413,
		URI_TOO_LONG = 						414,
		UNSUPPORTED_MEDIA_TYPE = 			415,
		RANGE_NOT_SATISFIABLE = 			416,
		EXPECTATION_FAILED = 				417,
		IM_A_TEAPOT = 						418,
		AUTHENTICATION_TIMEOUT = 			419,
		MISDIRECTED_REQUEST = 				421,
		UNPROCESSABLE_ENTITY = 				422,
		LOCKED = 							423,
		FAILED_DEPENDENCY = 				424,
		TOO_EARLY = 						425,
		UPGRADE_REQUIRED = 					426,
		PRECONDITION_REQUIRED = 			428,
		TOO_MANY_REQUESTS = 				429,
		REQUEST_HEADER_FIELDS_TOO_LARGE = 	431,
		RETRY_WITH = 						449,
		UNAVAILABLE_FOR_LEGAL_REASONS = 	451,
		CLIENT_CLOSED_REQUEST = 			499,

		INTERNAL_SERVER_ERROR = 			500,
		NOT_IMPLEMENTED = 					501,
		BAD_GATEWAY = 						502,
		SERVICE_ANAVAILABLE = 				503,
		GATEWAY_TIMEOUT = 					504,
		HTTP_VERSION_NOT_SUPPORTED = 		505,
		VARIANT_ALSO_NEGOTIATES = 			506,
		INSUFFCIEND_STORAGE = 				507,
		LOOP_DETECTED = 					508,
		BADWITH_LIMIT_EXCEEDED = 			509,
		NOT_EXTENDED = 						510,
		NETWORK_AUTHENTICATION_REQUIRED = 	511,
		UNKLONW_ERROR = 					520,
		WEB_SERVER_IS_DOWN = 				521,
		CONNECTION_TIMED_OUT = 				522,
		ORIGIN_IS_UNREACHABLE = 			523,
		A_TIMED_ACCURED = 					524,
		SSL_HANDSHAKE_FAILED = 				525,
		INVALID_SSL_CETIFICATE = 			526
	};


	class Request {
	private:
		StatusCode status_code;

		std::string headers;
		std::string body;
	
	public:
		Request(): status_code(StatusCode::OK), headers(""), body("") {}
		Request(StatusCode _status_code): status_code(_status_code), headers(""), body("") {}
		Request(StatusCode _status_code, const std::string& _headers): status_code(_status_code), headers(_headers), body("") {}
		Request(StatusCode _status_code, const std::string& _headers, const std::string& _body): status_code(_status_code), headers(_headers), body(_body) {}

		StatusCode get_status_code();

		Json::Json get_headers();
		Json::Json get_json();

		std::string get_content();
	};
}