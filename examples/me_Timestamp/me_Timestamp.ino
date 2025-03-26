// [me_Timestamp] test

/*
  Author: Martin Eden
  Last mod.: 2025-03-02
*/

#include <me_Timestamp.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

void PrintTs(
  me_Timestamp::TTimestamp Ts
)
{
  Console.Write("(");
  Console.Print(Ts.KiloS);
  Console.Print(Ts.S);
  Console.Print(Ts.MilliS);
  Console.Write(")");
}

void TestCompare()
{
  me_Timestamp::TTimestamp A, B;
  TSint_1 CompareResult;

  {
    A = { 0, 0, 0, 0 };
    B = { 0, 0, 0, 0 };
    CompareResult = me_Timestamp::Compare(A, B);
    PrintTs(A);
    Console.Print(CompareResult);
    PrintTs(B);
    Console.EndLine();
  }

  {
    A = { 0, 999, 0, 0 };
    B = { 0, 0, 0, 0 };
    CompareResult = me_Timestamp::Compare(A, B);
    PrintTs(A);
    Console.Print(CompareResult);
    PrintTs(B);
    Console.EndLine();
  }

  {
    A = { 0, 0, 0, 0 };
    B = { 0, 0, 1, 0 };
    CompareResult = me_Timestamp::Compare(A, B);
    PrintTs(A);
    Console.Print(CompareResult);
    PrintTs(B);
    Console.EndLine();
  }
}

void TestAdd()
{
  me_Timestamp::TTimestamp A, B;
  TBool IsWrapped;

  {
    A = { 0, 0, 0, 0 };
    B = { 0, 0, 0, 0 };
    PrintTs(A);
    Console.Write("+");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Add(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 0, 0, 1, 0 };
    B = { 0, 0, 999, 0 };
    PrintTs(A);
    Console.Write("+");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Add(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 500, 0, 1, 0 };
    B = { 499, 999, 999, 0 };
    PrintTs(A);
    Console.Write("+");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Add(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 0, 1, 760, 0 };
    B = { 0, 0, 1760, 0 };
    PrintTs(A);
    Console.Write("+");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Add(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }
}

void TestSub()
{
  me_Timestamp::TTimestamp A, B;
  TBool IsWrapped;

  {
    A = { 0, 0, 0, 0 };
    B = { 0, 0, 0, 0 };
    PrintTs(A);
    Console.Write("-");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Subtract(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 0, 1, 0, 0 };
    B = { 0, 0, 1, 0 };
    PrintTs(A);
    Console.Write("-");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Subtract(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 0, 0, 1, 0 };
    B = { 0, 0, 999, 0 };
    PrintTs(A);
    Console.Write("-");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Subtract(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }

  {
    A = { 500, 0, 1, 0 };
    B = { 499, 999, 999, 0 };
    PrintTs(A);
    Console.Write("-");
    PrintTs(B);
    IsWrapped = !me_Timestamp::Subtract(&A, B);
    Console.Print(IsWrapped);
    PrintTs(A);
    Console.EndLine();
  }
}

void setup()
{
  me_Uart::Init(me_Uart::Speed_115k_Bps);
  Console.Print("Init done.");

  TestCompare();
  TestAdd();
  TestSub();

  Console.Print("Done.");
}

void loop()
{
}

/*
  2025-03-02
*/
