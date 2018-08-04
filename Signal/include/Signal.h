/*
 * CommandFramework
 *
 * Copyright (C) 2018-2019 Sonu Lohani
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */

#include <functional>
#include <type_traits>
#include <unordered_map>

template <typename R = void, typename... Args> class Signal {
public:
  uint32_t connect(std::function<R(Args...)> const &slot) {
    m_idToSlotMap[m_currentId++] = slot;
    return m_currentId;
  }

  template <typename T>
  uint32_t connect(T *callable, R (T::*func)(Args...) const) {
    return connect([=](Args... args) { return (callable->*func)(args...); });
  }

  void emit(Args... args) {
    for (auto slot : m_idToSlotMap) {
      slot.second(args...);
    }
  }

  void disconnect(uint32_t id) { m_idToSlotMap.erase(id); }

  void disconnectAll() { m_idToSlotMap.clear(); }

private:
  std::unordered_map<uint32_t, std::function<R(Args...)>> m_idToSlotMap;
  uint32_t m_currentId = 0;
};