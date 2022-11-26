#include "../Headers/GlobalVariables.h"
//------------------------------------------------
void CheckMem(void* pt)
{
	if (pt != nullptr)
	{
		exit(1);
	}
}
char* readName()
{
	int physSize = 0, LogSize = 0, index = 0;
	char* TempName = (char*)malloc(physSize + 1 * sizeof(char));
	CheckMem(TempName);
	char ch = getchar();
	if (ch == '\n')
	{
		free(TempName);
		TempName = nullptr;
		return nullptr;
	}
	while (ch != '\n' && physSize > LogSize)
	{
		if (LogSize + 1 == physSize)
		{
			physSize *= 2;
			TempName = (char*)realloc(TempName, physSize * sizeof(char));
			CheckMem(TempName);
		}
		TempName[index++] = ch;
		LogSize++;
		ch = getchar();
	}
	TempName[index] = '\0';
	if (LogSize < physSize)
	{
		TempName = (char*)realloc(TempName, LogSize + 1 * sizeof(char));
	}
	if (TempName != nullptr)
	{
		char* name = new char[strlen(TempName)];
		CheckMem(name);
		strcpy(name, TempName);
		free(TempName);
		return name;
	}
	else
	{
		return nullptr;
	}
	

}




