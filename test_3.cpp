#include<iostream>
using namespace std;
typedef struct data{
 	char ch;
 	float pro;
 	int value[10];
 	int top;
 }data;
 
void sortByProbability(int n, data p[]) 
{ 
    int i, j; 
    data temp; 
    for (j = 1; j <= n - 1; j++) { 
        for (i = 0; i < n - 1; i++) { 
            if ((p[i].pro) > (p[i + 1].pro)) { 
                temp.pro = p[i].pro; 
                temp.ch = p[i].ch; 
  
                p[i].pro = p[i + 1].pro; 
                p[i].ch = p[i + 1].ch; 
  
                p[i + 1].pro = temp.pro; 
                p[i + 1].ch = temp.ch; 
            } 
        } 
    } 
} 

void shannon(int l, int h, data p[]) 
{ 
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0; 
    int i, d, k, j; 
    //data temp;
    if ((l + 1) == h || l == h || l > h) { 
        if (l == h || l > h) 
            return; 
        p[h].value[++(p[h].top)] = 0; 
        p[l].value[++(p[l].top)] = 1; 
        return; 
    } 
    else { 
        for (i = l; i <= h - 1; i++) 
            pack1 = pack1 + p[i].pro; 
        pack2 = pack2 + p[h].pro; 
        diff1 = pack1 - pack2; 
        if (diff1 < 0) 
            diff1 = diff1 * -1; 
        j = 2; 
        while (j != h - l + 1) { 
            k = h - j; 
            pack1 = pack2 = 0; 
            for (i = l; i <= k; i++) 
                pack1 = pack1 + p[i].pro; 
            for (i = h; i > k; i--) 
                pack2 = pack2 + p[i].pro; 
            diff2 = pack1 - pack2; 
            if (diff2 < 0) 
                diff2 = diff2 * -1; 
            if (diff2 >= diff1) 
                break; 
            diff1 = diff2; 
            j++; 
        } 
        k++; 
        for (i = l; i <= k; i++) 
            p[i].value[++(p[i].top)] = 1; 
        for (i = k + 1; i <= h; i++) 
            p[i].value[++(p[i].top)] = 0; 
  

        shannon(l, k, p); 
        shannon(k + 1, h, p); 
    } 
}  

void display(int n,data p[]){
 	int i, j;
 	cout << "\n\n\n\tSymbol\tProbability\tCode"; 
 	
	for (i = n-1; i > -1; i--) { 
    	cout << "\n\t" << p[i].ch
		 << "\t\t" << p[i].pro << "\t"; 
        for (j = 0; j <= p[i].top; j++) 
            cout << p[i].value[j];              
    } 
    
}


int main(){
	char ch;
	float total=0;
	int n;
	cout<<"enter no. of symbols :";
	cin>>n;
	data temp[n];
	
	for(int i=0;i<n;i++){
		cout<<"enter symbols "<<i+1<<":";
	 	cin>>temp[i].ch;
	}
	for(int i=0;i<n;i++){
		cout<<"enter probability "<<i+1<<":";
		cin>>temp[i].pro;
		
		total = total + temp[i].pro;
		cout<<total <<endl;
		
		if(total > 1){
			cout<< "Incorrect Entries";
			break;
		}
		
	}
	
		sortByProbability(n, temp); 
		//display(n, temp);
		
    	for (int i = 0; i < n; i++) 
        	temp[i].top = -1;
			 
   		printf("\nBefore shanon");
    	shannon(0, n - 1, temp); 
		printf("\nAfter shanon");
		display(n,temp);
	

	return 0;
}
