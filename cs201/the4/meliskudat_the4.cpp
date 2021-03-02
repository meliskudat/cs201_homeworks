# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include "strutils.h"

using namespace std;


bool LastWord(string line, string word)
{
	int count = 0 ;
	int i = int ('a') ;
	int index = line.find(word) ;
	int word_length = word.length() ;
	while ( 'a' <= i && i <= 'z')
    {
		if( line.find(i , index + word_length ) != string::npos )
		{
		 return true;
		}
	    i += 1;
	}
	return false ;
	

}





int main()
{
	string wordpoll , maintext , line , word , search;
	int word_length ;
	char ch ;
	cout << "Please enter a filename for the word pool: " ;
	cin >> wordpoll ;
	ifstream fwordpoll ;
	fwordpoll.open(wordpoll) ;
	while ( fwordpoll.fail())
	{
		cout << "Cannot open the word pool file." << endl;
		cout << "Please enter a filename for the word pool: " ;
		cin >> wordpoll ;
		fwordpoll.open( wordpoll) ;
	}
	cout << "Please enter a filename for the main text: " ;
	cin >> maintext ;
	
	ifstream fmaintext ;
	fmaintext.open(maintext) ;
	while ( fmaintext.fail())
	{
		cout << "Cannot open the main text file." << endl;
		cout << "Please enter a filename for the main text: " ;
		cin >> maintext ;
		fmaintext.open(maintext.c_str()) ;
	}
	cout << "You may find the results below:" << endl ;
	cout << endl ;

	while( getline(fmaintext , line))
	{
		istringstream input(line) ;
		while(input >> word)
		{
			ToLower(word) ;
			word_length = word.length() ;
			int count ;
			int maxCount = 0 ;
			string maxRepeated = "" ;
			while(fwordpoll >> search)
			{
				ToLower(search) ;
				count = 0 ;
				
				int search_length = search.length() ;
				if( search_length == word_length)
				{
					for(int i = 0 ; i < search_length ; i++)
					{
					
						if(search[i] == word[i])
						{
							count += 1 ;
						}
					}
					if( count > maxCount)
					{
						maxCount = count ;
						maxRepeated = search ;
					}
					else if( count == maxCount && count!= 0)
					{
						maxRepeated = maxRepeated + "," + search ;
					}
					else if(count < maxCount)
					{
						maxCount = maxCount ;
					}

				}
				
			}
		
			fwordpoll.clear() ;
			fwordpoll.seekg(0) ;
			
			if( maxRepeated.find(",") != string::npos   )
			{
				if( word_length % 2 == 0 && maxCount >= double(word_length) / 2)
				{
					cout << "(" << maxRepeated << ")" ;
				}
				else if( word_length % 2 != 0 && maxCount > double(word_length) / 2)
				{
					cout << "(" << maxRepeated << ")" ;
				}
				else
				{
					cout << "{" << word << "}" ; 
				}

			}
			else if( maxCount == 0 || maxCount < double(word_length)/2)
			{
				cout << "{" << word << "}" ;
			}
			else
			{
				cout << maxRepeated ;
			}
		 
		    int index_word = line.find(word) ;	
			int length_line = line.length() ;
		    
			
			if( line.find( " " , index_word+1 )!= string::npos && LastWord(line,word) == true)
		    {
			   cout << " " ;
		    }
		 
		}
		cout << endl ;
	}

}				
