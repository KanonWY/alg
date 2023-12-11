#include <iostream>
#include <memory>

class MyClass {
public:
    ~MyClass() {
        std::cout << "~MyClass()" << std::endl;
    }
};

// by value, 共享，维持引用计数
void share(std::shared_ptr<MyClass> p) {
    std::cout << "share" << std::endl;
    std::cout << "use_count = " << p.use_count() << std::endl;
    auto p2 = p;
}

void reseat(std::shared_ptr<MyClass>& p) {
    std::cout << "我想被重置，或者被修改" << std::endl;
    std::cout << "use_count = " << p.use_count() << std::endl;
}

void spmake(const std::shared_ptr<MyClass>& sp) {
    std::cout << "sp make" << std::endl;
    std::cout << "use_count = " << sp.use_count() << std::endl;
}

int main()
{
    auto sp = std::make_shared<MyClass>();
    std::cout << sp.use_count() << std::endl;
    spmake(sp);
    return 0;
}