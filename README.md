Adoption of https://github.com/ricab/scope_guard/ for ESP-IDF.

## TL;DR
```c++
#include <sope_guard.h>
...
{
  ...
  auto guard = sg::make_scope_guard(my_callback);
  ...
} // my_callback is invoked at this point

```
