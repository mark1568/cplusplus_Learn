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

//map�Ĺ���͸�ֵ
void test01()
{
	//����
	map<int, int>m;
	//��ֵ
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

	//��������
	map<int, int>m2(m);


}

//�ж��Ƿ�Ϊ��
void test02()
{
	//����
	map<int, int>m;
	//��ֵ
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	//printMap(m);
	if (m.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��" << endl;
		cout << "��С��" << m.size() << endl;
	}


}

//����
void test03()
{
	map<int, int>m1;
	//��ֵ
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	//��ֵ
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));

	cout << "����ǰ" << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "������" << endl;
	printMap(m1);
	printMap(m2);

}

//�����ɾ��
void test04()
{
	map<int, int>m1;
	//����
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(map<int, int>::value_type(3, 30));//�����飬̫����
	m1[4] = (4, 40);//������
	printMap(m1);
	cout << endl;
	//ɾ��
	m1.erase(m1.begin());
	m1.erase(3);
	printMap(m1);

	cout << endl;
	m1.clear();
	printMap(m1);

}

//���Һ�ͳ��
void test05()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//����,�᷵�ص�����
	map<int, int>::iterator pos = m.find(1);
	if (pos != m.end())
	{
		cout << "�ҵ�Ԫ��,ֵΪ" << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//ͳ��
	int num = m.count(3);
	cout << num << endl;
}

//����
//�º���
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
	//��ֵ
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