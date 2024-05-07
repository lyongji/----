#include <iostream>
#include <string>

class 抽象产品 {
public:
  抽象产品() {}
  void 打印名称(){};
  void 开始(){};
};

class 产品A : public 抽象产品 {
public:
  产品A() {
    打印名称();
    开始();
  }
  ~产品A() { std::cout << "产品A被销毁" << std::endl; }
  void 打印名称() { std::cout << "产品A" << std::endl; }
  void 开始() { std::cout << "产品A开始工作" << std::endl; }
};

class 产品B : public 抽象产品 {
public:
  产品B() {
    打印名称();
    开始();
  }
  ~产品B() { std::cout << "产品B被销毁" << std::endl; }
  void 打印名称() { std::cout << "产品B" << std::endl; }
  void 开始() { std::cout << "产品B开始工作" << std::endl; }
};

class 产品工厂 {
public:
  抽象产品 *创建产品(std::string 产品名) {
    抽象产品 *产品 = nullptr;
    // 创建具体产品
    if (产品名 == "A") {
      产品 = new 产品A();
    } else if (产品名 == "B") {
      产品 = new 产品B();
    } else {
      return nullptr;
    }
    return 产品;
  }
};

int main(int argc, char **argv) {
  std::cout << "简单工厂模式" << std::endl;
  产品工厂 *工厂 = new 产品工厂();
  抽象产品 *产品 = nullptr;
  产品 = 工厂->创建产品("A");
  产品->打印名称();
  产品 = 工厂->创建产品("B");
  产品->打印名称();
  delete 产品;
  产品 = nullptr;
  std::cout << "简单工厂模式结束" << std::endl;
  return 0;
}
