# Hospital Management System — Project Report

**Course:** Object-Oriented Programming (OOP)  
**Language:** C++  
**File:** main.cpp (single-file implementation)

---

## 1. Introduction

This project is a console-based Hospital Management System built in C++. It lets users manage patients, doctors, appointments, and billing through a simple menu interface. The entire program is in one file (main.cpp) to keep it easy to compile and follow.

The project was built to demonstrate the four main OOP concepts: encapsulation, inheritance, polymorphism, and abstraction.

---

## 2. Objectives

- Build a working hospital management system using C++ and OOP
- Apply inheritance through Patient and Doctor classes that share a common Person base class
- Use polymorphism with virtual functions so the right displayInfo() method runs based on the object type
- Keep class data private and use getters/setters (encapsulation)
- Keep the project simple and readable

---

## 3. OOP Concepts

### 3.1 Encapsulation

All class data members are private. Public getter and setter methods are used to access or change the data. This protects the internal state of each object.

For example, in the Patient class, `patientID` and `disease` are private. They can only be read through `getPatientID()` and `getDisease()`.

### 3.2 Inheritance

The `Person` class is the base class. It holds attributes shared by both patients and doctors: name, age, gender, and phone number.

`Patient` inherits from `Person` and adds `patientID` and `disease`. `Doctor` also inherits from `Person` and adds `doctorID`, `specialization`, and `fee`. This avoids repeating common code.

| Class   | Inherits From | Extra Attributes                  |
|---------|---------------|-----------------------------------|
| Person  | (base)        | name, age, gender, phone          |
| Patient | Person        | patientID, disease                |
| Doctor  | Person        | doctorID, specialization, fee     |

### 3.3 Polymorphism

`displayInfo()` is declared as `virtual` in `Person`. Both `Patient` and `Doctor` override it with their own version.

When a `Person*` pointer holds a `Patient` or `Doctor` object and `displayInfo()` is called, the correct version runs based on the actual object type at runtime. This is called runtime polymorphism. The program includes a menu option that demonstrates this directly.

### 3.4 Abstraction

Operations like adding a patient or generating a bill are hidden behind simple function calls. The user just provides inputs and sees results — they don't need to know how data is stored or managed internally.

---

## 4. Classes

### Person (Base Class)
Holds name, age, gender, and phone. Has a virtual `displayInfo()` method.

### Patient
Inherits from Person. Adds a unique patient ID and the patient's disease. Overrides `displayInfo()`.

### Doctor
Inherits from Person. Adds a unique doctor ID, specialization, and consultation fee. Overrides `displayInfo()`.

### Appointment
Stores an appointment ID, patient ID, doctor ID, date, and time slot. Links a patient to a doctor.

### Bill
Stores consultation fee, medicine cost, and room charges. Automatically calculates the total when the object is created.

---

## 5. Features

| Feature             | Description                                                   |
|---------------------|---------------------------------------------------------------|
| Add Patient         | Stores patient details in the patients array                  |
| View Patients       | Displays all patient records                                  |
| Search Patient      | Finds a patient by ID                                         |
| Add Doctor          | Stores doctor details including specialization and fee        |
| View Doctors        | Displays all doctor records                                   |
| Book Appointment    | Links a patient with a doctor for a given date and time       |
| View Appointments   | Shows all appointments with patient and doctor names          |
| Generate Bill       | Creates a bill; auto-fills consultation fee from appointment  |
| View Bills          | Shows all bills for a given patient                           |
| Show Polymorphism   | Calls displayInfo() via Person pointer on Patient and Doctor  |

---

## 6. How to Compile and Run

The project is a single file. To compile and run:

```
g++ main.cpp -o hospital
./hospital
```

On Windows:

```
g++ main.cpp -o hospital.exe
hospital.exe
```

No external libraries needed.

---

## 7. Limitations

- Data is not saved to a file — it is lost when the program closes
- Maximum of 50 records per category (patients, doctors, appointments, bills)
- No strict input format validation

---

## 8. Conclusion

This project applies the core OOP concepts in C++ through a practical example. Inheritance avoids repetition by placing shared attributes in a base class. Polymorphism lets different classes define their own behavior for the same method. Encapsulation keeps data safe and only accessible through controlled methods.

The program is kept simple on purpose — one file, straightforward menus, no unnecessary complexity.
