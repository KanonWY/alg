#include <filesystem>
#include <ios>
#include <iostream>
#include <string_view>
#include <system_error>


/**
 *
 *  (1) 创建目录
 *      创建单个目录，如果父目录不存在或者该目录已存在将会返回false
 *      // 直接使用返回值，判断是否创建成功即可，因为如果该目录已经存在，则也会返回false
 *      bool create_directory(std::filesystem::path)
 *      异常只会在出现系统错误的时候才会 ec
 *      bool create_directory(std::filesystem::path, std::error_code& ec)
 *
 *
 *  (2) 创建目录（包含其父目录）
 *      区别：可以在父目录不存在的情况下创建目录
 *      为了能够保证创建该目录，可以使用 create_directories() 这样会创建出实际的接口
 *      bool create_directories(std::filesystem::path, std::error_code& ec);
 *
 *  (3) 删除一个目录
 *      返回的是删除文件的数量
 *      如果文件不存在则会返回 0
 *      size_t std::filesystem::remove_all(std::filesystem::path);
 *
 *  (4) 删除一个常规文件, 或者空目录
 *      bool std::filesystem::remove(std::filesystem::path, std::error_code& ec);
 *      如果删除一个非空目录会包异常
 *
 *  (5) 遍历目录内容
 *       std::filesystem::directory_ioterator(std::filesysytem::path)
 *       这个对象本身就是一个迭代器对象，可以直接使用 for 循环进行访问
 *       1. 先判断是否该path 是否存在
 *       2. 然后判断该path 是否是一个目录
 *       3. 遍历
 *       for(const auto& item: std::filesysytem::directory_iterator(path_example))
 *       {
 *            // 获取到的是entry 对象，可以直接获取到每一个 path 对象
 *            std::cout << item.path() << std::endl;
 *       }
 *
 */


/**
 *\brief 创建单个目录
 */
void TEST_create_dir(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    if (std::filesystem::exists(path)) {
        std::cout << "目录存在无需创建" << std::endl;
    }
    else {
        std::error_code ec;
        bool            res = std::filesystem::create_directory(path, ec);
        if (ec) {
            std::cout << "创建目录失败: " << ec.message() << std::endl;
        }
        else {
            std::cout << "创建目录成功!" << std::endl;
        }
    }
}

void TEST_create_dir2(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    std::error_code       ec;
    bool                  res = std::filesystem::create_directory(path, ec);
    std::cout << "res = " << std::boolalpha << res << std::endl;
    if (!res) {
        std::cout << "Create Dir error" << std::endl;
        if (ec) {

            std::cout << ec.message() << std::endl;
        }
    }
}

void TEST_create_dir3(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    std::error_code       ec;
    bool                  res = std::filesystem::create_directories(path, ec);
    if (ec) {
        std::cout << ec.message() << std::endl;
    }
    if (!res) {
        std::cout << "创建目录失败" << std::endl;
    }
    else {
        std::cout << "创建目录成功" << std::endl;
    }
}


void TEST_remove_a_exist_dir(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    std::error_code       ec;
    auto                  size = std::filesystem::remove_all(path, ec);
    std::cout << "remove_all size = " << size << std::endl;
}

void TEST_remove_a_non_dir(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    std::error_code       ec;
    bool                  res = std::filesystem::remove(path, ec);
    if (ec) {
        std::cerr << "删除目录失败, 失败原因: " << ec.message() << std::endl;
    }
    else {
        if (res) {
            std::cout << "删除文件成功" << std::endl;
        }
    }
}

void TEST_travel_Dir(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        for (const auto& item: std::filesystem::directory_iterator(path)) {
            if (item.path().is_relative()) {
                auto abPath = std::filesystem::absolute(item.path());
                std::cout << abPath << std::endl;
                // make_preferred 没有什么变化?
                abPath.make_preferred();
                std::cout << abPath << std::endl;
            }
        }
    }
    // 一个 directory_entry 的大小为 80 字节.
    std::cout << "entry size = " << sizeof(std::filesystem::directory_entry) << std::endl;
    std::cout << "path  size = " << sizeof(std::filesystem::path) << std::endl;
}


int main() {

    TEST_travel_Dir("./test");
    return 0;
}
