
#include "favoriteseries.h" 
#include "strutils.h"
FavoriteSeries :: FavoriteSeries ( string name, string surname )
{
	userName = name ;
	userSurname = surname ;

}


string FavoriteSeries :: getFullName() const
{	
	string name = "" , surname = "" ;
	for( int t = 0 ; t < userName.length() ; t++){
	     name += userName[t] ;
	}
	for( int a = 0 ; a < userSurname.length() ; a++){
	     surname += userSurname[a] ;
	}
	
	ToUpper(name) ;
	ToUpper(surname) ;
	return name + " " + surname ;

}


void FavoriteSeries :: addSeries(const series & B)
{
	favSeries.push_back(B) ;
}


bool FavoriteSeries :: isListEmpty() const
{
	if(favSeries.size() == 0)
	{
		return true ;
	}
	else
	{
		return false ;
	}

}


void FavoriteSeries :: dropSeriesSorted(int dropcode)
{
	int size = favSeries.size() ;
	for(int i = 0 ; i < size ; i++)
	{
		if( favSeries[i].seriesCode == dropcode)
		{
			favSeries.erase(favSeries.begin() +i) ;
		}
     size = favSeries.size() ;
	}
    


}

bool FavoriteSeries :: ifExists(int seriesCode)
{
	for(int i = 0 ; i < favSeries.size() ; i++)
	{
		if(seriesCode == favSeries[i].seriesCode)
		{
			return true ; // listede bu koddan film vardi zaten demek
		}
	}
	return false ; // listede bu koddan film eklenmemis daha once , ekleyebilirsin
}

bool FavoriteSeries :: isConflict(const series & B) const
{
	 for(int i = 0 ; i < favSeries.size() ; i++)
	 {

		  for(int k = 0 ; k < favSeries[i].episodes.size() ; k++)
		  {
			  for(int j = 0 ; j < B.episodes.size() ; j++)
			  {
				  if( (favSeries[i].episodes[k].date == B.episodes[j].date) && (favSeries[i].episodes[k].slot == B.episodes[j].slot))
					  return true ;
			  }
		  }

	 }
     return false ;
}

void FavoriteSeries ::displayFavoriteList() const
{
	       int count = 0 ;
	       for(int k = 0 ; k < favSeries.size() ; k++)
		   {
			   for(int t = 0 ; t < favSeries[k].episodes.size() ; t++)
			   {
				   count += 1 ;
			   }

		   }

		   if(favSeries.size() != 0 )
			    
				cout << "CODE,SERIES,EPISODE,DATE,SLOT" << endl;
	     
	
			vector < daysmonths > favseriesdisplay(count) ;
			int e = 0 ;
			for(int y= 0 ; y < favSeries.size() ; y++)
			{
				for(int i = 0 ; i < favSeries[y].episodes.size() ; i++)
				{
					favseriesdisplay[e].days = favSeries[y].episodes[i].date.Day() ;
					favseriesdisplay[e].months = favSeries[y].episodes[i].date.Month() ;
					favseriesdisplay[e].monthname = favSeries[y].episodes[i].date.MonthName() ;
					favseriesdisplay[e].code = favSeries[y].episodes[i].seriesCode ;
					favseriesdisplay[e].slott = favSeries[y].episodes[i].slot ;
					favseriesdisplay[e].year = favSeries[y].episodes[i].date.Year() ;
					favseriesdisplay[e].episoden = favSeries[y].episodes[i].episodeName ;
					favseriesdisplay[e].serien = favSeries[y].seriesName ;
					e += 1 ;
				}
			}
			for( int t = 0 ; t < favseriesdisplay.size() ; t++)
			{
			  for( int a = t+1 ; a < favseriesdisplay.size() ; a++)
		      {
				
				    if(favseriesdisplay[a].year < favseriesdisplay[t].year)
				    {

					            int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = favseriesdisplay[t].months;         // swap min and k-th elements
								favseriesdisplay[t].months = favseriesdisplay[a].months;
								favseriesdisplay[a].months = gecici;
								gecici2 = favseriesdisplay[t].days;         // swap min and k-th elements
								favseriesdisplay[t].days = favseriesdisplay[a].days;
								favseriesdisplay[a].days = gecici2;
								gecici3 = favseriesdisplay[t].slott;         // swap min and k-th elements
								favseriesdisplay[t].slott = favseriesdisplay[a].slott;
								favseriesdisplay[a].slott = gecici3;
								gecici4 = favseriesdisplay[t].code;         // swap min and k-th elements
								favseriesdisplay[t].code = favseriesdisplay[a].code;
								favseriesdisplay[a].code = gecici4;
								gecici5 = favseriesdisplay[t].year;         // swap min and k-th elements
								favseriesdisplay[t].year = favseriesdisplay[a].year;
								favseriesdisplay[a].year = gecici5;
								gecici6 = favseriesdisplay[t].episoden;         // swap min and k-th elements
								favseriesdisplay[t].episoden = favseriesdisplay[a].episoden;
								favseriesdisplay[a].episoden = gecici6;
								gecici7 = favseriesdisplay[t].serien;         // swap min and k-th elements
								favseriesdisplay[t].serien = favseriesdisplay[a].serien;
								favseriesdisplay[a].serien = gecici7;
								gecici8 = favseriesdisplay[t].monthname;         // swap min and k-th elements
								favseriesdisplay[t].monthname = favseriesdisplay[a].monthname;
								favseriesdisplay[a].monthname = gecici8;

				    }
					else if( favseriesdisplay[a].months < favseriesdisplay[t].months && favseriesdisplay[t].year == favseriesdisplay[a].year)
					{
								 int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = favseriesdisplay[t].months;         // swap min and k-th elements
								favseriesdisplay[t].months = favseriesdisplay[a].months;
								favseriesdisplay[a].months = gecici;
								gecici2 = favseriesdisplay[t].days;         // swap min and k-th elements
								favseriesdisplay[t].days = favseriesdisplay[a].days;
								favseriesdisplay[a].days = gecici2;
								gecici3 = favseriesdisplay[t].slott;         // swap min and k-th elements
								favseriesdisplay[t].slott = favseriesdisplay[a].slott;
								favseriesdisplay[a].slott = gecici3;
								gecici4 = favseriesdisplay[t].code;         // swap min and k-th elements
								favseriesdisplay[t].code = favseriesdisplay[a].code;
								favseriesdisplay[a].code = gecici4;
								gecici5 = favseriesdisplay[t].year;         // swap min and k-th elements
								favseriesdisplay[t].year = favseriesdisplay[a].year;
								favseriesdisplay[a].year = gecici5;
								gecici6 = favseriesdisplay[t].episoden;         // swap min and k-th elements
								favseriesdisplay[t].episoden = favseriesdisplay[a].episoden;
								favseriesdisplay[a].episoden = gecici6;
								gecici7 = favseriesdisplay[t].serien;         // swap min and k-th elements
								favseriesdisplay[t].serien = favseriesdisplay[a].serien;
								favseriesdisplay[a].serien = gecici7;
								gecici8 = favseriesdisplay[t].monthname;         // swap min and k-th elements
								favseriesdisplay[t].monthname = favseriesdisplay[a].monthname;
								favseriesdisplay[a].monthname = gecici8;
								
					}
					else if( favseriesdisplay[t].months == favseriesdisplay[a].months && favseriesdisplay[a].days < favseriesdisplay[t].days && favseriesdisplay[t].year == favseriesdisplay[a].year)
					{


						       int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = favseriesdisplay[t].months;         // swap min and k-th elements
								favseriesdisplay[t].months = favseriesdisplay[a].months;
								favseriesdisplay[a].months = gecici;
								gecici2 = favseriesdisplay[t].days;         // swap min and k-th elements
								favseriesdisplay[t].days = favseriesdisplay[a].days;
								favseriesdisplay[a].days = gecici2;
								gecici3 = favseriesdisplay[t].slott;         // swap min and k-th elements
								favseriesdisplay[t].slott = favseriesdisplay[a].slott;
								favseriesdisplay[a].slott = gecici3;
								gecici4 = favseriesdisplay[t].code;         // swap min and k-th elements
								favseriesdisplay[t].code = favseriesdisplay[a].code;
								favseriesdisplay[a].code = gecici4;
								gecici5 = favseriesdisplay[t].year;         // swap min and k-th elements
								favseriesdisplay[t].year = favseriesdisplay[a].year;
								favseriesdisplay[a].year = gecici5;
								gecici6 = favseriesdisplay[t].episoden;         // swap min and k-th elements
								favseriesdisplay[t].episoden = favseriesdisplay[a].episoden;
								favseriesdisplay[a].episoden = gecici6;
								gecici7 = favseriesdisplay[t].serien;         // swap min and k-th elements
								favseriesdisplay[t].serien = favseriesdisplay[a].serien;
								favseriesdisplay[a].serien = gecici7;
								gecici8 = favseriesdisplay[t].monthname;         // swap min and k-th elements
								favseriesdisplay[t].monthname = favseriesdisplay[a].monthname;
								favseriesdisplay[a].monthname = gecici8;
					}
					else if( (favseriesdisplay[t].months == favseriesdisplay[a].months) && (favseriesdisplay[a].days == favseriesdisplay[t].days) && ( (favseriesdisplay[t].year == favseriesdisplay[a].year) && ((favseriesdisplay[a].slott == "evening" && favseriesdisplay[t].slott == "night") || (favseriesdisplay[a].slott =="morning" && favseriesdisplay[t].slott == "evening") || (favseriesdisplay[a].slott == "morning" && favseriesdisplay[t].slott == "night" ) || (favseriesdisplay[a].slott == "morning" && favseriesdisplay[t].slott == "afternoon" )|| (favseriesdisplay[a].slott == "afternoon" && favseriesdisplay[t].slott == "evening" ) || (favseriesdisplay[a].slott == "afternoon" && favseriesdisplay[t].slott == "night" ))))
					{
						 int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = favseriesdisplay[t].months;         // swap min and k-th elements
								favseriesdisplay[t].months = favseriesdisplay[a].months;
								favseriesdisplay[a].months = gecici;
								gecici2 = favseriesdisplay[t].days;         // swap min and k-th elements
								favseriesdisplay[t].days = favseriesdisplay[a].days;
								favseriesdisplay[a].days = gecici2;
								gecici3 = favseriesdisplay[t].slott;         // swap min and k-th elements
								favseriesdisplay[t].slott = favseriesdisplay[a].slott;
								favseriesdisplay[a].slott = gecici3;
								gecici4 = favseriesdisplay[t].code;         // swap min and k-th elements
								favseriesdisplay[t].code = favseriesdisplay[a].code;
								favseriesdisplay[a].code = gecici4;
								gecici5 = favseriesdisplay[t].year;         // swap min and k-th elements
								favseriesdisplay[t].year = favseriesdisplay[a].year;
								favseriesdisplay[a].year = gecici5;
								gecici6 = favseriesdisplay[t].episoden;         // swap min and k-th elements
								favseriesdisplay[t].episoden = favseriesdisplay[a].episoden;
								favseriesdisplay[a].episoden = gecici6;
								gecici7 = favseriesdisplay[t].serien;         // swap min and k-th elements
								favseriesdisplay[t].serien = favseriesdisplay[a].serien;
								favseriesdisplay[a].serien = gecici7;
								gecici8 = favseriesdisplay[t].monthname;         // swap min and k-th elements
								favseriesdisplay[t].monthname = favseriesdisplay[a].monthname;
								favseriesdisplay[a].monthname = gecici8;
								
					}
					else if( favseriesdisplay[t].months == favseriesdisplay[a].months && favseriesdisplay[a].days == favseriesdisplay[t].days && favseriesdisplay[a].slott.at(0) == favseriesdisplay[t].slott.at(0) && favseriesdisplay[a].code < favseriesdisplay[t].code && favseriesdisplay[t].year == favseriesdisplay[a].year)
					{ 
						       int gecici , gecici2 , gecici4 , gecici5 ;
								string gecici3 , gecici6 , gecici7 , gecici8;
								
								gecici = favseriesdisplay[t].months;         // swap min and k-th elements
								favseriesdisplay[t].months = favseriesdisplay[a].months;
								favseriesdisplay[a].months = gecici;
								gecici2 = favseriesdisplay[t].days;         // swap min and k-th elements
								favseriesdisplay[t].days = favseriesdisplay[a].days;
								favseriesdisplay[a].days = gecici2;
								gecici3 = favseriesdisplay[t].slott;         // swap min and k-th elements
								favseriesdisplay[t].slott = favseriesdisplay[a].slott;
								favseriesdisplay[a].slott = gecici3;
								gecici4 = favseriesdisplay[t].code;         // swap min and k-th elements
								favseriesdisplay[t].code = favseriesdisplay[a].code;
								favseriesdisplay[a].code = gecici4;
								gecici5 = favseriesdisplay[t].year;         // swap min and k-th elements
								favseriesdisplay[t].year = favseriesdisplay[a].year;
								favseriesdisplay[a].year = gecici5;
								gecici6 = favseriesdisplay[t].episoden;         // swap min and k-th elements
								favseriesdisplay[t].episoden = favseriesdisplay[a].episoden;
								favseriesdisplay[a].episoden = gecici6;
								gecici7 = favseriesdisplay[t].serien;         // swap min and k-th elements
								favseriesdisplay[t].serien = favseriesdisplay[a].serien;
								favseriesdisplay[a].serien = gecici7;
								gecici8 = favseriesdisplay[t].monthname;         // swap min and k-th elements
								favseriesdisplay[t].monthname = favseriesdisplay[a].monthname;
								favseriesdisplay[a].monthname = gecici8;
								
					}

	 			}
			}
				
				for( int k = 0 ; k < favseriesdisplay.size() ; k++)
				{
					if( favseriesdisplay[k].serien.find("i") != string::npos ){
						for( int m = 0 ; m < favseriesdisplay[k].serien.length() ; m++)
						{
							if( favseriesdisplay[k].serien.at(m) == 'i' )
								favseriesdisplay[k].serien.at(m) = 'I';
						}
					}
			
					ToUpper(favseriesdisplay[k].serien) ;
					ToUpper(favseriesdisplay[k].episoden) ;
					ToUpper(favseriesdisplay[k].slott) ;
					cout << favseriesdisplay[k].code << "," << favseriesdisplay[k].serien << "," << favseriesdisplay[k].episoden << "," << favseriesdisplay[k].monthname << " " << favseriesdisplay[k].days << " " << favseriesdisplay[k].year << "," << favseriesdisplay[k].slott << endl;
				}
			 
		     

}

void FavoriteSeries ::displayFavoriteActors() const
{

			vector <string> actornames ;
	        for( int t = 0 ; t < favSeries.size() ; t++)
			{
				for(int k = 0 ; k < favSeries[t].actorNames.size(); k++ )
				{
					actornames.push_back( favSeries[t].actorNames[k]) ;
				}

			}

			vector < foractordisplay > forthelast ;
			for(int x = 0 ; x < actornames.size() ; x++)
			{
				if( actornames[x] != "a" ) {
					int count = 0 ;
					for(int a = 0 ; a < actornames.size() ; a++ )
					{
						if( actornames[x] == actornames[a] & count == 0 )
						{
							count += 1 ;
						}
						else if( actornames[x] == actornames[a] & count != 0)
						{
							count += 1 ;	
							actornames[a] = "a" ;
						}
					}
					foractordisplay deniyorum ;
					deniyorum.countofrole = count ;
					deniyorum.thenameofactor = actornames[x] ;
					forthelast.push_back(deniyorum) ;
				}
			}
            
            
			for(int y = 0 ; y < forthelast.size() ; y++)
			{
				for(int m = y+1 ; m < forthelast.size() ; m++)
				{
					if( forthelast[m].countofrole > forthelast[y].countofrole){
							    int gecici ;
								string temp ;
						        gecici = forthelast[y].countofrole;         // swap min and k-th elements
								forthelast[y].countofrole = forthelast[m].countofrole;
								forthelast[m].countofrole = gecici;
								temp = forthelast[y].thenameofactor;         // swap min and k-th elements
								forthelast[y].thenameofactor = forthelast[m].thenameofactor;
								forthelast[m].thenameofactor = temp;
					}

					else if( forthelast[m].countofrole == forthelast[y].countofrole )
					{
					        string name1 = forthelast[m].thenameofactor ;
							string name2 = forthelast[y].thenameofactor ;
							ToUpper(name1) ;
							ToUpper(name2) ;
							if( name1 < name2) {
							    int gecici ;
								string temp ;
						        gecici = forthelast[y].countofrole;        
								forthelast[y].countofrole = forthelast[m].countofrole;
								forthelast[m].countofrole = gecici;
								temp = forthelast[y].thenameofactor;         
								forthelast[y].thenameofactor = forthelast[m].thenameofactor;
								forthelast[m].thenameofactor = temp;
						 }
						 
					}
					
				}

				
			}
				for(int d = 0 ; d < forthelast.size() ; d++){
					ToUpper( forthelast[d].thenameofactor ) ;
					cout << forthelast[d].thenameofactor << ": "<< forthelast[d].countofrole << endl ;
				}

			
}





