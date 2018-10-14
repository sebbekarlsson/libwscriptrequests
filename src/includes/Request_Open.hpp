#ifndef WSCRIPT_REQUEST_OPEN_H
#define WSCRIPT_REQUEST_OPEN_H
#include <wscript/AST/AST_BuiltinFunctionDefinition.hpp>
#include "Request.hpp"


class Request_Open: public AST_BuiltinFunctionDefinition {
    public:
        Request_Open(std::string name, Request* obj);
        ~Request_Open();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        Request* obj;
        
};
#endif
