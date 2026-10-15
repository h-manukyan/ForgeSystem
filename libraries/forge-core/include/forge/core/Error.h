#ifndef FORGE_CORE_ERROR_H
#define FORGE_CORE_ERROR_H

#include <string>

namespace forge::core {
    enum class ErrorType {
        InvalidArgument,
        InsufficientResource,
        Overflow,
        InternalError
    };

    class Error {
        private:
            ErrorType type_;
            std::string message_;

        public:
            Error(ErrorType typeE, std::string messageE) : type_(typeE), message_(messageE) {}

            ErrorType getType() const {return type_;}
            const std::string& getMessage() const {return message_;}
    };

}

#endif