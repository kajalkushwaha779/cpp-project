#include<iostream>
using namespace std;
class Timeconv{
	public:
		void secconv(int sec){
			int min,h;
			h=sec/3600;
			cout<<"The hours of "<<sec<<" is:"<<h <<endl;
			min=sec/60;
			cout<<"The minutes of "<<sec<<" is:"<<min <<endl;
		}
		void sec_count( int sec,int h, int min){
			int ans;
			ans=sec+(h*3600)+(min*60);
			cout<<"The total second is:"<<ans <<endl;
	   }
    };
   int main(){
   	 Timeconv t1;
     int choice,sec,min,h;
   	  cout<<"press 1 to convert second into minutes and hours"<<endl;
   	  cout<<"press 2 to convert total second"<<endl;
   	  cout<<"Enter your choice:-";
      cin>>choice;
	 switch(choice){
		case 1:
			cout<<"Enter second to convert:-";
			cin>>sec;
			t1.secconv(sec);
		break;
		case 2:
			cout<<"Enter second to count:";
			cin>>sec;	
			cout<<"Enter minutes to count:";
			cin>>min;
			cout<<"Enter hours to convert:";
			cin>>h;
			t1.sec_count(sec,h,min);
		break;			
	 }
	 return 0;  
    }

    