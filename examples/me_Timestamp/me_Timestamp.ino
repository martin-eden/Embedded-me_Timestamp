// [me_Timestamp] test

/*
  Author: Martin Eden
  Last mod.: 2025-09-19
*/

#include <me_Timestamp.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_DebugPrints.h>

void PrintTs(
  me_Timestamp::TTimestamp Ts
)
{
  me_DebugPrints::PrintDuration(Ts);
}

void Compare(
  me_Timestamp::TTimestamp A,
  me_Timestamp::TTimestamp B
)
{
  PrintTs(A);

  if (me_Timestamp::IsLess(A, B))
    Console.Write("<");

  if (me_Timestamp::IsGreater(A, B))
    Console.Write(">");

  if (me_Timestamp::AreEqual(A, B))
    Console.Write("=");

  PrintTs(B);

  Console.EndLine();
}

void TestCompare()
{
  Console.Print("( Comparison");
  Console.Indent();

  Compare({ 000, 000, 000, 000 }, { 000, 000, 000, 000 });
  Compare({ 000, 999, 000, 000 }, { 000, 000, 000, 000 });
  Compare({ 000, 000, 000, 000 }, { 000, 000, 001, 000 });

  Console.Unindent();
  Console.Print(")");
}

void Add(
  me_Timestamp::TTimestamp A,
  me_Timestamp::TTimestamp B
)
{
  TBool IsOk;

  PrintTs(A);

  Console.Write("+");

  PrintTs(B);

  Console.Write("=");

  IsOk = me_Timestamp::Add(&A, B);

  PrintTs(A);

  if (!IsOk)
    Console.Write("[!]");

  Console.EndLine();
}

void TestAdd()
{
  Console.Print("( Addition");
  Console.Indent();

  // A + B = B + A  -- commutativity
  Add({ 0, 0, 0, 1 }, { 0, 0, 0, 2 });
  Add({ 0, 0, 0, 2 }, { 0, 0, 0, 1 });

  // Carry
  Add({ 0, 0, 1, 0 }, { 0, 0, 999, 0 });

  // Overflow
  Add({ 500, 0, 0, 2 }, { 499, 999, 999, 999 });

  // Max field values
  Add({ 0, 0, 999, 0 }, { 0, 0, 999, 0 });

  // Invalid field value
  Add({ 0, 0, 0, 0 }, { 0, 0, 0, 1023 });

  Console.Unindent();
  Console.Print(")");
}

void Sub(
  me_Timestamp::TTimestamp A,
  me_Timestamp::TTimestamp B
)
{
  TBool IsOk;

  PrintTs(A);

  Console.Write("-");

  PrintTs(B);

  Console.Write("=");

  IsOk = me_Timestamp::Subtract(&A, B);

  PrintTs(A);

  if (!IsOk)
    Console.Write("[!]");

  Console.EndLine();
}

void TestSub()
{
  Console.Print("( Subtraction");
  Console.Indent();

  // Borrow
  Sub({ 0, 1, 0, 0 }, { 0, 0, 1, 0 });
  // Borrow
  Sub({ 0, 1, 0, 8 }, { 0, 0, 0, 9 });
  // Underflow
  Sub({ 0, 0, 1, 0 }, { 0, 0, 2, 0 });
  // Underflow
  Sub({ 499, 999, 999, 999 }, { 500, 0, 0, 2 });
  // Correct
  Sub({ 500, 0, 0, 2 }, { 499, 999, 999, 999 });

  Console.Unindent();
  Console.Print(")");
}

void RunTests()
{
  TestCompare();
  TestAdd();
  TestSub();
}

void setup()
{
  Console.Init();
  Console.Print("( [me_Timestamp] test");

  Console.Indent();
  RunTests();
  Console.Unindent();

  Console.Print(") Done");
}

void loop()
{
}

/*
  2025-03-02
  2025-08-01
  2025-09-19
*/
