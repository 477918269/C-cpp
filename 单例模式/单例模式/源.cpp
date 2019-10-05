
#include <iostream>
using namespace std;

class Singleton{
public:
	static Singleton* getInstance();

private:
	Singleton();
	//把复制构造函数和=操作符也设为私有,防止被复制
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static Singleton* instance;
};

Singleton::Singleton(){

}


Singleton::Singleton(const Singleton&){

}


Singleton& Singleton::operator=(const Singleton&){
	return *this;
}


//在此处初始化
Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance(){
	return instance;
}

int main(){
	Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2)
		fprintf(stderr, "singleton1 = singleton2\n");

	return 0;
}
