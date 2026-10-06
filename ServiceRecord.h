#include <iostream>
#include <string>

using namespace std;

class ServiceRecord
{
private:

    string recordID;
    string productID;
    string serviceDate;
    string serviceCompany;
    string serviceType;
    string serviceStatus;
    string remarks;

public:

    // Default Constructor
    ServiceRecord()
    {
        recordID = "Not Assigned";
        productID = "Not Assigned";
        serviceDate = "Not Assigned";
        serviceCompany = "Not Assigned";
        serviceType = "Not Assigned";
        serviceStatus = "Pending";
        remarks = "No Remarks";
    }


    // Parameterized Constructor
    ServiceRecord(string id, string deviceID, string date,
                  string company, string type,
                  string status, string note)
    {
        recordID = id;
        productID = deviceID;
        serviceDate = date;
        serviceCompany = company;
        serviceType = type;
        serviceStatus = status;
        remarks = note;
    }


    // Setters

    void setRecordID(string id)
    {
        recordID = id;
    }

    void setProductID(string deviceID)
    {
        productID = deviceID;
    }

    void setServiceDate(string date)
    {
        serviceDate = date;
    }

    void setServiceCompany(string company)
    {
        serviceCompany = company;
    }

    void setServiceType(string type)
    {
        serviceType = type;
    }

    void setServiceStatus(string status)
    {
        serviceStatus = status;
    }

    void setRemarks(string note)
    {
        remarks = note;
    }


    // Getters

    string getRecordID()
    {
        return recordID;
    }

    string getProductID()
    {
        return productID;
    }

    string getServiceDate()
    {
        return serviceDate;
    }

    string getServiceCompany()
    {
        return serviceCompany;
    }

    string getServiceType()
    {
        return serviceType;
    }

    string getServiceStatus()
    {
        return serviceStatus;
    }

    string getRemarks()
    {
        return remarks;
    }


    // Display Function

    void displayServiceRecord()
    {
        cout << "\n----- Service Record -----" << endl;

        cout << "Record ID       : " << recordID << endl;
        cout << "Product ID      : " << productID << endl;
        cout << "Service Date    : " << serviceDate << endl;
        cout << "Service Company : " << serviceCompany << endl;
        cout << "Service Type    : " << serviceType << endl;
        cout << "Service Status  : " << serviceStatus << endl;
        cout << "Remarks         : " << remarks << endl;
    }
};