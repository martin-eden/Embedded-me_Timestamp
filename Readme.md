# What

(2025-03)

Time interval definition and management for ATmega328/P.

We use fancy record to track time:

```
  KiloS [0, 999]
  S [0, 999],
  MilliS ...,
  MicroS
```

So yes, four words with values relation of 1000.

Core functions of course **Add()**, **Subtract()** and **Compare()**.

(
  Implementation is typical long arithmetic but code is copy-paste.
  We don't want to provide array alias for record just for shorter
  source code of implementation.
)

## Code

* [Interface][Interface]
* [Implementation][Implementation]
* [Examples][Examples]

## Requirements

  * arduino-cli
  * bash

## Install/remove

This is low-level library which depends only of `me_BaseTypes`.
However example uses my other libraries. To save us time I recommend to
clone [GetLibs][GetLibs] repo and run it's code to get all my stuff.

## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Interface]: src/me_Timestamp.h
[Implementation]: src/me_Timestamp.cpp
[Examples]: examples/

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
