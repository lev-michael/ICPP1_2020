#include "App.h"

using namespace std;


App::App()
{
    this->book = new PhoneBook();
    this->stillContinue = true;
}

App::~App()
{
    delete book;
}

void App::writeMenu() const{
    printDelimeter();
    cout << endl << "Menu" << endl << "Press 1 : Show all persons in PhoneBook" << endl
        << "Press 2 : Add new person to PhoneBook" << endl
        << "Press 3 : Find person by ID" << endl
        << "Press 4 : Edit person from PhoneBook" << endl
        << "Press 5 : Delete person from PhoneBook" << endl
        << "Press 6 : Export data of PhoneBook to the file" << endl
        << "Press 0 : Exit app" << endl;
    printDelimeter();

}

bool App::is_number(const std::string& s) const
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

string App::getInput(string text) const{
    string i;
    while (true) {
        cout << endl << text;
        getline(cin, i);
        if (!i.empty()) {
            return i;
        }
        cout << endl << "Invalid input. Try again" << endl;
    }
}

int App::getNumberInput(string text) const {
    string input;
    while (true) {
        cout << endl << text;
        getline(cin, input);
        if (is_number(input)) {
            return stoi(input);
        }
        cout << endl << "Wrong input. Try again" << endl;
    }
}

string App::getEditInput(string text) const
{
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

int App::getEditNumberInput(string text) const
{
    string input;
    while (true) {
        cout << text;
        getline(cin, input);
        if (is_number(input)) {
            return stoi(input);
        } 
        if (input.empty()) {
            return NULL;
        }
    }
}

void App::listAll() const
{
    if (this->book->isEmpty()) {
        printDelimeter();
        cout << "PhoneBook is empty" << endl;
    }
    else {
        cout << endl << "All persons in PhoneBook" << endl;
        printDelimeter();
        book->toString();
    }

}


void App::saveAtEnd() const
{
    string input = getEditInput("Do you want to save the changes? (Write y for Yes):");
    if (input == "y") {
        book->save("contacts");
        cout << endl << "PhoneBook saved";
    } 
}

void App::find() const {
    string input = getInput("Find person by ID\nID: ");
    try {
        cout << book->find(input)->toString() << endl;
    }
    catch (invalid_argument e) {
        printDelimeter();
        cout << e.what() << endl;
        printDelimeter();

    }
}



void App::add() {
    string name = getInput("Add new person\nName: ");
    string phone = getInput("Phone: ");
    string street = getInput("Address - street: ");
    int house = getNumberInput("Address - house number: ");
    string city = getInput("Address - city: ");
    string zip = getInput("Address - ZIP: ");
    int day = getNumberInput("Birthday - day: ");
    int month = getNumberInput("Address - month: ");
    int year = getNumberInput("Address - year: ");
    try {
        book->add(new Person(name, phone, day, month, year, street, house, city, zip));
        printDelimeter();
        cout << "Person added" << endl;
    }
    catch (range_error e) {
        printDelimeter();
        cout << e.what() << endl;
        cout << "Person addition failed" << endl;
        printDelimeter();
    }
}

void App::deletePerson() {
    string input = getInput("Delete Person by ID\nID:");
    try {
        Person* p = book->remove(input);
        cout << "Deleting person: " << p->toString() << endl;
        delete p;
        cout << "Deletion complete " << endl;
    }
    catch (invalid_argument e) {
        printDelimeter();
        cout << e.what() << endl;
        printDelimeter();
    }
    
}

void App::editPerson() {
    string input;
    string name, phone, street, city, zip;
    int house, day, month;
    int year;
    Person* p;
    while (true) {
        try {
            input = getInput("Edit Person\nFind person by ID:");
            p = book->find(input);
            cout << endl << "Person found" << p->toString()  << endl << "Let input empty to keep original value" << endl << endl;
            cout << endl << "Original name: " + p->GetName() << endl;
            name = getEditInput("Enter new name: ");
            name = name == "" ? p->GetName() : name;
            p->SetName(name);

            cout << endl << "Original phone: " + p->GetPhone() << endl;
            phone = getEditInput("New Phone: ");
            phone = phone == "" ? p->GetPhone() : phone;
            p->SetPhone(phone);

            cout << endl << "Original street: " + p->GetAddress()->GetStreet() << endl;
            street = getEditInput("New Address - street: ");
            street = street == "" ? p->GetAddress()->GetStreet() : street;
            p->SetAddressStreet(street);

            cout << endl << "Original House number: " + to_string(p->GetAddress()->getHouseNum()) << endl;
            house = getEditNumberInput("New Address - house number: ");
            house = house == NULL ? p->GetAddress()->getHouseNum() : house;
            p->SetAddressHouse(house);

            cout << endl << "Original city: " + p->GetAddress()->GetCity() << endl;
            city = getEditInput("New Address - city: ");
            city = city == "" ? p->GetAddress()->GetCity() : city;
            p->SetAddressCity(city);

            cout << endl << "Original ZIP code: " + p->GetAddress()->GetZip() << endl;
            zip = getEditInput("New Address - ZIP: ");
            zip = zip == "" ? p->GetAddress()->GetZip() : zip;
            p->SetAddressZip(zip);

            while (true) {
                cout << endl << "Original Birthday - day: " + to_string(p->GetBirthday()->GetDay()) << endl;
                day = getEditNumberInput("New Birthday - day: ");
                day = day == NULL ? p->GetBirthday()->GetDay() : day;
                cout << endl << "Original Birthday - month: " + to_string(p->GetBirthday()->GetMonth()) << endl;
                month = getEditNumberInput("New Birthday - month: ");
                month = month == NULL ? p->GetBirthday()->GetMonth() : month;
                cout << endl << "Original Birthday - year: " + to_string(p->GetBirthday()->GetYear()) << endl;
                year = getEditNumberInput("New Birthday - year: ");
                year = year == NULL ? p->GetBirthday()->GetYear() : year;
                try {
                    p->SetBirthDay(day);
                    p->SetBirthMonth(month);
                    p->SetBirthYear(year);
                    break;
                }
                catch (range_error e) {
                    cout << e.what() << endl << "Try again" << endl;
                }
            }
            printDelimeter();
            cout << "Person edited" << endl;
            break;
        }
        catch (invalid_argument e) {
            printDelimeter();
            cout << e.what() << endl;
            input = getInput("Do you want to try again ? (Write y for Yes) :");
            if (input != "y") {
                break;
            }
        }
        
    }
}

void App::save() const {
    string input = getInput("Export data to the file\nEnter file name: ");
    book->save(input);
    printDelimeter();
    cout << endl << "PhoneBook saved in " << input << ".json" << endl;;

}

void App::printDelimeter() const
{
    cout << endl << "-----------------------------" << endl;
}

void App::run()
{
    cout << "Welcome in PhoneBook" << endl ;
    int input;
    string i;
    while (stillContinue) {
        writeMenu();
        input = getNumberInput("Your choice: ");
        printDelimeter();
            switch (input)
            {
            case 1:
                listAll();
                break;
            case 2:
                add();
                break;
            case 3:
                find();
                break;
            case 4:
                editPerson();
                break;
            case 5:
                deletePerson();
                break;
            case 6:
                save();
                break;
            case 0:
                stillContinue = false;
                saveAtEnd();
                break;
            default:
                cout << "Invalid input" << endl;
            }
   
    }
}
