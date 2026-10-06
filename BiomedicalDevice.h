#include <iostream>
#include <string>

using namespace std;

class BiomedicalDevice
{
private:

    string productID;
    string deviceName;
    string companyID;
    string modelNo;
    string wardNo;
    string roomNo;
    string purchaseDate;
    string serviceDueDate;
    string status;

public:

    // Default Constructor
    BiomedicalDevice()
    {
        productID = "Not Assigned";
        deviceName = "Not Assigned";
        companyID = "Not Assigned";
        modelNo = "Not Assigned";
        wardNo = "Not Assigned";
        roomNo = "Not Assigned";
        purchaseDate = "Not Assigned";
        serviceDueDate = "Not Assigned";
        status = "Available";
    }

    // Parameterized Constructor
    BiomedicalDevice(string id, string name, string company,
                     string model, string ward, string room,
                     string purchase, string serviceDue,
                     string deviceStatus)
    {
        productID = id;
        deviceName = name;
        companyID = company;
        modelNo = model;
        wardNo = ward;
        roomNo = room;
        purchaseDate = purchase;
        serviceDueDate = serviceDue;
        status = deviceStatus;
    }

    // Setters

    void setProductID(string id)
    {
        productID = id;
    }

    void setDeviceName(string name)
    {
        deviceName = name;
    }

    void setCompanyID(string company)
    {
        companyID = company;
    }

    void setModelNo(string model)
    {
        modelNo = model;
    }

    void setWardNo(string ward)
    {
        wardNo = ward;
    }

    void setRoomNo(string room)
    {
        roomNo = room;
    }

    void setPurchaseDate(string date)
    {
        purchaseDate = date;
    }

    void setServiceDueDate(string date)
    {
        serviceDueDate = date;
    }

    void setStatus(string deviceStatus)
    {
        status = deviceStatus;
    }


    // Getters

    string getProductID()
    {
        return productID;
    }

    string getDeviceName()
    {
        return deviceName;
    }

    string getCompanyID()
    {
        return companyID;
    }

    string getModelNo()
    {
        return modelNo;
    }

    string getWardNo()
    {
        return wardNo;
    }

    string getRoomNo()
    {
        return roomNo;
    }

    string getPurchaseDate()
    {
        return purchaseDate;
    }

    string getServiceDueDate()
    {
        return serviceDueDate;
    }

    string getStatus()
    {
        return status;
    }


    // Display Function

    void displayDevice()
    {
        cout << "\n----- Biomedical Device Details -----" << endl;

        cout << "Product ID       : " << productID << endl;
        cout << "Device Name      : " << deviceName << endl;
        cout << "Company ID       : " << companyID << endl;
        cout << "Model No.        : " << modelNo << endl;
        cout << "Ward No.         : " << wardNo << endl;
        cout << "Room No.         : " << roomNo << endl;
        cout << "Purchase Date    : " << purchaseDate << endl;
        cout << "Service Due Date : " << serviceDueDate << endl;
        cout << "Status           : " << status << endl;
    }
};