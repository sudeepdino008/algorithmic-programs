/*assignment my M. SUDEEP KUMAR(11CS30017) */


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#define MIN_PURCHASE_TO_WIN_GOLD_COIN 10000
using namespace std;



/*simple function to convert string to integer*/
int string_to_integer(string s)
{
	int result;
	stringstream(s)>>result;
	return result;
}
	   
/*simple function to convert integer to string*/
string int_to_string(int n)
{
    ostringstream convert;
    convert<<n;
    return convert.str();
}


/* char print_operations() prints the operations available to the user and returns the user choice*/
char print_operations()                                  
{
	cout<<"\n1.Create new user.\n";
	cout<<"2.Enter existing UCN number and update total purchase.\n";
	cout<<"3.Quit\n";
	char ch;
	cin>>ch;
	return ch;
}

/*Generates a 5-digit unique customer number(UCN)*/
void generate_UCN(string & UCN)
{
	int i,n;
	UCN="";
	for(i=1;i<=5;i++)
	{
		n = rand()%10;
		UCN = UCN+char(n+'0');
	}
}

/*creates a new customer database and assigns the UCN number*/
void create_new_user_and_write(ofstream& customer_database)
{
	customer_database.close();
	customer_database.open("customer_database", ios::app);
	
	string name;
	string address;
	string telephone;
	string driving_license_number;
	string UCN;
	string todays_purchase;
	cout<<"Name:"<<endl;
	getline(cin,name);
	getline(cin,name);
	cout<<"Address:"<<endl;
	getline(cin,address);
	cout<<"Telephone:"<<endl;
	getline(cin,telephone);
	cout<<"Driving License Number:"<<endl;
	getline(cin,driving_license_number);
	cout<<"Todays total purchase:"<<todays_purchase<<endl;
	getline(cin, todays_purchase);
	generate_UCN(UCN);
	cout<<"Your UCN number is:\n"<<UCN;


	customer_database << "\n";
	customer_database << "\nUCN:"<<UCN;
	customer_database << "\nNAME:"<<name;
	customer_database << "\nADDRESS:"<<address;
	customer_database << "\nTELEPHONE:"<<telephone;
	customer_database << "\nDRIVING LICENSE NUMBER:"<<driving_license_number;
	customer_database << "\nTOTAL PURCHASE:"<<todays_purchase;
	

	customer_database.close();
	customer_database.open("customer_database", ios::app);
}


/*deal with an old customer i.e. take the UCN and update the total purchase for the year*/
void deal_with_old_customer(ofstream& new_customer_database, fstream& read_customer_database, ofstream& customer_database)
{
	int i;
	string UCN,line;
	cout<<"Enter your UCN:\n";
	cin>>UCN;

	new_customer_database.close();
	new_customer_database.open(".new_customer_database", ios::trunc);
	new_customer_database.close();
	new_customer_database.open(".new_customer_database", ios::app);
	read_customer_database.close();
	read_customer_database.open("customer_database");
	
	/*copy the new contents to new_customer_database and copy its content to an emptied customer_database and then empty the new_customer_database*/
	while(!read_customer_database.eof())
	{
		//cout<<"hello\n";
		getline(read_customer_database, line);
		
		int spot = line.find(UCN);
		//cout<<"....."<<line<<endl;
		
		if(spot>=0)
		{
			new_customer_database<<line<<"\n";
			getline(read_customer_database,line);                    //the "NAME:**********" string getting stored in line
			new_customer_database<<line<<"\n";
			getline(read_customer_database,line);                    //the "address string"
			new_customer_database<<line<<"\n";
			getline(read_customer_database,line);                    //the "telephone number" string
			new_customer_database<<line<<"\n";
			getline(read_customer_database,line);                    //the driving "license number" string
			new_customer_database<<line<<"\n";
			getline(read_customer_database,line);                   //the "total purchase" string
			int index_colon = line.find(":");
			int index_end_of_line = line.find("\n");
			int purchase = string_to_integer(line.substr(index_colon+1, index_end_of_line));          //storing total purchase
			
			int todays_purchase;
			cout<<"Todays total purchase:\n";
			cin>>todays_purchase;
			purchase+=todays_purchase;
			string total_purchase = int_to_string(purchase);
			//cout<<"#############"<<total_purchase<<endl;
			new_customer_database<<"TOTAL PURCHASE:"<<total_purchase<<"\n\n";
			
		}
		else
			new_customer_database<<line<<"\n";
	   	}


	new_customer_database.close();
	read_customer_database.close();
	read_customer_database.open(".new_customer_database");
	customer_database.close();
	customer_database.open("customer_database",ios::trunc);

	while(!read_customer_database.eof())
	{
		getline(read_customer_database, line);
		//cout<<"@@@........."<<line<<endl;
		customer_database<<line<<"\n";
	}

	//emptying the new_customer_databse
	
	new_customer_database.open(".new_customer_database", ios::trunc);
	customer_database.close();
	customer_database.open("customer_database", ios::app);
	read_customer_database.close();
	read_customer_database.open("customer_database");
	 
	
}

/*distribute gold coins to customers having a total purchase of Rs. 10000/- */
void distribute_gold_coins(fstream& read_customer_database)
{
	read_customer_database.close();
	read_customer_database.open("customer_database");
	string name, ucn, line;
	int index, purchase;
	bool atleast_one_winner = false;
	
	while(!read_customer_database.eof())
	{
		getline(read_customer_database, line);
		index = line.find("UCN:");
		if(index>=0)
		{
			ucn = line.substr(index+4);
			getline(read_customer_database, line);
			index = line.find("NAME:");
			name = line.substr(index+5);
			getline(read_customer_database, line);            //read address
			getline(read_customer_database, line);            //read telephone number
			getline(read_customer_database, line);            //read driving license number
			getline(read_customer_database, line);            //read total purchase
			index = line.find("TOTAL PURCHASE:");
			index = index+15;
			purchase = string_to_integer(line.substr(index));
			if(purchase>=MIN_PURCHASE_TO_WIN_GOLD_COIN)
			{
				if(atleast_one_winner==false)
				{
					atleast_one_winner = true;
					cout<<"\t\tAnd the winner of 22-carat gold coins are:\n";
				}
				cout<<"UCN:"<<ucn<<"\n";
				cout<<"name:"<<name<<"\n";
				cout<<"Total Purchase:"<<purchase<<"\n\n";
				
			}
		}
	}
	read_customer_database.close();
	read_customer_database.open("customer_database");
	
	
}

/*surprise gifts to maximum 10 customers*/
void surprise_gift(fstream& read_customer_database)
{
	read_customer_database.close();
	read_customer_database.open("customer_database");
	
	
	
	map<int, string> user_map;         //maps the purchase value to user name
	string line, name_s;
	int index;


	//storing the total purchase, name and UCN in the map data structure
	while(!read_customer_database.eof())
	{
		getline(read_customer_database, line);
		index = line.find("UCN:");
		if(index>=0)
		{
			
			getline(read_customer_database, line);
			name_s = line.substr(5);       //extract name
			getline(read_customer_database, line);
			getline(read_customer_database, line);
			getline(read_customer_database, line);
			getline(read_customer_database, line);
			user_map[string_to_integer(line.substr(15))] = name_s;;
		}
	}

	int max, i=10;
	cout<<"\n\n\t\tSurprise Prizes and Goodies for the following customers:\n";
	for(i=0;i<2 && !user_map.empty() ; i++)
	{
		max = INT_MIN;
		for(map<int, string>::const_iterator it = user_map.begin() ; it!=user_map.end() ; it++)
		{
			if(max<=it->first)
				max = it->first;
		}
		cout<<"NAME:\t"<<user_map[max]<<"\n\n";
		user_map.erase(max);
	}

	read_customer_database.close();
	read_customer_database.open("customer_database");

}

/*resets all database and records the years total sales*/
void reset_database_and_record_sales_position(fstream& read_customer_database, ofstream& customer_database)
{
	string line;
	read_customer_database.close();
	read_customer_database.open("customer_database");
	ofstream annual_data(".annual_sales_database", ios::app);
	

	/*utilising the tm structure for getting todays date*/
	time_t t = time(0);
	struct tm *now = localtime(&t);
	int year = now->tm_year+1900;                //tm_year gives the number of years since 1900
	int index, sum=0;

	while(!read_customer_database.eof())
	{
		getline(read_customer_database, line);
		index = line.find("TOTAL PURCHASE:");
		if(index>=0)
			sum+=string_to_integer(line.substr(15));
		
	}
	annual_data<<int_to_string(year)<<":"<<int_to_string(sum)<<"\n";
	annual_data.close();
	read_customer_database.close();
	customer_database.close();
	customer_database.open("customer_database", ios::trunc);
	customer_database.close();
	customer_database.open("customer_database",ios::app);
	read_customer_database.open("customer_database");
}

/*checks for new year, prints customer who won prizes and resets the customer databases*/
void check_for_new_year(ofstream& customer_database, fstream& read_customer_database)
{
	time_t t = time(0);                         //get present time(number of seconds elapsed since January 1, 1970 i.e. the unix epoch)
	struct tm *now = localtime(&t);             //the tm structure getting filled by the localtime(time_t *) function
	if(now->tm_yday==0)                         //tm_yday return number of days from January 1. Hence it is new year if now->tm_day=0
	{
		cout<<"\t\tHAPPY NEW YEAR\n\n";
		distribute_gold_coins(read_customer_database);
		surprise_gift(read_customer_database);	
	reset_database_and_record_sales_position(read_customer_database, customer_database);
	}
}

int main()
{
	srand(time(NULL));
	ofstream new_customer_database(".new_customer_database", ios::trunc | ios::app);
	ofstream customer_database("customer_database",ios::app);
	fstream read_customer_database("customer_database");
	cout<<"\t\tWELCOME TO THE SUPER MARKET!!!!!!\n";
	check_for_new_year(customer_database, read_customer_database);
	char ch = print_operations();
	while(ch!='3')                                             /*the '3' option corresponds to the quit operation*/
	{
		if(ch=='1')                                           /*create new user*/
			create_new_user_and_write(customer_database);
		else if(ch=='2')
			deal_with_old_customer(new_customer_database,read_customer_database,customer_database);
		ch=print_operations();
	}
	customer_database.close();
	new_customer_database.close();
	read_customer_database.close();
	return 0;
}
