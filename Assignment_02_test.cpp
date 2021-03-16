#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j=0,n,k;
	float yx[10][10],s[10],hx,hy,hxy,x[10][10],xy[10][10],y[10];
	cout<<"Enter number of inputs: ";
	cin>>n;
	cout<<"Enter probabilities of source signals:";
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cout<<"Enter probabilities of"<<endl;
	for(i=0;i<n;i++)
	{
		if(j<3)
		cout<<"x"<<i+1<<"y"<<j+1<<endl;
		if(j>=3)
		cout<<"x"<<i+1<<"y"<<j-i<<endl;
		for(j=0;j<n;j++)
		{
			cin>>yx[i][j];
			
		}	
	}
	cout<<" P(Y/X):\n"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<yx[i][j];
			
			}
		cout<<"\n";	
	}
	cout<<"\n";
		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			x[i][j]=s[i];
			else
			x[i][j]=0;
			}

	}
	cout<<" P(X)d:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<x[i][j];
			
			}
		cout<<"\n";	
	}
	cout<<"\n";
	for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            xy[i][j] = 0;
            for (k = 0; k < n; k++)
            {
			
                xy[i][j] += x[i][k] * yx[k][j];
        	}
    	}
	}
cout<<" P(X,Y):\n";
for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<xy[i][j];
			
			}
		cout<<"\n";	
	}
	cout<<"\n";
for(i=0;i<n;i++)
{

	y[i]=0;
	for(j=0;j<n;j++)
	{
		y[i] += xy[j][i];
	}
		cout<<" P(Y"<<i+1<<") : "<<y[i]<<"\t";
}
	cout<<"\n";
for(i=0;i<n;i++)
{
 hx += (s[i]*(log2(s[i])))*(-1);//source entropy
	}	

for(i=0;i<n;i++)
{
 hy += (y[i]*(log2(y[i])))*(-1);
	}	

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
 hxy += (xy[i][j]*(log2(xy[i][j])))*(-1);//joint entropy
	}	
	
}
cout<<"\n\n";
cout<<"H(x): "<<hx<<"\n\n";
cout<<"H(y): "<<hy<<"\n\n";
cout<<"H(X,Y): "<<hxy<<"\n\n";
cout<<"H(Y/X): "<<(hxy-hx)<<"\n\n";
cout<<"H(X/Y): "<<(hxy-hy)<<"\n\n";
cout<<"I(X,Y)= "<<(hx+hy-hxy)<<endl;

	if(hx==hxy && hy==hxy)
	cout<<"\n It is a Noiseless Channel"<<endl;
	
	 if(hy==hxy && hxy!=hx)
	cout<<"\n It is a Lossless Channel"<<endl;
	
	 if (hx==hxy && hxy!=hy)
	cout<<"\n It is a Deterministic Channel"<<endl;

	if(hx==(hxy-hx) || hy==hxy) 
	cout<<"\n It is a Useless Channel"<<endl;	
}
/*#include<bits/stdc++.h>
using namespace std;

int main(){
	int r,c;
	cout<<"enter no. of rows ";
	cin>>r;
	cout<<"enter no. of columns ";
	cin>>c;
	float a[r][c],b[r];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	
	cout<<"enter input probabilities ";
	for(int i=0;i<r;i++){
		cin>>b[i];
	}
	cout<<"The input probabilities are : ";
	for(int i=0;i<r;i++){
		cout<<b[i]<<" ";
	}
	cout<<"\nChannel Matrix is:     ";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl<<"                       " ;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j]=a[i][j]*b[i];
		}
	}
	
	cout<<endl;
	cout<<"Joint Probability Matrix is: ";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<< a[i][j]<<" ";
		}
		cout<<endl<<"                             " ;
	}
	float s_entropy=0;
	for(int i=0;i<r;i++){
		s_entropy = s_entropy + ((-b[i]*log2(b[i])));
	}
	cout<<endl<<"-------------------------------\n\nsource entropy is :"<<s_entropy<<"bits/msg"<<endl;
	
	float j_entropy=0;
		for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]==0){
				j_entropy = j_entropy + 0;
			}
			else{
			j_entropy = j_entropy + ((-a[i][j]*log2(a[i][j])));
		}
		}
	}
	cout<<"joint entropy is  :"<<j_entropy<<"bits/msg"<<endl;
	float o_entropy=0;
	float sum=0,sum1=0;
	for(int j=0;j<c;j++){
	float k=0;
	for(int i=0;i<r;i++){
		k =	k + a[i][j];
	}	
	sum = sum + k;
}
for(int j=0;j<c;j++){
	float k=0;
	for(int i=0;i<r;i++){
		k =	k + a[i][j];
	}	
	o_entropy = o_entropy + ((-k*log2(k)));
	sum1 = sum1 + k;
	
}
cout<<"\noutput entropy is :"<<o_entropy<<"bits/msg"<<endl;
float Hxy = j_entropy - o_entropy;
float Hyx = j_entropy - s_entropy;
cout<<"H(x/y) is :"<<Hxy <<"   H(y/x) is:"<<Hyx<<endl;
float c1= log2(r);
float c2= log2(c);
if(j_entropy==s_entropy && j_entropy==o_entropy){
	cout<<"\n It is a Noiseless Channel"<<endl;
	cout<<"Mutual information is :"<<s_entropy<<"bits/msg"<<endl;
	cout<<"Channel Capacity is   :"<<c1<<"bits/channel use "<<endl;
}
else if(o_entropy==j_entropy && Hxy==0 && Hyx!=0){
	cout<<"It is a Lossless Channel"<<endl;
	cout<<"Mutual information is :"<<s_entropy<<"bits/msg"<<endl;
	cout<<"Channel Capacity is   :"<<c1<<"bits/channel use "<<endl;
}
else if(j_entropy==s_entropy && Hxy!=0 && Hyx==0){
	cout<<"It is a Deterministic Channel"<<endl;
	cout<<"Mutual information is :"<<o_entropy<<"bits/msg"<<endl;
	cout<<"Channel Capacity is   :"<<c2<<"bits/channel use "<<endl;
}
else if(sum==1 && sum1==1 && r==2 && c==2){
	cout<<"It is a binary symmetric Channel"<<endl;
	cout<<"Mutual information is :"<<o_entropy - s_entropy<<"bits/msg"<<endl;
	cout<<"Channel Capacity is   :"<<1-s_entropy<<"bits/channel use "<<endl;
}
else if(Hxy!=0 && Hyx!=0){
	cout<<"It is a Useless Channel"<<endl;
	cout<<"Mutual information is :"<<"0"<<"bits/msg"<<endl;
	cout<<"Channel Capacity is   :"<<"0"<<"bits/channel use "<<endl;
}



}*/
