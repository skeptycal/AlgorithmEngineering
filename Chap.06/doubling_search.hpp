/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

template <class T>
typename std::vector<T>::iterator doubling_search_intersection(const std::vector<T>& a, const std::vector<T>& b, typename std::vector<T>::iterator result) {
  std::vector<T> m = a;
  std::vector<T> n = b;
  if( m.size() > n.size() )
    std::swap(m, n);
  int i=0;
  for(T x : m) {
    int k=1;
    while(i+k < n.size() && x > n[i+k])
     k <<= 1;
    auto start = n.begin()+i;
    auto end = n.begin() + std::min(i+k, (int)n.size());
    int ip = distance(n.begin(), lower_bound(start, end, x));
    if( ip == n.size() ) break;
    if( n[ip] == x ) {
      *result = x;
      ++result;
    }
    i = ip; 
  }
  return result;
}
