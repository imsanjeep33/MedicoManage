#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
public:
    int patientID;
    string name;
    int age;
    string gender;
    string contactInfo;
    string medicalHistory;

    Patient(int id, string n, int a, string g, string contact, string history)
        : patientID(id), name(n), age(a), gender(g), contactInfo(contact), medicalHistory(history) {}
};

class Doctor {
public:
    int doctorID;
    string name;
    string specialization;
    string contactInfo;

    Doctor(int id, string n, string spec, string contact)
        : doctorID(id), name(n), specialization(spec), contactInfo(contact) {}
};

class Appointment {
public:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
    string status;

    Appointment(int id, int patient, int doctor, string d, string t, string stat)
        : appointmentID(id), patientID(patient), doctorID(doctor), date(d), time(t), status(stat) {}
};

class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    int patientIDCounter;
    int doctorIDCounter;
    int appointmentIDCounter;

public:
    Hospital() : patientIDCounter(1), doctorIDCounter(1), appointmentIDCounter(1) {}

    void AddPatient() {
        cout << "Enter patient details:" << endl;
        string name, gender, contact, history;
        int age;

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin.ignore();
        getline(cin, gender);
        cout << "Contact Info: ";
        cin.ignore();
        getline(cin, contact);
        cout << "Medical History: ";
        cin.ignore();
        getline(cin, history);

        patients.emplace_back(patientIDCounter++, name, age, gender, contact, history);
        cout << "Patient added with ID: " << patientIDCounter - 1 << endl;
    }

    void AddDoctor() {
        cout << "Enter doctor details:" << endl;
        string name, specialization, contact;

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Specialization: ";
        cin.ignore();
        getline(cin, specialization);
        cout << "Contact Info: ";
        cin.ignore();
        getline(cin, contact);

        doctors.emplace_back(doctorIDCounter++, name, specialization, contact);
        cout << "Doctor added with ID: " << doctorIDCounter - 1 << endl;
    }

    void CreateAppointment() {
        cout << "Enter appointment details:" << endl;
        int patientID, doctorID;
        string date, time;

        cout << "Patient ID: ";
        cin >> patientID;
        cout << "Doctor ID: ";
        cin >> doctorID;
        cout << "Date (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, date);
        cout << "Time: ";
        getline(cin, time);

        appointments.emplace_back(appointmentIDCounter++, patientID, doctorID, date, time, "Pending");
        cout << "Appointment created with ID: " << appointmentIDCounter - 1 << endl;
    }

    void ViewPatientInformation() {
        int patientID;
        cout << "Enter Patient ID: ";
        cin >> patientID;

        for (const Patient& p : patients) {
            if (p.patientID == patientID) {
                cout << "Patient Information for ID " << p.patientID << ":" << endl;
                cout << "Name: " << p.name << endl;
                cout << "Age: " << p.age << endl;
                cout << "Gender: " << p.gender << endl;
                cout << "Contact Info: " << p.contactInfo << endl;
                cout << "Medical History: " << p.medicalHistory << endl;
                return;
            }
        }
        cout << "Patient not found with ID " << patientID << endl;
    }

    void ViewDoctorInformation() {
        int doctorID;
        cout << "Enter Doctor ID: ";
        cin >> doctorID;

        for (const Doctor& d : doctors) {
            if (d.doctorID == doctorID) {
                cout << "Doctor Information for ID " << d.doctorID << ":" << endl;
                cout << "Name: " << d.name << endl;
                cout << "Specialization: " << d.specialization << endl;
                cout << "Contact Info: " << d.contactInfo << endl;
                return;
            }
        }
        cout << "Doctor not found with ID " << doctorID << endl;
    }

    void ViewAppointmentInformation() {
        int appointmentID;
        cout << "Enter Appointment ID: ";
        cin >> appointmentID;

        for (const Appointment& a : appointments) {
            if (a.appointmentID == appointmentID) {
                cout << "Appointment Information for ID " << a.appointmentID << ":" << endl;
                cout << "Patient ID: " << a.patientID << endl;
                cout << "Doctor ID: " << a.doctorID << endl;
                cout << "Date: " << a.date << endl;
                cout << "Time: " << a.time << endl;
                cout << "Status: " << a.status << endl;
                return;
            }
        }
        cout << "Appointment not found with ID " << appointmentID << endl;
    }
};

int main() {
    Hospital hospital;

    int choice;
    while (true) {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Create Appointment\n";
        cout << "4. View Patient Information\n";
        cout << "5. View Doctor Information\n";
        cout << "6. View Appointment Information\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.AddPatient();
                break;
            case 2:
                hospital.AddDoctor();
                break;
            case 3:
                hospital.CreateAppointment();
                break;
            case 4:
                hospital.ViewPatientInformation();
                break;
            case 5:
                hospital.ViewDoctorInformation();
                break;
            case 6:
                hospital.ViewAppointmentInformation();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
