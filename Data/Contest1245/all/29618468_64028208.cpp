#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#ifdef STOPIT
#define debug(...) 0
#else
#define debug(...)\
do {\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;\
} while (false)
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

class union_find {
    int n;
    std::vector<int> prt;

  public:
    union_find (int n) : n(n), prt(n, -1){}

    bool is_root (int x)        const {return prt.at(x) < 0;}
    int  size    (int x)        const {return -prt.at(find(x));}
    bool same(int x, int y)     const {return find(x) == find(y);}
    int  find    (int x)        const {
      while (!is_root(x)) x = prt.at(x);
      return x;
    }
    // Returns `true` if x and y are newly connected.
    // The smaller one x becomes a child of the larger one y.
    bool unite   (int x, int y) {
      if ((x = find(x)) == (y = find(y))) return false;
      if (size(x) > size(y)) std::swap(x, y);
      prt.at(y) += prt.at(x);
      prt.at(x) = y;
      return true;
    }
};

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& tuple_input_impl(std::istream& os, Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { (void)std::initializer_list<int>{((void)(os >> std::get< Inds >(tuple)), 0)...}; return os; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& operator>> (std::istream& os, Tuple<Args...>& tuple)
  { return tuple_input_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& tuple_output_impl(std::ostream& os, const Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { os << "("; (void)std::initializer_list<int>{((void)(os << (Inds > 0 ? "," : "") << std::get< Inds >(tuple)), 0)...}; return os << ")"; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& operator<< (std::ostream& os, const Tuple<Args...>& tuple)
 { return tuple_output_impl(os, tuple, std::index_sequence_for<Args...>()); }

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  union_find uf(n + 1);
  int special = n;
  std::vector< lint > x(n), y(n);
  rep(i, 0, n) {
    std::cin >> x.at(i) >> y.at(i);
  }
  std::vector< lint > c(n), k(n);
  std::cin >> c >> k;

  std::vector< std::tuple< lint, int, int > > edges;
  rep(i, 0, n) {
    edges.emplace_back(c.at(i), i, special);
  }
  rep(i, 0, n) rep(j, i + 1, n) {
    edges.emplace_back(
      (std::abs(x.at(i) - x.at(j)) + std::abs(y.at(i) - y.at(j)))
        * (k.at(i) + k.at(j)),
      i, j
    );
  }
  std::sort(all(edges));
  // debug(edges);

  lint score = 0;
  std::vector< std::pair< int, int > > ans;
  for (auto const & tuple : edges) {
    lint x; int i, j; std::tie(x, i, j) = tuple;
    if (uf.unite(i, j)) {
      score += x;
      if (j < i) std::swap(i, j);
      ans.emplace_back(i, j);
    }
  }
  // debug(ans);

  std::vector< int > charge;
  std::vector< std::pair< int, int > > road;
  for (auto pair : ans) {
    int i, j; std::tie(i, j) = pair;
    if (j == special) {
      charge.emplace_back(i + 1); // index
    } else {
      road.emplace_back(i + 1, j + 1); // index
    }
  }

  std::cout << score << std::endl;

  int sz0 = charge.size();
  std::cout << sz0 << std::endl;
  rep(i, 0, sz0) {
    std::cout << (0 < i ? " " : "") << charge.at(i);
  }
  std::cout << std::endl;

  std::cout << road.size() << std::endl;
  for (auto const pair : road) {
    std::cout << pair.first << " " << pair.second << std::endl;
  }
  return 0;
}
