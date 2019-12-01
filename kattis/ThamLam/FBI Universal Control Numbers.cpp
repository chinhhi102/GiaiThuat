#include <stdio.h>
#include <ctype.h>

int alphaLookup[26] =
{
	10,	//A
	8,	//B = 8
	11,	//C
	12,	//D
	13,	//E
	14, //F
	11, //G = C
	15, // H
	1,  //I = 1
	16, //J
	17, //K
	18, //L
	19, //M
	20, //N
	0,  //O = 0
	21, //P
	0,  //Q = 0
	22, //R
	5,  //S = 5
	23, //T
	24, //U = V
	24, //V
	25, //W
	26, //X
	24, //Y = V
	2	//Z = 2
};

int factors[8] = {2, 4, 5, 7, 8, 10, 11, 13};

int UCNdigits[9];

int parseInput(char *pb, int inprob) 
{
	int i, probnum = 0;
	char c;
	// skip leading spaces
	while(*pb != 0) {
		if(!isspace(*pb))
			break;
		pb++;
	}
	while(*pb != 0) {
		if(!isdigit(*pb))
			break;
		probnum = (probnum*10) + (*pb - '0');
		pb++;
	}
	// skip spaces between probnum and digit string
	while(*pb != 0) {
		if(!isspace(*pb))
			break;
		pb++;
	}
	// parse UCN digits
	for(i = 0; i < 9 ; i++) {
		c = *pb++;
		if((c >= '0') && (c <= '9')) {
			UCNdigits[i] = c - '0';
		} else if((c >= 'A') && (c <= 'Z')) {
			UCNdigits[i] = alphaLookup[c - 'A'];
		}
	}
	return probnum;
}

int checkDigit(){
	int i, ret = 0;
	for(i = 0; i < 8 ; i++) {
		ret += UCNdigits[i]*factors[i];
	}
	ret = (ret % 27);
	return ret;
}

char inbuf[256];
int main()
{
	int i, nprob, curprob, index, ret;
	unsigned long low, high;

	fgets(&(inbuf[0]), 255, stdin);
	sscanf(&(inbuf[0]), "%d", &nprob);
	for(curprob = 1; curprob <= nprob ; curprob++){
		fgets(&(inbuf[0]), 255, stdin);
		index = parseInput(&(inbuf[0]), curprob);
		ret = checkDigit();
		if(ret != UCNdigits[8]) {
			printf("%d Invalid\n", curprob);
		} else {
			high = low = 0;
			for(i = 0; i < 8 ; i++) {
				low = (low *27) + UCNdigits[i];
				high = (high *27) + low/100000000;
				low = low%100000000;
			}
			printf("%d %d%08d\n", curprob, high, low);
		}
	}
	return 0;
}
