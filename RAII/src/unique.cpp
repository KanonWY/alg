#include <memory>
#include <iostream>
#include <string>
#include <vector>

struct MyClass {
    std::string name;
    std::vector<std::string> m_vec;
    ~MyClass() {
        std::cout << "~MyClass" << std::endl;
    }
    void echo() {
        std::cout << "echo" << std::endl;
    }
};

// 使用值传递表达所有权的转移
void sink(std::unique_ptr<MyClass> ts) {
    ts.reset();
    std::cout << "sink takes ownership of MyClass" << std::endl;
}

// const ref 的独占指针没有意义
// unknow behavior
void thinko(const std::unique_ptr<MyClass>& ms) {
    ms->echo();
    std::cout << "do what" << std::endl;
}

// 引用传递表明需要重置该指针执行
void doReset(std::unique_ptr<MyClass>& ms) {
    ms.reset();
}



int main() {
    auto ptr = std::make_unique<MyClass>();
    // take ownership of myclass
    sink(std::move(ptr));

    auto ptr2 = std::make_unique<MyClass>();
    thinko(ptr2);


}
