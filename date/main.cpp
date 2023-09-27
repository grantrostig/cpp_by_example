#include "../../date/include/date/date.h"
#include <chrono>
#include <iostream>

using std::cout, std::endl;

int main() {
  using namespace date;
  // using namespace std::chrono;

  std::chrono::time_point today1 =
      date::floor<date::days>(std::chrono::system_clock::now());
  date::year_month_day today1b{today1};

  auto today1c_ymd = date::year_month_day{today1};

  std::chrono::time_point today2 =
      date::floor<std::chrono::seconds>(std::chrono::system_clock::now());

  std::chrono::time_point today3 = std::chrono::system_clock::now();

  constexpr date::year_month_day x1 = date::March / 22 / 2015;

  unsigned int my_month{5};
  date::year_month_day x2 =
      date::year{2020} / date::month{my_month} / date::day{14};

  cout << today1b << endl;
  cout << today2 << endl;
  cout << today3 << endl;
  cout << x1 << endl;
  cout << x2 << endl;
  cout << "###" << endl;
  return 0;
}
