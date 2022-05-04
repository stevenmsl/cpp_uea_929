#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol929;
using namespace std;

/*takeaways
  - don't remove the '.' in the domain name
*/

int Solution::findUnique(vector<string> &emails)
{
  auto unique = unordered_set<string>();

  for (auto e : emails)
  {
    string name;
    for (auto c : e)
    {
      if (c == '.')
        continue;
      if (c == '+' || c == '@')
        break;
      name.push_back(c);
    }

    /* copy everything after and include '@' */
    auto email = name + e.substr(e.find('@'));
    unique.insert(email);
  }

  return unique.size();
}
