#include <iostream>
#include <vector>
#include <algorithm>

template <typename... Args>
auto reverse(Args&&... args) -> std::vector<std::common_type_t<Args...>> {
    std::vector<std::common_type_t<Args...>> res; 
    
    bool tmp{false};

    // 利用逗号表达式支持额外的语句执行;
    // push_back方法不返回任何值，所以用false作为返回值;
    // 利用 = 号表达式，从左至右计算的特性，完成序列的翻转。
    (tmp = ... = (res.push_back(args), false));

    return res;
}

int main() {
    
    auto res = reverse<int, float, double, char>(1, 10.1f, 9.9, 8); 

    for_each(res.begin(), res.end(), [](auto&& e){std::cout << e << std::endl;});    

    const int arr[]{1,2,3,4};
    // error, 很好的说明了 auto 的推导规则，在&符号时，会推导为引用，同时这种情况下也会保留底层const等修饰。
    //std::for_each(std::begin(arr), std::end(arr), [](auto&& e){e = 1;});
    //

    int a = 10, b = 1022, c = 1023, d=1024;
    bool t{false};

    (((t = (a, false)) = (b, false)) = (c, false));
    std::cout << t << std::endl;

    a = b = c = d;
    std::cout << a << std::endl;

    return 0;
}
