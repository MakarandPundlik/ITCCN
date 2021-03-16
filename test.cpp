#include<iostream>
using namespace std;
//create Node to hold values
class Node{
	public:
	char symbol;
	float prob;
	string code;
	
};

void sortArray(Node *p,int n);
int main()
{
	int n,i;
	
	cout<<"Enter How Many Symbols do You Want to Enter : ";
	cin>>n;
	Node *p=new Node[n];
	for(i=0;i<n;i++){
		cout<<"Enter Symbol "<<i+1<<" ---> ";
		cin>>p[i].symbol;
	}
	scan_prob:
	i=0;
	while(i<n){
		cout<<"Enter probability of "<<p[i].symbol<<" ---> ";
		cin>>p[i].prob;
		p[i].code="";
		i++;
	}
	
	//sum of all probs
	i=0;
	float sum=0;
	while(i<n)
	{
		sum=sum+p[i].prob;
		i++;
	}
	
	//validation of probabilities
	if(sum!=1){
		cout<<"Re-enter the probabilities as addition is not 1 \n";
		goto scan_prob;
	}
	//sort array in decreasing order of their probabilities
	sortArray(p,n);
	
	//initializa left and right sum
	float sum_left=0,sum_right=0;
	
	for(i=0;i<n-1;i++)
	{
		sum_left=p[i].prob;
		sum_right+=p[i+1].prob;
		
		//assign codes
		if(sum_left>=sum_right)
		{
			p[i].code+="0";
			for(int j=i+1;j<n;j++)
			p[j].code+="1";
		}
	}
	
	//print codes
	i=0;
	cout<<"Symbol\tProb\tcode \n";
	while(i<n){
		cout<<p[i].symbol<<"\t"<<p[i].prob<<"\t"<<p[i].code<<endl;
		i++;
	}
	
return 0;
}
//user defined sort
void sortArray(Node *p,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].prob<p[j+1].prob){
				Node q= p[j];
				p[j]=p[j+1];
				p[j+1]=q;
			}
		}
	}
}

