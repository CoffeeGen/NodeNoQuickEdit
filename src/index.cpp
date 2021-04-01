// src/index.cpp

#include <napi.h>
#include <string>
#include "noquickedit.h"

// Native C++ function that is assigned to 'disableQuickEdit' property on 'exports' object.
Napi::Number disableQuickEdit( const Napi::CallbackInfo& info ) {
    Napi::Env env = info.Env( );
    return Napi::Number::New( env, disable( ) );
}

// callback method when module is registered with Node.js
Napi::Object Init( Napi::Env env, Napi::Object exports ) {
    // set a key on 'exports' object.
    exports.Set(
        Napi::String::New( env, "disableQuickEdit" ),
        Napi::Function::New( env, disableQuickEdit )
    );

    return exports;
}

NODE_API_MODULE( noquickedit, Init );