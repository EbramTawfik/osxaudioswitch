#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// node headers
#include <nan.h>
#include <v8.h>
#include <node.h>
#include <unistd.h>
#include <string.h>
#include "audio_switch.h"

using namespace node;
using namespace v8;

NAN_METHOD(SwitchOutput)
{
  Nan::Utf8String name(info[0]);
  const char *str = *name;
  switchOutput(str);
}



NAN_METHOD(ResetOutput)
{
  resetOutput();
}


NAN_MODULE_INIT(Init) {

Nan::SetMethod(target, "switchOutput", SwitchOutput);
  Nan::SetMethod(target, "resetOutput", ResetOutput);

}

NAN_MODULE_WORKER_ENABLED(osxaudioswitch, Init);
