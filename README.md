# Kotlin Multiplatform Native Library for Windows Tutorial

This is code for a [video tutorial on how to make a native Windows
library with Kotlin](https://youtu.be/M1JWWHc50Kw).

It's a modification of
[Kotlin/Native as a dynamic library – tutorial](https://kotlinlang.org/docs/native-dynamic-libraries.html) on the official
Kotlin site.

There are two steps:

1. build native library for Windows desktop
2. use library in sample C program

## use gradle to link native

```text
> ./gradlew linkNative


BUILD SUCCESSFUL in 1s
4 actionable tasks: 1 executed, 3 up-to-date
```

## Output native Windows library with x64 Native Tools

Using Windows x64 Native Tools.


```text
>lib /def:libnative.def /out:libnative.lib
Microsoft (R) Library Manager Version 14.29.30151.0
Copyright (C) Microsoft Corporation.  All rights reserved.

LINK : warning LNK4068: /MACHINE not specified; defaulting to X64
   Creating library libnative.lib and object libnative.exp
```

## compile c program with native library

Using Windows x64 Native Tools.

```text
>cl.exe main.c libnative.lib
Microsoft (R) C/C++ Optimizing Compiler Version 19.29.30151 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

main.c
Microsoft (R) Incremental Linker Version 14.29.30151.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj
libnative.lib
```

## run program

```text
.\main.exe
in: Hello from Native!
out:That is 'Hello from Native!' from C
DemoClazz returned 42
custom greeting: Aloha, from Craig.  This is inside a Kotlin class
```
