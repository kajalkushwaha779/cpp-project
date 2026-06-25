#include <iostream>
using namespace std;

class Train{
  private:
    string trainName;
    string source;
    string destination;
    string trainTime;
  public:
	//static variable
    int trainNumber;
	static int traincount;
	//default constructer
	Train(){
	}
	//parameterized constructer
     Train(int Number, string Name,string source,string destination,string Time){
     	this->trainNumber=Number;
     	this->trainName=Name;
     	this->source=source;
     	this->destination=destination;
        this->trainTime=Time;
	 }
	 
	 //setter function
	 void inputTrainDetails(){
	 	cout<<"\nEnter Train number :";
    		cin>>trainNumber;
    		cout<< endl<<"Enter Train name :";
    		cin>>trainName;	
			cout<< endl<<"Enter Train source :";
    		cin>>source;
    		cout<< endl<<"Enter Train destination :";
    		cin>>destination;
    		cout<< endl<<"Enter Train time :";
    		cin>>trainTime;
    		traincount++;
	 }
	 //getter function
	 void displayTrainDetails(){
	 	cout<<"\ntrain number :"<<trainNumber<<endl;
	    cout<<"train name :"<<trainName<<endl;
		cout<<"train source :"<<source<<endl;
		cout<<"train destination :"<<destination<<endl;
		cout<<"train time :"<<trainTime<<endl;
	 	cout<<"--------------------------"<<endl;
	 }
	  // Static Function
    static void getTrainCount(){
        cout << "\nTotal Trains = " << traincount << endl;
    }
	//destructor
	 ~Train(){
		traincount--;
	 }
	  };
 int Train::traincount=0;
	class RailwaySystem{
		private:
			Train trains[25];
			int indextrains=0;
		public:
			void addTrain(){
				trains[indextrains].inputTrainDetails();
				indextrains++;
				cout<<"\nTrain added successfully\n";
			}
		    void displayAllTrains(){
              cout << "\n===== TRAIN DETAILS =====\n";
				for(int i=0;i<indextrains;i++){
					trains[i].displayTrainDetails();
				}
			}
			void searchTrainBYNumber(int num){
				for(int i=0;i<indextrains;i++){
					if(trains[i].trainNumber==num){
					trains[i].displayTrainDetails();
					}
				}
			}
	};
  int main(){
    int choice;
    RailwaySystem irctc;
    do{
        cout << "\n========================";
        cout << "\n Railway Reservation System";
        cout << "\n========================";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train By Number";
        cout << "\n4. Show Train Count";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            irctc.addTrain();
            break;
        case 2:
            irctc.displayAllTrains();
            break;
        case 3:
            int trainnumber;
            cout << "\nEnter Train Number to Search: ";
            cin >> trainnumber;
            irctc.searchTrainBYNumber(trainnumber);
            break;
        case 4:
            Train::getTrainCount();
            break;
        case 5:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }
    } while (choice != 5);
  return 0;
}
