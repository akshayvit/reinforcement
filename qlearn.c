#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define e 0.2
#define alpha 0.8
#define gama 0.8
#define states 6
#define actions 4

double qtable[states][actions];

double reward(int state,int action)
{
	return abs(state-action);
}

int explore()
{
	return rand()%actions;
}


double q_value(double q0,double max,int state,int action)
{
	return q0+alpha*(reward(state,action)+gama*(max)-q0);
}

int exploit(double action[])
{
	int i,ind;
	double max=-INT_MAX;
	for(i=0;i<actions;++i){
		if(action[i]>max)
		{
			max=action[i];
			ind=i;
		}
	}
	return ind;
}

main()
{
	int i,j;
	double max=0;
	for(i=0;i<states;i++)

	{
		for(j=0;j<actions;j++)
		{
			qtable[i][j]=0;
		}
	}
	for(i=0;i<states;i++)
	{
		if(rand()%1<e)
			j=explore();
		else
			j=exploit(qtable[i]);
		qtable[i][j]=q_value(qtable[i][j],max,i,j);
		if(qtable[i][j]>max)
			max=qtable[i][j];
	}
	for(i=0;i<states;i++)
	{
		for(j=0;j<actions;j++)
		{
			printf("%lf ",qtable[i][j]);
		}
		printf("\n");
	}
}   
