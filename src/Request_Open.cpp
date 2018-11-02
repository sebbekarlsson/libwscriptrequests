#include "includes/Request_Open.hpp"
#include <string>
#include <wscript/AST/AST_NoOp.hpp>
#include <wscript/AST/AST_VarDecl.hpp>
#include <iostream>


Request_Open::Request_Open(std::string name, Request* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
    this->expected_args.push_back(TokenType::String);
    this->expected_args.push_back(TokenType::String);
    this->expected_args.push_back(TokenType::Integer);
};

Request_Open::~Request_Open() {};

AST* Request_Open::call(std::vector<AST*> args, Interpreter* interpreter) {
    anything _request_method = interpreter->visit(args[0]);
    anything _url = interpreter->visit(args[1]);
    anything _async = interpreter->visit(args[2]);

    if (_url.type() == typeid(std::string)) {
        this->obj->url = boost::get<std::string>(_url);
        this->obj->get_private_scope()->set_variable("url", this->obj->url);
        this->obj->curl = curl_easy_init();
    }

    return new AST_NoOp();
};
