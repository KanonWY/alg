#include <filesystem>
#include <iostream>

// space
// C++17 此类的接口功能不完善

int main() {
    std::filesystem::space_info devi = std::filesystem::space("/dev/null");
    std::cout << devi.free << std::endl;
    std::cout << devi.capacity << std::endl;
    std::cout << devi.available << std::endl;
    return 0;
}
