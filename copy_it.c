#define BUFFERSIZE 25
#define TRUE 1
#define FALSE 0

int copy_it(char *input)
{
	char lbuf[BUFFERSIZE]="";
	char c, *p = input, *d = &lbuf[0];
	char *ulimit = &lbuf[BUFFERSIZE-10];
	int quotation = FALSE;
	int rquote = FALSE;
	
	while((c = *p++) != '\0')
	{
		if ((c == '<') && (!quotation))
		{
			quotation = TRUE;
			ulimit--;
		}
		if ((c == '>') && (quotation))
		{
			quotation = FALSE;
			ulimit++;
		}
		if (c == '(' && !quotation && !rquote)
		{
			rquote = TRUE;
			// FIX: insert ulimit--; here
		}
		if (c == ')' && !quotation && rquote)
		{
			rquote = FALSE;
			ulimit++;
		}
		if (d < ulimit)
			*d++ = c;
	}
	if (rquote)
		*d++ = ')';
	if (quotation)
		*d++ = '>';
    
    return rquote;
}
	

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;

	return copy_it(argv[1]);
}
