#include <stdio.h>
#include <assert.h>

const char * IND(const char * str, const char * substr)
{
	assert(substr != NULL && str != NULL);
	const char * psub = substr;
	const char * pstr = str;

	while (*pstr)
	{
		//      if (*pstr != *psub)
		//          continue;

		const char * tmp = pstr;
		while (*tmp++ == *psub++);

		if (*psub == '\0')
			return pstr;

		psub = substr;
		pstr++;
	}

	return NULL;
}

int main()
{
	//char * substr = "hello";
	char * substr = "";
	char * str = "skljdfhellosjdlf";

	const char * res = IND(str, substr);
	if (res != NULL)
		printf("%s\n", res);
	else
		printf("not find\n");

	res = strstr(str, substr);
	if (res != NULL)
		printf("%s\n", res);
	else
		printf("not find\n");

	return 0;
}