#include <iostream>
#include <vector>

/* still error
template <typename T, typename T1>
using P = std::pair<T, T1>;
*/

/* still error
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> p) {
*/

namespace Inner {

    using std::operator<<;
    
    template <typename T1, typename T2>
    using P = std::pair<T1, T2>;

    template <typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os,  const P<T1, T2>& p) {
        return os << "<" << p.first <<  ", " << p.second << ">";
    }

    class PP {
    public:
        template <typename T1, typename T2>
        using Pair = std::pair<T1, T2>;

        int x;
        int y;
    };

    std::ostream& operator<<(std::ostream& os,  const PP& p) {
        return os << "<" << p.x <<  ", " << p.y << ">";
    }
}

int main() {

    //std::cout << v[0] << std::endl;
    //std::cout << v[0].first << std::endl;
    //Inner::PP::Pair<int, double> p1 = std::make_pair(1, 1.4f);
    Inner::P<int, double> p1 = std::make_pair(1, 1.4f);
    Inner::operator<<(std::cout, p1);
    std::cout << "---" << std::endl;
    // using 没法触发 ADL 寻找
    // 下面两条语句，没法找到22行 Inner::<<
    // 依然找的是 std namespace, 也就是using 别名指向的namespace
    //operator<<(std::cout, p1);
    //operator<<(std::cout, v[0]);
    //std::vector<Inner::P<int, double>> v0{{1, 5.5}};
    //std::cout << v0[0] << std::endl;
    
    Inner::PP p2{1024, 2048};
    Inner::PP();
    Inner::PP p3;
    Inner::operator<<(std::cout, p2);
    Inner::operator<<(std::cout, p3);
    std::cout << std::endl;

    std::cout << "---" << std::endl;

    // 使用类，正常触发了ADL
    operator<<(std::cout, p3);
    std::cout << p3 << std::endl;
    std::cout << "---" << std::endl;

    // 作为容器的元素，一样正常触发ADL
    std::vector<Inner::PP> v{{1, 5}};
    std::cout << v[0] << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<Inner::PP>(std::cout, " "));

    return 0;
}
