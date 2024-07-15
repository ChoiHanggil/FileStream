#include<iostream>
#include<fstream>		//file stream object
#include<string>
#include<vector>

struct Monster
{
	std::string mName;
	int mLevel;
	int mHp;
	int mMp;
};

std::ifstream& operator >> (std::ifstream& ifs, Monster& m)
{
	std::string buffer;

	std::getline(ifs, buffer, ',');
	m.mName = buffer;
	std::getline(ifs, buffer, ',');
	m.mLevel = std::stoi(buffer);
	std::getline(ifs, buffer, ',');
	m.mHp = std::stoi(buffer);
	std::getline(ifs, buffer);
	m.mMp = std::stoi(buffer);

	return ifs;
}

// {SLIME, 1, 1, 1}
// {WOLF, 5, 5, 5}
// {DEMON, 10, 10, 10}

int main()
{
	//C++ File Management
	//1. File Stream Object
	//2. ������ ����
	//3. ���ų� �б�
	//4. ������ �ݱ�

	//input file stream
	// \: escape sequence
	// ������
	//std::ifstream ifs("C:\\Users\\chj19\\source\\repos\\FileStream\\Data\\SimpleData.txt");
	//����� - ��������(�۾����)�� ������� ��ġ
	//	std::ifstream ifs("Data/SimpleData.txt");
	std::ifstream ifs("./Data/SimpleData.txt");
	if (ifs)
	{
		std::cout << "File Open" << std::endl;
	}
	else
	{
		std::cout << "Filee Not Found" << std::endl;
	}
	
	// ���� �ǳʶٱ�
	std::string buffer;
	std::getline(ifs, buffer);

	//������
	std::vector<Monster> monsters;
	while (ifs && !ifs.eof())
	{
		Monster m;
		ifs >> m;

		monsters.push_back(m);
	}

	ifs.close();
}

//���� ��� ǥ���
// 
// Windows ǥ���
// C:\folde1\file.ext
//	C++ "C:\\folde1\\file.ext"
// 
// Unix ǥ���(Linux, MacOs)
// C:/folde1/file.ext
//	C++ "C:/folde1/file.ext"
// 
// ������ vs �����
// 
// ���������ġ
//	�ɼ�
//	������ ���� ����
//	�ݵ�� ���� ���
// 
//	filestream
//		good()		//
//		eof()		//end of file
//		fail()		//���� ����
//		bad()		//������ ����
// 
// csv ���� ����
// comma seperated values
//
