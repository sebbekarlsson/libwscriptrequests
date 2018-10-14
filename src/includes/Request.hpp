#ifndef WSCRIPT_REQUEST_H
#define WSCRIPT_REQUEST_H
#include <wscript/Interpreter.hpp>
#include <wscript/AST/AST.hpp>
#include <wscript/AST/AST_Object.hpp>
#include <wscript/AST/AST_ObjectCustom.hpp>
#include <wscript/Token.hpp>
#include <wscript/Scope.hpp>
#include <curl/curl.h>



class Request: public AST_ObjectCustom {
    public:
       Request(Token* token);
      ~Request();

        std::string request_method;
        std::string url;
        bool async;
        CURL* curl;
};
#endif
