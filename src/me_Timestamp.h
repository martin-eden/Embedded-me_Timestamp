// Time interval definition and management

/*
  Author: Martin Eden
  Last mod.: 2025-09-14
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Timestamp
{
  /*
    Duration record

    Size: 40 bits (5 bytes)
    Capacity: 1 mega-second (~11 days)
    Granularity: 1 micro-second
  */
  struct TTimestamp
  {
    TUint_2 KiloS : 10;
    TUint_2 S : 10;
    TUint_2 MilliS : 10;
    TUint_2 MicroS : 10;
  };

  /*
    Comparison

    (
      AreEqual
      IsLess
      IsGreater
      IsLessOrEqual
      IsGreaterOrEqual
    ) - boolean functions for readable code
  */
  TBool AreEqual(TTimestamp A, TTimestamp B);
  TBool IsLess(TTimestamp A, TTimestamp B);
  TBool IsGreater(TTimestamp A, TTimestamp B);
  TBool IsLessOrEqual(TTimestamp A, TTimestamp B);
  TBool IsGreaterOrEqual(TTimestamp A, TTimestamp B);

  /*
    Add/subtract functions
  */
  TBool Add(TTimestamp * A, TTimestamp B);
  TBool Subtract(TTimestamp * A, TTimestamp B);
}

/*
  2025-03-02
  2025-08-02
*/
