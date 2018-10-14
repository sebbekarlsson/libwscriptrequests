#include "includes/Request_Send.hpp"
#include <string>
#include <wscript/AST/AST_NoOp.hpp>
#include <iostream>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

Request_Send::Request_Send(std::string name, Request* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
};

Request_Send::~Request_Send() {};

AST* Request_Send::call(std::vector<AST*> args, Interpreter* interpreter) {
    CURLcode res;

    CURL* curl = this->obj->curl;
    if(curl) {
        std::string readBuffer;

        curl_easy_setopt(curl, CURLOPT_URL, this->obj->url.c_str());
        /* example.com is redirected, so we tell libcurl to follow redirection */ 
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        /* Perform the request, res will get the return code */ 
        res = curl_easy_perform(curl);
        /* Check for errors */ 
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */ 
        curl_easy_cleanup(curl);

        this->obj->get_private_scope()->set_variable("responseText", readBuffer);
    }

    return new AST_NoOp();
};
