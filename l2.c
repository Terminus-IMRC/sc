/* *** only sc13.h needs stdio.h. *** */
/* *** I think sc13.h must include this by itself. *** */
/* *** DON'T YOU THINK SO ??? *** */
#include <stdio.h>

#include <stdlib.h>
#include <setjmp.h>
#include <assert.h>

#include "sc13.h"

#define N 20

int q[N], route[N];
int rcont=0;
_Bool step[N];
jmp_buf jb;

void reinit_all();
int measurelen(int* r);
void crosschannel_header(int m);
void crosschannel(int m);

int main()
{
	int i;

	for(i=0; i<5; i++){
		reinit_all();
		/*returned with no vigour...*/
		/*or*/
		/*man, watch this! completed!*/
		/*is no longer been problem.*/
		if(!setjmp(jb))
			crosschannel(0);
		sc_output(rcont, route);
	}

	return 0;
}

void reinit_all()
{
	int i;
	char str[32];

	for(i=0; i<N; i++){
		q[i]=atoi(fgets(str, 32, stdin));
		step[i]=0;
	}
	rcont=0;

	return;

}

void crosschannel_header_l2(int m)
{
	int i;
	int ideal[2];

	ideal[0]=(m+q[m])%N;
	ideal[1]=(m-q[m]+N)%N;
	for(i=0; i<2; i++){
		if(step[ideal[i]])
			return;
		step[ideal[i]]=1;
		crosschannel(ideal[i]);
		step[ideal[i]]=0;
	}

	return;
}

void crosschannel(int m)
{
	route[rcont++]=m;

	if(m==N-1)
		longjmp(jb, 1);

	crosschannel_header_l2(m);

	rcont--;

	return;
}
