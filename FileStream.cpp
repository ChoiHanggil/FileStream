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
	//2. 파일을 열기
	//3. 쓰거나 읽기
	//4. 파일을 닫기

	//input file stream
	// \: escape sequence
	// 절대경로
	//std::ifstream ifs("C:\\Users\\chj19\\source\\repos\\FileStream\\Data\\SimpleData.txt");
	//상대경로 - 실행파일(작업경로)에 상대적인 위치
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
	
	// 제목 건너뛰기
	std::string buffer;
	std::getline(ifs, buffer);

	//데이터
	std::vector<Monster> monsters;
	while (ifs && !ifs.eof())
	{
		Monster m;
		ifs >> m;

		monsters.push_back(m);
	}

	ifs.close();
}

//파일 경로 표기법
// 
// Windows 표기법
// C:\folde1\file.ext
//	C++ "C:\\folde1\\file.ext"
// 
// Unix 표기법(Linux, MacOs)
// C:/folde1/file.ext
//	C++ "C:/folde1/file.ext"
// 
// 절대경로 vs 상대경로
// 
// 보조기억장치
//	옵션
//	문제가 많이 생김
//	반드시 예외 고려
// 
//	filestream
//		good()		//
//		eof()		//end of file
//		fail()		//논리적 오류
//		bad()		//물리적 오류
// 
// csv 파일 포멧
// comma seperated values
//
