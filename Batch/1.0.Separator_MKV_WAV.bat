echo ***** This is a MKV Audio Separator. *****

FOR /F %%a IN ('dir /O /b *.mkv') do ffmpeg -i "%%a" -vn "%%~nxa.wav"

pause