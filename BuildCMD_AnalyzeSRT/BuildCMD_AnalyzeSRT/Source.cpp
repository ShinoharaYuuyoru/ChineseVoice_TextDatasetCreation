//���빦�ܣ���ȡָ���ļ�������ļ�����д�뵽�ı��ļ���  
//---------------- - ������������ͷ�ļ���------------------ -
#include<io.h>           //��ȡ�ļ���Ҫ������ͷ�ļ�   
#include<iostream>  
#include<stdlib.h>  
#include<vector>  
#include<fstream>  
#include<string>
//---------------------------------------------------------  

//---------------��������ʹ�õ������ռ䡿--------------  
using namespace std;
//---------------------------------------------------------  

//---------------------��ȫ�ֺ���������-----------------  
void GetFileName(string path, vector<string>& files);
//--------------------------------------------------------  

//--------------------��main()������--------------------  
int main()
{
	char *path = "./";                         //ָ���ļ�Ŀ¼
	vector<string> filesName;
	ofstream file_out("AnalyzeSRT_CMD.txt");                //���ı��ļ�
	GetFileName(path, filesName);                   //��ȡ�ļ���

	string fileName;
	int fileNameLength;

	for (size_t i = 0; i<filesName.size(); i++)            //���ļ���д�뵽�ı���  
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
	file_out.close();     //�ر��ı��ļ�  

	return 0;
}

void GetFileName(string path, vector<string>& filesName)
{

	long   hFile = 0;                    //�ļ����   
	struct _finddata_t fileinfo;        //�����ļ���Ϣ�ṹ��  
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) //ʹ�ú���_findfirst()���ļ�����ȡ��һ���ļ���  
	{
		do
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //"."��ʾ��ǰĿ¼��".."��ʾ��Ŀ¼  
				filesName.push_back(fileinfo.name);
		} while (_findnext(hFile, &fileinfo) == 0);      //ʹ�ú���_findnext()������ȡ�����ļ���  
		_findclose(hFile);              //ʹ�ú���_findclose()�ر��ļ���  
	}
}