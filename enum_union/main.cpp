#include <iostream>

using namespace std;

enum class field_completion: int {
    up,
    down
};

enum class intra_field: int  {
    left,
    right
};

// enum class fields : /* intra_field,*/ field_completion {
// };

enum class fields_u {
    intra_field,
    field_completion
};
//=======================================
// https://stackoverflow.com/questions/18344646/combine-enums-c
//=======================================
enum OperationType {
    Comparison = 0x100,
    Arithmetic = 0x200
};
enum ComparisonType
{
    LT = Comparison,     // "<"
    GT,     // ">"
    EQ,     // "=="
    LTEQ,   // "<="
    GTEQ,   // ">="
    NEQ     // "!="
};
enum ArithmeticType
{
    ADD = Arithmetic,    // "+"
    SUB,    // "-"
    MUL,    // "*"
    DIV,    // "/"
    MOD    // "%"
};
// constexpr OperationType getOperationType(unsigned value) {return value & 0xFF00;}  // TODO compile error
constexpr OperationType getOperationType(unsigned value) { auto v = value & 0xFF00; return (OperatorType)v;}  // TODO compile error
//=======================================
//enum Comparison
//{
//    LT,     // "<"
//    GT,     // ">"
//    EQ,     // "=="
//    LTEQ,   // "<="
//    GTEQ,   // ">="
//    NEQ,    // "!="
//    LastComparison
//};
//enum Logical
//{
//    AND = LastComparison,
//    OR,
//    XOR,
//    LastLogical
//};
//=======================================
enum class Comparisonc : int
{
    LT,     // "<"
    GT,     // ">"
    EQ,     // "=="
    LTEQ,   // "<="
    GTEQ,   // ">="
    NEQ,    // "!="
    LastComparison
};
enum class Logicalc : int
{
    AND = (int)Comparisonc::LastComparison,
    OR,
    XOR,
    LastLogical
};
struct unionc {
    union {
        Comparisonc a;
        Logicalc    b;
    };
};
//==========================================

int main()
{
//    if (                   LT ==                XOR ) {}
    if ( (int)Comparisonc::LT == (int)Logicalc::XOR ) {}

    switch ( (int) Comparisonc::LT  ) {
    case     (int) Comparisonc::LT  :
    case     (int) Logicalc::   XOR :
        break;
    }

    cout << "###" << endl;
    return 0;
}
