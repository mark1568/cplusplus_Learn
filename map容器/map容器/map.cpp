#include <iostream>
using namespace std;
#include <map>


void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << (*it).first << "\t" << "value=" << (*it).second << endl;
	}
}

//map的构造和赋值
void test01()
{
	//创建
	map<int, int>m;
	//赋值
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

	//拷贝构造
	map<int, int>m2(m);


}

//判断是否为空
void test02()
{
	//创建
	map<int, int>m;
	//赋值
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	//printMap(m);
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "大小：" << m.size() << endl;
	}


}

//交换
void test03()
{
	map<int, int>m1;
	//赋值
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	//赋值
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));

	cout << "交换前" << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "交换后" << endl;
	printMap(m1);
	printMap(m2);

}

//插入和删除
void test04()
{
	map<int, int>m1;
	//插入
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(map<int, int>::value_type(3, 30));//不建议，太长了
	m1[4] = (4, 40);//不建议
	printMap(m1);
	cout << endl;
	//删除
	m1.erase(m1.begin());
	m1.erase(3);
	printMap(m1);

	cout << endl;
	m1.clear();
	printMap(m1);

}

//查找和统计
void test05()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//查找,会返回迭代器
	map<int, int>::iterator pos = m.find(1);
	if (pos != m.end())
	{
		cout << "找到元素,值为" << (*pos).second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计
	int num = m.count(3);
	cout << num << endl;
}

//排序
//仿函数
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void test06()
{
	map<int, int,MyCompare>m1;
	//赋值
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	for (map<int, int,MyCompare>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key=" << it->first << "\t" << "value=" << it->second << endl;
	}
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}