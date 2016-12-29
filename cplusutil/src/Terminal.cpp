#include "Terminal.h"

void cplusutil::Terminal::showProgress(std::string label, int step, int _total)
{
	printf("\r");
	int tmptotal = _total;
	if (tmptotal == 0)
	{
		tmptotal = 1;
	}

	//progress width
	const int pwidth = 72;

	//minus label len
	int width = pwidth - label.length();
	int pos = (step * width) / tmptotal;


	int percent = (step * 100) / tmptotal;


	printf("%s[", label.c_str());

	//fill progress bar with =
	for (int i = 0; i < pos; i++)  printf("%c", '=');

	//fill progress bar with spaces
	printf("% *c", width - pos + 1, ']');
	printf(" %3d%%\r", percent);
}