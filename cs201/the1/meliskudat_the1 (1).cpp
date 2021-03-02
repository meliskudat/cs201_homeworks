#include <iostream>
#include <string>
using namespace std;

int main()
{
	string student_name, course_name, answer , grade , switch_chance , previous_grade , current_grade , selected_grade ;
	
	cout << "Welcome to the Fall 2020-2021 Semester grading system. What is your name? " ;
	cin >> student_name ;

    cout << "Hello " << student_name << "! Please enter the name of the course to be processed: ";
	cin >> course_name ;

	cout << "Hello " << student_name << "! If you take the " << course_name << " for the first time, enter YES otherwise NO: ";
	cin >> answer ;

	if(answer == "YES")
	{
	    cout << "What is your grade from (A,B,C,D,F)? ";
		cin >> grade ;
		if(grade == "A"|| grade == "B" || grade == "C" || grade =="D" )
		{
			cout << "Do you want to switch your grade from " << grade << " to S (YES or NO)? " ;
			cin >> switch_chance ;
			if(switch_chance == "NO")
			{
				cout << student_name << ", your final grade for " << course_name << " is " << grade << "." << " Goodbye..." << endl;
			}
			else if(switch_chance == "YES")
			{
				cout << student_name << ", your final grade for " << course_name << " is S. Goodbye..." << endl;

			}

			else
			{
				cout << "Invalid grade selection. Goodbye..." << endl;
			}
		
		
		}
        else if( grade == "F")
		{
			cout << "Do you want to switch your grade from F to U (YES or NO)? " ;
			cin >> switch_chance ;
			if(switch_chance == "YES")
			{
				cout << student_name << ", your final grade for " << course_name << " is U. Goodbye..." << endl ;

			}
		    else if(switch_chance == "NO")
			{
				cout << student_name << ", your final grade for " << course_name << " is F. Goodbye..." << endl;
			}
			else
			{
				cout << "Invalid grade selection. Goodbye..." << endl;
			}
	    }
        else 
	    {
			cout << "Invalid grade selection. Goodbye..." << endl;
		}
	}
    else if(answer == "NO")
	{
	   cout << "Please enter your previous grade from (A,B,C,D,F,S,U): " ;
	   cin >> previous_grade ;

	   if(previous_grade == "U")
	   {
		   cout << "Please enter your current grade from (A,B,C,D,F): " ;
		   cin >> current_grade ;
		   
		   if(current_grade == "A" || current_grade == "B" || current_grade == "C" || current_grade == "D")
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): " ;
			   cin >> selected_grade ;
				   if(selected_grade == "S")
				   {
					   cout << student_name << ", your final grade for " << course_name << " is S. Goodbye..." << endl ;
                   }
				   else if(selected_grade == current_grade)
				   {
					   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
				   }
				   else
				   {
					  cout << "Invalid grade selection. If you received U before, you may choose S or current letter grade." << endl ;
				   }
		   }
		   else if(current_grade == "F")
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade == "U")
			   {
					   cout << student_name << ", your final grade for " << course_name << " is U. Goodbye..." << endl ;
               }
			   else if(selected_grade == current_grade)
			   {
					   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
			   else
			   {
				cout << "Invalid grade selection. Goodbye..." << endl;
			   }
		   }
		   else
		   {
			   cout << " Invalid grade selection. Goodbye..." << endl ;
		   }
	   }
	   else if(previous_grade == "F")
	   {
		   cout << "Please enter your current grade from (A,B,C,D,F): " ;
		   cin >> current_grade ;
		   if(current_grade == "F")
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade != "F")
			   {
				   cout << "Invalid grade selection. If you received F before, and fail this semester, you get F." << endl;
			   }
			   else if(selected_grade == "F")
			   {
				    cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
			   
           }
		   else if(current_grade == "A" || current_grade == "B" || current_grade == "C" || current_grade == "D")
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade == current_grade)
			   {
				   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
			   else if( selected_grade >= current_grade || selected_grade <= current_grade ) 
			   {
				   cout << "Invalid grade selection. You cannot choose a higher or lower grade than you deserve. " << endl;
			   }
		   }
		   else
		   {
				cout << "Invalid grade selection. Goodbye..." << endl;
		   }
	   }
	   else if(previous_grade == "S")
	   {
		   cout << "Please enter your current grade from (A,B,C,D,F): " ;
		   cin >> current_grade ;
		   if(current_grade == "F")
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade != "F")
			   { 
				   cout << "Invalid grade selection. If you received S before and fail this semester, you get F." << endl;
			   }
			   else if(selected_grade == "F")
			   {
				    cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
		   }
		   else if( current_grade == "A" || current_grade == "B" || current_grade == "C" || current_grade == "D" )
		   {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade == current_grade)
			   {
				   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
			   else if( selected_grade == "S")
			   {
				   cout << student_name << ", your final grade for " << course_name << " is S. Goodbye..." << endl ;
			   }

			   else if( selected_grade >= current_grade || selected_grade <= current_grade ) 
			   {
				   cout << "Invalid grade selection. You cannot choose a higher or lower grade than you deserve. " << endl;
			   }
		      
		  }
		  else
		  {
				cout << "Invalid grade selection. Goodbye..." << endl;
		  }
	   }
	   else if(previous_grade == "A" || previous_grade == "B" || previous_grade == "C" || previous_grade == "D" )
	   {
		    cout << "Please enter your current grade from (A,B,C,D,F): " ;
		    cin >> current_grade ;
			if(current_grade == "F") 
			{
				cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			    cin >> selected_grade ;
			    if(selected_grade == "U") 
				{
				   cout << student_name << ", your final grade for " << course_name << " is U. Goodbye..." << endl ;
			    } 
	            else if( selected_grade == "F")
				{
				   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			    }
				else
			    {
				cout << "Invalid grade selection. Goodbye..." << endl;
			    }
			}
			else if(current_grade == "A" || current_grade == "B" || current_grade == "C" || current_grade == "D")
		    {
			   cout << "Please enter the grade you want to choose from (A,B,C,D,F,S,U): ";
			   cin >> selected_grade ;
			   if(selected_grade == current_grade)
			   {
				   cout << student_name << ", your final grade for " << course_name << " is " << current_grade << ". Goodbye..." << endl ;
			   }
			   else if( selected_grade == "S")
			   {
				   cout << student_name << ", your final grade for " << course_name << " is S. Goodbye..." << endl ;
			   }
			   
			   else if( selected_grade >= current_grade || selected_grade <= current_grade ) 
			   {
				   cout << "Invalid grade selection. You cannot choose a higher or lower grade than you deserve." << endl;
			   } 
			
			   else 
			   {
				cout << "Invalid grade selection. Goodbye..." << endl;
			   }
			}
            else
			{
				cout << "Invalid grade selection. Goodbye..." << endl;
			}
	   }
	   else
	   {
				cout << "Invalid grade selection. Goodbye..." << endl;
	   }
	   
	 }
  return 0 ;	 
  }	  

// melis kudat
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	 
