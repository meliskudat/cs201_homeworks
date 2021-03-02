#include <iostream>
#include <string>

using namespace std ;

bool InputCheck( string user_input )
{
	int i = 0 ;
	int a = user_input.length() ;
	char b = ' ' ;
	while (i < a )
	{
		if ( user_input.at(i) == b || ( 65 <= user_input.at(i) && user_input.at(i) <= 90 ) || (97 <= user_input.at(i) && user_input.at(i) <= 122 ) || '0' <= user_input.at(i) && user_input.at(i) <= '9' )
		{
		   i = i +1 ;
		   
		}
		else 
		{
			return false ;
		}

	}
	return true ;

}
string SourceStringEnd()
{
	string user_word ;
	cout << "Enter source string: " ;
	cin >> user_word ;
	string s = "" ;
	while(user_word != "end" && user_word != "END" )
	{
		s = s + user_word + " " ;
		cin >> user_word ;

	}
	s = s + user_word ;
	return s ;
}


string RemovedVersion (string input_search , char removed_one)
{
	string x = "" ;
	int a = input_search.length() ;
	for(int i = 0 ; i < a ; i++)
	{
		if (input_search.at(i) != removed_one)
		{
			x = x + input_search.at(i) ;
		}

	}
	return x ;

}

string PrintedSearchString( int starting_point , int ending_point , string for_source_string)
{
	string printed_word = "" ;
	for( int i = starting_point ; i < ending_point ; i++)
	{
		printed_word = printed_word + for_source_string.at(i) ;
		
	}
	return printed_word ;
}

int main()
{
	int  a , b;
	string s , search_string , search_string_without_punc ;
	s = SourceStringEnd() ;
	if ( InputCheck(s) == false)
    {
		while( InputCheck(s) == false ) 
		{
		   s = SourceStringEnd() ;  
		}
	}
	cout << "Enter search string: " ;
	cin >> search_string ;
	while(search_string != "quit" && search_string != "QUIT")
	{
		int x = search_string.length() ;
		
		if (search_string.at(x-1) == '+')
		{
			search_string_without_punc = RemovedVersion(search_string , '+' ) ;
		    a = s.find(search_string_without_punc) ;
			b = s.find(' ' , a) ;
			while( a!= -1)
			{	
				if( s.find(' ') == b && a == 0 )  // ilkse diye
				{
						{
						cout << "index: " << a << " word: " <<  PrintedSearchString(0 , b , s ) << endl ;
						}
				}
				else if ( s.at(a-1) == ' ') 
				{
					if ( b != -1)
					{
						int y = s.rfind(' ' , a) ;
						cout << "index: " << a << " word: " <<  PrintedSearchString(y+1 , b , s ) << endl;
					}
				}
			    
			a = s.find(search_string_without_punc, a+1) ;
			b = s.find(' ' , a) ;
			

			}
		}
		
		else if (search_string.at(x-1) == '.')
		{
			search_string_without_punc = RemovedVersion(search_string , '.' ) ;
		    int z = search_string_without_punc.length() ;
			a = s.find(search_string_without_punc) ;
			b = s.find(' ' , a) ;
			while( a != -1 )
			{
				if (( s.at(a+ z) == ' ') && ( s.find(' ' ) == b))  // ilk kelimeyse diye
				{
					cout << "index: " << a << " word: " <<  PrintedSearchString(0 , b , s ) << endl ;
				}
				
				else if ( s.at(a+ z) == ' ' && s.find(' ', a) == b) // ilk kelime degilse diye
				{  
					if ( b != -1)
					{
						int y = s.rfind(' ' , a) ;
						cout << "index: " << a << " word: " <<  PrintedSearchString( y+1 , b , s )  << endl ;
					}
			    }
            a = s.find(search_string_without_punc, a+1) ;
			b = s.find(' ' , a) ;
			}
		}
		
		else if(search_string.at(x-1) == '*' && search_string.at(x-2) != '*')
		{
			search_string_without_punc = RemovedVersion(search_string , '*' ) ;
		    a = s.find(search_string_without_punc) ;
			int z = search_string_without_punc.length() ;
			b = s.find(' ' , a) ;
			while( a != -1)
			{
				
				if( s.find(' ') == b && s.at(a + z) != ' ' && s.at(b-1) != s.at(a)) // ilk kelimeyse diye
				{
					cout << "index: " << a << " word: " <<  PrintedSearchString(0 , b , s ) << endl ;
				}
				else if( s.at(a-1) != ' ' && s.at(a + z) != ' ' && s.at(b-1) != s.at(a)) // ilk kelime degilse diye
				{
					if ( b != -1)
					{
						int y = s.rfind(' ' , a) ;
						cout << "index: " << a << " word: " <<  PrintedSearchString( y+1 , b , s )  << endl ;
				    }
				}
            a = s.find(search_string_without_punc, a+1) ;
			b = s.find(' ' , a) ;
			}
		}
		
		
		else if(search_string.at(x-1) == '*' && search_string.at(x-2) == '*')
		{
			search_string_without_punc = RemovedVersion(search_string , '*' ) ;
			
            a = s.find(search_string_without_punc) ;
			int z = search_string_without_punc.length() ;
			b = s.find(' ' , a) ;
			while(a != -1)
			{
				if( s.find(' ') == b)
				{
					cout << "index: " << a << " word: " <<  PrintedSearchString(0 , b , s ) << endl ;
				}
				else if( s.find(' ') != b ) // ilk kelime degilse diye
				{
					if ( b != -1)
					{
						int y = s.rfind(' ' , a) ;
						cout << "index: " << a << " word: " <<  PrintedSearchString( y+1 , b , s )  << endl ;
					}
				}
            a = s.find(search_string_without_punc, a+1) ;
			b = s.find(' ' , a) ;
			}
		}
        cout << "Enter search string: " ;  
        cin >> search_string ;
   }
   return 0 ;
}