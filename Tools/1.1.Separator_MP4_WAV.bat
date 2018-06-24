echo ***** This is a MP4 Audio Separator. *****

FOR /F %%a IN ('dir /O /b *.mp4') do ffmpeg -i "%%a" -vn "%%~nxa.wav"

pause