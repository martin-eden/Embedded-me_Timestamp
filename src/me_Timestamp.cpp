// Time interval management

/*
  Author: Martin Eden
  Last mod.: 2025-03-03
*/

/*
  It's sort of "long arithmetic": (0 0 123 456) means 123 milliseconds
  and 456 microseconds.
*/

#include <me_Timestamp.h>

using namespace me_Timestamp;

// Compare: -1 for less, 1 for greater, 0 for equal
TSint_1 me_Timestamp::Compare(
  TTimestamp A,
  TTimestamp B
)
{
  if (A.KiloS < B.KiloS)
    return -1;

  if (A.KiloS > B.KiloS)
    return 1;

  if (A.S < B.S)
    return -1;

  if (A.S > B.S)
    return 1;

  if (A.MilliS < B.MilliS)
    return -1;

  if (A.MilliS > B.MilliS)
    return 1;

  if (A.MicroS < B.MicroS)
    return -1;

  if (A.MicroS > B.MicroS)
    return 1;

  return 0;
}

/*
  Add timestamp

  On overflow wraps around and returns "false".
*/
TBool me_Timestamp::Add(
  TTimestamp * Dest,
  TTimestamp Ts
)
{
  TUint_1 Carry, NextCarry;

  NextCarry = 0;

  Dest->MicroS += Ts.MicroS;

  if (Dest->MicroS >= 1000)
  {
    Dest->MicroS -= 1000;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  Dest->MilliS += Ts.MilliS + Carry;

  if (Dest->MilliS >= 1000)
  {
    Dest->MilliS -= 1000;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  Dest->S += Ts.S + Carry;

  if (Dest->S >= 1000)
  {
    Dest->S -= 1000;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  Dest->KiloS += Ts.KiloS + Carry;

  if (Dest->KiloS >= 1000)
  {
    Dest->KiloS -= 1000;
    NextCarry = 1;
  }

  Carry = NextCarry;

  return (Carry == 0);
}

/*
  Subtract timestamp

  On underflow wraps around and returns "false".
*/
TBool me_Timestamp::Subtract(TTimestamp * Dest, TTimestamp Ts)
{
  TUint_1 Borrow, NextBorrow;

  NextBorrow = 0;

  if (Dest->MicroS < Ts.MicroS)
  {
    Dest->MicroS += 1000;
    NextBorrow = 1;
  }

  Dest->MicroS -= Ts.MicroS;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (Dest->MilliS < Ts.MilliS + Borrow)
  {
    Dest->MilliS += 1000;
    NextBorrow = 1;
  }

  Dest->MilliS -= Ts.MilliS + Borrow;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (Dest->S < Ts.S + Borrow)
  {
    Dest->S += 1000;
    NextBorrow = 1;
  }

  Dest->S -= Ts.S + Borrow;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (Dest->KiloS < Ts.KiloS + Borrow)
  {
    Dest->KiloS += 1000;
    NextBorrow = 1;
  }

  Dest->KiloS -= Ts.KiloS + Borrow;

  Borrow = NextBorrow;

  return (Borrow == 0);
}

/*
  2025-03-02
  2025-03-03
*/
