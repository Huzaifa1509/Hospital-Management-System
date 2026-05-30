#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 50;

// Base class
class Person {
protected:
    string name;
    int age;
    string gender;
    string phone;

public:
    Person() : name(""), age(0), gender(""), phone("") {}

    Person(string n, int a, string g, string p)
        : name(n), age(a), gender(g), phone(p) {}

    string getName() { return name; }
    int getAge() { return age; }

    virtual void displayInfo() {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Gender : " << gender << endl;
        cout << "Phone  : " << phone << endl;
    }

    virtual ~Person() {}
};

// Patient inherits from Person
class Patient : public Person {
private:
    int patientID;
    string disease;

public:
    Patient() : Person(), patientID(0), disease("") {}

    Patient(int id, string n, int a, string g, string p, string d)
        : Person(n, a, g, p), patientID(id), disease(d) {}

    int getPatientID() { return patientID; }
    string getDisease() { return disease; }

    void displayInfo() override {
        cout << "\n--- Patient ---" << endl;
        cout << "Patient ID : " << patientID << endl;
        Person::displayInfo();
        cout << "Disease    : " << disease << endl;
    }
};

// Doctor inherits from Person
class Doctor : public Person {
private:
    int doctorID;
    string specialization;
    double fee;

public:
    Doctor() : Person(), doctorID(0), specialization(""), fee(0) {}

    Doctor(int id, string n, int a, string g, string p, string s, double f)
        : Person(n, a, g, p), doctorID(id), specialization(s), fee(f) {}

    int getDoctorID() { return doctorID; }
    string getSpecialization() { return specialization; }
    double getFee() { return fee; }

    void displayInfo() override {
        cout << "\n--- Doctor ---" << endl;
        cout << "Doctor ID       : " << doctorID << endl;
        Person::displayInfo();
        cout << "Specialization  : " << specialization << endl;
        cout << "Consultation Fee: Rs. " << fixed << setprecision(2) << fee << endl;
    }
};

// Appointment class
class Appointment {
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string timeSlot;

public:
    Appointment() : appointmentID(0), patientID(0), doctorID(0), date(""), timeSlot("") {}

    Appointment(int aid, int pid, int did, string d, string t)
        : appointmentID(aid), patientID(pid), doctorID(did), date(d), timeSlot(t) {}

    int getAppointmentID() { return appointmentID; }
    int getPatientID() { return patientID; }
    int getDoctorID() { return doctorID; }

    void display() {
        cout << "\nAppointment ID : " << appointmentID << endl;
        cout << "Patient ID     : " << patientID << endl;
        cout << "Doctor ID      : " << doctorID << endl;
        cout << "Date           : " << date << endl;
        cout << "Time           : " << timeSlot << endl;
    }
};

// Bill class
class Bill {
private:
    int billID;
    int patientID;
    double consultFee;
    double medicineCost;
    double roomCharges;
    double total;

public:
    Bill() : billID(0), patientID(0), consultFee(0), medicineCost(0), roomCharges(0), total(0) {}

    Bill(int bid, int pid, double cf, double mc, double rc)
        : billID(bid), patientID(pid), consultFee(cf), medicineCost(mc), roomCharges(rc) {
        total = cf + mc + rc;
    }

    int getBillID() { return billID; }
    int getPatientID() { return patientID; }

    void display() {
        cout << "\nBill ID          : " << billID << endl;
        cout << "Patient ID       : " << patientID << endl;
        cout << "Consultation Fee : Rs. " << fixed << setprecision(2) << consultFee << endl;
        cout << "Medicine Cost    : Rs. " << medicineCost << endl;
        cout << "Room Charges     : Rs. " << roomCharges << endl;
        cout << "Total            : Rs. " << total << endl;
    }
};

// Arrays to store data
Patient patients[MAX];
Doctor doctors[MAX];
Appointment appointments[MAX];
Bill bills[MAX];

int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int billCount = 0;

int nextPatientID = 1;
int nextDoctorID = 1;
int nextAppointmentID = 1;
int nextBillID = 1;

// Helper: find patient index by ID
int findPatient(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].getPatientID() == id)
            return i;
    }
    return -1;
}

// Helper: find doctor index by ID
int findDoctor(int id) {
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].getDoctorID() == id)
            return i;
    }
    return -1;
}

void addPatient() {
    if (patientCount >= MAX) {
        cout << "Cannot add more patients." << endl;
        return;
    }

    string name, gender, phone, disease;
    int age;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter gender: ";
    getline(cin, gender);
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter disease: ";
    getline(cin, disease);

    patients[patientCount] = Patient(nextPatientID, name, age, gender, phone, disease);
    patientCount++;
    cout << "Patient added. ID: " << nextPatientID << endl;
    nextPatientID++;
}

void viewPatients() {
    if (patientCount == 0) {
        cout << "No patients found." << endl;
        return;
    }
    for (int i = 0; i < patientCount; i++) {
        patients[i].displayInfo();
    }
}

void searchPatient() {
    int id;
    cout << "Enter patient ID: ";
    cin >> id;
    int idx = findPatient(id);
    if (idx != -1)
        patients[idx].displayInfo();
    else
        cout << "Patient not found." << endl;
}

void addDoctor() {
    if (doctorCount >= MAX) {
        cout << "Cannot add more doctors." << endl;
        return;
    }

    string name, gender, phone, spec;
    int age;
    double fee;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter gender: ";
    getline(cin, gender);
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter specialization: ";
    getline(cin, spec);
    cout << "Enter consultation fee: ";
    cin >> fee;

    doctors[doctorCount] = Doctor(nextDoctorID, name, age, gender, phone, spec, fee);
    doctorCount++;
    cout << "Doctor added. ID: " << nextDoctorID << endl;
    nextDoctorID++;
}

void viewDoctors() {
    if (doctorCount == 0) {
        cout << "No doctors found." << endl;
        return;
    }
    for (int i = 0; i < doctorCount; i++) {
        doctors[i].displayInfo();
    }
}

void bookAppointment() {
    if (patientCount == 0 || doctorCount == 0) {
        cout << "Add patients and doctors first." << endl;
        return;
    }

    cout << "\nAvailable Patients:" << endl;
    for (int i = 0; i < patientCount; i++)
        cout << "  ID " << patients[i].getPatientID() << " - " << patients[i].getName() << endl;

    int pid;
    cout << "Enter patient ID: ";
    cin >> pid;
    if (findPatient(pid) == -1) {
        cout << "Patient not found." << endl;
        return;
    }

    cout << "\nAvailable Doctors:" << endl;
    for (int i = 0; i < doctorCount; i++)
        cout << "  ID " << doctors[i].getDoctorID() << " - " << doctors[i].getName()
             << " (" << doctors[i].getSpecialization() << ")" << endl;

    int did;
    cout << "Enter doctor ID: ";
    cin >> did;
    if (findDoctor(did) == -1) {
        cout << "Doctor not found." << endl;
        return;
    }

    string date, timeSlot;
    cin.ignore();
    cout << "Enter date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter time slot: ";
    getline(cin, timeSlot);

    appointments[appointmentCount] = Appointment(nextAppointmentID, pid, did, date, timeSlot);
    appointmentCount++;
    cout << "Appointment booked. ID: " << nextAppointmentID << endl;
    nextAppointmentID++;
}

void viewAppointments() {
    if (appointmentCount == 0) {
        cout << "No appointments found." << endl;
        return;
    }
    for (int i = 0; i < appointmentCount; i++) {
        appointments[i].display();
        int pi = findPatient(appointments[i].getPatientID());
        int di = findDoctor(appointments[i].getDoctorID());
        if (pi != -1) cout << "Patient : " << patients[pi].getName() << endl;
        if (di != -1) cout << "Doctor  : " << doctors[di].getName() << endl;
    }
}

void generateBill() {
    if (patientCount == 0) {
        cout << "No patients in the system." << endl;
        return;
    }

    cout << "\nAvailable Patients:" << endl;
    for (int i = 0; i < patientCount; i++)
        cout << "  ID " << patients[i].getPatientID() << " - " << patients[i].getName() << endl;

    int pid;
    cout << "Enter patient ID: ";
    cin >> pid;
    if (findPatient(pid) == -1) {
        cout << "Patient not found." << endl;
        return;
    }

    double cf = 0, mc, rc;

    // check if patient has appointment, auto-fill consultation fee
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].getPatientID() == pid) {
            int di = findDoctor(appointments[i].getDoctorID());
            if (di != -1) {
                cf = doctors[di].getFee();
                cout << "Consultation fee from appointment: Rs. " << cf << endl;
                break;
            }
        }
    }

    if (cf == 0) {
        cout << "Enter consultation fee: ";
        cin >> cf;
    }

    cout << "Enter medicine cost: ";
    cin >> mc;
    cout << "Enter room charges: ";
    cin >> rc;

    bills[billCount] = Bill(nextBillID, pid, cf, mc, rc);
    bills[billCount].display();
    billCount++;
    nextBillID++;
}

void viewBills() {
    if (billCount == 0) {
        cout << "No bills found." << endl;
        return;
    }
    int pid;
    cout << "Enter patient ID: ";
    cin >> pid;
    bool found = false;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].getPatientID() == pid) {
            bills[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No bills found for this patient." << endl;
}

// Demonstrates polymorphism using base class pointer
void showPolymorphism() {
    if (patientCount == 0 && doctorCount == 0) {
        cout << "Add some patients and doctors first." << endl;
        return;
    }

    Person* p;

    if (patientCount > 0) {
        cout << "\nCalling displayInfo() via Person pointer on a Patient object:" << endl;
        p = &patients[0];
        p->displayInfo();
    }

    if (doctorCount > 0) {
        cout << "\nCalling displayInfo() via Person pointer on a Doctor object:" << endl;
        p = &doctors[0];
        p->displayInfo();
    }
}

void patientMenu() {
    int choice;
    do {
        cout << "\nPatient Management" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addPatient();
        else if (choice == 2) viewPatients();
        else if (choice == 3) searchPatient();
        else if (choice != 4) cout << "Invalid choice." << endl;

    } while (choice != 4);
}

void doctorMenu() {
    int choice;
    do {
        cout << "\nDoctor Management" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. View All Doctors" << endl;
        cout << "3. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addDoctor();
        else if (choice == 2) viewDoctors();
        else if (choice != 3) cout << "Invalid choice." << endl;

    } while (choice != 3);
}

void appointmentMenu() {
    int choice;
    do {
        cout << "\nAppointment System" << endl;
        cout << "1. Book Appointment" << endl;
        cout << "2. View Appointments" << endl;
        cout << "3. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) bookAppointment();
        else if (choice == 2) viewAppointments();
        else if (choice != 3) cout << "Invalid choice." << endl;

    } while (choice != 3);
}

void billingMenu() {
    int choice;
    do {
        cout << "\nBilling System" << endl;
        cout << "1. Generate Bill" << endl;
        cout << "2. View Bills" << endl;
        cout << "3. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) generateBill();
        else if (choice == 2) viewBills();
        else if (choice != 3) cout << "Invalid choice." << endl;

    } while (choice != 3);
}

int main() {
    cout << "Hospital Management System" << endl;

    int choice;
    do {
        cout << "\nMain Menu" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Management" << endl;
        cout << "3. Appointment System" << endl;
        cout << "4. Billing System" << endl;
        cout << "5. Show Polymorphism" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) patientMenu();
        else if (choice == 2) doctorMenu();
        else if (choice == 3) appointmentMenu();
        else if (choice == 4) billingMenu();
        else if (choice == 5) showPolymorphism();
        else if (choice == 6) cout << "Goodbye!" << endl;
        else cout << "Invalid choice." << endl;

    } while (choice != 6);

    return 0;
}
