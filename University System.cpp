#include<iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Main { // by all team
public:
    void Add(string path)
    {

        fstream file;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format, ios_base::out | ios::app);
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string FIRSTNAME;
        string SURNAME;
        string ID;
        cin.ignore();

        while (!file.eof())
        {
            cout << "Enter  ID : ";
            getline(cin, ID);
            if (ID == "exit")
                break;
            while (ID.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
            }
            cout << "Enter First name : ";
            getline(cin, FIRSTNAME);
            if (FIRSTNAME == "exit")
                break;
            cout << "Enter Surname : ";
            getline(cin, SURNAME);
            if (SURNAME == "exit")
                break;

            firstname.push_back(FIRSTNAME);
            surname.push_back(SURNAME);
            id.push_back(ID);
        }
        cout << "\t\n-------------------------" << endl;
        cout << "\t\n||Data has been added ^,^||" << endl;
        cout << "\t\n-------------------------" << endl;
        for (int i = 0; i < firstname.size(); i++)
        {
            file << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();
    }
    void Show(string FilePath)
    {
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string inputfirstname;
        string inputsurname;
        string inputid;
        string file_format = ".txt", Disc_name;
        file.open(FilePath + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "==========================================" << endl;
        cout << "   Name   \t\  |         ID                " << endl;
        cout << "==========================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }
        file.close();
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
        }
        cout << "==========================================" << endl;
    }
    void Searching(string path)
    {
        string format = ".txt";
        ifstream fileInput;
        fileInput.open(path + format);
        string line, Search;
        int Choice;
        cout << "\t\n|1-  Search by ID         " << endl
            << "\t\n|2 - Search by Name      " << endl
            << "\t\n-------------------------" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Please enter the id to search: ";
            cin >> Search;
            while (Search.length() != 9)
            {
                cout << "Try agin , Please enter the term to search: ";
                cin >> Search;
            }
        }
        else if (Choice == 2)
        {
            cout << "Please enter the name to search: ";
            cin >> Search;
        }
        for (unsigned int curLine = 0; getline(fileInput, line); curLine++)
        {
            if (line.find(Search) != string::npos)
            {
                cout << "found: " << Search << " on line: " << curLine << endl
                    << line << endl;
            }
        }
    }
    void Backup()
    {
        fstream f1;
        fstream f2;
        string copy, transferbackup, Receivebackup;
        cout << "Enter the name of the file you want to back up :";
        cin >> transferbackup;
        f1.open(transferbackup + ".txt", ios::in);
        if (f1.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "Enter the path of the disk where you want to save the backup ,Format ( D:// ) : ";
        cin >> Receivebackup;

        f2.open(Receivebackup + "Backup.txt", ios::out);
        if (f2.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     Backup Done ! ^,^      ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||    Backup not Done ! :( ! ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (!f1.eof()) {

            getline(f1, copy);
            f2 << copy << endl;
        }
        f2.open(Receivebackup + "Backup.txt", ios::in);

        while (!f2.eof()) {
            getline(f2, copy);
        }
        f1.close();
        f2.close();
    }
    void Update(string path)
    {
        ifstream file;

        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        int i = 0;
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;

        while (file >> inputfirstname && file >> inputsurname && file >> inputid)
        {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }

        fstream fileSave;
        string search;

        string FIRSTNAME;
        string SURNAME;
        string ID;

        cout << "Search by id to update >> ";
        cin >> search;
        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {

            if (id[x] == search)
            {
                cout << "This Is The Data You Searched For >> ";
                cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
                cin.ignore();
                cout << "Enter ID : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                while (ID.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, ID);
                    if (ID == "exit")
                        break;
                }
                cout << "Enter First name : ";
                getline(cin, FIRSTNAME);
                if (FIRSTNAME == "exit")
                    break;
                cout << "Enter Surname : ";
                getline(cin, SURNAME);
                if (SURNAME == "exit")
                    break;

                id[x] = ID;
                firstname[x] = FIRSTNAME;
                surname[x] = SURNAME;
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Updated   ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Update Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < firstname.size(); i++)
        {
            fileSave << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();

    }
    void Delete(string path)
    {
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string inputfirstname;
        string inputsurname;
        string inputid;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        int i = 0;
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;

        while (file >> inputfirstname && file >> inputsurname && file >> inputid)
        {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }

        fstream fileSave;


        string search;

        string FIRSTNAME;
        string SURNAME;
        string ID;
        char choise;

        cout << "Search by id to delete >> ";
        cin >> search;
        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {
            if (id[x] == search)
            {
                cout << "This Data Will Be Deleted ! >> ";
                cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
                cout << "are you sure you want to delete this data?";
                cout << "Press y or Y to confirm: ";
                cin >> choise;
                if ((choise == 'y' || choise == 'Y'))
                {
                    id[x] = " ";
                    firstname[x] = " ";
                    surname[x] = " ";
                }
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Deleted!   ^,^   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Delete Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < firstname.size(); i++)
        {
            fileSave << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();
    }
    void DashBoard(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                Show(path);
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }
    void DashBoardAdmin(string path)
    {

        int choise;
        system("cls");
        do {
            cout << "\t\t==================================================\n";
            cout << "\t\t                 DashBoard Admin \n";
            cout << "\t\t==================================================\n\n";
            cout << "\t\t==================================================\n";
            cout << "\t\t Information of Technology (IT) Management System \n";
            cout << "\t\t==================================================\n\n";
            cout << "\t\t---------------------------------------------------\n";
            cout << "\t\t||\t\t1. Add  \t\t\t ||\n";
            cout << "\t\t||\t\t2. Display \t\t\t ||\n";
            cout << "\t\t||\t\t3. Search \t\t\t ||\n";
            cout << "\t\t||\t\t4. Delete                    \t ||\n";
            cout << "\t\t||\t\t5. Update \t\t         ||\n";
            cout << "\t\t||\t\t6. Backup \t\t         ||\n";
            cout << "\t\t||\t\t7. Exit\t\t\t\t ||\n";
            cout << "\t\t---------------------------------------------------\n";
            cout << "\nEnter Choice: ";
            cin >> choise;
            cout << "-----------------------" << endl;
            cin.ignore();
            if (choise == 1)
            {
                Add(path);
            }
            else if (choise == 2)
            {
                Show(path);
            }
            else if (choise == 3)
            {
                char  Try;
                do
                {
                    Searching(path);
                    cout << "If you want to search again enter y or Y : ";
                    cin >> Try;
                } while (Try == 'Y' || Try == 'y');
            }
            else if (choise == 6)
            {
                Backup();
            }
            else if (choise == 5)
            {
                Update(path);
            }
            else if (choise == 4)
            {
                Delete(path);
            }
            else
                break;
        } while (choise != 0);
        cout << "GoodBye :) ...! " << endl;

    }
};
class Doctor : public Main { // by R a w a n

public:
    void showDoctor(string path, string coursepath) {
        ifstream coursefile;
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        coursefile.open(coursepath + file_format);
        file.open(path + file_format);
        if (file.is_open() && coursefile.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }

        cout << "==============================================================================================" << endl;
        cout << "   Name   \t\  |         ID     |       Course name     |       CODE    |    Credit hours     " << endl;
        cout << "==============================================================================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);

        }
        file.close();

        string line;
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x];
            for (unsigned int curLine = 0; getline(coursefile, line); curLine++)
            {
                if (line.find(id[x]) != string::npos)
                {
                    cout << line << endl;
                }
                cout << endl;
            }
        }
        cout << "==========================================" << endl;
    }
    void DashBoardDoctor(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Main::Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Main::Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Main::Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Main::Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                showDoctor(path, "Datacourse");
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }


};
class demonstrator : public Main { // by Atef

public:
    void showDemonstrator(string path, string coursepath) {
        ifstream coursefile;
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        coursefile.open(coursepath + file_format);
        file.open(path + file_format);
        if (file.is_open() && coursefile.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }

        cout << "==============================================================================================" << endl;
        cout << "   Name   \t\  |         ID     |       Course name     |       CODE    |    Credit hours     " << endl;
        cout << "==============================================================================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);

        }
        file.close();

        string line;
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x];
            for (unsigned int curLine = 0; getline(coursefile, line); curLine++)
            {
                if (line.find(id[x]) != string::npos)
                {
                    cout << line << endl;
                }
                cout << endl;
            }
        }
        cout << "==========================================" << endl;
    }
    void DashBoardDemonstrator(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Main::Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Main::Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Main::Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Main::Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                showDemonstrator(path, "course");
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }


};
class student : public Main { // by sara

public:

};
class course : public Main { // by rashad , ramez
    // ofstream course + daoc + demonstartor  ;
public:
    void AddCourse(string path) {
        cout << endl << endl;
        /*   cout << "------------------------------------------" << endl;
           cout << "Please Enter The Course's Doctor Data: "<<endl;
           cout << "------------------------------------------"<<endl;
           Main::Add(pathDoc);
           cout << "------------------------------------------" << endl;
           cout << "Please Enter The Course's Demonstrator Data: "<<endl;
           cout << "------------------------------------------"<<endl;
           Main::Add(pathdem);*/
        cout << "------------------------------------------" << endl;
        cout << "Please Enter The Course Data: " << endl;
        cout << "------------------------------------------" << endl;

        fstream file;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format, ios_base::out | ios::app);
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , PLS Enter New name and code , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        string ID;
        string COURSENAME;
        string CREDITHOURS;
        vector<string> iddoctor;
        vector<string> iddemonstrator;
        string IDdoctor;
        string IDdemonstrator;

        cin.ignore();
        while (!file.eof())
        {
            cout << "Enter Course CODE : ";
            getline(cin, ID);
            if (ID == "exit")
                break;
            while (ID.length() != 6)
            {
                cout << "Try agin , Enter Course CODE : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
            }
            cout << "Enter Course name : ";
            getline(cin, COURSENAME);
            if (COURSENAME == "exit")
                break;
            cout << " Please Enter Course Credit Hours: ";
            getline(cin, CREDITHOURS);
            if (CREDITHOURS == "exit")
                break;

            cout << "Enter  ID of the doctor : ";
            getline(cin, IDdoctor);
            if (IDdoctor == "exit")
                break;
            while (IDdoctor.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, IDdoctor);
                if (IDdoctor == "exit")
                    break;
            }


            cout << "Enter  ID of the Demonstrator : ";
            getline(cin, IDdemonstrator);
            if (IDdemonstrator == "exit")
                break;
            while (IDdemonstrator.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, IDdemonstrator);
                if (IDdemonstrator == "exit")
                    break;
            }

            coursename.push_back(COURSENAME);
            credithours.push_back(CREDITHOURS);
            id.push_back(ID);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);

        }
        cout << "\t\n-------------------------" << endl;
        cout << "\t\n||Data has been added ^,^||" << endl;
        cout << "\t\n-------------------------" << endl;
        for (int i = 0; i < coursename.size(); i++)
        {
            file << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void ShowCourse(string FilePath)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;

        string ID;
        string COURSENAME;
        string CREDITHOURS;

        string file_format = ".txt", Disc_name;
        file.open(FilePath + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "====================================================" << endl;
        cout << "  Course name     |       CODE    |    Credit hours " << endl;
        cout << "====================================================" << endl;
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
        }
        file.close();
        for (int x = 0; x < id.size(); x++)
        {
            cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
        }
        cout << "=====================================================" << endl;
    }
    void SearchCourse(string path)
    {
        string format = ".txt";
        ifstream fileInput;
        fileInput.open(path + format);
        string line, Search;
        int Choice;
        cout << "\t\n|1-  Search by CODE         " << endl
            << "\t\n|2 - Search by Name      " << endl
            << "\t\n-------------------------" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Please enter the code to search: ";
            cin >> Search;
            while (Search.length() != 6)
            {
                cout << "Try agin , Please enter the term to search: ";
                cin >> Search;
            }
        }
        else if (Choice == 2)
        {
            cout << "Please enter the name to search: ";
            cin >> Search;
        }
        else
            cout << "Error , pls Enter 1 or 2 ";

        for (unsigned int curLine = 0; getline(fileInput, line); curLine++)
        {
            if (line.find(Search) != string::npos)
            {
                cout << "====================================================" << endl;
                cout << "found: " << Search << " on line: " << curLine << endl;
                cout << "====================================================" << endl;
                cout << "  Course name     |       CODE    |    Credit hours " << endl;
                cout << "====================================================" << endl;
                cout << line << endl;

            }
        }
        cout << "====================================================" << endl << endl;
    }
    void BackupCourse()
    {
        Main::Backup();
    }
    void UpdataCourse(string path)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        vector<string> iddoctor;
        vector<string> iddemonstrator;

        string ID;
        string COURSENAME;
        string CREDITHOURS;
        string IDdoctor;
        string IDdemonstrator;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS && file >> IDdoctor && file >> IDdemonstrator) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);
        }

        fstream fileSave;
        string search;

        cout << "Search by code to update >> ";
        cin >> search;

        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {

            if (id[x] == search)
            {
                cout << "This Is The Data You Searched For >> ";
                cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
                cin.ignore();
                cout << "Enter Course CODE : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                while (ID.length() != 6)
                {
                    cout << "Try agin , Enter Course CODE : ";
                    getline(cin, ID);
                    if (ID == "exit")
                        break;
                }
                cout << "Enter Course name : ";
                getline(cin, COURSENAME);
                if (COURSENAME == "exit")
                    break;
                cout << " Please Enter Course Credit Hours: ";
                getline(cin, CREDITHOURS);
                if (CREDITHOURS == "exit")
                    break;

                cout << "Enter  ID of the doctor : ";
                getline(cin, IDdoctor);
                if (IDdoctor == "exit")
                    break;
                while (IDdoctor.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, IDdoctor);
                    if (IDdoctor == "exit")
                        break;
                }


                cout << "Enter  ID of the Demonstrator : ";
                getline(cin, IDdemonstrator);
                if (IDdemonstrator == "exit")
                    break;
                while (IDdemonstrator.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, IDdemonstrator);
                    if (IDdemonstrator == "exit")
                        break;
                }

                id[x] = ID;
                coursename[x] = COURSENAME;
                credithours[x] = CREDITHOURS;
                iddoctor[x] = IDdoctor;
                iddemonstrator[x] = IDdemonstrator;
                break;
            }
        }
        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Updated   ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Update Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < coursename.size(); i++)
        {
            fileSave << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void DeleteCourse(string path)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        vector<string> iddoctor;
        vector<string> iddemonstrator;


        string ID;
        string COURSENAME;
        string CREDITHOURS;
        string IDdoctor;
        string IDdemonstrator;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS && file >> IDdoctor && file >> IDdemonstrator) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);
        }

        fstream fileSave;
        string search;

        char choise;
        cout << "Search by id to delete >> ";
        cin >> search;

        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {
            if (id[x] == search)
            {
                cout << "This Data Will Be Deleted ! >> ";
                cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
                cout << "are you sure you want to delete this data?";
                cout << "Press y or Y to confirm: ";
                cin >> choise;
                if ((choise == 'y' || choise == 'Y'))
                {
                    id[x] = " ";
                    coursename[x] = " ";
                    credithours[x] = " ";
                    iddoctor[x] = " ";
                    iddemonstrator[x] = " ";
                }
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Deleted!   ^,^   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Delete Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < coursename.size(); i++)
        {
            fileSave << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void courseDashBoard(string menu, string  path) {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new   " << menu << "      " << endl
                << "|   2- Search    " << menu << "      " << endl
                << "|   3- Update    " << menu << "       " << endl
                << "|   4- Delete    " << menu << "      " << endl
                << "|   5- Display   " << menu << "      " << endl
                << "|   6- Backup    " << menu << "      " << endl
                << "|   7- Exit                     " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                AddCourse(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                SearchCourse(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                UpdataCourse(path);
            }
            else if (option == 4) {
                cin.ignore();
                DeleteCourse(path);
            }
            else if (option == 5) {
                system("CLS");
                ShowCourse(path);
            }
            else if (option == 6) {
                system("CLS");
                BackupCourse();
            }
            else if (option == 7) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }
};

int main()
{
    //course c1;
    //c1.courseDashBoard("Course", "Datacourse");
    Doctor d1;

    d1.DashBoardDoctor("Doctor", "DataDoctor");


    return 0;
}//Al5er Gy :D
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Main { // by all team
public:
    void Add(string path)
    {

        fstream file;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format, ios_base::out | ios::app);
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string FIRSTNAME;
        string SURNAME;
        string ID;
        cin.ignore();

        while (!file.eof())
        {
            cout << "Enter  ID : ";
            getline(cin, ID);
            if (ID == "exit")
                break;
            while (ID.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
            }
            cout << "Enter First name : ";
            getline(cin, FIRSTNAME);
            if (FIRSTNAME == "exit")
                break;
            cout << "Enter Surname : ";
            getline(cin, SURNAME);
            if (SURNAME == "exit")
                break;

            firstname.push_back(FIRSTNAME);
            surname.push_back(SURNAME);
            id.push_back(ID);
        }
        cout << "\t\n-------------------------" << endl;
        cout << "\t\n||Data has been added ^,^||" << endl;
        cout << "\t\n-------------------------" << endl;
        for (int i = 0; i < firstname.size(); i++)
        {
            file << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();
    }
    void Show(string FilePath)
    {
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string inputfirstname;
        string inputsurname;
        string inputid;
        string file_format = ".txt", Disc_name;
        file.open(FilePath + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "==========================================" << endl;
        cout << "   Name   \t\  |         ID                " << endl;
        cout << "==========================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }
        file.close();
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
        }
        cout << "==========================================" << endl;
    }
    void Searching(string path)
    {
        string format = ".txt";
        ifstream fileInput;
        fileInput.open(path + format);
        string line, Search;
        int Choice;
        cout << "\t\n|1-  Search by ID         " << endl
            << "\t\n|2 - Search by Name      " << endl
            << "\t\n-------------------------" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Please enter the id to search: ";
            cin >> Search;
            while (Search.length() != 9)
            {
                cout << "Try agin , Please enter the term to search: ";
                cin >> Search;
            }
        }
        else if (Choice == 2)
        {
            cout << "Please enter the name to search: ";
            cin >> Search;
        }
        for (unsigned int curLine = 0; getline(fileInput, line); curLine++)
        {
            if (line.find(Search) != string::npos)
            {
                cout << "found: " << Search << " on line: " << curLine << endl
                    << line << endl;
            }
        }
    }
    void Backup()
    {
        fstream f1;
        fstream f2;
        string copy, transferbackup, Receivebackup;
        cout << "Enter the name of the file you want to back up :";
        cin >> transferbackup;
        f1.open(transferbackup + ".txt", ios::in);
        if (f1.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "Enter the path of the disk where you want to save the backup ,Format ( D:// ) : ";
        cin >> Receivebackup;

        f2.open(Receivebackup + "Backup.txt", ios::out);
        if (f2.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     Backup Done ! ^,^      ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||    Backup not Done ! :( ! ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (!f1.eof()) {

            getline(f1, copy);
            f2 << copy << endl;
        }
        f2.open(Receivebackup + "Backup.txt", ios::in);

        while (!f2.eof()) {
            getline(f2, copy);
        }
        f1.close();
        f2.close();
    }
    void Update(string path)
    {
        ifstream file;

        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        int i = 0;
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;

        while (file >> inputfirstname && file >> inputsurname && file >> inputid)
        {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }

        fstream fileSave;
        string search;

        string FIRSTNAME;
        string SURNAME;
        string ID;

        cout << "Search by id to update >> ";
        cin >> search;
        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {

            if (id[x] == search)
            {
                cout << "This Is The Data You Searched For >> ";
                cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
                cin.ignore();
                cout << "Enter ID : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                while (ID.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, ID);
                    if (ID == "exit")
                        break;
                }
                cout << "Enter First name : ";
                getline(cin, FIRSTNAME);
                if (FIRSTNAME == "exit")
                    break;
                cout << "Enter Surname : ";
                getline(cin, SURNAME);
                if (SURNAME == "exit")
                    break;

                id[x] = ID;
                firstname[x] = FIRSTNAME;
                surname[x] = SURNAME;
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Updated   ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Update Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < firstname.size(); i++)
        {
            fileSave << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();

    }
    void Delete(string path)
    {
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;
        string inputfirstname;
        string inputsurname;
        string inputid;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        int i = 0;
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , pls Enter New name and id , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;

        while (file >> inputfirstname && file >> inputsurname && file >> inputid)
        {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);
        }

        fstream fileSave;


        string search;

        string FIRSTNAME;
        string SURNAME;
        string ID;
        char choise;

        cout << "Search by id to delete >> ";
        cin >> search;
        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {
            if (id[x] == search)
            {
                cout << "This Data Will Be Deleted ! >> ";
                cout << firstname[x] << " " << surname[x] << "\t\t" << id[x] << endl;
                cout << "are you sure you want to delete this data?";
                cout << "Press y or Y to confirm: ";
                cin >> choise;
                if ((choise == 'y' || choise == 'Y'))
                {
                    id[x] = " ";
                    firstname[x] = " ";
                    surname[x] = " ";
                }
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Deleted!   ^,^   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Delete Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < firstname.size(); i++)
        {
            fileSave << firstname[i] << " " << surname[i] << "\t\t" << id[i] << endl;
        }
        file.close();
    }
    void DashBoard(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                Show(path);
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }
    void DashBoardAdmin(string path)
    {

        int choise;
        system("cls");
        do {
            cout << "\t\t==================================================\n";
            cout << "\t\t                 DashBoard Admin \n";
            cout << "\t\t==================================================\n\n";
            cout << "\t\t==================================================\n";
            cout << "\t\t Information of Technology (IT) Management System \n";
            cout << "\t\t==================================================\n\n";
            cout << "\t\t---------------------------------------------------\n";
            cout << "\t\t||\t\t1. Add  \t\t\t ||\n";
            cout << "\t\t||\t\t2. Display \t\t\t ||\n";
            cout << "\t\t||\t\t3. Search \t\t\t ||\n";
            cout << "\t\t||\t\t4. Delete                    \t ||\n";
            cout << "\t\t||\t\t5. Update \t\t         ||\n";
            cout << "\t\t||\t\t6. Backup \t\t         ||\n";
            cout << "\t\t||\t\t7. Exit\t\t\t\t ||\n";
            cout << "\t\t---------------------------------------------------\n";
            cout << "\nEnter Choice: ";
            cin >> choise;
            cout << "-----------------------" << endl;
            cin.ignore();
            if (choise == 1)
            {
                Add(path);
            }
            else if (choise == 2)
            {
                Show(path);
            }
            else if (choise == 3)
            {
                char  Try;
                do
                {
                    Searching(path);
                    cout << "If you want to search again enter y or Y : ";
                    cin >> Try;
                } while (Try == 'Y' || Try == 'y');
            }
            else if (choise == 6)
            {
                Backup();
            }
            else if (choise == 5)
            {
                Update(path);
            }
            else if (choise == 4)
            {
                Delete(path);
            }
            else
                break;
        } while (choise != 0);
        cout << "GoodBye :) ...! " << endl;

    }
};
class Doctor : public Main { // by R a w a n

public:
    void showDoctor(string path, string coursepath) {
        ifstream coursefile;
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        coursefile.open(coursepath + file_format);
        file.open(path + file_format);
        if (file.is_open() && coursefile.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }

        cout << "==============================================================================================" << endl;
        cout << "   Name   \t\  |         ID     |       Course name     |       CODE    |    Credit hours     " << endl;
        cout << "==============================================================================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);

        }
        file.close();

        string line;
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x];
            for (unsigned int curLine = 0; getline(coursefile, line); curLine++)
            {
                if (line.find(id[x]) != string::npos)
                {
                    cout << line << endl;
                }
                cout << endl;
            }
        }
        cout << "==========================================" << endl;
    }
    void DashBoardDoctor(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Main::Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Main::Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Main::Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Main::Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                showDoctor(path, "Datacourse");
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }


};
class demonstrator : public Main { // by Atef

public:
    void showDemonstrator(string path, string coursepath) {
        ifstream coursefile;
        ifstream file;
        vector<string> firstname;
        vector<string> surname;
        vector<string> id;

        string inputfirstname;
        string inputsurname;
        string inputid;

        string file_format = ".txt", Disc_name;
        coursefile.open(coursepath + file_format);
        file.open(path + file_format);
        if (file.is_open() && coursefile.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }

        cout << "==============================================================================================" << endl;
        cout << "   Name   \t\  |         ID     |       Course name     |       CODE    |    Credit hours     " << endl;
        cout << "==============================================================================================" << endl;
        while (file >> inputfirstname && file >> inputsurname && file >> inputid) {
            firstname.push_back(inputfirstname);
            surname.push_back(inputsurname);
            id.push_back(inputid);

        }
        file.close();

        string line;
        for (int x = 0; x < id.size(); x++)
        {
            cout << firstname[x] << " " << surname[x] << "\t\t" << id[x];
            for (unsigned int curLine = 0; getline(coursefile, line); curLine++)
            {
                if (line.find(id[x]) != string::npos)
                {
                    cout << line << endl;
                }
                cout << endl;
            }
        }
        cout << "==========================================" << endl;
    }
    void DashBoardDemonstrator(string menu, string path)
    {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new " << menu << "      " << endl
                << "|   2- Search  " << menu << "      " << endl
                << "|   3- Update " << menu << "       " << endl
                << "|   4- Delete  " << menu << "      " << endl
                << "|   5- Display List         " << endl
                << "|   6- Quit                 " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                Main::Add(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                Main::Searching(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                Main::Update(path);
            }
            else if (option == 4) {
                cin.ignore();
                Main::Delete(path);
            }
            else if (option == 5) {
                system("CLS");
                showDemonstrator(path, "course");
            }
            else if (option == 6) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }


};
class student : public Main { // by sara

public:

};
class course : public Main { // by rashad , ramez
    // ofstream course + daoc + demonstartor  ;
public:
    void AddCourse(string path) {
        cout << endl << endl;
        /*   cout << "------------------------------------------" << endl;
           cout << "Please Enter The Course's Doctor Data: "<<endl;
           cout << "------------------------------------------"<<endl;
           Main::Add(pathDoc);
           cout << "------------------------------------------" << endl;
           cout << "Please Enter The Course's Demonstrator Data: "<<endl;
           cout << "------------------------------------------"<<endl;
           Main::Add(pathdem);*/
        cout << "------------------------------------------" << endl;
        cout << "Please Enter The Course Data: " << endl;
        cout << "------------------------------------------" << endl;

        fstream file;
        string file_format = ".txt", Disc_name;
        file.open(path + file_format, ios_base::out | ios::app);
        if (file.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File is open ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  File not  open :( ! ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t|| Hello ! , PLS Enter New name and code , type exit to finsh|| " << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        string ID;
        string COURSENAME;
        string CREDITHOURS;
        vector<string> iddoctor;
        vector<string> iddemonstrator;
        string IDdoctor;
        string IDdemonstrator;

        cin.ignore();
        while (!file.eof())
        {
            cout << "Enter Course CODE : ";
            getline(cin, ID);
            if (ID == "exit")
                break;
            while (ID.length() != 6)
            {
                cout << "Try agin , Enter Course CODE : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
            }
            cout << "Enter Course name : ";
            getline(cin, COURSENAME);
            if (COURSENAME == "exit")
                break;
            cout << " Please Enter Course Credit Hours: ";
            getline(cin, CREDITHOURS);
            if (CREDITHOURS == "exit")
                break;

            cout << "Enter  ID of the doctor : ";
            getline(cin, IDdoctor);
            if (IDdoctor == "exit")
                break;
            while (IDdoctor.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, IDdoctor);
                if (IDdoctor == "exit")
                    break;
            }


            cout << "Enter  ID of the Demonstrator : ";
            getline(cin, IDdemonstrator);
            if (IDdemonstrator == "exit")
                break;
            while (IDdemonstrator.length() != 9)
            {
                cout << "Try agin , Enter ID : ";
                getline(cin, IDdemonstrator);
                if (IDdemonstrator == "exit")
                    break;
            }

            coursename.push_back(COURSENAME);
            credithours.push_back(CREDITHOURS);
            id.push_back(ID);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);

        }
        cout << "\t\n-------------------------" << endl;
        cout << "\t\n||Data has been added ^,^||" << endl;
        cout << "\t\n-------------------------" << endl;
        for (int i = 0; i < coursename.size(); i++)
        {
            file << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void ShowCourse(string FilePath)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;

        string ID;
        string COURSENAME;
        string CREDITHOURS;

        string file_format = ".txt", Disc_name;
        file.open(FilePath + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        cout << "====================================================" << endl;
        cout << "  Course name     |       CODE    |    Credit hours " << endl;
        cout << "====================================================" << endl;
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
        }
        file.close();
        for (int x = 0; x < id.size(); x++)
        {
            cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
        }
        cout << "=====================================================" << endl;
    }
    void SearchCourse(string path)
    {
        string format = ".txt";
        ifstream fileInput;
        fileInput.open(path + format);
        string line, Search;
        int Choice;
        cout << "\t\n|1-  Search by CODE         " << endl
            << "\t\n|2 - Search by Name      " << endl
            << "\t\n-------------------------" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Please enter the code to search: ";
            cin >> Search;
            while (Search.length() != 6)
            {
                cout << "Try agin , Please enter the term to search: ";
                cin >> Search;
            }
        }
        else if (Choice == 2)
        {
            cout << "Please enter the name to search: ";
            cin >> Search;
        }
        else
            cout << "Error , pls Enter 1 or 2 ";

        for (unsigned int curLine = 0; getline(fileInput, line); curLine++)
        {
            if (line.find(Search) != string::npos)
            {
                cout << "====================================================" << endl;
                cout << "found: " << Search << " on line: " << curLine << endl;
                cout << "====================================================" << endl;
                cout << "  Course name     |       CODE    |    Credit hours " << endl;
                cout << "====================================================" << endl;
                cout << line << endl;

            }
        }
        cout << "====================================================" << endl << endl;
    }
    void BackupCourse()
    {
        Main::Backup();
    }
    void UpdataCourse(string path)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        vector<string> iddoctor;
        vector<string> iddemonstrator;

        string ID;
        string COURSENAME;
        string CREDITHOURS;
        string IDdoctor;
        string IDdemonstrator;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS && file >> IDdoctor && file >> IDdemonstrator) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);
        }

        fstream fileSave;
        string search;

        cout << "Search by code to update >> ";
        cin >> search;

        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {

            if (id[x] == search)
            {
                cout << "This Is The Data You Searched For >> ";
                cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
                cin.ignore();
                cout << "Enter Course CODE : ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                while (ID.length() != 6)
                {
                    cout << "Try agin , Enter Course CODE : ";
                    getline(cin, ID);
                    if (ID == "exit")
                        break;
                }
                cout << "Enter Course name : ";
                getline(cin, COURSENAME);
                if (COURSENAME == "exit")
                    break;
                cout << " Please Enter Course Credit Hours: ";
                getline(cin, CREDITHOURS);
                if (CREDITHOURS == "exit")
                    break;

                cout << "Enter  ID of the doctor : ";
                getline(cin, IDdoctor);
                if (IDdoctor == "exit")
                    break;
                while (IDdoctor.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, IDdoctor);
                    if (IDdoctor == "exit")
                        break;
                }


                cout << "Enter  ID of the Demonstrator : ";
                getline(cin, IDdemonstrator);
                if (IDdemonstrator == "exit")
                    break;
                while (IDdemonstrator.length() != 9)
                {
                    cout << "Try agin , Enter ID : ";
                    getline(cin, IDdemonstrator);
                    if (IDdemonstrator == "exit")
                        break;
                }

                id[x] = ID;
                coursename[x] = COURSENAME;
                credithours[x] = CREDITHOURS;
                iddoctor[x] = IDdoctor;
                iddemonstrator[x] = IDdemonstrator;
                break;
            }
        }
        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Updated   ^,^    ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Update Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < coursename.size(); i++)
        {
            fileSave << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void DeleteCourse(string path)
    {
        ifstream file;

        vector<string> coursename;
        vector<string> credithours;
        vector<string> id;
        vector<string> iddoctor;
        vector<string> iddemonstrator;


        string ID;
        string COURSENAME;
        string CREDITHOURS;
        string IDdoctor;
        string IDdemonstrator;

        string file_format = ".txt", Disc_name;
        file.open(path + file_format);
        if (file.is_open())
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||      File is open ^,^     ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        else
        {
            cout << "\t\t==============================" << endl;
            cout << "\t\t||     File not open :( !    ||" << endl;
            cout << "\t\t==============================" << endl;
        }
        while (file >> COURSENAME && file >> ID && file >> CREDITHOURS && file >> IDdoctor && file >> IDdemonstrator) {
            coursename.push_back(COURSENAME);
            id.push_back(ID);
            credithours.push_back(CREDITHOURS);
            iddoctor.push_back(IDdoctor);
            iddemonstrator.push_back(IDdemonstrator);
        }

        fstream fileSave;
        string search;

        char choise;
        cout << "Search by id to delete >> ";
        cin >> search;

        fileSave.open(path + file_format, ios_base::out);
        for (int x = 0; x < id.size(); x++)
        {
            if (id[x] == search)
            {
                cout << "This Data Will Be Deleted ! >> ";
                cout << coursename[x] << "\t\t" << id[x] << "\t\t" << credithours[x] << endl;
                cout << "are you sure you want to delete this data?";
                cout << "Press y or Y to confirm: ";
                cin >> choise;
                if ((choise == 'y' || choise == 'Y'))
                {
                    id[x] = " ";
                    coursename[x] = " ";
                    credithours[x] = " ";
                    iddoctor[x] = " ";
                    iddemonstrator[x] = " ";
                }
                break;
            }
        }

        if (fileSave.is_open())
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||     Deleted!   ^,^   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t-------------------------" << endl;
            cout << "\t\t\t\t||  Delete Faild :( !   ||" << endl;
            cout << "\t\t\t\t-------------------------" << endl;
        }
        for (int i = 0; i < coursename.size(); i++)
        {
            fileSave << coursename[i] << "\t\t" << id[i] << "\t\t" << credithours[i] << "\t\t" << iddoctor[i] << "\t\t" << iddemonstrator[i] << endl;
        }
        file.close();
    }
    void courseDashBoard(string menu, string  path) {
        string search;
        int option;
        bool Quit = true;
        system("CLS");
        do
        {
            cout << "=========================" << endl;
            cout << "|   Dashboard " << menu << "      " << endl;
            cout << "|======= " << menu << "  ======== " << endl
                << "|   1- Add new   " << menu << "      " << endl
                << "|   2- Search    " << menu << "      " << endl
                << "|   3- Update    " << menu << "       " << endl
                << "|   4- Delete    " << menu << "      " << endl
                << "|   5- Display   " << menu << "      " << endl
                << "|   6- Backup    " << menu << "      " << endl
                << "|   7- Exit                     " << endl
                << "=========================" << endl;
            cout << "Select option >> ";
            cin >> option;
            if (option == 1) {
                AddCourse(path);
                system("CLS");
            }
            else if (option == 2) {
                system("CLS");
                cin.ignore();
                SearchCourse(path);
            }
            else if (option == 3) {
                system("CLS");
                cin.ignore();
                UpdataCourse(path);
            }
            else if (option == 4) {
                cin.ignore();
                DeleteCourse(path);
            }
            else if (option == 5) {
                system("CLS");
                ShowCourse(path);
            }
            else if (option == 6) {
                system("CLS");
                BackupCourse();
            }
            else if (option == 7) {
                system("CLS");
                Quit = false;
            }
            else
                cout << "Try agin choise 1 - 6 " << endl;
        } while (Quit);
        cout << "Exit... Saving to file !";
        cin.get();
    }
};

int main()
{
    //course c1;
    //c1.courseDashBoard("Course", "Datacourse");
    Doctor d1;

    d1.DashBoardDoctor("Doctor", "DataDoctor");


    return 0;
}
