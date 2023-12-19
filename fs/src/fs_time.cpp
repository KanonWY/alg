#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std::chrono_literals;


// C++ 17 中这个接口不是很完善
int main() {
    fs::path p = fs::current_path() / "example.bin";
    std::ofstream(p.c_str()).put('c');

    std::filesystem::file_time_type lastWriteTime = std::filesystem::last_write_time(p);


    return 0;
}
