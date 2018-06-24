#include <iostream>
#include <tchar.h>
#include <iomanip>
#include <Windows.h>
#include "lib/srtparser.h"

using namespace std;

char* U2G(const char* utf8);

//unsigned int Counter = 0;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "ERROR!" << endl;
		cout << "Please pass the filename as an argument: audioname.wav subtitlename.srt\n" << endl;

		return 1;
	}

	string audioName;
	audioName = argv[1];

	SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(argv[2]);
	SubtitleParser *parser = subParserFactory->getParser();

	std::vector<SubtitleItem*> sub = parser->getSubtitles();

	string outputName;
	int nameLength;
	outputName = argv[2];
	nameLength = outputName.length();
	outputName[nameLength - 3] = 't';
	outputName[nameLength - 2] = 'x';
	outputName[nameLength - 1] = 't';

	ofstream myfile;
	myfile.open(outputName);

	long int lInt_startTime;
	long int lInt_endTime;
	long int lInt_durationTime;
	double startTime;
	double endTime;
	double durationTime;

	string processText;
	char* outputText;

	//Counter = 1;

	for (SubtitleItem * element : sub)
	{
		//myfile << "BEGIN" << endl;
		//myfile << "startString : " << element->getStartTimeString() << endl;
		//myfile << "start : " << element->getStartTime() << endl;
		//myfile << "endString : " << element->getEndTimeString() << endl;
		//myfile << "end : " << element->getEndTime() << endl;
		//myfile << "text : " << element->getText() << endl;

		//myfile << "justDialogue : " << element->getDialogue() << endl;
		//myfile << "words count : " << element->getWordCount() << endl;
		//myfile << "words :";
		//std::vector<std::wstring> word = element->getIndividualWords();
		//for (std::wstring display : word)
		//	myfile << display << ", ";
		//myfile << endl;

		//myfile << "speakerCount : " << element->getSpeakerCount() << endl;
		//myfile << "speakers : ";
		//if (element->getSpeakerCount())
		//{
		//	std::vector<std::wstring> name = element->getSpeakerNames();
		//	for (std::wstring display : name)
		//		myfile << display << ", ";
		//	myfile << endl;
		//}

		//myfile << "ignore : " << element->getIgnoreStatus() << endl;

		// Get sec.ms time.
		lInt_startTime = element->getStartTime();
		lInt_endTime = element->getEndTime();
		lInt_durationTime = element->getEndTime() - element->getStartTime();
		startTime = (int)(lInt_startTime / 1000) + (lInt_startTime % 1000) / 1000.0 - 0.5;
		endTime = (int)(lInt_endTime / 1000) + (lInt_endTime % 1000) / 1000.0;
		durationTime = (int)(lInt_durationTime / 1000) + (lInt_durationTime % 1000) / 1000.0 + 1.0;

		myfile << "ffmpeg -y -i ";
		myfile << "\"" << audioName << "\"" << " ";
		myfile << "-ss ";
		myfile << setiosflags(ios::fixed) << setprecision(3) << startTime << " ";
		myfile << "-t ";
		myfile << setiosflags(ios::fixed) << setprecision(3) << durationTime << " ";
		myfile << "-acodec copy ";

		processText = element->getText();

		// Remove invalid characters, include '!', '.', ' ' and so on.
		processText.erase(remove(processText.begin(), processText.end(), '\\'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '/'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), ':'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '*'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '?'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '"'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '<'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '>'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '|'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), '!'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), ','), processText.end());

		//processText.erase(remove(processText.begin(), processText.end(), '¡¢'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '£º'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '£¿'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '¡°'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '¡±'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '¡¶'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '¡·'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '|'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '£¡'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '£¬'), processText.end());
		//processText.erase(remove(processText.begin(), processText.end(), '¡£'), processText.end());

		processText.erase(remove(processText.begin(), processText.end(), '.'), processText.end());
		processText.erase(remove(processText.begin(), processText.end(), ' '), processText.end());

		int pos = 0;
		pos = processText.find("br");
		while (pos != -1)
		{
			processText.erase(pos, 2);
			pos = processText.find("br");
		}

		outputText = U2G(processText.c_str());

		myfile << "\"" << ".\\output\\" << outputText << ".wav\"" << endl;

		//myfile << "END" << endl << endl;
		
		//Counter++;
	}

	myfile.close();

	return 0;
}

char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}