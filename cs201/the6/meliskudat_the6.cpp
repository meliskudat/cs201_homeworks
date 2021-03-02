#include "favoriteseries.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "strutils.h"
#include <vector>

using namespace std;



void displaymenu()
{
	cout << "---" << endl ;
    cout << "MENU" << endl ;
    cout << "1. Print all TV series" << endl;
    cout << "2. Add TV series" << endl;
    cout << "3. Drop TV series" <<endl ;
    cout << "4. Print your favorite series with schedule" << endl ;
    cout << "5. Print all your favorite actors" << endl;
    cout << "6. Exit" << endl ;
    cout <<	"---" << endl ;
}





int main()
{
	series B ;
	int choice , codeforfav , codefordrop ;
	string name, surname , filename1 = "series.txt" , nameofactor , x, filename2 = "episodes.txt" , line , forlast, serienameunion, seriename, line2 , seriescode, codeofserie, dayofserie , timeslot , episodename, line3;
	cout << "Welcome to my favorite TV series schedule program!" << endl;
	cout << "Please, enter your name and surname: " ;
	cin >> name ;
	cin >> surname ;
	FavoriteSeries A(name, surname) ;
	ifstream seriesfile , episodesfile ;
	seriesfile.open(filename1.c_str()) ;
	episodesfile.open(filename2.c_str()) ;
	displaymenu() ;
	int movie_count = 0 ;
	while(getline(seriesfile , line))
	{
		 movie_count += 1 ;
	}
	int episode_count = 0 ;
	while(getline(episodesfile , line))
	{
		 episode_count += 1 ;
	}
	vector < episode > forfirstchoice(episode_count) ;
	seriesfile.clear() ;
	seriesfile.seekg(0) ;
	episodesfile.clear() ;
	episodesfile.seekg(0) ;

	int i = 0 ;
	while(getline(episodesfile , line2) && i < episode_count)
	{
		istringstream input(line2) ;
		input >> codeofserie ;
		int codeofserienew = atoi(codeofserie) ;
		forfirstchoice[i].seriesCode = codeofserienew ;
		input >> dayofserie ;
		int index = line2.find("/") ;
		int index2 = line2.find("/" , index+1) ;
		int index3 = dayofserie.find("/") ;
		string monthtime = dayofserie.substr(0 , index3) ;
		string daytime = line2.substr(index+1 , index2) ;
		string yeartime = line2.substr(index2+1 ) ;
	    int monthtimenew = atoi(monthtime) ;
		int daytimenew = atoi(daytime) ;
		int yeartimenew = atoi(yeartime) ;
		Date d(monthtimenew, daytimenew, yeartimenew) ;
		forfirstchoice[i].date = d ;
		input >> timeslot ;
		forfirstchoice[i].slot = timeslot ;
		string episodenameunited = "" ;
		while( input >> episodename)
		{
			episodenameunited += " " + episodename ;
		}
		forfirstchoice[i].episodeName = episodenameunited.substr(1) ;
		i += 1 ;
	}

	episodesfile.clear() ;
	episodesfile.seekg(0) ;
	vector <series > forseries(movie_count) ;
	int k = 0;
	while( getline(seriesfile, line3) && k < episode_count)
	{
		int counta = 0 ;
		istringstream intake(line3) ;
		intake >> seriescode ;
		int seriescodenew = atoi(seriescode) ;
		for( int a = 0 ; a < episode_count  ; a++)
		{
			if(seriescodenew == forfirstchoice[a].seriesCode && counta == 0)
			{
				forseries[k].seriesCode = forfirstchoice[a].seriesCode ;
				intake >> seriename ;
				serienameunion = "" ;
				while(seriename.find(";") == string::npos)
				{
					serienameunion += " " + seriename;
					intake >> seriename ;
				}
				
				int indexnoktali = seriename.find(";") ;
				serienameunion += " " + seriename.substr(0,indexnoktali) ;
				forseries[k].seriesName = serienameunion.substr(1) ;
				forseries[k].episodes.push_back(forfirstchoice[a]); //forseries->episodes size1 -> size2 forfirstchoice 
				
				//cout << forseries[k].episodes[0].episodeName << endl;
				x = "" ;
				while( intake >> nameofactor ) 
				{
				
					if( nameofactor.find(",") == string::npos)
					{
					    x += " " + nameofactor ;
					}
					else 
					{
						int indexvirgul = nameofactor.find(",") ;
						x = x + " " + nameofactor.substr(0, indexvirgul) ;
						x = x.substr(1) ;
						forseries[k].actorNames.push_back(x) ;
						x = "" ;
					}

				}
				x = x.substr(1) ;
				forseries[k].actorNames.push_back(x) ;

				counta += 1 ;


			}
			else if(seriescodenew == forfirstchoice[a].seriesCode && counta != 0)
			{
				forseries[k].episodes.push_back(forfirstchoice[a]); 
			}


		}
		k+= 1 ;

	}

	cout << "Please enter your choice: " ;
	cin >> choice ;
	while(choice != 6)
	{
		if(choice == 1)
		{
			vector < daysmonths > time(episode_count) ;
			int e = 0 ;
			for(int y= 0 ; y < forseries.size() ; y++)
			{
				for(int i = 0 ; i < forseries[y].episodes.size() ; i++)
				{
					time[e].days = forseries[y].episodes[i].date.Day() ;
					time[e].months = forseries[y].episodes[i].date.Month() ;
					time[e].monthname = forseries[y].episodes[i].date.MonthName() ;
					time[e].code = forseries[y].episodes[i].seriesCode ;
					time[e].slott = forseries[y].episodes[i].slot ;
					time[e].year = forseries[y].episodes[i].date.Year() ;
					time[e].episoden = forseries[y].episodes[i].episodeName ;
					time[e].serien = forseries[y].seriesName ;
					e += 1 ;
				}
			}
			for( int t = 0 ; t < time.size() ; t++)
			{
			  for( int a = t+1 ; a < time.size() ; a++)
		      {
				
				    if(time[a].year < time[t].year)
				    {

					            int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = time[t].months;         // swap min and k-th elements
								time[t].months = time[a].months;
								time[a].months = gecici;
								gecici2 = time[t].days;         // swap min and k-th elements
								time[t].days = time[a].days;
								time[a].days = gecici2;
								gecici3 = time[t].slott;         // swap min and k-th elements
								time[t].slott = time[a].slott;
								time[a].slott = gecici3;
								gecici4 = time[t].code;         // swap min and k-th elements
								time[t].code = time[a].code;
								time[a].code = gecici4;
								gecici5 = time[t].year;         // swap min and k-th elements
								time[t].year = time[a].year;
								time[a].year = gecici5;
								gecici6 = time[t].episoden;         // swap min and k-th elements
								time[t].episoden = time[a].episoden;
								time[a].episoden = gecici6;
								gecici7 = time[t].serien;         // swap min and k-th elements
								time[t].serien = time[a].serien;
								time[a].serien = gecici7;
								gecici8 = time[t].monthname;         // swap min and k-th elements
								time[t].monthname = time[a].monthname;
								time[a].monthname = gecici8;

				    }
					else if( time[a].months < time[t].months && time[t].year == time[a].year)
					{
								int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = time[t].months;         // swap min and k-th elements
								time[t].months = time[a].months;
								time[a].months = gecici;
								gecici2 = time[t].days;         // swap min and k-th elements
								time[t].days = time[a].days;
								time[a].days = gecici2;
								gecici3 = time[t].slott;         // swap min and k-th elements
								time[t].slott = time[a].slott;
								time[a].slott = gecici3;
								gecici4 = time[t].code;         // swap min and k-th elements
								time[t].code = time[a].code;
								time[a].code = gecici4;
								gecici5 = time[t].year;         // swap min and k-th elements
								time[t].year = time[a].year;
								time[a].year = gecici5;
								gecici6 = time[t].episoden;         // swap min and k-th elements
								time[t].episoden = time[a].episoden;
								time[a].episoden = gecici6;
								gecici7 = time[t].serien;         // swap min and k-th elements
								time[t].serien = time[a].serien;
								time[a].serien = gecici7;
								gecici8 = time[t].monthname;         // swap min and k-th elements
								time[t].monthname = time[a].monthname;
								time[a].monthname = gecici8;
								
					}
					else if( time[t].months == time[a].months && time[a].days < time[t].days && time[t].year == time[a].year)
					{


						        int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = time[t].months;         // swap min and k-th elements
								time[t].months = time[a].months;
								time[a].months = gecici;
								gecici2 = time[t].days;         // swap min and k-th elements
								time[t].days = time[a].days;
								time[a].days = gecici2;
								gecici3 = time[t].slott;         // swap min and k-th elements
								time[t].slott = time[a].slott;
								time[a].slott = gecici3;
								gecici4 = time[t].code;         // swap min and k-th elements
								time[t].code = time[a].code;
								time[a].code = gecici4;
								gecici5 = time[t].year;         // swap min and k-th elements
								time[t].year = time[a].year;
								time[a].year = gecici5;
								gecici6 = time[t].episoden;         // swap min and k-th elements
								time[t].episoden = time[a].episoden;
								time[a].episoden = gecici6;
								gecici7 = time[t].serien;         // swap min and k-th elements
								time[t].serien = time[a].serien;
								time[a].serien = gecici7;
								gecici8 = time[t].monthname;         // swap min and k-th elements
								time[t].monthname = time[a].monthname;
								time[a].monthname = gecici8;
					}
					else if( (time[t].months == time[a].months) && (time[a].days == time[t].days) && ( (time[t].year == time[a].year) && ((time[a].slott == "evening" && time[t].slott == "night") || (time[a].slott =="morning" && time[t].slott == "evening") || (time[a].slott == "morning" && time[t].slott == "night" ) || (time[a].slott == "morning" && time[t].slott == "afternoon" )|| (time[a].slott == "afternoon" && time[t].slott == "evening" ) || (time[a].slott == "afternoon" && time[t].slott == "night" ))))
					{

					
						        int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = time[t].months;         // swap min and k-th elements
								time[t].months = time[a].months;
								time[a].months = gecici;
								gecici2 = time[t].days;         // swap min and k-th elements
								time[t].days = time[a].days;
								time[a].days = gecici2;
								gecici3 = time[t].slott;         // swap min and k-th elements
								time[t].slott = time[a].slott;
								time[a].slott = gecici3;
								gecici4 = time[t].code;         // swap min and k-th elements
								time[t].code = time[a].code;
								time[a].code = gecici4;
								gecici5 = time[t].year;         // swap min and k-th elements
								time[t].year = time[a].year;
								time[a].year = gecici5;
								gecici6 = time[t].episoden;         // swap min and k-th elements
								time[t].episoden = time[a].episoden;
								time[a].episoden = gecici6;
								gecici7 = time[t].serien;         // swap min and k-th elements
								time[t].serien = time[a].serien;
								time[a].serien = gecici7;
								gecici8 = time[t].monthname;         // swap min and k-th elements
								time[t].monthname = time[a].monthname;
								time[a].monthname = gecici8;
								
					}
					else if( time[t].months == time[a].months && time[a].days == time[t].days && time[a].slott.at(0) == time[t].slott.at(0) && time[a].code < time[t].code && time[t].year == time[a].year)
					{
						        int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7, gecici8 ;
								
								gecici = time[t].months;         // swap min and k-th elements
								time[t].months = time[a].months;
								time[a].months = gecici;
								gecici2 = time[t].days;         // swap min and k-th elements
								time[t].days = time[a].days;
								time[a].days = gecici2;
								gecici3 = time[t].slott;         // swap min and k-th elements
								time[t].slott = time[a].slott;
								time[a].slott = gecici3;
								gecici4 = time[t].code;         // swap min and k-th elements
								time[t].code = time[a].code;
								time[a].code = gecici4;
								gecici5 = time[t].year;         // swap min and k-th elements
								time[t].year = time[a].year;
								time[a].year = gecici5;
								gecici6 = time[t].episoden;         // swap min and k-th elements
								time[t].episoden = time[a].episoden;
								time[a].episoden = gecici6;
								gecici7 = time[t].serien;         // swap min and k-th elements
								time[t].serien = time[a].serien;
								time[a].serien = gecici7;
								gecici8 = time[t].monthname;         // swap min and k-th elements
								time[t].monthname = time[a].monthname;
								time[a].monthname = gecici8;
								
					}

	 			}
			}
			cout << "CODE,SERIES,EPISODE,DATE,SLOT" << endl ;
			for( int k = 0 ; k < time.size() ; k++)
			{
				if( time[k].serien.find("i") != string::npos ){
					for( int m = 0 ; m < time[k].serien.length() ; m++)
					{
						if( time[k].serien.at(m) == 'i' )
							time[k].serien.at(m) = 'I';
					}
				}
			
				ToUpper(time[k].serien) ;
				ToUpper(time[k].episoden) ;
				ToUpper(time[k].slott) ;
				cout << time[k].code << "," << time[k].serien << "," << time[k].episoden << "," << time[k].monthname << " " << time[k].days << " " << time[k].year << "," << time[k].slott << endl;
			}
		 }

		 else if(choice == 2)
		 {		 
			 cout << "Enter code for the TV series you want to add: " ;
			 cin >> codeforfav ;
			 for( int i = 0 ; i < forseries.size() ; i++)
			 {
				 if( codeforfav == forseries[i].seriesCode)
				 {
					 B.actorNames = forseries[i].actorNames ;
					 B.episodes = forseries[i].episodes ;
					 B.seriesCode = codeforfav ;
					 B.seriesName = forseries[i].seriesName ;
				 }

			 }

			 int countb = 0 ;
			 for(int i = 0 ; i < forseries.size() ; i++)
			 {
				 if( codeforfav == forseries[i].seriesCode)
				 {
					 countb += 1;
				 }
					
			 }
			 if(countb == 0)
			 {
				 cout << A.getFullName() << ", there is no such TV series in the database!" << endl ;
			 }
			 else if( A.ifExists(codeforfav) == true)
			 {
				 cout << A.getFullName() << ", you can't add this TV series because you already added it!" << endl ;
			 }
			 else if( A.isConflict(B) == true )
			 {
				 
				 cout << A.getFullName()<< ", you can't add this TV series because of a date and slot conflict!" << endl ;
			 }

			 else
			 {
				 string nameofmovie = B.seriesName ;
				 ToUpper(nameofmovie) ;
				 cout << A.getFullName() << ", "<<nameofmovie << " added to your schedule." << endl ;
				 A.addSeries(B) ;
			 }

		 }
		 else if(choice == 3)
		 {

			 if ( A.isListEmpty())
			 {
				 cout << A.getFullName()  << ", you did not add any TV series yet!" << endl ;
			 }

			 else
			 {
				 string nameversion ;
				 cout << "Enter code for the TV series you want to drop: ";
				 cin >> codefordrop ;
				 if( A.ifExists(codefordrop) == true){
					 for(int t= 0 ; t < forseries.size() ; t++)
					 {
						 if(codefordrop == forseries[t].seriesCode)
						 {
							 nameversion = forseries[t].seriesName ;
						 }

					 }
					 ToUpper(nameversion) ;
					 A.dropSeriesSorted(codefordrop) ;
					 cout << A.getFullName() << ", " << nameversion << " has been dropped from your favorite list!" << endl ;
			     }
				 else{
					cout << A.getFullName() << ", there is no such TV series in your favorite list!" << endl ;
				 }
		    
		      }
		 }

         else if(choice == 4) 
		 {
			  if( A.isListEmpty() == false){
			     cout << A.getFullName() << ", here is your favorite TV series:" << endl; 
				 A.displayFavoriteList() ;
			  }
			  else{
				cout << A.getFullName() << ", you did not add any TV series yet!" << endl ;
			  }
		 }

		 else if(choice ==5)
		 {
           if( A.isListEmpty() == false){
			 cout << A.getFullName() << ", here is your favorite actors:" << endl ;
			 A.displayFavoriteActors() ;
		   }
		   else{
				cout << A.getFullName() << ", you did not add any TV series yet!" << endl ;
		   }
		   		
		   
		 }

		 else 
		 {
			 cout << "Invalid option!" << endl ;
		 }

		 displaymenu() ;
         cout << "Please enter your choice: ";
		 cin >> choice ;
		 
		 }
		 if(choice == 6)
		 {
			 cout <<"Goodbye, " << A.getFullName()<<"!" << endl ;
		 }		
	}














	




	





















