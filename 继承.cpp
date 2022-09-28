//继承
//继承的好处：减少重复代码
//语法 class 子类：继承方式 父类
//class c++: public BasePage
//子类 也称为 派生类
//父类 也称为 基类
//
//派生类中的成员，包含两大部分
//一部分是基类继承过来的，一类是自己增加的成员
//从基类继承过来的表现其共性，自己新增的成员体现了其个性

//继承方式
//公共继承
//保护继承
//私有继承
//
//父类中所有非静态成员属性都会被子类继承下去
//父类中私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
//
//利用开发人员命令提示工具查看对象模型
//跳转盘符 F：
//跳转文件路径 cd 具体路径下
//查看命名
//c1 /d1 reportSingleClassLayout类名 文件名

//#include<iostream>
//using namespace std;
//class far
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//
//};
//class son :protected far
//{
//public:
//	int d;
//};
//int main()
//{
//	son s1;
//	system("pause");
//	return 0;
//}

//继承中的构造和析构顺序
//
//先构造父类 再构造子类 析构的顺序与构造相反

//继承同名成员处理方式
//
//当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据？
//
//访问子类同名成员 直接访问即可
//访问父类同名成员 需要加作用域 
//当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数（即使是函数重载），
//加作用域可以访问到父类中同名函数 

//静态成员和非静态成员处理方式一样 只不过静态成员变量有两种访问方式 对象访问 类名访问
//son::m_A 通过类名的方式访问
//son：：base::m_A 第一个：：代表通过类名方式访问  第二个：：表示访问父类作用域下

//多继承语法
//c++允许一个类继承多个类
//语法 class 子类：继承方式 父类1，继承方式 父类2、
//多继承可能会引发父类中有同名成员出现，需要加作用域区分
//c++实际开发中 不建议用多继承

//菱形继承
//两个派生类继承同一个基类
//又有某个类同时继承两个派生类
//这种继承被称为菱形继承或者钻石继承

//菱形继承问题
//羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数剧时，就会产生二义性
// 解决方案 通过作用域区分
//草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就够了
//利用虚继承  继承之前加上关键字 virtual变为虚继承 Animal变为虚基类 不需要作用域区分 
//避免了资源浪费

//vbptr 虚基类指针 virtual base point  放在 vatable
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//	int age;
//};
//class sheep: virtual public Animal {};
//class tuo : virtual public Animal {};
//class sheeptuo:public sheep,public tuo{};
//void test01()
//{
//	Animal a;
//	a.age = 20;
//	sheep s;
//	s.age = 18;
//	sheeptuo t;
//	
//	t.sheep::age = 21;
//	t.tuo::age = 15;
//	cout << s.age << endl;
//	cout << s.Animal::age << endl;
//	cout << t.sheep::age << endl;
//	cout << t.tuo::age << endl;
//}
//int main()
//{
//	test01();
//	cout << "size of =" << sizeof(sheeptuo) << endl;
//	cout << "size of =" << sizeof(sheep) << endl;
//	cout << "size of =" << sizeof(tuo) << endl;
//		cout << "size of =" << sizeof(Animal) << endl;
//	system("pause");
//	return 0;
//}
