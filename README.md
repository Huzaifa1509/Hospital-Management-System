# Hospital Management System

A console-based Hospital Management System built in C++ as an Object-Oriented Programming course project. The entire program is in a single file (`main.cpp`) and runs in the terminal.

---

## Table of Contents

- [Introduction](#introduction)
- [OOP Concepts](#oop-concepts)
- [Class Design](#class-design)
- [Features](#features)
- [How to Set Up and Run](#how-to-set-up-and-run)
- [Project Structure](#project-structure)
- [Limitations](#limitations)

---

## Introduction

This system simulates basic hospital operations: registering patients and doctors, booking appointments, and generating bills. It was built to demonstrate the four main pillars of Object-Oriented Programming in C++.

The program is entirely menu-driven. No external libraries or databases are needed — just a C++ compiler.

---

## OOP Concepts

### Encapsulation

All class data members are declared `private`. Public getter and setter methods are provided to read or modify the data. This protects the internal state of each object from being changed directly.

For example, in the `Patient` class, `patientID` and `disease` are private and can only be accessed through `getPatientID()` and `getDisease()`.

### Inheritance

`Person` is the base class. It holds attributes common to both patients and doctors: name, age, gender, and phone number.

`Patient` and `Doctor` both inherit from `Person` and add their own specific attributes. This avoids repeating the same code in both classes.

| Class   | Inherits From | Additional Attributes             |
|---------|---------------|-----------------------------------|
| Person  | (base class)  | name, age, gender, phone          |
| Patient | Person        | patientID, disease                |
| Doctor  | Person        | doctorID, specialization, fee     |

### Polymorphism

`displayInfo()` is declared as `virtual` in `Person`. Both `Patient` and `Doctor` override this method with their own version that displays class-specific information.

When a `Person*` pointer holds a `Patient` or `Doctor` object and `displayInfo()` is called, the correct version runs at runtime based on the actual object type. This is **runtime polymorphism**.

The program includes a dedicated menu option that shows this in action using a base class pointer.

### Abstraction

Operations like adding a patient, booking an appointment, or generating a bill are wrapped in functions. The user only interacts with simple inputs and outputs — the internal logic is hidden.

---

## Class Design

### `Person` — Base Class
- **Attributes (private):** `name`, `age`, `gender`, `phone`
- **Methods:** getters/setters, `virtual displayInfo()`

### `Patient` — Derived from Person
- **Additional attributes:** `patientID` (int), `disease` (string)
- **Overrides:** `displayInfo()` — shows patient-specific info

### `Doctor` — Derived from Person
- **Additional attributes:** `doctorID` (int), `specialization` (string), `fee` (double)
- **Overrides:** `displayInfo()` — shows doctor-specific info

### `Appointment`
- **Attributes:** `appointmentID`, `patientID`, `doctorID`, `date`, `timeSlot`
- Links a patient with a doctor for a specific date and time

### `Bill`
- **Attributes:** `billID`, `patientID`, `consultFee`, `medicineCost`, `roomCharges`, `total`
- Total is automatically calculated when the object is created

---

## Features

| Feature              | Description                                                         |
|----------------------|---------------------------------------------------------------------|
| Add Patient          | Register a new patient with name, age, gender, phone, and disease   |
| View All Patients    | List all registered patients                                        |
| Search Patient       | Find a patient by their ID                                          |
| Add Doctor           | Register a new doctor with specialization and consultation fee      |
| View All Doctors     | List all registered doctors                                         |
| Book Appointment     | Book a patient with a doctor for a given date and time              |
| View Appointments    | Show all appointments with patient and doctor names                 |
| Generate Bill        | Create a bill; consultation fee is auto-filled from appointment     |
| View Patient Bills   | Show all bills for a specific patient                               |
| Show Polymorphism    | Demonstrate virtual function calls through a base class pointer     |

---

## How to Set Up and Run

### Requirements

- A C++ compiler (g++ recommended)
- Windows, Linux, or macOS terminal

### Compile

```bash
g++ main.cpp -o hospital
```

### Run

On Linux/macOS:
```bash
./hospital
```

On Windows:
```bash
hospital.exe
```

### Example Session

```
Main Menu
1. Patient Management
2. Doctor Management
3. Appointment System
4. Billing System
5. Show Polymorphism
6. Exit
Enter choice: 1

Patient Management
1. Add Patient
2. View All Patients
3. Search Patient
4. Back
Enter choice: 1

Enter name: Ali Khan
Enter age: 30
Enter gender: Male
Enter phone: 0300-1234567
Enter disease: Fever
Patient added. ID: 1
```

---

## Project Structure

```
Hospital Management System/
└── main.cpp       ← entire project in one file
```

All classes are defined and implemented in `main.cpp`:
- `Person` (base class)
- `Patient` (inherits Person)
- `Doctor` (inherits Person)
- `Appointment`
- `Bill`
- Helper functions and menu logic
- `main()` entry point

---

## Limitations

- Data is not saved to a file — everything resets when the program exits
- Maximum 50 records per category (patients, doctors, appointments, bills)
- No strict input format validation (e.g., date format is not enforced)

---

## Conclusion

This project covers all four OOP pillars in a practical setting. Inheritance keeps the code clean by avoiding repetition. Polymorphism lets different classes behave differently for the same method call. Encapsulation keeps data safe. Abstraction hides complexity behind a simple interface.
