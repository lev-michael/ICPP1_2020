#include <api.h>
#include "PhoneBook.h"
#include "Person.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>


using namespace std;

int PhoneBook::findIndex( string id)
{
    for (size_t i = 0; i < contacts->getSize(); i++)
    {
        if (contacts->getElementAt(i)->GetId() == id) {
            return i;
        }
    }
    return -1;
}

PhoneBook::PhoneBook()
{
    contacts = new DynamicArray<Person*>();
    load();
}


PhoneBook::~PhoneBook()
{
    for (size_t i = 0; i < contacts->getSize(); i++)
    {
        delete  contacts->getElementAt(i);
    }
    delete contacts;
}

void PhoneBook::add(Person* person)
{
    contacts->append(person);
}

Person* PhoneBook::remove(string id)
{
    int i = findIndex(id);
    if (i != -1) {
        return this->contacts->remove(i);
    }
    throw invalid_argument("No person found");
}

Person* PhoneBook::find(string id)
{
    int i = findIndex(id);
    if (i != -1) {
        return this->contacts->getElementAt(i);
    }
    throw invalid_argument("No person found");
}

void PhoneBook::toString() const
{
    for (size_t i = 0; i < contacts->getSize(); i++)
    {
        cout << contacts->getElementAt(i)->toString();
    }
}

bool PhoneBook::isEmpty() const
{
    return this->contacts->getSize() == 0;
}


void PhoneBook::load()
{
    ifstream in{};
    in.open("contacts.json");
    if (in.is_open()) {
        stringstream ss;
        ss << in.rdbuf();
        try {
            Value* val = JSON::deserialize(ss.str());
            ArrayValue* persons = dynamic_cast<ArrayValue*>(val);
            for (size_t i = 0; i < persons->size; i++)
            {
                ObjectValue* person = dynamic_cast<ObjectValue*>(persons->array->getElementAt(i));
                string id = dynamic_cast<StringValue*>(person->getValue("id"))->get();
                string name = dynamic_cast<StringValue*>(person->getValue("name"))->get();
                string phone = dynamic_cast<StringValue*>(person->getValue("phone"))->get();
                ObjectValue* date = dynamic_cast<ObjectValue*>(person->getValue("birthday"));
                ObjectValue* address = dynamic_cast<ObjectValue*>(person->getValue("address"));
                int day = (int) dynamic_cast<NumberValue*>(date->getValue("day"))->get();
                int month = (int) dynamic_cast<NumberValue*>(date->getValue("month"))->get();
                int year = (int) dynamic_cast<NumberValue*>(date->getValue("year"))->get();
                string street = dynamic_cast<StringValue*>(address->getValue("street"))->get();
                string city = dynamic_cast<StringValue*>(address->getValue("city"))->get();
                string zip = dynamic_cast<StringValue*>(address->getValue("zip"))->get();
                int house = (int) dynamic_cast<NumberValue*>(address->getValue("houseNumber"))->get();
                try {
                    this->add(new Person(id, name, phone, day, month, year, street, house, city, zip));
                }
                catch (range_error e) {
                    cout << "Person "<< name << " not loaded, " << e.what() << endl;
                }
            }
            delete val;
        }
        catch (invalid_argument e) {
            cout << "No data loaded" <<endl << e.what() << endl;
            in.close();
        }
        in.close();    
    }  
}


void PhoneBook::save(string file) const{
    ArrayValue* persons = new ArrayValue();
    for (size_t i = 0; i < this->contacts->getSize(); i++)
    {
        ObjectValue* person = new ObjectValue();
        ObjectValue* address = new ObjectValue();
        ObjectValue* birthday = new ObjectValue();
        address->append(KeyValuePair{ "street", new StringValue(contacts->getElementAt(i)->GetAddress()->GetStreet()) });
        address->append(KeyValuePair{ "houseNumber", new NumberValue(contacts->getElementAt(i)->GetAddress()->getHouseNum()) });
        address->append(KeyValuePair{ "city", new StringValue(contacts->getElementAt(i)->GetAddress()->GetCity()) });
        address->append(KeyValuePair{ "zip", new StringValue(contacts->getElementAt(i)->GetAddress()->GetZip()) });

        birthday->append(KeyValuePair{ "day", new NumberValue(contacts->getElementAt(i)->GetBirthday()->GetDay()) });
        birthday->append(KeyValuePair{ "month", new NumberValue(contacts->getElementAt(i)->GetBirthday()->GetMonth()) });
        birthday->append(KeyValuePair{ "year", new NumberValue(contacts->getElementAt(i)->GetBirthday()->GetYear()) });

        person->append(KeyValuePair{ "id", new StringValue(contacts->getElementAt(i)->GetId()) });
        person->append(KeyValuePair{ "name", new StringValue(contacts->getElementAt(i)->GetName()) });
        person->append(KeyValuePair{ "phone", new StringValue(contacts->getElementAt(i)->GetPhone()) });
        person->append(KeyValuePair{ "address", address });
        person->append(KeyValuePair{ "birthday", birthday });

        persons->append(person);
    }
    string output = JSON::serialize(persons);
    delete persons;
    
    std::ofstream ofs{};
    ofs.open(file+".json");
    if (ofs.is_open())
    {
        ofs << output;
        ofs.close();
    }
    else
    {
        std::cout << "Error while opening file";
    }
}


