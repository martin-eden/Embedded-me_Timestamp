# What

(2025-03, 2025-08)

Time interval definition and management.

Base is second. We scale it to kilo, milli and micro.

We use record with four fields. Each field can hold value from 0 to 999.

```
  KiloS [0, 999]
  S [0, 999],
  MilliS ...,
  MicroS
```

Core functions of course comparison functions plus **Add()** and **Subtract()**.

(
  Implementation is typical long arithmetic but code is copy-paste.
  Data structure for "normal" long numbers uses array to access digits.
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

[Interface]: src/me_Duration.h
[Implementation]: src/me_Duration.cpp
[Examples]: examples/

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
