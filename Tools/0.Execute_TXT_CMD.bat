echo ***** This is a executer which reads commands from text file. *****

for /f %%a in ('dir /O /b *.txt') do (
	for /f "delims=" %%b in (%%a) do (
		%%b
	)
)

pause