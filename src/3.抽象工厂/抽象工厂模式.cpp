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

class 产品A1 : public 抽象产品 {
public:
  产品A1() {
    打印名称();
    开始();
  }
  ~产品A1() { std::cout << "产品A1被销毁" << std::endl; }
  void 打印名称() { std::cout << "产品A1" << std::endl; }
  void 开始() { std::cout << "产品A1开始工作" << std::endl; }
};

class 产品B1 : public 抽象产品 {
public:
  产品B1() {
    打印名称();
    开始();
  }
  ~产品B1() { std::cout << "产品B1被销毁" << std::endl; }
  void 打印名称() { std::cout << "产品B1" << std::endl; }
  void 开始() { std::cout << "产品B1开始工作" << std::endl; }
};

class 抽象工厂 {
public:
  抽象工厂() {}
  virtual ~抽象工厂() {}

  virtual 抽象产品 *创建产品A() = 0;
  virtual 抽象产品 *创建产品B() = 0;
};

class 产品工厂1 : public 抽象工厂 {
public:
  产品工厂1() { std::cout << "产品工厂1被创建" << std::endl; }
  ~产品工厂1() {}
  抽象产品 *创建产品A() { return new 产品A1; }
  抽象产品 *创建产品B() { return new 产品B1; }
};

class 产品工厂 : public 抽象工厂 {
public:
  产品工厂() { std::cout << "产品A工厂被创建" << std::endl; }
  ~产品工厂() {}
  抽象产品 *创建产品A() { return new 产品A; }
  抽象产品 *创建产品B() { return new 产品B; }
};

int main(int argc, char **argv) {
  std::cout << "抽象工厂模式" << std::endl;
  // 创建字母产品族
  抽象工厂 *工厂 = nullptr;
  抽象产品 *产品A = nullptr;
  抽象产品 *产品B = nullptr;
  工厂 = new 产品工厂;
  产品A = 工厂->创建产品A();
  产品A->打印名称();
  产品B = 工厂->创建产品B();
  产品B->打印名称();

  delete 工厂;
  工厂 = nullptr;
  delete 产品A;
  产品A = nullptr;
  delete 产品B;
  产品B = nullptr;

  // 创建数字产品族
  工厂 = new 产品工厂1;
  产品A = 工厂->创建产品A();
  产品A->打印名称();
  产品B = 工厂->创建产品B();
  产品B->打印名称();

  delete 工厂;
  工厂 = nullptr;
  delete 产品A;
  产品A = nullptr;
  delete 产品B;
  产品B = nullptr;

  std::cout << "抽象工厂模式结束" << std::endl;
  return 0;
}
