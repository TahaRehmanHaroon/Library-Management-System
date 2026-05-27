# include <iostream>
# include <fstream>
# include <windows.h>

using namespace std; 

  void greeting(); 
  void userlogin();  
  void signup();
  void usermenu(); 
  void donation(); 
  void pending(); 
  void duration(); 
  void search_book(); 
  void recommendations(); 
  void educational(); 
  void fantasy(); 

  
  void adminmenu();
  void donationcheck();
  void durationcheck();
  void pendingcheck();

int main(){
    system("Color 03");
    int loginchoice=0, choiceloop1;

    greeting();

    cout << " --------------------LOGIN--------------------"<<endl;
    cout << " 1. Admin\n 2. User"<<endl;
    cout << " ";
    cin >> loginchoice;

    switch (loginchoice){

        case 1:
        break;

        case 2:
        signup();
        userlogin();
        break;

        default:
        cout << " Choose a valid option!"<<endl;
        break;

    }

    if (loginchoice == 1){
        adminmenu();
    }
    else if (loginchoice == 2){
        usermenu();
    }

    return 0;
}

void greeting(){
    cout << "             Welcome to our Library!\n You will be facilitated with numerous services"<<endl;
};

void  userlogin(){
    system("CLS");

    ifstream passsearch("credentials.txt"), namesearch("credentials.txt"), linescount("credentials.txt");
    string store, id, password, userpass, name, lines;
    int counter=0;
    bool loopbreak = true;

    cout << " --------------------USER LOGIN--------------------"<<endl;

    cout << " Enter your id: ";
    cin >> id; 

    while(getline(linescount, lines)){
        counter++;
    }

    for (int i=1 ; i<=counter ; i++){
        passsearch >> store;
        namesearch >> name;
    
        if (store == id){
            for (int j=1; j<2; j++){
                namesearch >> name;
            }
            for (int j=1; j<3; j++){
                passsearch >> password;
            }
            break;
        }
    }

do {
    cout << " Enter password: ";
    cin >> userpass;

    if (userpass == password){
        cout << " Login Successful!"<<endl;
        cout << " Welcome "<<name<<" :)"<<endl;
        loopbreak = false;
    }
    
    else {
        cout << " Incorrect Password. Try again!"<<endl;
    }
} while (loopbreak == true);

passsearch.close();
namesearch.close();
linescount.close();
    
};

void signup(){
    system("CLS");
    ifstream storeid("credentials.txt"), lines("credentials.txt");
    ofstream assign;
    assign.open("credentials.txt", ios :: app);

    string skipline, name, password, linescount;
    int userchoice=0, id, loopbreak=1, counter;

    while (getline(lines,linescount)){
        counter++;
    }
    for (int i=1; i<=counter;i++){
        if (i%3 == 1){
            storeid >> id;
            continue;
        }

        storeid >> skipline;
    }

    cout <<" - Enter 1 to Login\n - Enter 2 to SignUp"<<endl;
    cout << " ";
    cin >> userchoice;

    system("CLS");

    cout << " --------------------REGISTRATION--------------------"<<endl;
    
    if (userchoice == 2){
        cout << " Your id is: "<< id + 1 <<endl;
        assign << endl <<id + 1 << endl;
        cout << " Enter your first name: ";
        cin >> name;
        assign << name << endl;

    while (loopbreak !=0 ){
        cout << " Enter a 4-digit password: ";
        cin >> password;

        if (password.length() > 4 || password.length() < 4){
            cout << " Password should be 4-digits! Try again."<<endl;
        }
        else {
            cout << " Password accepted! Redirecting...."<<endl;
            Sleep(1500);

            loopbreak = 0;
        }
    }
    assign << password << endl;

    }

    storeid.close();
    assign.close();

};

void  search_book(){
    ifstream findbook("availablebooks.txt");
    string bookname, search;
    int notavailable=1;

    cout << " Enter name of Book you want to search: ";
    cin.ignore();

    getline(cin, bookname);

    for (int i=0; i<bookname.length() ;i++){
        if (bookname[i] == 32){
            continue;
        }

        if (bookname[i] >= 65 && bookname[i] <=90){
            continue;
        }
        bookname[i] = bookname[i]-32;
    }
    
    do {
    if (search == bookname){
        cout << " Book is available! Redirecting...."<<endl;
        Sleep(1500);
        system("CLS");
        duration();
        notavailable = 0;
        break;
    } 
    }while (getline(findbook,search));

    if (notavailable == 1){
        cout << " Book is not available. Redirecting...."<<endl;
        Sleep(1500);
        system("CLS");
    }
    
}
    
void  duration(){

    string days, id;

    cout << " Enter your ID"<<endl;
    cout << " ";
    getline(cin,id);

    cout << " Enter the amount of days you want to borrow for"<<endl;
    cout << " ";
    getline(cin,days);

    ofstream writedays;
    writedays.open("days.txt",ios :: app);

    writedays << "User id: "<< id << endl;
    writedays << "Borrowed a book for "<<days<<" days " << endl;

    cout <<" You information is recieved!\n Redirecting...."<<endl;

    Sleep(2500);
    system("CLS");
};

void  recommendations(){
    int choice=3;
    do {
    cout << " What type of Book would you like?" << endl;
    cout << " - Enter 1 for Fantasy\n - Enter 2 for Educational\n - Enter 0 to Exit to Main Menu"<<endl;
    cout << " ";
    cin >> choice;

    switch (choice){
        case 1:
        system("CLS");
        fantasy();
        break;

        case 2:
        system("CLS");
        educational();
        break;

        case 0:
        break;

        default:
        system("CLS");
        cout << " Choose a valid option!"<<endl;
        break;
    }
    } while (choice != 0);
    system("CLS");
    
};

void fantasy(){
    int genrechoice=0, availability=0;
    string storeanddisplay, filename, genre, choosebook; 
    cout << " - Enter 1 for Fictional\n - Enter 2 for Novels\n - Enter 3 for Horror\n - Enter 4 for Sci-Fi\n - Enter 5 for Thriller"<<endl;
    cout << " ";
    cin >> genrechoice;

    switch (genrechoice){
    case 1:
    filename = "fictional.txt";
    genre = "FICTIONAL";
    break;

    case 2:
    filename = "novels.txt";
    genre = "NOVEL";
    break;

    case 3:
    filename = "horror.txt";
    genre = "HORROR";
    break;

    case 4:
    filename = "scifi.txt";
    genre = "SCI-FI";
    break;

    case 5:
    filename = "thriller.txt";
    genre = "THRILLER";
    break;

    }

    system("CLS");

    ifstream displaybooks(filename);
    cout << "            "<< genre << " BOOKS"<< endl;
    cout << endl;

    while (getline (displaybooks, storeanddisplay )){
        cout << " - "<< storeanddisplay << endl;
    }

    displaybooks.close();

    bool runonce = true;
    cout << endl;
    TRY: cout <<" Enter full name of Book you want to choose"<<endl;
         cout <<" ";
    if (runonce == true ){
        cin.ignore();
        }

    getline(cin, choosebook);

    for (int i=0; i<choosebook.length() ;i++){
        if (choosebook[i] == 32){
            continue;
        }

        if (choosebook[i] >= 65 && choosebook[i] <=90){
            continue;
        }
       choosebook[i] = choosebook[i]-32;
    }
    
   ifstream matchname(filename);
   string check;

   while (getline(matchname , check)){
    if (check == choosebook){
        system("CLS");
        cout << " Book matched!" <<endl;
        availability = 1;
        duration();
        break;
    }
   }

   if (availability == 0){
    cout << " Entered name not found! Try again"<<endl;
    runonce = false;
    goto TRY;
   }

   matchname.close();
   
};

void  educational(){
    int subjectchoice=0, availability=0;
    string storeanddisplay, filename, subjectname, choosebook; 

    cout << " - Enter 1 Mathematics\n - Enter 2 for Computer Programming\n - Enter 3 for Physics\n - Enter 4 for Medical\n - Enter 5 for English"<<endl;
    cout << " ";
    cin >> subjectchoice;

    switch (subjectchoice){
    case 1:
    filename = "maths.txt";
    subjectname = "MATHEMATICS";
    break;

    case 2:
    filename = "computerprogramming.txt";
    subjectname = "COMPUTER PROGRAMMING";
    break;

    case 3:
    filename = "physics.txt";
    subjectname = "PHYSICS";
    break;

    case 4:
    filename = "medical.txt";
    subjectname = "MEDICAL";
    break;

    case 5:
    filename = "english.txt";
    subjectname = "ENGLISH";
    break;

    }

    system("CLS");

    ifstream displaybooks(filename);
    cout << "            " << subjectname << " BOOKS"<< endl;
    cout << endl;

    while (getline (displaybooks, storeanddisplay )){
        cout << " - " << storeanddisplay << endl;
    }

    displaybooks.close();

     bool runonce = true;
         cout << endl;
    TRY: cout <<" Enter full name of Book you want to choose"<<endl;
         cout <<" ";

    if (runonce == true ){
        cin.ignore();
        }

    getline(cin, choosebook);

    for (int i=0; i<choosebook.length() ;i++){
        if (choosebook[i] == 32){
            continue;
        }

        if (choosebook[i] >= 65 && choosebook[i] <=90){
            continue;
        }
       choosebook[i] = choosebook[i]-32;
    }
    
   ifstream matchname(filename);
   string check;

   while (getline(matchname , check)){
    if (check == choosebook){
        system("CLS");
        cout << " Book matched!" <<endl;
        availability = 1;
        duration();
        break;
    }
   }

   if (availability == 0){
    cout << " Entered name not found! Try again"<<endl;
    runonce = false;
    goto TRY;
   }

   matchname.close();
};

void  donation(){
    ofstream bookdonated;
    bookdonated.open("donation.txt", ios :: app);
    string write;

    cout << " Enter your ID"<<endl;
    cout << " ";
    cin.ignore();

    getline(cin, write);
    bookdonated << "Donor ID: "<< write <<endl;

    cout << " Enter name of book you want to donate"<<endl;
    cout << " ";
    getline(cin, write);
    bookdonated << "Book Donated: "<<write <<endl;

    bookdonated.close();

    cout << " Thank you for the donation!\n Redirecting...."<<endl;

    Sleep(2500);
    system("CLS");
};

void  pending(){
    string id, storenmatch, linecheck;
    ifstream pending_check("pendingbooks.txt"), lines("pendingbooks.txt");
    int sim=1, counter=0;

    cout << " Enter your ID"<<endl;
    cout << " ";
    cin >> id;

    while(getline(lines, linecheck)){
        counter++;
    }

    for (int i=1; i<=counter; i++){ 
        getline(pending_check,storenmatch);
        if (storenmatch == id){
            for (int j=1 ;j<=3 ;j++){
                getline(pending_check,storenmatch);
                cout << " - " <<storenmatch << endl;
            }
            break;
        }
    }
    cout << " Enter 0 to exit to Main Menu"<<endl;
    cout << " ";
    cin >> sim;
    
    system("CLS");
    pending_check.close();
    lines.close();
};

void usermenu(){
int userchoice;
do {

    cout <<" --------------------MENU--------------------"<<endl;

    cout << " - Enter 1 to Search from Available Books\n - Enter 2 for Book Recommendations\n - Enter 3 to Donate a Book\n - Enter 4 to Check Pending Books\n - Enter 0 to Exit "<<endl;
    cout << " ";
    cin >> userchoice;
    system("CLS");

    switch (userchoice){
        case 1:
        search_book();
        break;

        case 2:
        recommendations();
        break;

        case 3:
        donation();
        break;

        case 4:
        pending();
        case 0:
        break;

        default:
        cout << " Choose a valid option!"<<endl;
        break;

    }

    } while (userchoice != 0);
};

void adminmenu(){
    int adminchoice=0;

    do {
        system("CLS");
        
        cout << " - Enter 1 to Check Donations\n - Enter 2 to Check Duration Record \n - Enter 3 to Check All Pending Books\n - Enter 0 to Exit"<<endl;
        cout << " ";
        cin >> adminchoice;

        switch (adminchoice){
            case 1:
            donationcheck();
            break;

            case 2: 
            durationcheck();
            break;

            case 3:
            pendingcheck();
            break;

            case 0:
            break;

            default:
            cout << " Choose a valid option!";

        }
    } while (adminchoice != 0);
};

void donationcheck(){
    ifstream read("donation.txt");
    string store, dummy;

    system("CLS");

    while(getline(read,store)){
        cout <<" " << store << endl;
    }

    cout << " Enter 0 to Exit to Main Menu"<<endl;
    cout << " ";
    cin >> dummy;

    read.close();
    
};

void durationcheck(){
    ifstream read("days.txt");
    string store, dummy;

    system("CLS");

    while(getline(read,store)){
        cout << " "<<store << endl;
    }

    cout << " Enter 0 to Exit to Main Menu"<<endl;
    cout << " ";
    cin >> dummy;

    read.close();
    
};

void pendingcheck(){
    ifstream read("pendingbooks.txt");
    string store, dummy;

    system("CLS");

    while(getline(read,store)){
        cout << " "<<store << endl;
    }

    cout << " Enter 0 to Exit to Main Menu"<<endl;
    cout << " ";
    cin >> dummy;

    read.close();
    
};