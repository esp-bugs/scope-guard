#pragma once

#include "scope_guard.h"


namespace
{
  struct DeferHelper {
    template<typename F>
    auto operator|(F&& fn) const {
      return sg::make_scope_guard(std::move(fn));
    }
  };
}

#define ESBG_DEFER__(x) ESBG_DEFER__ ## x
#define ESBG_DEFER_(x) ESBG_DEFER__(x)

#define ESBG_DEFER const auto ESBG_DEFER_(__COUNTER__) = DeferHelper() | [&]
#define DEFER ESBG_DEFER
