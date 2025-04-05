#pragma once

#include <stdint.h>

#include "RequestType.h"


namespace FastServ {
    typedef uint64_t FastServSocket;

    enum class ErrState { OK, ERR };
}