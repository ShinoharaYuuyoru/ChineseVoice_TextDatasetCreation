# ChineseVoice_TextDatasetCreation  
## Introduction  
This is a part of my Graduation Project.  
  
This project aims to set up a Chinese Voice-Text Dataset.  
  
The project uses chinese dramas and their subtitles.  
Cut the sound of dramas by subtitles to get Voice and Text sentences.  
  
In my graduation project, I set up a dataset including 370000 sentences, 300 hours, 100GB dataset.  
I maybe publish this dataset belongs to the condition.  
I whish this project and the dataset will help more reasearchers in Chinese Audio Processing and NLP.  
  
## Programs  
There are 2 C++ programs, 1 Python script, 3 batchfiles, 1 file searching program.  
1. 2 C++ programs  
	* BuildCMD_AnalyzeSRT.exe  
		This program will set up a txt file: AnalyzeSRT_CMD.txt  
		This txt file includes several commands like this:  
			*AnalyzeSRT.exe "01.mp4.wav" "01.srt"*  
		The txt file will be read by 0.Execute_TXT_CMD.bat and execute all the commands.  
	* AnalyzeSRT.exe  
		* srtparser.h  
			Please refer to [srtparser.h](https://github.com/saurabhshri/simple-yet-powerful-srt-subtitle-parser-cpp).  
			Thanks for saurabhshri(Saurabh Shrivastava)'s work!  
		* Main  
			This program will set up several txt files: xx.txt  
			xx is the name of audio. These txt files includes several commands like this:  
				*ffmpeg -y -i "01.mp4.wav" -ss 97.320 -t 1.960 -acodec copy ".\output\在一九九七年.wav"*  
			The project uses [FFmpeg](http://ffmpeg.org/) to separate audio files.  
  
2. 1 Python script  
	* asstosrt  
		Please refer to [asstosrt](https://github.com/sorz/asstosrt).  
		Thanks for sorz(Shell Chen)'s work!  
  
3. 3 batchfiles  
	* 0.Execute_TXT_CMD.bat  
		This batchfile will execute all txt files in the directory, the txt files including several CMD commands.  
	* 1.Separator_xxx_WAV.bat  
		These batch files(for MKV and MP4) will extract audio files from video filess in the directory.  
		Please use corresponding batchfile by the format of video you have.  
		You can also use some other programs like [Format Factory](http://www.pcfreetime.com/).  
	* 2.ReplaceFileName.bat  
		* SpecialCharaList.txt  
			This txt file includes some illegal characters.  
			We can refer to this to clear up dataset finally.  
		* Main  
			This batch will delete a character in a file name, like:  
				*我要吃饭!.wav* -> *我要吃饭.wav*  
  
4. 1 file searching program  
	* Everything  
		Please refer to [Everything](http://www.voidtools.com/).  
		This program will help you search some files including illegal characters to clear up the dataset.  
  
## Execute Steps  
1. Get audio files  
2. Analyze subtitles  
3. Cut audio files  
4. Clear up dataset  
