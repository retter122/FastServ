#pragma once

#include "datatypes/JsonType.h"

#include <stdint.h>
#include <string>


namespace Json {
    Json serialize(const std::string& _dat);
    std::string deserialize(const Json& _obj);
}