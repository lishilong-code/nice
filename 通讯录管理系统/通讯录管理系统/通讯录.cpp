#include<iostream>

using namespace std;
#define MAX 1000
//联系人的结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks//通讯录的结构体
{  
	struct Person personArray[MAX];//通讯中保存的联系人数数组

	int m_Size;//通讯录联系人个数

};
//添加联系人
void addPerson(Addressbooks  *abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{//添加联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
	    //性别
		cout << "请你输入你的性别" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//如果输入的是1或2则退出循环
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
				cout << "输入有误，请重新输入" << endl;
			}
		}
			//年龄
			cout << "请输入年龄：" << endl;
			int age = 0;
			cin >> age;
			abs->personArray[abs->m_Size].m_age = age;
			//电话
			cout << "请输入你的电话：" << endl;
			string number;
			cin >> number;
			abs->personArray[abs->m_Size].m_Phone = number;
			//家庭住址
			cout << "请输入你的家庭住址：" << endl;
			string adder;
			cin >> adder;
			abs->personArray[abs->m_Size].m_Addr = adder;
			//更新通讯录人数
			abs->m_Size++;
			cout << "添加成功" << endl;
			system("pause");//按任意键继续
			system("cls");//清屏操作
	}
}
void showperson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：  " <<abs->personArray[i].m_Name<< "/t";
			cout << "性别：  " << (abs->personArray[i].m_Sex ==1?"男":"女") << "/t";//三目运算符
			cout << "年龄：  " << abs->personArray[i].m_age << "/t";
			cout << "电话：  " << abs->personArray[i].m_Phone << "/t";
			cout << "住址：  " << abs->personArray[i].m_Addr << endl;
		}
	
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
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
//封装删除联系人的函数
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");

}
//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "/t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "/t";
		cout << "年龄：" << abs->personArray[ret].m_age << "/t";
		cout << "电话" << abs->personArray[ret].m_Phone << "/t";
		cout << "住址" << abs->personArray[ret].m_Addr << endl;;
	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{   
		string name;
		cout << "请输入修改的姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//电话
		cout << "请输入电话：" << endl;
		string number;
		cin >> number;
		abs->personArray[ret].m_Phone = number;
		//住址
		cout << "请输入地址" << endl;
		string adderss;
		cin >> adderss;
		abs->personArray[ret].m_Addr = adderss;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}
//清空所有联系人
//只用作逻辑上的清空就行了
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//做逻辑清空，即访问不到信息
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");

}


//菜单界面
void showMenu()
{
	cout << "*************************************" << endl;
	cout << "*******       1,添加联系人    *******" << endl;
	cout << "*******       2,显示联系人    *******" << endl;
	cout << "*******       3,删除联系人    *******" << endl;
	cout << "*******       4,查找联系人    *******" << endl;
	cout << "*******       5,修改联系人    *******" << endl;
	cout << "*******       6,清空联系人    *******" << endl;
	cout << "*******       0,退出联系人    *******" << endl;
	cout << "*************************************" << endl;
}
int main() {
	//通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	
	int select = 0;//创建用户选择输入的变量
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
		case 0:cout << "欢迎下次登录" << endl;
			system("pause");
			return 0;


		default:
			break;
		}
	}
	system("pause");
	return 0;
}
//1，联系人结构提
//2，设计通讯录结构体
//3，main中创建通讯录
//4，封装联系人函数
//5，测试添加联系人功能
