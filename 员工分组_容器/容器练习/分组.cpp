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

//������Ա����
void createWorker(vector<work>& w)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		work worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		w.push_back(worker);
	}
}

//Ա�����麯��
void setGroup(vector<work>&v,multimap<int,work>&m)
{
	for (vector<work>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;//0��1��2
		m.insert(make_pair(deptId, *it));
	}
}

//������ʾ����
void showWorker(multimap<int,work>&m)
{
	cout << "�߻�����:" << endl;
	multimap<int, work>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index <count;index++,pos++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "����" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "��������:" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "����" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "�з�����:" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "����" << pos->second.m_Salary << endl;
	}
}


int main()
{
	//��ʵ���
	srand((unsigned int)time(NULL));

	//����Ա��
	vector<work> vWorker;
	createWorker(vWorker);
	//for (vector<work>::iterator it = w.begin(); it != w.end(); it++)
	//{
	//	cout << it->m_Name << "\t" << it->m_Salary << endl;
	//}

	//Ա������
	multimap<int, work> mWorker;
	setGroup(vWorker,mWorker);

	//������ʾ
	showWorker(mWorker);

	system("pause");
	return 0;
}