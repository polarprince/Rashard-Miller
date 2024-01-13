#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void concertDetails();
void ticketListFile(string name, int amountOfTickets);


int main() 
{

  int location, amount, more;
  int x = 0;
  double floorPrice = 120.00;
  double balconyPrice = 75.00;
  string name;


  // calling function to dislay concert details for user.
  concertDetails();

  cout << "What is your first and last name " << endl;
  getline(cin, name);
  

  while(x == 0)
  {
  cout << "Would you like balcony tickets, or floor tickets? " << endl
       << "For balcony type 1 , for floor type 2. " << endl;
  cin >> location;

  if(location != 1 && location != 2)
    {
      cout << "Invalid Input. Try Again. \n " << endl;
    }
    else 
      ++x;
  }


  switch(location)
  {
  //Balcony Ticket Purchase
   case 1:
      cout << fixed << showpoint << setprecision(2)
           << "Balcony Ticket Price: $" << balconyPrice << endl
           << "How many balcony tickets would you like? " << endl;
      cin >> amount;

      cout << "Balcony Tickets: " << amount << endl
           << "Total: $" << amount * 75.00 << endl;
      break;

  //Floor Ticket Purchase
   case 2:
      cout << "Floor Ticket Price: $" << floorPrice << endl
           << "How many floor tickets would you like? " << endl;
      cin >> amount;

      cout << "Floor Tickets: " << amount << endl
           << "Total: $" << amount * 120.00 << endl;
      break;
  }

//Creating an array to keep track of how many tickets sold.
  int ticketAvailability[100];
  

/*Testing to see if there are still tickets available.
If there are then then a one is placed in an array space to 
represent one ticket being sold.*/

  int counter = 0;
  if(ticketAvailability[100] == 1)
  {
    cout << "The concert is sold out." << endl;
  }
   else 
   {
    for(int z = 0; z <= 100; ++z)          // counter is intializedcremented each time
    {
      if(ticketAvailability[z] != 1)
      {
        if(counter <= amount)
        {
          ticketAvailability[z] = 1;
          ++counter;
        } 
      }

      if (counter > amount)
      {
        break;
      }
    }
   }


  /*Calling the function that will write the users 
  information to the file.*/
  if(ticketAvailability[100] != 1)
  {
    ticketListFile(name, amount);
  }
  
  //Possibility
  /*
  cout << "Would you like too purchase more tickets? " << endl
       << "Enter a 1 for yes, or a 2 for no. " << endl;
  cin >> more;
  
  if(more == 1)
    {
      cout << "Would you like balcony tickets, or floor tickets? " << endl
           << "For balcony type 1 , for floor type 2. " << endl;
      cin >> location;
    }
    else 
      ++x;  */

  return 0;
}


// Function for Displaying Event Details
  void concertDetails(){
    // Artist Performing
    string artistFirst = "Sam";
    string artistLast = "Cooke";

    // Concert Runtime
    int hours = 2;
    int minutes = 30;

    // Concert Time
    int clockhr = 8;
    int clockmin = 45;
    string morningNight = "pm";

    // Ticket Prices
    double floorPrice = 120.00;
    double balconyPrice = 75.00;

    cout << artistFirst << " " << artistLast << " at The Apollo! " << endl
         << "Venue Address: 253 W 125th St, New York, NY 10027 " << endl
         << "Concert Time: " << clockhr << ":" << clockmin << " " << morningNight << endl
         << "Concert Runtime: " << hours << " hours " << minutes << " minutes" << endl << endl
         << fixed << showpoint << setprecision(2)
         << "Ticket Price: \n \t Floor Ticket: $" << floorPrice << endl
         << "\t Balcony Ticket: $" << balconyPrice << endl << endl
         << "Concert Rules: \n \t Clear Bag Policy \n \t No Guns Allowed \n \t No outside food or drink. " << endl << endl;
  }



// Fuction for writing to the file
  void ticketListFile(string name, int amountOfTickets){

    ifstream inPut;
    ofstream outPut;

    inPut.open("TicketList.csv");
    outPut.open("TicketList.csv");

    outPut << name << " " <<  amountOfTickets;

    inPut.close();
    outPut.close();
    
  }