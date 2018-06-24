注意：
	请严格按照以下步骤运行！否则会出现问题！
	请务必事先校准字幕文件的时间轴！
	请严格使字幕的文件名为【视频名】.ass，例如ABCD.ass。音频文件为【包括拓展名的视频名】.wav，例如ABCD.mp4.wav。

运行步骤：
	1. 根据视频文件类型情况，选择相应提取音频bat脚本，并运行，得到wav格式音频文件。此后不再需要视频文件，将音频文件单独拉出一个文件夹。
	2. 将 BuildCMD_AnalyzeSRT.exe放入音频文件夹，运行。打开生成的AnalyzeSRT_CMD.txt，删除最上边的两行（即与字幕处理无关的两个命令），保存关闭。
	3. 如有ass字幕，将字幕文件单独组织一个文件夹，打开CMD，输入命令asstosrt。得到srt字幕。注意，请事先确认视频文件与字幕文件“只有”文件类型不同！
	4. 将srt字幕、AnalyzeSRT.exe、AnalyzeSRT_CMD.txt、0.Execute_TXT_CMD.bat一同放到同一个文件夹，运行bat，得到与音频数量相等、名字相同的txt文件。
	5. 将wav音频、上一步生成的众多txt文档、0.Execute_TXT_CMD.bat放在同一文件夹，并在此文件夹中创建output文件夹，运行bat。
	6. 在output文件夹下获得输出文件。
完成