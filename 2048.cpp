#include<bits/stdc++.h>
#include<conio.h>


using namespace std;

void display(int a[4][4])
{
	cout<<"\n\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	 int gamescore = 0; 
  
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            if (a[i][j] > gamescore) { 
                gamescore = a[i][j]; 
            } 
        } 
    } 
  
    cout<<"\t\t\t\t\t\t\t\n\t\t\t\t\t\t\tYOUR SCORE="<<gamescore<<endl;
	
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t------------------\n";
}

int checkEmpty(int a[4][4])
{
	int l=0,k=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			l=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			k=1;
    			break;
			}
			
	if(l || k) return 1;
	else return 0;
}
int check(int b[4][4],int a[4][4])
{
	int k=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(b[i][j]!=a[i][j])
    		{
    			k=0;
    			break;
			}
	return k;
}
void addNumber(int a[4][4])
{
	int l,k;
	srand(time(0));
	while(1)
	{
		l=rand()%4;
		k=rand()%4;
		if(a[l][k]==0)
		{
			a[l][k]=pow(2,l%2 + 1);
			break;
		}
	}

}

void upmove(int a[4][4])
{
int i,j;
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            for(int k=i+1;k<4;k++)
            {
            	if(a[k][j]==0)
            		continue;
            	else if(a[k][j]==a[i][j])
            		{
            		a[i][j]*=2;
            		a[k][j]=0;
            		}
					else break;
			}	
        }
    }
    

        
    
     for(j=0;j<4;j++)
    {	int count=0;
    	int temp[4];
        for(i=0;i<4;i++)
        {
            	if(a[i][j]!=0)
            	{
            		temp[count]=a[i][j];
            		count++;
            	}
        
        }

        for(i=0;i<count;i++)
        {
            	a[i][j]=temp[i];
            	
        }
        for(i=count;i<4;i++)
        {
        a[i][j]=0;
        }
    }
}


void downmove(int a[4][4])
{
    int i,j;
    for(j=0;j<4;j++)
    {
        for(i=3;i>=0;i--)
        {
            for(int k=i-1;k>=0;k--)
            {
            	if(a[k][j]==0)
            		continue;
            	else if(a[k][j]==a[i][j])
            		{
            		a[i][j]*=2;
            		a[k][j]=0;
            		}
            	else
            	break;
            	
        }
    }
    }

        
    
     for(j=0;j<4;j++)
    {	int count=0;
    	int temp[4];
        for(i=3;i>=0;i--)
        {
            	if(a[i][j]!=0)
            	{
            		temp[count]=a[i][j];
            		count++;
            	}
        
        }

        for(i=0;i<count;i++)
        {
            	a[3-i][j]=temp[i];
            	
        }
        for(i=count;i<4;i++)
        {
        a[3-i][j]=0;
        }
    }
}


void rightmove(int a[4][4])
{
	 int i,j;
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
            	if(a[i][k]==0)
            		continue;
            	else if(a[i][k]==a[i][j])
            		{
            		a[i][j]*=2;
            		a[i][k]=0;
            		}
            	else
            	break;
            	
        }
    }
    }

        
    
     for(i=0;i<4;i++)
    {	int count=0;
    	int temp[4];
        for(j=3;j>=0;j--)
        {
            	if(a[i][j]!=0)
            	{
            		temp[count]=a[i][j];
            		count++;
            	}
        
        }

        for(j=0;j<count;j++)
        {
            	a[i][3-j]=temp[j];
            	
        }
        for(j=count;j<4;j++)
        {
        a[i][3-j]=0;
        }
    }
}



void leftmove(int a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            for(int k=j+1;k<4;k++)
            {
            	if(a[i][k]==0)
            		continue;
            	else if(a[i][k]==a[i][j])
            		{
            		a[i][j]*=2;
            		a[i][k]=0;
            		}
            	else
            	break;
            	
        }
    }
    }

        
    
     for(i=0;i<4;i++)
    {	int count=0;
    	int temp[4];
        for(j=0;j<4;j++)
        {
            	if(a[i][j]!=0)
            	{
            		temp[count]=a[i][j];
            		count++;
            	}
        
        }

        for(j=0;j<count;j++)
        {
            	a[i][j]=temp[j];
            	
        }
        for(j=count;j<4;j++)
        {
        a[i][j]=0;
        }
    }
}




  




int main()
{
	cout<<"\t\t\n\n\t\tWELCOME TO THE GAME 2048\n";
	cout<<"\n\n\n\n\t\t\n\n\t\tPress ENTER to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int a[4][4]={0},b[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=4;
	display(a);
	
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			b[i][j]=a[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) upmove(a);
    	if(ch==80) downmove(a);
    	if(ch==75) leftmove(a);
    	if(ch==77) rightmove(a);
		if(ch==27) break;
		
		
		if(!check(b,a))
			addNumber(a);
		display(a);
			
		if(!checkEmpty(a))
		{
			cout<<"|n\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}	
	}
	return 0;
}
