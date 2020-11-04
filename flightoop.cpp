#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<string.h>
#include <sstream>

using namespace std;


struct f_seat{
		string f_row;
		string f_cls;
		string f_seats;
		
	};
	
class flight{
	
	string f_number;
	string date_time;
	string dep_airport;
	string arr_airport;
	struct f_seat seat[60];
	int classB;
	int classE;
	
	public:
	void setF_number(string x){
		f_number=x;
	}
	
	void setDate_time(string y){
		date_time=y;
	}
	
	void setDep_airport(string z){
		dep_airport=z;
	}
	
	void setArr_airport(string p){
		arr_airport=p;
	}
	
	void setClassB(int classB){
		this->classB = classB;
	}
	
	int getClassB(){
		return classB;
	}
	
	int getClassE(){
		return classE;
	}
	
	void setClassE(int classE){
		this->classE = classE;
	}
	
	void setSeatData(string a,string b,string c, int y){
		seat[y].f_row = a;
		seat[y].f_cls = b;
		seat[y].f_seats = c;
	}
	
	string getRow(int j){
		return seat[j].f_row;
	}
	
	string getClass(int j){
		return seat[j].f_cls;
	}
	
	string getSeatName(int j){
		return seat[j].f_seats;
	}
	
	string getF_number(){
		return f_number;
	}
	string getData_time(){
		return date_time;
	}
	string getDep_airport(){
		return dep_airport;
	}
	string getArr_airport(){
		return arr_airport;
	}
	void display_flight();
	
	void display_flight_seats(int x);
	
};


void flight::display_flight(){
	cout<<endl<< " Flight Number : "<<f_number<<endl;
	cout<<" Date And Time : "<<date_time<<endl;
	cout<<" Departure Airport : "<<dep_airport<<endl;
	cout<<" Arrival Airport : "<<arr_airport<<endl;
	cout <<" Bussiness Class : "<<classB <<endl;
	cout <<" Ecconomic Class : "<<classE << endl;
}

void flight::display_flight_seats(int i){
	cout<<" "<<seat[i].f_row << " ";
	cout<<" "<<seat[i].f_cls << " ";
	cout<<" "<<seat[i].f_seats<<endl;;
}
	

int main(){
	
	int i=0,j=0;
	ifstream file;
	int count=0;
	file.open("flights.txt");
	
	
	if(!file.is_open()){
		cout<<"Error while open\n"<<endl;
	}else{
		string line;
		while(!file.eof()){
			getline(file,line);
		//cout<<line.size();
		//	break;
			if(line.empty()){
				count++;
			}
		}
		file.close();
		//cout<<count;
	}
	flight f_array[count];
	
	int lCount = 0, SeatLineCounter = 0, objCounter = 0;
	int classE = 0, classB = 0;
	int colSeatsNum;
	string line;
    ifstream file1("flights.txt");
    
        if(file1.is_open()){
        while(getline(file1, line)){

            if(line != "\0"){
                ++lCount;

                if(lCount == 1)
                f_array[objCounter].setF_number(line); 
                else if(lCount == 2)
                f_array[objCounter].setDate_time(line);
                else if(lCount == 3)
                f_array[objCounter].setDep_airport(line);
                else if(lCount == 4)
                f_array[objCounter].setArr_airport(line);
                else{
                istringstream xxx(line);
                string row, sclass, number;
                xxx >> row >> sclass >> number;
                colSeatsNum=number.size();
                if(line != "\0"){
                    f_array[objCounter].setSeatData(row, sclass, number, SeatLineCounter);
                    ++SeatLineCounter;
                }
                if(sclass=="E"){
                	classE+=colSeatsNum;
				}else{
					classB+=colSeatsNum;
				}
				f_array[objCounter].setClassE(classE);
				//count << f_array[objCounter].getClassE()<<endl;
				f_array[objCounter].setClassB(classB);
                }
            } 
            else{
                ++objCounter;
                lCount = 0;
                SeatLineCounter = 0;
                classE=0,classB=0;
                
            }           
        }

        file1.close();
    }
	

	char ss;
	while(ss!='5'){
		cout<<endl;
		cout<<"//////////////// Virgin Airline //////////////////////"<<endl;
		cout<<endl;
		cout<<"		1.Display available flights"<<endl;
		cout<<"		2.View flight"<<endl;
		cout<<"		3.Seat availability"<<endl;
		cout<<"		4.Seat booking"<<endl;
		cout<<"		5.Exit"<<endl;
		cout<<endl;
		cout<<"//////////////////////////////////////////////////////"<<endl;
		cout<<endl;
	

		cout<<" Enter an option :";
		cin>>ss;
		
		switch(ss){
		case '1':
			for(int i=0; i < count; i++){
				if(f_array[i].getF_number() != "\0")
				f_array[i].display_flight();	
			}
			
			break;
		case '2':{
			string f_num;
			int count1=0;
			cout<<endl<<" Enter the flight number : ";
			cin>>f_num;
		
			for(int i=0; i < count; i++){
				if(f_array[i].getF_number() == f_num){
					count1++;
					f_array[i].display_flight();
					cout<<endl<<"--Seats Availability--"<<endl;
					for(int j=0;f_array[i].getRow(j).empty()!=1; j++){
						f_array[i].display_flight_seats(j);
					}
				}
			}
			if(count1!=1)
					cout<<endl<<" Requested flight is not present!!!"<<endl;
			break;
		}
		case '3':{
		string f_num;
			int numberOfSeats;
		
			int count1=0;
			int count4=0;
			int z,a;
			cout<<endl<<" Enter the flight number : ";
			cin>>f_num;
			for(z=0 ; z < count ; z++){
				if(f_array[z].getF_number() == f_num){
					a=1;
					break;
				}
			}
				
			if(a==1){
				cout <<endl<<" Enter The Numbre Of Seats That You Need : ";
				cin >> numberOfSeats;
				
				
					count1=f_array[z].getClassB()+f_array[z].getClassE();
				
				
				if(numberOfSeats <= count1){
					cout <<endl<<"--Seats Availability--"<< endl;
					for(int j=0;f_array[z].getRow(j).empty()!=1;j++){ 
						 f_array[z].display_flight_seats(j);
					
					}
					 cout << endl;
				}else{
					cout <<" Sorry..Requested Number Of Seats Are Not Available!!!\n" << endl;
				}
			
				
			}else{
				cout << " Sorry..The Flight You Looked For Is Not Available!!!\n" << endl;
			}
			break;
		}
			
		case '4':{
		
			string fl_number , r_num;
			int count_f=0;
		
			int p;
			string seat_num;
					cout<<endl<<" Enter the flight Number : ";
					cin>>fl_number;
					
					int flag_c4=0;
					for(int i=0;i<count;i++){
						if(f_array[i].getF_number() == fl_number){
								count_f=1;
								cout<<endl<<" Row Number : ";
								cin>>r_num;
							for(j=0;f_array[i].getRow(j).empty()!=1;j++){
								if(r_num == f_array[i].getRow(j)){
									
									
									flag_c4=1;			
									
									cout << " Available Seats : " << f_array[i].getSeatName(j)<<endl;
									cout << " Seat Number : "	;
									cin >> 	seat_num;
									cout<<" --Seat Booking-- ";
									
									if(f_array[i].getClass(j) == "E"){
										int f_E=f_array[i].getClassE() - 1;
										f_array[i].setClassE(f_E);
									}
									
									if(f_array[i].getClass(j) == "B"){
										int f_B=f_array[i].getClassB() - 1;
										f_array[i].setClassB(f_B);
									}
									
									for(int t=0;t <= f_array[i].getSeatName(j).size();t++){
										
										if(f_array[i].getSeatName(j).substr(t,1) == seat_num){
											
											f_array[i].setSeatData(f_array[i].getRow(j),f_array[i].getClass(j),	f_array[i].getSeatName(j).erase(t,1),j);
										
											break;
										}
									}				
								}
							}
							
							if(flag_c4==0){
								cout <<endl<<" Sorry..There is no empty seats in that row.\n" << endl;
							}
							
						}
					}
					
					
					
					if(count_f==0){
						cout <<endl<<" Sorry..The Flight You Looked For Is Not Available.\n" << endl;
					}
					
				
			
		
			break;
		}
		case '5':{
			ofstream f_update;
			f_update.open("flights.dat");
			for(int m=0;m < count ; m++){
				f_update<<f_array[m].getF_number()<<endl;
				f_update<<f_array[m].getData_time()<<endl;
				f_update<<f_array[m].getDep_airport()<<endl;
				f_update<<f_array[m].getArr_airport()<<endl;
				
				for(int h=0;f_array[m].getRow(h).empty()!=1;h++){
					f_update<<f_array[m].getRow(h)<<" "<<f_array[m].getClass(h)<<" "<<f_array[m].getSeatName(h)<<endl;
				}
				f_update<<endl;
			}
			f_update.close();
			exit(0);
			break;
		}
			
		default:
			cout<<endl<<" Wrong option!!!  "<<endl;
	}
		
	
	}	
	
	
	return 0;
}

