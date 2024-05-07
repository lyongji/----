#include <iostream>
#include <string>

class 抽象产品 {
public:
  抽象产品() {}
  virtual ~抽象产品() {}

  virtual void 打印名称() = 0;
  virtual void 开始() = 0;
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

class 抽象工厂 {
public:
  抽象工厂() {}
  virtual ~抽象工厂() {}

  virtual 抽象产品 *创建产品() = 0;
};

class 产品A工厂 : public 抽象工厂 {
public:
  产品A工厂() { std::cout << "产品A工厂被创建" << std::endl; }
  ~产品A工厂() {}
  抽象产品 *创建产品() { return new 产品A; }
};

class 产品B工厂 : public 抽象工厂 {
public:
  产品B工厂() { std::cout << "产品B工厂被创建" << std::endl; }
  ~产品B工厂() {}
  抽象产品 *创建产品() { return new 产品B; }
};

int main(int argc, char **argv) {
  std::cout << "工厂方法模式" << std::endl;

  抽象工厂 *工厂 = nullptr;
  抽象产品 *产品 = nullptr;

  工厂 = new 产品A工厂;
  产品 = 工厂->创建产品();
  产品->打印名称();
  delete 工厂;
  工厂 = nullptr;
  delete 产品;
  产品 = nullptr;

  工厂 = new 产品B工厂;
  产品 = 工厂->创建产品();
  产品->打印名称();
  delete 工厂;
  工厂 = nullptr;
  delete 产品;
  产品 = nullptr;

  std::cout << "工厂方法模式结束" << std::endl;
  return 0;
}
