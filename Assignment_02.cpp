//take countX and countY from user
//p(x)i = [] take from user i=0 to countX
//p(y/x) take from user
//form the matrix using p(xy)

#include<iostream>
using namespace std;


int main()
{
	int cx,cy;
	cout<<"Enter number of transmitted messages : ";
	cin>>cx;
	
	cout<<"Enter number of received messages : ";
	cin>>cy;
	
	int i,j;
		cout<<"Enter probabilities of transmitted messages : ";
	double px[cx];//initialize prob array for transmitted messages
	for(i=0;i<cx;i++)
	cin>>px[i];
	
	cout<<"Enter the p(y/x) matrix : ";
	double pyx[cx][cy];//initialize prob array for received messages
	for(i=0;i<cx;i++)
		for(j=0;j<cy;j++)
			cin>>pyx[i][j];
			
	//p(xy) = p(x)d * p(y/x)	
		
	double pxd[cx][cx];//initialize pxd matrix
	for(i=0;i<cx;i++)
		for(j=0;j<cx;j++)
			if(i==j)
				pxd[i][j]=px[i];
			else pxd[i][j]=0;
	//display
	cout<<"Diagonal matrix of p(x) : \n";
	for( i=0;i<cx;i++)
		{
			for(j=0;j<cx;j++)
			cout<<pxd[i][j]<<"\t";
			
			cout<<"\n";
		}	
		
	//multiply p(y/x) anf p(x)d to get p(x,y)
	double pxy[cx][cy];
		
	return 0;
}
