#include <wscript/TOKEN_TYPES.hpp>
#include "includes/Request.hpp"
#include "includes/Request_Open.hpp"
#include "includes/Request_Send.hpp"
#include <wscript/Scope.hpp>
#include <wscript/AST/AST_Str.hpp>
#include <wscript/typedefs.hpp>
#include <string>


Scope* global_scope = new Scope("global");
Request::Request(Token* token) : AST_ObjectCustom(token) {
    Request_Open* o = new Request_Open("open", this);
    this->private_scope->define_builtin_function(o);

    Request_Send* s = new Request_Send("send", this);
    this->private_scope->define_builtin_function(s);
};

Request::~Request() {};

extern "C" AST_ObjectCustom* create() {
    return new Request(nullptr);
};

extern "C" void destroy(AST_ObjectCustom* p) {
    //delete p;
};
