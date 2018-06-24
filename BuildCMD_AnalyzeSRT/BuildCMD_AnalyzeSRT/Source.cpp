//代码功能：获取指定文件夹里的文件名并写入到文本文件中  
//---------------- - 【程序所依赖头文件】------------------ -
#include<io.h>           //读取文件名要包含的头文件   
#include<iostream>  
#include<stdlib.h>  
#include<vector>  
#include<fstream>  
#include<string>
//---------------------------------------------------------  

//---------------【程序所使用的命名空间】--------------  
using namespace std;
//---------------------------------------------------------  

//---------------------【全局函数声明】-----------------  
void GetFileName(string path, vector<string>& files);
//--------------------------------------------------------  

//--------------------【main()函数】--------------------  
int main()
{
	char *path = "./";                         //指定文件目录
	vector<string> filesName;
	ofstream file_out("AnalyzeSRT_CMD.txt");                //打开文本文件
	GetFileName(path, filesName);                   //获取文件名

	string fileName;
	int fileNameLength;

	for (size_t i = 0; i<filesName.size(); i++)            //将文件名写入到文本中  
	{
		fileName = filesName[i];
		fileNameLength = fileName.length();


		file_out << "AnalyzeSRT.exe ";
		file_out << "\"" << fileName << "\"" << " ";
		fileName[fileNameLength - 7] = 's';
		fileName[fileNameLength - 6] = 'r';
		fileName[fileNameLength - 5] = 't';
		file_out << "\"" << fileName.substr(0, fileNameLength - 4) << "\"" << endl;
	}
	file_out.close();     //关闭文本文件  

	return 0;
}

void GetFileName(string path, vector<string>& filesName)
{

	long   hFile = 0;                    //文件句柄   
	struct _finddata_t fileinfo;        //定义文件信息结构体  
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) //使用函数_findfirst()打开文件并获取第一个文件名  
	{
		do
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //"."表示当前目录，".."表示父目录  
				filesName.push_back(fileinfo.name);
		} while (_findnext(hFile, &fileinfo) == 0);      //使用函数_findnext()继续获取其他文件名  
		_findclose(hFile);              //使用函数_findclose()关闭文件夹  
	}
}