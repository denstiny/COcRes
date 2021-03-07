#pragma Staff  // 设置启动一次
#include <fstream>
#define FILENAME "test"

using namespace std;

// 创建员工类
class Employees{
	public:
		// 员工姓名
		char EmployName[100];
		// 员工年龄
		int EmployAge;
		// 员工信息
		char Emaployposition[100];
		long len;
};

// 公司类
class Company {
	public:
		friend Employees;
		fstream obs;
		long len,templen;
		// 打印菜单
		void ShowMenu();
		
		//  写入文件
		bool WriteFileClass(Employees &p);
		// 添加数据
		bool AddEmployees();
		// 读取文件信息
		bool ReadFileClass(Employees &p);
		// 获取数据
		bool ObtainEmploy();
		// 获取员工人数
		void SetLenEmploy();
		// 清空员工数据
		void CloseCompany();
		// 删除员工数据
		void DeleEmploy();
		// 查找员工信息
		bool SeleEmploy(char bufName[100],Employees &p);
		// 临时存储员工信息
		Employees* SaveEmpoly(Employees *p,Employees s);
		// 修改员工数据
		void ModifyEmploy();
		// 修改数据
		Employees* ModifySaveEmpoly(Employees *p,Employees s);
		Company();
		~Company();
};

