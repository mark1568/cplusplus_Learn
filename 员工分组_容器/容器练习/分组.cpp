#include <iostream>
using namespace std;
#include <vector>
#include <map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class work
{
public:
	string m_Name;
	int m_Salary;
};

//创建成员函数
void createWorker(vector<work>& w)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		work worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		w.push_back(worker);
	}
}

//员工分组函数
void setGroup(vector<work>&v,multimap<int,work>&m)
{
	for (vector<work>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;//0，1，2
		m.insert(make_pair(deptId, *it));
	}
}

//分组显示函数
void showWorker(multimap<int,work>&m)
{
	cout << "策划部门:" << endl;
	multimap<int, work>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index <count;index++,pos++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "美术部门:" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "研发部门:" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资" << pos->second.m_Salary << endl;
	}
}


int main()
{
	//真实随机
	srand((unsigned int)time(NULL));

	//创建员工
	vector<work> vWorker;
	createWorker(vWorker);
	//for (vector<work>::iterator it = w.begin(); it != w.end(); it++)
	//{
	//	cout << it->m_Name << "\t" << it->m_Salary << endl;
	//}

	//员工分组
	multimap<int, work> mWorker;
	setGroup(vWorker,mWorker);

	//分组显示
	showWorker(mWorker);

	system("pause");
	return 0;
}