#include <iostream>
#include <string>

using namespace std;

class Hospital
{
private:

    string hospitalID;
    string hospitalName;
    string hospitalAddress;
    string contactNumber;

public:

    // Default Constructor
    Hospital()
    {
        hospitalID = "Not Assigned";
        hospitalName = "Not Assigned";
        hospitalAddress = "Not Assigned";
        contactNumber = "Not Assigned";
    }


    // Parameterized Constructor
    Hospital(string id, string name, string address, string contact)
    {
        hospitalID = id;
        hospitalName = name;
        hospitalAddress = address;
        contactNumber = contact;
    }


    // Setters

    void setHospitalID(string id)
    {
        hospitalID = id;
    }

    void setHospitalName(string name)
    {
        hospitalName = name;
    }

    void setHospitalAddress(string address)
    {
        hospitalAddress = address;
    }

    void setContactNumber(string contact)
    {
        contactNumber = contact;
    }


    // Getters

    string getHospitalID()
    {
        return hospitalID;
    }

    string getHospitalName()
    {
        return hospitalName;
    }

    string getHospitalAddress()
    {
        return hospitalAddress;
    }

    string getContactNumber()
    {
        return contactNumber;
    }


    // Display Function

    void displayHospital()
    {
        cout << "\n----- Hospital Details -----" << endl;

        cout << "Hospital ID      : " << hospitalID << endl;
        cout << "Hospital Name    : " << hospitalName << endl;
        cout << "Hospital Address : " << hospitalAddress << endl;
        cout << "Contact Number   : " << contactNumber << endl;
    }
};