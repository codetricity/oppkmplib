#include "libnative_api.h"
#include "stdio.h"

int main(int argc, char** argv) {
  //obtain reference for calling Kotlin/Native functions
  libnative_ExportedSymbols* lib = libnative_symbols();

  lib->kotlin.root.opplibdemo.forIntegers(1, 2, 3, 4);
  lib->kotlin.root.opplibdemo.forFloats(1.0f, 2.0);

  //use C and Kotlin/Native strings
  const char* str = "Hello from Native!";
  const char* response = lib->kotlin.root.opplibdemo.strings(str);
  printf("in: %s\nout:%s\n", str, response);
  lib->DisposeString(response);

  //create Kotlin object instance
 libnative_kref_opplibdemo_Clazz newInstance = lib->kotlin.root.opplibdemo.Clazz.Clazz();
 long x = lib->kotlin.root.opplibdemo.Clazz.memberFunction(newInstance, 42);

 const char* craigGreeting = lib->kotlin.root.opplibdemo.Clazz.craigMethodGreeting(newInstance);
  lib->DisposeStablePointer(newInstance.pinned);

  printf("DemoClazz returned %ld\n", x);
  printf("custom greeting: %s\n", craigGreeting);

  return 0;
}