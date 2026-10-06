#include <iostream>
#include <string>

using namespace std;

class Company
{
private:

    string companyID;
    string companyName;
    string serviceCenter;
    string contactNumber;

public:

    // Default Constructor
    Company()
    {
        companyID = "Not Assigned";
        companyName = "Not Assigned";
        serviceCenter = "Not Assigned";
        contactNumber = "Not Assigned";
    }

    // Parameterized Constructor
    Company(string id, string name, string center, string contact)
    {
        companyID = id;
        companyName = name;
        serviceCenter = center;
        contactNumber = contact;
    }


    // Setters

    void setCompanyID(string id)
    {
        companyID = id;
    }

    void setCompanyName(string name)
    {
        companyName = name;
    }

    void setServiceCenter(string center)
    {
        serviceCenter = center;
    }

    void setContactNumber(string contact)
    {
        contactNumber = contact;
    }


    // Getters

    string getCompanyID()
    {
        return companyID;
    }

    string getCompanyName()
    {
        return companyName;
    }

    string getServiceCenter()
    {
        return serviceCenter;
    }

    string getContactNumber()
    {
        return contactNumber;
    }


    // Display Function

    void displayCompany()
    {
        cout << "\n----- Company Details -----" << endl;

        cout << "Company ID      : " << companyID << endl;
        cout << "Company Name    : " << companyName << endl;
        cout << "Service Center  : " << serviceCenter << endl;
        cout << "Contact Number  : " << contactNumber << endl;
    }
};