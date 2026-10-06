#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Hospital.h"
#include "Company.h"
#include "BiomedicalDevice.h"
#include "ServiceRecord.h"

using namespace std;

const string DEVICE_FILE = "devices.txt";
const string SERVICE_FILE = "service_records.txt";

const int MAX_DEVICES = 30;
const int MAX_SERVICE_RECORDS = 30;


// ---------------------------------------------------------
// GLOBAL ARRAYS
// ---------------------------------------------------------

BiomedicalDevice devices[MAX_DEVICES];
ServiceRecord serviceRecords[MAX_SERVICE_RECORDS];

int deviceCount = 0;
int serviceRecordCount = 0;


// ---------------------------------------------------------
// SAVE DEVICES TO FILE
// ---------------------------------------------------------

void saveDevicesToFile()
{
    ofstream file(DEVICE_FILE);

    if (!file)
    {
        cout << "\nError: Could not save device data.\n";
        return;
    }

    for (int i = 0; i < deviceCount; i++)
    {
        file << devices[i].getProductID() << "|"
             << devices[i].getDeviceName() << "|"
             << devices[i].getCompanyID() << "|"
             << devices[i].getModelNo() << "|"
             << devices[i].getWardNo() << "|"
             << devices[i].getRoomNo() << "|"
             << devices[i].getPurchaseDate() << "|"
             << devices[i].getServiceDueDate() << "|"
             << devices[i].getStatus() << endl;
    }

    file.close();
}


// ---------------------------------------------------------
// LOAD DEVICES FROM FILE
// ---------------------------------------------------------

void loadDevicesFromFile()
{
    ifstream file(DEVICE_FILE);

    if (!file)
    {
        return;
    }

    string line;

    while (getline(file, line) && deviceCount < MAX_DEVICES)
    {
        if (line.empty())
            continue;

        string fields[9];
        stringstream ss(line);

        int i = 0;

        while (getline(ss, fields[i], '|') && i < 9)
        {
            i++;
        }

        if (i == 9)
        {
            devices[deviceCount] = BiomedicalDevice(
                fields[0],
                fields[1],
                fields[2],
                fields[3],
                fields[4],
                fields[5],
                fields[6],
                fields[7],
                fields[8]
            );

            deviceCount++;
        }
    }

    file.close();
}


// ---------------------------------------------------------
// SAVE SERVICE RECORDS TO FILE
// ---------------------------------------------------------

void saveServiceRecordsToFile()
{
    ofstream file(SERVICE_FILE);

    if (!file)
    {
        cout << "\nError: Could not save service records.\n";
        return;
    }

    for (int i = 0; i < serviceRecordCount; i++)
    {
        file << serviceRecords[i].getRecordID() << "|"
             << serviceRecords[i].getProductID() << "|"
             << serviceRecords[i].getServiceDate() << "|"
             << serviceRecords[i].getServiceCompany() << "|"
             << serviceRecords[i].getServiceType() << "|"
             << serviceRecords[i].getServiceStatus() << "|"
             << serviceRecords[i].getRemarks() << endl;
    }

    file.close();
}


// ---------------------------------------------------------
// LOAD SERVICE RECORDS FROM FILE
// ---------------------------------------------------------

void loadServiceRecordsFromFile()
{
    ifstream file(SERVICE_FILE);

    if (!file)
    {
        return;
    }

    string line;

    while (getline(file, line) &&
           serviceRecordCount < MAX_SERVICE_RECORDS)
    {
        if (line.empty())
            continue;

        string fields[7];
        stringstream ss(line);

        int i = 0;

        while (getline(ss, fields[i], '|') && i < 7)
        {
            i++;
        }

        if (i == 7)
        {
            serviceRecords[serviceRecordCount] = ServiceRecord(
                fields[0],
                fields[1],
                fields[2],
                fields[3],
                fields[4],
                fields[5],
                fields[6]
            );

            serviceRecordCount++;
        }
    }

    file.close();
}


// ---------------------------------------------------------
// ADD SAMPLE DATA
// ---------------------------------------------------------

void createSampleData()
{
    if (deviceCount == 0)
    {
        devices[0] = BiomedicalDevice(
            "BD016",
            "Anaesthesia Workstation",
            "C001",
            "Perseus A500",
            "OT",
            "OT-02",
            "2024-09-07",
            "2026-09-07",
            "Service Due"
        );

        devices[1] = BiomedicalDevice(
            "BD017",
            "Patient Monitor",
            "C002",
            "Vista 120",
            "ICU",
            "ICU-03",
            "2025-02-15",
            "2027-02-15",
            "Available"
        );

        devices[2] = BiomedicalDevice(
            "BD018",
            "Infusion Pump",
            "C002",
            "Agilia SP MC",
            "Ward 1",
            "W1-05",
            "2024-06-20",
            "2026-06-20",
            "Under Maintenance"
        );

        deviceCount = 3;

        saveDevicesToFile();
    }

    if (serviceRecordCount == 0)
    {
        serviceRecords[0] = ServiceRecord(
            "SR001",
            "BD016",
            "2026-09-07",
            "C001",
            "Preventive Maintenance",
            "Completed",
            "Calibration completed"
        );

        serviceRecords[1] = ServiceRecord(
            "SR002",
            "BD017",
            "2026-08-15",
            "C002",
            "Inspection",
            "Completed",
            "Routine inspection completed"
        );

        serviceRecords[2] = ServiceRecord(
            "SR003",
            "BD018",
            "2026-09-10",
            "C002",
            "Repair",
            "Pending",
            "Pump requires inspection"
        );

        serviceRecordCount = 3;

        saveServiceRecordsToFile();
    }
}


// ---------------------------------------------------------
// VIEW ALL DEVICES
// ---------------------------------------------------------

void viewAllDevices()
{
    if (deviceCount == 0)
    {
        cout << "\nNo biomedical devices found.\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "       ALL BIOMEDICAL DEVICES\n";
    cout << "============================================\n";

    for (int i = 0; i < deviceCount; i++)
    {
        devices[i].displayDevice();
    }
}


// ---------------------------------------------------------
// SEARCH DEVICE
// ---------------------------------------------------------

void searchDevice()
{
    string id;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == id)
        {
            devices[i].displayDevice();
            return;
        }
    }

    cout << "\nDevice with Product ID " << id << " not found.\n";
}


// ---------------------------------------------------------
// ADD NEW DEVICE
// ---------------------------------------------------------

void addDevice()
{
    if (deviceCount >= MAX_DEVICES)
    {
        cout << "\nDevice storage is full.\n";
        return;
    }

    string id;
    string name;
    string company;
    string model;
    string ward;
    string room;
    string purchase;
    string serviceDue;
    string status;

    cout << "\n========== ADD NEW DEVICE ==========\n";

    cout << "Enter Product ID: ";
    cin >> id;

    // Check duplicate ID
    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == id)
        {
            cout << "\nError: Product ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Device Name: ";
    getline(cin, name);

    cout << "Enter Company ID: ";
    getline(cin, company);

    cout << "Enter Model No.: ";
    getline(cin, model);

    cout << "Enter Ward No.: ";
    getline(cin, ward);

    cout << "Enter Room No.: ";
    getline(cin, room);

    cout << "Enter Purchase Date (YYYY-MM-DD): ";
    getline(cin, purchase);

    cout << "Enter Service Due Date (YYYY-MM-DD): ";
    getline(cin, serviceDue);

    cout << "Enter Status: ";
    getline(cin, status);

    devices[deviceCount] = BiomedicalDevice(
        id,
        name,
        company,
        model,
        ward,
        room,
        purchase,
        serviceDue,
        status
    );

    deviceCount++;

    saveDevicesToFile();

    cout << "\nDevice added successfully.\n";
}


// ---------------------------------------------------------
// UPDATE ROOM
// ---------------------------------------------------------

void updateRoom()
{
    string id;
    string newRoom;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == id)
        {
            cout << "Current Room No.: "
                 << devices[i].getRoomNo() << endl;

            cout << "Enter New Room No.: ";
            cin >> newRoom;

            devices[i].setRoomNo(newRoom);

            saveDevicesToFile();

            cout << "\nRoom number updated successfully.\n";
            return;
        }
    }

    cout << "\nDevice not found.\n";
}


// ---------------------------------------------------------
// UPDATE DEVICE STATUS
// ---------------------------------------------------------

void updateStatus()
{
    string id;
    string newStatus;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == id)
        {
            cout << "Current Status: "
                 << devices[i].getStatus() << endl;

            cin.ignore();

            cout << "Enter New Status: ";
            getline(cin, newStatus);

            devices[i].setStatus(newStatus);

            saveDevicesToFile();

            cout << "\nDevice status updated successfully.\n";
            return;
        }
    }

    cout << "\nDevice not found.\n";
}


// ---------------------------------------------------------
// DELETE DEVICE
// ---------------------------------------------------------

void deleteDevice()
{
    string id;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == id)
        {
            // Shift remaining devices to the left
            for (int j = i; j < deviceCount - 1; j++)
            {
                devices[j] = devices[j + 1];
            }

            deviceCount--;

            saveDevicesToFile();

            cout << "\nDevice deleted successfully.\n";
            return;
        }
    }

    cout << "\nDevice not found.\n";
}


// ---------------------------------------------------------
// VIEW ALL SERVICE RECORDS
// ---------------------------------------------------------

void viewAllServiceRecords()
{
    if (serviceRecordCount == 0)
    {
        cout << "\nNo service records found.\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "          ALL SERVICE RECORDS\n";
    cout << "============================================\n";

    for (int i = 0; i < serviceRecordCount; i++)
    {
        serviceRecords[i].displayServiceRecord();
    }
}


// ---------------------------------------------------------
// ADD SERVICE RECORD
// ---------------------------------------------------------

void addServiceRecord()
{
    if (serviceRecordCount >= MAX_SERVICE_RECORDS)
    {
        cout << "\nService record storage is full.\n";
        return;
    }

    string recordID;
    string productID;
    string serviceDate;
    string company;
    string serviceType;
    string status;
    string remarks;

    cout << "\n========== ADD SERVICE RECORD ==========\n";

    cout << "Enter Record ID: ";
    cin >> recordID;

    // Check duplicate record ID
    for (int i = 0; i < serviceRecordCount; i++)
    {
        if (serviceRecords[i].getRecordID() == recordID)
        {
            cout << "\nError: Record ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Product ID: ";
    getline(cin, productID);

    // Check whether device exists
    bool deviceExists = false;

    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getProductID() == productID)
        {
            deviceExists = true;
            break;
        }
    }

    if (!deviceExists)
    {
        cout << "\nError: Product ID does not exist.\n";
        return;
    }

    cout << "Enter Service Date (YYYY-MM-DD): ";
    getline(cin, serviceDate);

    cout << "Enter Service Company: ";
    getline(cin, company);

    cout << "Enter Service Type: ";
    getline(cin, serviceType);

    cout << "Enter Service Status: ";
    getline(cin, status);

    cout << "Enter Remarks: ";
    getline(cin, remarks);

    serviceRecords[serviceRecordCount] = ServiceRecord(
        recordID,
        productID,
        serviceDate,
        company,
        serviceType,
        status,
        remarks
    );

    serviceRecordCount++;

    saveServiceRecordsToFile();

    cout << "\nService record added successfully.\n";
}


// ---------------------------------------------------------
// HOSPITAL AND COMPANY DETAILS
// ---------------------------------------------------------

void viewHospitalDetails()
{
    Hospital hospital(
        "H001",
        "City Care Hospital",
        "Mumbai",
        "022-12345678"
    );

    hospital.displayHospital();
}


void viewCompanyDetails()
{
    Company company1(
        "C001",
        "Drager",
        "Mumbai Service Center",
        "1800-123-4567"
    );

    Company company2(
        "C002",
        "Philips",
        "Mumbai Service Center",
        "1800-987-6543"
    );

    company1.displayCompany();
    company2.displayCompany();
}


// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------

int main()
{
    // Student Identification
    cout << "============================================\n";
    cout << " Name     : Taikhoom Rajkotwala\n";
    cout << " Roll No. : 25204A0047\n";
    cout << "============================================\n";

    cout << "\n";
    cout << " BIOMEDICAL DEVICE LIFECYCLE MANAGEMENT SYSTEM\n";
    cout << "\n";

    // Load existing data
    loadDevicesFromFile();
    loadServiceRecordsFromFile();

    // Create sample data if files are empty/not present
    createSampleData();

    int choice;

    do
    {
        cout << "\n============================================\n";
        cout << "                  MAIN MENU\n";
        cout << "============================================\n";

        cout << "1.  View Hospital Details\n";
        cout << "2.  View Company Details\n";
        cout << "3.  View All Biomedical Devices\n";
        cout << "4.  View All Service Records\n";
        cout << "5.  Add New Device\n";
        cout << "6.  Search Device\n";
        cout << "7.  Update Device Room\n";
        cout << "8.  Update Device Status\n";
        cout << "9.  Delete Device\n";
        cout << "10. Add Service Record\n";
        cout << "11. Save Data\n";
        cout << "12. Exit\n";

        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                viewHospitalDetails();
                break;

            case 2:
                viewCompanyDetails();
                break;

            case 3:
                viewAllDevices();
                break;

            case 4:
                viewAllServiceRecords();
                break;

            case 5:
                addDevice();
                break;

            case 6:
                searchDevice();
                break;

            case 7:
                updateRoom();
                break;

            case 8:
                updateStatus();
                break;

            case 9:
                deleteDevice();
                break;

            case 10:
                addServiceRecord();
                break;

            case 11:
                saveDevicesToFile();
                saveServiceRecordsToFile();

                cout << "\nAll data saved successfully.\n";
                break;

            case 12:
                saveDevicesToFile();
                saveServiceRecordsToFile();

                cout << "\nData saved.\n";
                cout << "Thank you for using BDLMS.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 12);

    return 0;
}