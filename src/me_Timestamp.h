// Time interval definition and management

/*
  Author: Martin Eden
  Last mod.: 2025-03-02
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Timestamp
{
  struct TTimestamp
  {
    TUint_2 KiloS;
    TUint_2 S;
    TUint_2 MilliS;
    TUint_2 MicroS;
  };

  TSint_1 Compare(TTimestamp A, TTimestamp B);
  TBool Add(TTimestamp * Dest, TTimestamp Ts);
  TBool Subtract(TTimestamp * Dest, TTimestamp Ts);
}

/*
  2025-03-02
*/
