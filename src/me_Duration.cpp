// Time interval management

/*
  Author: Martin Eden
  Last mod.: 2025-09-20
*/

/*
  It's sort of "long arithmetic": (0 0 123 456) means 123 milli-seconds
  and 456 micro-seconds.
*/

#include <me_Duration.h>

#include <me_BaseTypes.h>

using namespace me_Duration;

const TUint_2 MaxFieldValue = 999;

/*
  True when timestamps are equal
*/
TBool me_Duration::AreEqual(
  TDuration A,
  TDuration B
)
{
  return
    (A.KiloS == B.KiloS) &&
    (A.S == B.S) &&
    (A.MilliS == B.MilliS) &&
    (A.MicroS == B.MicroS);
}

/*
  True when timestamp is less
*/
TBool me_Duration::IsLess(
  TDuration A,
  TDuration B
)
{
  if (A.KiloS < B.KiloS)
    return true;
  if (A.KiloS > B.KiloS)
    return false;

  if (A.S < B.S)
    return true;
  if (A.S > B.S)
    return false;

  if (A.MilliS < B.MilliS)
    return true;
  if (A.MilliS > B.MilliS)
    return false;

  if (A.MicroS < B.MicroS)
    return true;

  return false;
}

/*
  True when timestamp is greater
*/
TBool me_Duration::IsGreater(
  TDuration A,
  TDuration B
)
{
  return IsLess(B, A);
}

/*
  True when timestamp is less or equal
*/
TBool me_Duration::IsLessOrEqual(
  TDuration A,
  TDuration B
)
{
  return
    IsLess(A, B) ||
    AreEqual(A, B);
}

/*
  True when timestamp is greater or equal
*/
TBool me_Duration::IsGreaterOrEqual(
  TDuration A,
  TDuration B
)
{
  return
    IsGreater(A, B) ||
    AreEqual(A, B);
}

/*
  Check that duration data is valid

  All fields must lie in [000, 999].
*/
TBool DurationIsValid(
  TDuration Dur
)
{
  return
    (Dur.KiloS <= MaxFieldValue) &&
    (Dur.S <= MaxFieldValue) &&
    (Dur.MilliS <= MaxFieldValue) &&
    (Dur.MicroS <= MaxFieldValue);
}

/*
  Add timestamp

  For field values over 999 returns "false".
  On overflow wraps around and returns "false".
*/
TBool me_Duration::Add(
  TDuration * A,
  TDuration B
)
{
  TUint_2 KiloS, S, MilliS, MicroS;
  TUint_1 Carry, NextCarry;

  if (!DurationIsValid(*A)) return false;
  if (!DurationIsValid(B)) return false;

  KiloS = A->KiloS;
  S = A->S;
  MilliS = A->MilliS;
  MicroS = A->MicroS;

  NextCarry = 0;

  MicroS += B.MicroS;

  if (MicroS > MaxFieldValue)
  {
    MicroS -= MaxFieldValue + 1;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  MilliS += B.MilliS + Carry;

  if (MilliS > MaxFieldValue)
  {
    MilliS -= MaxFieldValue + 1;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  S += B.S + Carry;

  if (S > MaxFieldValue)
  {
    S -= MaxFieldValue + 1;
    NextCarry = 1;
  }

  Carry = NextCarry;
  NextCarry = 0;

  KiloS += B.KiloS + Carry;

  if (KiloS > MaxFieldValue)
  {
    KiloS -= MaxFieldValue + 1;
    NextCarry = 1;
  }

  Carry = NextCarry;

  A->KiloS = KiloS;
  A->S = S;
  A->MilliS = MilliS;
  A->MicroS = MicroS;

  return (Carry == 0);
}

/*
  Subtract duration

  For field values over 999 returns "false".
  On underflow wraps around and returns "false".
*/
TBool me_Duration::Subtract(
  TDuration * A,
  TDuration B
)
{
  TUint_2 KiloS, S, MilliS, MicroS;
  TUint_1 Borrow, NextBorrow;

  if (!DurationIsValid(*A)) return false;
  if (!DurationIsValid(B)) return false;

  KiloS = A->KiloS;
  S = A->S;
  MilliS = A->MilliS;
  MicroS = A->MicroS;

  NextBorrow = 0;

  if (MicroS < B.MicroS)
  {
    MicroS += MaxFieldValue + 1;
    NextBorrow = 1;
  }

  MicroS -= B.MicroS;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (MilliS < TUint_2(B.MilliS + Borrow))
  {
    MilliS += MaxFieldValue + 1;
    NextBorrow = 1;
  }

  MilliS -= B.MilliS + Borrow;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (S < TUint_2(B.S + Borrow))
  {
    S += MaxFieldValue + 1;
    NextBorrow = 1;
  }

  S -= B.S + Borrow;

  Borrow = NextBorrow;
  NextBorrow = 0;

  if (KiloS < TUint_2(B.KiloS + Borrow))
  {
    KiloS += MaxFieldValue + 1;
    NextBorrow = 1;
  }

  KiloS -= B.KiloS + Borrow;

  Borrow = NextBorrow;

  A->KiloS = KiloS;
  A->S = S;
  A->MilliS = MilliS;
  A->MicroS = MicroS;

  return (Borrow == 0);
}

/*
  2025-03-02
  2025-03-03
  2025-08-01
*/
