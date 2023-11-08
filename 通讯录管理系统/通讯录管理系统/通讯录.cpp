#include<iostream>

using namespace std;
#define MAX 1000
//��ϵ�˵Ľṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks//ͨѶ¼�Ľṹ��
{  
	struct Person personArray[MAX];//ͨѶ�б������ϵ��������

	int m_Size;//ͨѶ¼��ϵ�˸���

};
//�����ϵ��
void addPerson(Addressbooks  *abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{//�����ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
	    //�Ա�
		cout << "������������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//����������1��2���˳�ѭ��
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
				cout << "������������������" << endl;
			}
		}
			//����
			cout << "���������䣺" << endl;
			int age = 0;
			cin >> age;
			abs->personArray[abs->m_Size].m_age = age;
			//�绰
			cout << "��������ĵ绰��" << endl;
			string number;
			cin >> number;
			abs->personArray[abs->m_Size].m_Phone = number;
			//��ͥסַ
			cout << "��������ļ�ͥסַ��" << endl;
			string adder;
			cin >> adder;
			abs->personArray[abs->m_Size].m_Addr = adder;
			//����ͨѶ¼����
			abs->m_Size++;
			cout << "��ӳɹ�" << endl;
			system("pause");//�����������
			system("cls");//��������
	}
}
void showperson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������  " <<abs->personArray[i].m_Name<< "/t";
			cout << "�Ա�  " << (abs->personArray[i].m_Sex ==1?"��":"Ů") << "/t";//��Ŀ�����
			cout << "���䣺  " << abs->personArray[i].m_age << "/t";
			cout << "�绰��  " << abs->personArray[i].m_Phone << "/t";
			cout << "סַ��  " << abs->personArray[i].m_Addr << endl;
		}
	
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//��װɾ����ϵ�˵ĺ���
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;

	}
	system("pause");
	system("cls");

}
//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "/t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "/t";
		cout << "���䣺" << abs->personArray[ret].m_age << "/t";
		cout << "�绰" << abs->personArray[ret].m_Phone << "/t";
		cout << "סַ" << abs->personArray[ret].m_Addr << endl;;
	}
	else
	{
		cout << "���޴���" << endl;

	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{   
		string name;
		cout << "�������޸ĵ�������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//�绰
		cout << "������绰��" << endl;
		string number;
		cin >> number;
		abs->personArray[ret].m_Phone = number;
		//סַ
		cout << "�������ַ" << endl;
		string adderss;
		cin >> adderss;
		abs->personArray[ret].m_Addr = adderss;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	
	system("pause");
	system("cls");
}
//���������ϵ��
//ֻ�����߼��ϵ���վ�����
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//���߼���գ������ʲ�����Ϣ
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");

}


//�˵�����
void showMenu()
{
	cout << "*************************************" << endl;
	cout << "*******       1,�����ϵ��    *******" << endl;
	cout << "*******       2,��ʾ��ϵ��    *******" << endl;
	cout << "*******       3,ɾ����ϵ��    *******" << endl;
	cout << "*******       4,������ϵ��    *******" << endl;
	cout << "*******       5,�޸���ϵ��    *******" << endl;
	cout << "*******       6,�����ϵ��    *******" << endl;
	cout << "*******       0,�˳���ϵ��    *******" << endl;
	cout << "*************************************" << endl;
}
int main() {
	//ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	
	int select = 0;//�����û�ѡ������ı���
	while(true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:addPerson(&abs);
			break;
		case 2:showperson(&abs);
			break;
		case 3:deletePerson(&abs);
			break;
		case 4:findPerson(&abs);
			break;
		case 5:modifyPerson(&abs);
			break;
		case 6:cleanPerson(&abs);
			break;
		case 0:cout << "��ӭ�´ε�¼" << endl;
			system("pause");
			return 0;


		default:
			break;
		}
	}
	system("pause");
	return 0;
}
//1����ϵ�˽ṹ��
//2�����ͨѶ¼�ṹ��
//3��main�д���ͨѶ¼
//4����װ��ϵ�˺���
//5�����������ϵ�˹���
