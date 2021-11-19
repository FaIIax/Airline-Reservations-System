#include <iostream>

using namespace std;


char changeClass(char, int);  //function to print the boarding pass

void boarding_pass(int, int);  //function to get the input for yn variable(when customer choosing to change the class) in lowercase and check the input is valid or not


int main(){

  int seats[10]={0};  //array to represent seats.
  
  int i, count;  //i variable to use in for loops. count variable to check whether each class is full
  
  int section;  //to store prefred class(first or economoy).  
  
  char yn;  //toto store whether customer wants to change calss or not(in case if prefered class ifs full).
  
  bool availability = true;  //to choose to continue or not.
  //Untill availability is true main loop continues.
  
  while(availability){ 

    //printing the required input for each class and getting the input.
    cout<<"\n==Welcome==\n";
    cout<<"\nEnter 1 for first class\n";
    cout<<"Enter 2 for economy class\n";
    cout<<"\nEnter class: ";
    cin>>section;  //storing the input in section vaiablr

    //loop to check whether the input is anything other than 1 or 2.
    while(section!=1&&section!=2){
      cout<<"\nInvalid class number! Please select class again.\n";
      cout<<"Enter 1 for first class\n";
      cout<<"Enter 2 for economy class\n";
      cout<<"\nEnter class: ";
      cin>>section;
    }

    //if first class is chosen this statement will run.
    if(section==1){      
      count=0;

      //for loop checking fisrt five elements(which means first class seats).
      for(i=0; i<5; i++){        
        
        if(seats[i]==0){
          seats[i]=1;
          boarding_pass(i, section);  //print boarding pass.
          count+=1;  //increase count by 1 so if statement to change class won't run.
          break;
        }        
      }

      //if no seat is booked(which means the class is full).
      if(count==0){

        //for loop to check element 4 to 9(which means economy class).
        for(i=5; i<10; i++){           
          
          if(seats[i]==0){            
            cout<<"\nFirst class full. Dou you like to move to economy class(y,n): ";
            cin>>yn;
            yn=changeClass(yn, section);  //function to check input validity.          
            
            if(yn=='y'){
              seats[i]=1;
              boarding_pass(i, section+1);
              break;           
            }

            else if(yn=='n'){
              cout<<"\nNext flight leaves in 3 hours, Thank you.\n";
              break;
            }

          }
        }
      }
    }

    //if economy class is chosen this statement will run.
    if(section==2){
      count=0;
      
      for(i=5; i<10; i++){
        
        if(seats[i]==0){
          seats[i]=1;
          boarding_pass(i, section);
          count+=1;
          break;
        }
      }

      if(count==0){
        
        for(i=0; i<5; i++){
          
          if(seats[i]==0){
            cout<<"\nEconomy class full. Dou you like to move to first class(y,n): ";
            cin>>yn;
            yn=changeClass(yn, section);  
            
            if(yn=='y'){
              seats[i]=1;
              boarding_pass(i, section-1);
              break;
            }
            
            else if(yn=='n'){
              cout<<"\nNext flight leaves in 3 hours. Thank you.\n";
              break;            
            }

          }
        }
      }
    }

    //to end the program if all seats are full.
    if(seats[9]==1&&seats[4]==1){
      cout<<"\nAll seats are now booked.\n";
      cout<<"Next flight leaves in 3 hours. Thank you.\n"; 
      availability=false;
    }
    
  }

}


void boarding_pass(int seatno, int sectionno){
  cout<<"\n==Boarding pass==\n";
  
  if(sectionno==1){
    cout<<"Section: First Class\n";
  }
  
  else if(sectionno==2){
    cout<<"Section: Economy class\n";
  }
  
  cout<<"Seat no: "<<seatno+1<<endl;
  cout<<"Enjoy your flight!";
  cout<<endl;
}


char changeClass(char yesno, int section){
  yesno=tolower(yesno);  //to always change the input character to lowercase.

  //loop to check the input validity
  while(yesno!='y'&&yesno!='n'){
    cout<<"\nInvalid response! Please tell us your choice again.";
    
    if(section==1){
      cout<<"\nDo you like to move to economy class(y,n): ";
      cin>>yesno;
      yesno=tolower(yesno);   
    }

    else if(section==2){
      cout<<"\nDo you like to move to first class(y,n): ";
      cin>>yesno;
      yesno=tolower(yesno);
    }

  }
  return yesno;
}
