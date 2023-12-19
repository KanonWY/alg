
#include <ctime>
#include <fstream>
#include <gtest/gtest.h>
#include <filesystem>
#include <ios>
#include <iomanip>
#include <string_view>
#include <system_error>
#include <chrono>
/**
 *  std::filesystem::path
 *  常用函数:
 *  (1) 文件名字相关
 *
 *    文件名
 *    filename()
 *    扩展名
 *    extension()
 *    文件名不包含扩展名
 *    stem()
 *
 *    修改文件名字
 *    bool std::filesystem::rename(oldfilepath, newfilepath);
 *    std::error_code ec;
 *    std::filesystem::rename(oldfilepath, newfilepath, ec);
 *    如果修改失败返回，false，存储错误信息到 ec 中。
 *
 *
 *    相对路径 or 绝对路径
 *    path.is_absolute()
 *    path.is_relative()
 *
 *    相对路径转换为绝对路径
 *    std::filesystem::path path("./xxx");
 *    std::filesystem::path abso_path =  std::filesystem::absolute(path);
 *
 *    返回路径的泛化表示, 返回的是一个字符串, 如果是绝对路径，返回的是一个包含所有路径的字符串
 *    path.generic_string()
 *
 *  (2) 返回当前的目录
 *    std::filesystem::path std::filesystem::current_path();
 *
 *  (3) 上一次文件修改的时间
 *    std::filesystem::last_write_time(std::filesystem::path)
 *
 *
 */

void PrintNormalPathInfo(const std::string_view& name) {
    std::filesystem::path path(name.data());
    // 判断文件是否存在
    if (std::filesystem::exists(path)) {
        std::cout << "path.filename()  = " << path.filename() << std::endl;
        std::cout << "path.extension() = " << path.extension() << std::endl;
        std::cout << "path.stem()      = " << path.stem() << std::endl;
        std::cout << std::boolalpha << path.is_absolute() << std::endl;
        std::cout << std::boolalpha << path.is_relative() << std::endl;
    }
    else {
        std::cout << "file " << name.data() << " not exists" << std::endl;
    }
}

void ModifyFileName(const std::string_view& path_name, const std::string_view& new_file_path) {
    std::filesystem::path path(path_name);
    std::filesystem::path new_path(new_file_path);
    if (std::filesystem::exists(path)) {
        std::error_code ec;
        std::filesystem::rename(path, new_path, ec);
        if (ec) {
            std::cout << "std::filesystem::rename error, error_code = " << ec.message() << std::endl;
        }
        else {
            std::cout << "rename success" << std::endl;
        }
    }
}


/**
 *\breif 根据传入的文件路径，获取绝对路径
 *
 */
std::filesystem::path getAbsolu(const std::string_view& path_name) {
    std::filesystem::path path(path_name.data());
    if (std::filesystem::exists(path)) {
        if (path.is_relative()) {
            auto res = std::filesystem::absolute(path);
            return res;
        }
    }
    return {};
}

/* TEST(filesystem, path1) { */
/*     EXPECT_EQ(1, 1 * 1); */
/* } */
int main() {
    return 0;
}
