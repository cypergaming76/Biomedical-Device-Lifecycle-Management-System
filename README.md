# Biomedical Device Lifecycle Management System (BDLMS)

## Project Overview

The **Biomedical Device Lifecycle Management System (BDLMS)** is a C++ OOP microproject designed to manage biomedical devices in a hospital.

The system helps maintain information about biomedical devices, manufacturers/service companies, device locations, service due dates, device status and service records.

The current implementation uses **C++ file handling** for persistent data storage.

---

## Student Details

**Name:** Taikhoom Rajkotwala 
          Sujal Bote
      
**Roll No.:** 25204A0047
              25204A0022
              
**Branch:** Diploma in Electronics and Computer Engineering

---

## Problem Statement

Hospitals use different biomedical devices such as patient monitors, infusion pumps and anaesthesia machines.

Managing these devices manually can make it difficult to:

- Track device information
- Locate devices in wards and rooms
- Monitor service due dates
- Maintain service and maintenance history
- Track device status
- Maintain company and service information

BDLMS provides a simple computerized solution for organizing this information.

---

## Objectives

- Maintain biomedical device information digitally
- Store product ID, model, company and location details
- Track service due dates and device status
- Maintain service and maintenance records
- Provide add, search, update and delete operations
- Reduce manual record keeping
- Demonstrate practical OOP concepts
- Use C++ file handling for persistent data storage

---

## Technologies Used

- **C++**
- **Object-Oriented Programming (OOP)**
- **C++ File Handling**
- **Text-file based data storage**

---

## Main Classes

### 1. Hospital
Stores hospital identification, name, address and contact information.

### 2. Company
Stores manufacturer/service company information such as company ID, name, service centre and contact number.

### 3. BiomedicalDevice
Stores product ID, device name, company, model number, ward, room, purchase date, service due date and status.

### 4. ServiceRecord
Stores service record ID, product ID, service date, service company, service type, service status and remarks.

---

## OOP Concepts Demonstrated

- Classes and Objects
- Encapsulation
- Constructors
- Default and Parameterized Constructors
- Access Specifiers
- Getters and Setters
- Arrays of Objects
- File Handling

Inheritance and polymorphism are not required in the current design.

---

## Main Features

- View hospital details
- View company details
- View all biomedical devices
- View all service records
- Add new biomedical devices
- Search devices using Product ID
- Update device room
- Update device status
- Delete devices
- Add service records
- Save data to files
- Load existing data when the program starts

---

## File Handling

The system uses two text files for persistent storage:

```text
devices.txt
service_records.txt
