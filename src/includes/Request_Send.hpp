#ifndef WSCRIPT_REQUEST_SEND_H
#define WSCRIPT_REQUEST_SEND_H
#include <wscript/AST/AST_BuiltinFunctionDefinition.hpp>
#include "Request.hpp"


class Request_Send: public AST_BuiltinFunctionDefinition {
    public:
        Request_Send(std::string name, Request* obj);
        ~Request_Send();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        Request* obj;
};
#endif
