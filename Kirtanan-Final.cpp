/***
//// Last Build : date of submission
//// Compiler   : VS2022
//// Programmer : Kirtanan Rethi
//// Capability : Implementing a variable size record.
//// Function   : add,search, delete, modify, display records
***/


/////////////     Includes    /////////////

#include <cstdlib> // system()
#include <conio.h> // getch()
#include <fstream>
#include <sys\stat.h> // stat(status of a file)
#include <iostream>
#include<string>
using namespace std;


/////////////     Data types    /////////////


struct User_Record // User record; is the structName
{

  //define all variable after this line
  //30th January 2024
  string Name;
  string Age;
  string Nationality;
  string IdentificationCard;
  string PassportNumber;
  string ExpiryDate;
  string Country;
  char option;
  string Gender;
  string PhoneNumber;
  string EmailAddress;
  string DateOfRegistration;
  string CourseName;
  int semester;
  string Coursecode;
  int Credithours;
  string Grade;
  float GPA;
  float CGPA;
  string numofsub;






  //Don't touch after this line
  bool deleted;
};


/////////////     Variable Declarations & Constants /////////////

#define User_FILE_NAME "User.txt" // name of the database file to store User informations

User_Record User; //variable declaration of User
char     choice; // for choice in menu
fstream* fs = NULL, * fs1 = NULL;// file streams for files : fs -> 'User', fs1 -> 'temp'
bool     deletion = false; // if any record has been deleted


/////////////     Function Prototypes    /////////////

void closeFile(fstream*); // closes a file with its pointer, then deletes the file pointer
bool isFileExist(const char*); // check if a file exists

//Function prototypes
bool isValidEmail(const string & email);

/////////////     Main    /////////////
int main()
{
  while (true)
  {
    do ////// Menu //////
    {
      system("cls"); // clear screen

      cout << "\n    < User Database > \n\n";
      cout << "(1) Add     a new Record \n";
      cout << "(2) Search an existing Record\n";
      cout << "(3) Update an existing Record\n";
      cout << "(4) Delete an existing Record \n";
      cout << "(5) Display Records \n";
      cout << "(6) Exit \n\n";
      cout << " Enter a choice (1-6) : " << flush;
      choice = _getch();
    } while (choice < '1'  choice > '6'); // while we have no good(between 1 and 5), show menu again

    system("cls");

    // to modify, delete or display records, database file should exist, then we have some records           
    if (choice == '2'  choice == '3'  choice == '4'  choice == '5')
    {
      if (!isFileExist(User_FILE_NAME)) // if database file doesn't exist
      {
        cout << "\n Database file ('" << User_FILE_NAME << "') doesn't exist, then there are no records." << endl;
        system("pause");
        continue; // show the menu again
      }
    }

    switch (choice)
    {
      long long int recs_num; // number of records before the record for modifying(deletion)
      int id;

    case '1': ////// Add Record //////

      cout << "\n\t\t < Entering a new record > ";
      cout << "\n   Enter the following informations for the new record : ";
      //30th January 2024
      cout << endl;
      cout << "1) Name :";
      getline(cin, User.Name);//getline only for string data type
      while
        (User.Name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
      {
        cout << "\nInvalid Input!Please Enter In A Valid Name!" << endl;
        cout << "Name :";
        getline(cin, User.Name);
      }
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "3)" << "Age:";
      cin >> User.Age;
      while (User.Age.find_first_of("123456789") == string::npos)
      {
        cout << "\n\t\t Invalid Input! Please Enter a valid Age" << endl;
        cout << "\t\t Age          ";
      }
      cout << "-----------------------------------------------------------------------------" << endl;
      cout << "4) Nationality : " << endl;
      cout << "\tA. Malaysian" << endl;
      cout << "\tB. International" << endl;

      cout << "Enter a choice : " << endl;
      cin >> User.Nationality;

      while ((User.Nationality != "A") && (User.Nationality != "B"))
      {
        cout << "Please enter again!" << endl;
        cout << "Enter a choice(A or B):";
        cin >> User.Nationality;
      }
      if (User.Nationality == "A") {
        User.Nationality = "Malaysian";
        cout << "Nationality: Malaysian" << endl;

        cout << "5)" << "Idendification Card : ";
        cin >> User.IdentificationCard;
        cout << "  IdendificationCard:" << User.IdentificationCard << endl;
        cout << "---------------------------------------------------------------------" << endl;
      }

      else if (User.Nationality == "B") {
        User.Nationality = "International";
        cout << "Nationality: International" << endl;
        cout << "\n";

        cout << "6)" << "PassportNumber (Ex.A123456789):"; 
        cin >> User.PassportNumber;
        cout << "  Expiry Date: " << User.ExpiryDate;
        cin >> User.ExpiryDate;
        cout << "  Country: " << User.Country;
        cin >> User.Country;
        cout << "---------------------------------------------------------------------" << endl;
      }

      cout << "7)" << "Gender:";
      cout << "Enter a Choice:" << endl;
      cout << "Write (A)Male or (B)Female: ";
      cin >> User.Gender;
      while ((User.Gender != "A") && (User.Gender != "B"))
      {
        cout << "Please enter again." << endl;
        cout << "Enter a choice (A or B):";
        cin >> User.Gender;
      }
      if (User.Gender == "A")
      {
        User.Gender = "Male";
      }
      if (User.Gender == "B")
      {
        User.Gender = "Female";
      }
      cout << "Gender:" << User.Gender << endl;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "8)" << "PhoneNumber";
      cin.ignore();
      getline (cin, User.PhoneNumber);
      while (User.PhoneNumber.size() != 10)  (User.PhoneNumber.find_first_of("0169802110") == string::npos);
      {
        cout << "\nInvalid Input! Please Enter in a valid Phone Nuumber" << endl;
        cout << "Phone Number           ";
        getline(cin, User.PhoneNumber);
      }
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "4) EmailAddress :";
      cin >> User.EmailAddress;
      while (! isValidEmail (User.EmailAddress)) {
        cout << "Invalid email address! Please enter a valid email address: ";
        cin >> User.EmailAddress;
      }
      cout << "---------------------------------------------------------------------" << endl;

      cout << "5) DateOfRegistration(DD-MM-YYYY):";
      cin >> User.DateOfRegistration;
      cout << "  From: " << User.DateOfRegistration << endl;
      cout << "---------------------------------------------------------------------" << endl;

      cout << "6)" << "CourseName:" << "(Ex:CFIT = FOUNDATION IN IT) : ";
      cin >> User.CourseName;
      cout << "CourseName:" << User.CourseName << endl;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "7)" << "Semester: ";
      cin >> User.semester;
      cout << "CourseName:" << User.CourseName << endl;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "8)" << "Coursecode: " << endl;
      cout << "How much subjects do you have? " << endl;
      cin >> User.numofsub;

      while ((User.numofsub != "1") && (User.numofsub != "2") && (User.numofsub!= "3") 
			      && (User.numofsub != "4 ") & (User.numofsub != "5 ")) {
					
					cout << "Invalid choice! Please select 1, 2, 3, 4 or 5" << endl;
                    cout << "Enter a choice( 1/2/3/4/5 ): ";
                    cin >> User.numofsub;
				}

				if (User.numofsub == "1") {
                    cout << "i)";
                    cin >> User.Coursecode;
                }
				if (User.numofsub == "2") {
                    cout << "i)";
                    cin >> User.Coursecode;
                    cout << "ii)";
                    cin >> User.Coursecode;
                }
                if (User.numofsub == "3") {
                    cout << "i)";
                    cin >> User.Coursecode;
                    cout << "ii)";
                    cin >> User.Coursecode;
                    cout << "iii)";
                    cin >> User.Coursecode;
                }
                if (User.numofsub == "4") {
                    cout << "i)";
                    cin >> User.Coursecode;
                    cout << "ii)";
                    cin >> User.Coursecode;
                    cout << "iii)";
                    cin >> User.Coursecode;
                    cout << "iv)";
                    cin >> User.Coursecode;
                }
                if (User.numofsub == "5") {
                    cout << "i)";
                    cin >> User.Coursecode;
                    cout << "ii)";
                    cin >> User.Coursecode;
                    cout << "iii)";
                    cin >> User.Coursecode;
                    cout << "iv)";
                    cin >> User.Coursecode;
                    cout << "v)";
                    cin >> User.Coursecode;
                }
      
      cout << "-----------------------------------------------------------------------------" << endl;
      cout << "9)" << "Credithours" << endl;
      cout << "Write 0 if you have subjects less than 5. " << endl;
      cout << "i)";
      cin >> User.Credithours;
      cout << "ii)";
      cin >> User.Credithours;
      cout << "iii)";
      cin >> User.Credithours;
      cout << "iv)";
      cin >> User.Credithours;
      cout << "v)";
      cin >> User.Credithours;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "10)" << "Grade" << endl;
      cout << "Write - if you have subjects less than 5. " << endl;
      cout << "i)" << "Subject 1: ";
      cin >> User.Grade;
      cout << "ii)" << "Subject 2: ";
      cin >> User.Grade;
      cout << "iii)" << "Subject 3: ";
      cin >> User.Grade;
      cout << "iv)" << "Subject 4: ";
      cin >> User.Grade;
      cout << "v)" << "Subject 5: ";
      cin >> User.Grade;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "11)" << "GPA: ";
      cin >> User.GPA;
      cout << "GPA:" << User.GPA << endl;
      cout << "-----------------------------------------------------------------------------" << endl;

      cout << "12)" << "CGPA:";
      cin >> User.CGPA;
      cout << "CGPA:" << User.CGPA << endl;
      cout << "-----------------------------------------------------------------------------" << endl;


      //Don't touch after this line

      User.deleted = 0;

      fs = new fstream(User_FILE_NAME, ios::out | ios::app | ios::binary);

      if (!fs)
      {
        cout << "\n Can't open or create '" << User_FILE_NAME << "' file" << endl;
        system("pause");
        break;
      }

      fs->write((char*)&User, sizeof(User));

      closeFile(fs);

      cout << "\n Record added." << endl;
      system("pause");

      break;
      /*
          case '2': ////// Search Record //////

          case '3': ////// Modify Record //////

            cout << "\n Enter User ID, that you want modify its informatin : ";
            cin >> id;

            fs = new fstream(User_FILE_NAME, ios::in | ios::out | ios::binary);

            if (!fs)
            {
              cout << "\n Can't open or create '" << User_FILE_NAME << "' file" << endl;
              system("pause");

              break;
            }

            recs_num = -1;

            while (fs->read((char*)&User, sizeof(User)))
            {
              recs_num++;

              if (User.ID == id && !User.deleted)
                break;
            }
            if (fs->eof()) // if (the record is not in the file  it's there but it's deleted)
            {
              cout << "\n Your specified User doesn't exist in file." << endl;
              closeFile(fs);
              system("pause");
              break;
            }


            cout << "\n   Enter new informations for this record : ";
            cout << "\n\n PAY_TYPE ( SALARIED : 0, HOURLY : 1 ) : ";
            cin >> User.PAY_TYPE;

            cout << "\n ID : ";
            cin >> User.ID;
            cout << "\n AGE : ";
            cin >> User.AGE;
            cout << "\n DEPT (one character) : ";
            cin >> User.DEPT;

            if (User.PAY_TYPE == SALARIED)
            {
              cout << "\n MONTHLY_RATE : ";
              cin >> User.MONTHLY_RATE;
              cout << "\n START_DATE : ";
              cin >> User.START_DATE;
            }

            if (User.PAY_TYPE == HOURLY)
            {
              cout << "\n RATE_PER_HOUR : ";
              cin >> User.RATE_PER_HOUR;
              cout << "\n REG_HOURS : ";
              cin >> User.REG_HOURS;
              cout << "\n OVERTIME_HOURS : ";
              cin >> User.OVERTIME_HOURS;
            }


            fs->seekp(sizeof(User) * recs_num, ios::beg); // go to the first of the record to be modified
            fs->write((char*)&User, sizeof(User));

            closeFile(fs);

            cout << "\n Record is modified." << endl;
            system("pause");

            break;


          case '4': ////// Delete Record //////

            cout << "\n Enter User's ID, for deletion : ";
            cin >> id;

            fs = new fstream(User_FILE_NAME, ios::in | ios::out | ios::binary);

            if (!fs)
            {
              cout << "\n Can't open or create '" << User_FILE_NAME << "' file." << endl;
              system("pause");
              break;
            }

            recs_num = -1;

            while (fs->read((char*)&User, sizeof(User)))
            {
              recs_num++;

              if (User.ID == id && !User.deleted) // if User deleted an User then added another one with the same ID in the same instance of program runs, deleted User is still there, then we should go through all the file
                break;
            }

            if (fs->eof()) // if (the record is not in the file  it's there but it's deleted)
            {
              cout << "\n Your specified User doesn't exist in database file." << endl;
              closeFile(fs);
              system("pause");
              break;
            }

            User.deleted = 1;

            fs->seekp(sizeof(User) * recs_num, ios::beg);
            fs->write((char*)&User, sizeof(User));

            closeFile(fs);

            deletion = true; // we have some deleted records

            cout << "\n Record is deleted." << endl;
            system("pause");

            break;


          case '4': // Display Records

            ////// Print Salaried records...
            fs = new fstream(User_FILE_NAME, ios::in | ios::binary);

            if (!fs)
            {
              cout << "\n Can't open or create '" << User_FILE_NAME << "' file." << endl;
              system("pause");
              break;
            }

            // display column titles
            cout << "\n\t\t < Salaried >\n\n";
            cout << "ID\tAGE\tDEPT\tMONTHLY_RATE\tSTART_DATE\n"
              << "-------------------------------------------------- \n";

            while (fs->read((char*)&User, sizeof(User))) // display records
            {
              if (User.PAY_TYPE == SALARIED && !User.deleted)
              {
                cout << User.ID << '\t';
                cout << User.AGE << '\t';
                cout << User.DEPT << '\t';
                cout << User.MONTHLY_RATE << "\t\t";
                cout << User.START_DATE << '\n';
              }
            }

            cout << "\n To see Hourly records, "; system("pause");

            closeFile(fs);

            ////// Print Hourly records...
            system("cls");
            fs = new fstream(User_FILE_NAME, ios::in | ios::binary);

            if (!fs)
            {
              cout << "\n Can't open or create '" << User_FILE_NAME << "' file." << endl;
              system("pause");
              break;
            }

            cout << "\n\t\t\t < Hourly > \n\n";
            cout << "ID\tAGE\tDEPT\tRATE_PER_HOUR\tREG_HOURS\tOVERTIME_HOURS\n"
              << "---------------------------------------------------------------------- \n";

            while (fs->read((char*)&User, sizeof(User_Record)))
            {
              if (User.PAY_TYPE == HOURLY && !User.deleted)
              {
                cout << User.ID << '\t';
                cout << User.AGE << '\t';
                cout << User.DEPT << '\t';
                cout << User.RATE_PER_HOUR << "\t\t";
                cout << User.REG_HOURS << "\t\t";
                cout << .OVERTIME_HOURS << '\n';
              }
            }

            cout << "\n To see menu, "; system("pause");

            closeFile(fs);

            break;


      */
    case '6': // Exit

      if (deletion) // if there is any deletion, then update database file (create a new temp file that doesn't have deleted records, then remove the old database file and rename temp file to database file name)
      {
        cout << "\n Updating '" << User_FILE_NAME << "' File..." << endl;

        fs = new fstream(User_FILE_NAME, ios::in | ios::binary);
        if (!fs)
        {
          cout << "\n Can't open '" << User_FILE_NAME << "' file, then Updating is incomplete." << endl;
          system("pause");

          system("cls");
          return 1;
        }

        fs1 = new fstream("temp", ios::out | ios::binary);
        if (!fs1)
        {
          cout << "\n Can't create temp file, then Updating is incomplete." << endl;
          system("pause");

          closeFile(fs);
          system("cls");
          return 1;
        }

        // write nondeleted records to the temp file
        while (fs->read((char*)&User, sizeof(User)))
          if (!User.deleted)
            fs1->write((char*)&User, sizeof(User));

        closeFile(fs);
        closeFile(fs1);

        if (remove(User_FILE_NAME) == -1) // if there is an error
        {
          cout << "\n Can't delete '" << User_FILE_NAME << "' file, then Updating is incomplete." << endl;
          system("pause");

          system("cls");
          return 1;
        }


        struct stat st; // to check size of the temp file
        int res = stat("temp", &st);

        if (st.st_size == 0) // if all of records are deleted then the temp file size is zero                        
          remove("temp"); // we have no records, then no database file is needed, just delete the temp file
        else
          if (rename("temp", User_FILE_NAME))
          {
            cout << "\n Can't rename temp file, then Updating is incomplete." << endl;
            system("pause");

            system("cls");
            return 1;
          }

        cout << "\n Updating database file completed." << endl;
        system("pause");
      }

      system("cls");
      return 0;

      break;
    } // end 'switch'
  } // end 'while'

  return 0;
} // end 'main()'


/////////////     Function Definitions    /////////////

void closeFile(fstream* fs)
{
  fs->close(); // close the file
  delete fs;
  fs = NULL;
}


bool isFileExist(const char* file_name)
{
  struct stat st; // to check status of file
  int res = stat(file_name, &st);
  return (res == 0); // if file exists     
}
