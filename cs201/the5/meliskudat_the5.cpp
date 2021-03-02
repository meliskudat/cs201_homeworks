
# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <sstream>
# include "strutils.h"




using namespace std;

struct for_4 {
	string movie_name ;
	double movie_rate ;
	string actress_name ;

} ;

struct netflix {
	string actor_name , serie_name ;
	double serie_rate , count  ;
};

void PrintMenu() 
{
	 cout << "MENU" << endl ;
	 cout << "1. Print the series" << endl ;
	 cout << "2. Search the series according to the rating" << endl ;
	 cout << "3. Add the series to the favorite list" << endl ;
	 cout << "4. Print the favorite list" << endl ;
	 cout << "5. Exit" << endl ;
}



bool Correctness( vector < string > & a , string number)
{
	if( a.size() == 0 )
	{
		return true ;
	}
	if( a.size() != 0)
	{
		for(int i = 0 ; i < a.size() ; i++)
		{
			if( a[i] == number)
			{
				 return false;
			}
		}
	}
	return true;

}





int main()
{
	int acount = 0 ;
	
	cout << "Welcome to Netflix TV Series Ratings Calculator!" << endl ;
	vector < string > the_printed_one ;
	string chosen_number , words , favorites_string = "";
	string actor_file , rating_file, line , actors_in_file , movie_name_in_file , rating , name_rating , actorname , moviename , word , word_next;
	cout << "Please enter a filename for Series-Actor file: " ;
	cin >> actor_file ;
	ifstream actor_series_file ;
	actor_series_file.open(actor_file) ;
	while ( actor_series_file.fail())
	{
		cout << "Can not find the specified file." << endl;
		cout << "Please enter a filename for Series-Actor file: " ;
		cin >> actor_file ;
		actor_series_file.open( actor_file) ;
	}
	cout << "Please enter a filename for Rating file: " ;
	cin >> rating_file ;
	
	ifstream fraiting_file ;
	fraiting_file.open(rating_file) ;
	while ( fraiting_file.fail())
	{
		cout << "Can not find the specified file." << endl;
		cout << "Please enter a filename for Rating file: " ;
		cin >> rating_file ;
		fraiting_file.open(rating_file.c_str()) ;
	}

	int movie_count = 0 ;
	while(getline(actor_series_file , line))
	{
		
		 movie_count += 1 ;
	}

	vector < netflix > tv_shows(movie_count) ;
	
	int i = 0 ;
	actor_series_file.clear() ;
	actor_series_file.seekg(0) ;
			
	while(getline(actor_series_file,line))
	{
		
		int index_comma = line.find(";") ;
		actorname = line.substr(0, index_comma) ;
		tv_shows[i].actor_name = actorname ;
		int length = line.length() ;
		string newline = line.substr(index_comma +1 , line.length()) ;
		istringstream input(newline) ;
		string moviename ;
		input >> moviename ;
		while( input >> word)
		{
			moviename += " " + word ;
		}

		tv_shows[i].serie_name = moviename ;
		i += 1 ;
		
	}
	
	for( int i = 0 ; i < tv_shows.size() ; i++)
	{
		tv_shows[i].count = 0 ;
		tv_shows[i].serie_rate = 0 ;
	}


    while( getline(fraiting_file, line))
    {
		 
	        istringstream input(line) ;
			input >> rating ;
			double double_rating =  atof(rating) ;
			input >> name_rating ;
			while(input >> word_next)
			{
				name_rating += " " + word_next ;
			}
			for( int i = 0 ; i < tv_shows.size() ; i++)
			{
				string lowered_one = tv_shows[i].serie_name ;
				ToLower(lowered_one) ;
				string name_rating_lowered  = name_rating;
				ToLower(name_rating_lowered) ;
				if( lowered_one == name_rating_lowered  )
				{
					tv_shows[i].serie_rate += double_rating ;
					tv_shows[i].count += 1 ;
				}
			}
			
			
	 }
	 

	 for(int i = 0 ;  i < tv_shows.size() ; i++)
	 {
		 if( tv_shows[i].count > 1)
		 {
			 tv_shows[i].serie_rate = tv_shows[i].serie_rate / tv_shows[i].count ;
		 }

	 }

	 double temp ; 
     int j, k, maxIndex, numElts = tv_shows.size() , temp3 ;
	 string temp2 , temp4 ;
	 for(k=0; k < numElts -1 ; k++){
		 maxIndex = k;             // minimal element index
		 for(j=k+1; j < numElts; j++)
		{
			if (tv_shows[j].serie_rate > tv_shows[maxIndex].serie_rate)
				   maxIndex = j;     // new min, store index
		}
		temp = tv_shows[k].serie_rate;         // swap min and k-th elements
		tv_shows[k].serie_rate = tv_shows[maxIndex].serie_rate;
		tv_shows[maxIndex].serie_rate = temp;

		temp2 = tv_shows[k].serie_name;         // swap min and k-th elements
		tv_shows[k].serie_name = tv_shows[maxIndex].serie_name;
		tv_shows[maxIndex].serie_name = temp2;

		temp3 = tv_shows[k].count;         // swap min and k-th elements
		tv_shows[k].count = tv_shows[maxIndex].count;
		tv_shows[maxIndex].count = temp3;

		temp4 = tv_shows[k].actor_name;         // swap min and k-th elements
		tv_shows[k].actor_name = tv_shows[maxIndex].actor_name;
		tv_shows[maxIndex].actor_name = temp4; 
	 }

	for( int t = 0 ; t < tv_shows.size() ; t++)
	{
		for( int a = t+1 ; a < tv_shows.size() ; a++)
		{
			if(tv_shows[t].serie_rate == tv_shows[a].serie_rate)
			{
				if( tv_shows[t].serie_name.at(0) > tv_shows[a].serie_name.at(0))
				{
							double gecici , gecici4;
							string gecici2, gecici3 ;
							gecici = tv_shows[t].serie_rate;         // swap min and k-th elements
							tv_shows[t].serie_rate = tv_shows[a].serie_rate;
							tv_shows[a].serie_rate = gecici;
							gecici2 = tv_shows[t].actor_name;         // swap min and k-th elements
							tv_shows[t].actor_name = tv_shows[a].actor_name;
							tv_shows[a].actor_name = gecici2;
							gecici3 = tv_shows[t].serie_name;         // swap min and k-th elements
							tv_shows[t].serie_name = tv_shows[a].serie_name;
							tv_shows[a].serie_name = gecici3;
							gecici4 = tv_shows[t].serie_rate;         // swap min and k-th elements
							tv_shows[t].count = tv_shows[a].count;
							tv_shows[a].count = gecici4;
				}

	 		}
		}
	 }
     cout << "---" << endl;
	 PrintMenu() ;
	 cout << "---" << endl ;
	 
	 cout << "Enter your choice: " ;
	 cin >> chosen_number ;
	 int integer_chosen_number = atoi(chosen_number) ;
	 cout << "---" << endl;
	 while(integer_chosen_number != 5)
	 {
		 if( integer_chosen_number == string::npos || 0 >= integer_chosen_number || integer_chosen_number > 5)
		 { 
			  cout << "This is not a valid option!" << endl;
			  

		 }
	 
		 if(integer_chosen_number == 1)
		 {
			cout << "RANK,NAME,ACTOR,POINTS" << endl ;
			
			for( int z = 0; z < tv_shows.size() ; z ++ )
			{
				ToUpper(tv_shows[z].serie_name);
				ToUpper(tv_shows[z].actor_name);

				int num = z+1 ;
				cout << num << "," << tv_shows[z].serie_name  << "," << tv_shows[z].actor_name << "," << tv_shows[z].serie_rate << endl;
				ToLower(tv_shows[z].serie_name);
		     	ToLower(tv_shows[z].actor_name);
			}
			


		}
		if( integer_chosen_number == 2)
		{
			
			string minimum_rating ;
			cout << "Please enter the minimum rating: " ;
			cin >> minimum_rating ;
			double double_minimum_rating = atof(minimum_rating) ;
			if( double_minimum_rating == string::npos || 0 > double_minimum_rating || double_minimum_rating > 10)
			{ 
			  cout << "This is not a valid rating!" << endl ;
			}
			else
			{
				cout << "RANK,NAME,ACTOR,POINTS" << endl;
				for( int z = 0; z < tv_shows.size() ; z ++ )
				{
					if( tv_shows[z].serie_rate >= double_minimum_rating)
					{
						ToUpper(tv_shows[z].serie_name) ;
						ToUpper(tv_shows[z].actor_name) ;
						cout << z+1 << "," << tv_shows[z].serie_name << "," << tv_shows[z].actor_name << "," << tv_shows[z].serie_rate << endl;
					}

				}
			}

		}
		if(integer_chosen_number == 3)
		{
		
			string nameofseries;
			
			cout << "Please enter the name of series: " ;
			cin.ignore() ;
			getline(cin , nameofseries) ;
			
		
			int count = 0 ;
			for( int i = 0 ; i < tv_shows.size() ; i ++)
			{
				string tv_shows_lower = tv_shows[i].serie_name ;
				ToLower(tv_shows_lower) ;
				string nameofserieslower = nameofseries ;
				ToLower(nameofserieslower) ;

				if( nameofserieslower == tv_shows_lower && Correctness(the_printed_one , tv_shows[i].serie_name) == true)
				{
					the_printed_one.push_back(tv_shows[i].serie_name) ;
					count += 1 ;
					acount += 1 ;
				}
				else if( nameofserieslower == tv_shows_lower && Correctness(the_printed_one , tv_shows[i].serie_name) == false)
				{
					string nameofseriesupper = nameofseries ;
					ToUpper(nameofseriesupper) ;
					cout << "Your favorite list already have " << nameofseriesupper << endl;
					count += 1 ;
				}
			
			}
			
			if(count == 0)
			{
				cout << "There is no such TV series!" << endl ;

			}
			
		}	
		
		if(integer_chosen_number == 4)
		{
			vector < for_4 > newVector(acount) ; 
			if(the_printed_one.size() != 0)
			{
				
				cout << "RANK,NAME,ACTOR,POINTS" << endl ;
				
				for(int u = 0 ;u < acount ; u++)
				{
					for(int x= 0 ; x < tv_shows.size() ; x++)
					{
						if(the_printed_one[u] == tv_shows[x].serie_name)
						{
							 newVector[u].movie_name = tv_shows[x].serie_name ;
							 newVector[u].movie_rate  = tv_shows[x].serie_rate ;
							 newVector[u].actress_name = tv_shows[x].actor_name ;
						}

					}
				}

				int size = newVector.size() ;
				double tempa ;
				string tempb, tempc ;
				for(int d =0; d < size-1 ; d++){
					int maxInd = d;             // minimal element index
					for(int j=d+1; j < size; j++)
					{
							if (newVector[j].movie_rate > newVector[maxInd].movie_rate)
							   maxInd = j;     // new min, store index
							

					}
					tempa = newVector[d].movie_rate;         // swap min and k-th elements
					newVector[d].movie_rate = newVector[maxInd].movie_rate;
					newVector[maxInd].movie_rate = tempa;

					tempb = newVector[d].movie_name;         // swap min and k-th elements
					newVector[d].movie_name = newVector[maxInd].movie_name;
					newVector[maxInd].movie_name = tempb;

					tempc = newVector[d].actress_name;         // swap min and k-th elements
					newVector[d].actress_name = newVector[maxInd].actress_name;
					newVector[maxInd].actress_name = tempc;
				}
				for(int f = 0 ; f < size ; f++)
				{

					  for(int a = f+1 ; a < size ; a++)
					  {


						if( newVector[f].movie_rate == newVector[a].movie_rate)
						{
							if(newVector[f].actress_name.at(0) > newVector[a].actress_name.at(0))
							{
								int tempe = newVector[f].movie_rate;         // swap min and k-th elements
								newVector[f].movie_rate = newVector[a].movie_rate;
								newVector[a].movie_rate = tempe;

							    string tempf = newVector[f].actress_name;         // swap min and k-th elements
								newVector[f].actress_name = newVector[a].actress_name;
								newVector[a].actress_name = tempf;

							    string tempg = newVector[f].movie_name;         // swap min and k-th elements
								newVector[f].movie_name = newVector[a].movie_name;
								newVector[a].movie_name = tempf;

								
							}

						 }
					 }


		        }
			
				for( int b = 0 ; b < size ; b++)
				{
						 ToUpper(newVector[b].movie_name) ;
						 ToUpper(newVector[b].actress_name) ;
						 cout << b+1 << "," << newVector[b].movie_name << "," << newVector[b].actress_name << "," << newVector[b].movie_rate << endl ;
			    
				}
			}
		
		    if(the_printed_one.size() == 0 )
			{
				cout <<	"Your favorite list is currently empty!" << endl;

			}
		}


		
		cout << "---" << endl ;
	    PrintMenu() ;
		cout << "---" << endl;
		cout << "Enter your choice: " ;
	    cin >> chosen_number ;
		integer_chosen_number = atoi(chosen_number) ;
		cout << "---" << endl;

    
	}
}

