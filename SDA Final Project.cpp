#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <limits>
using namespace std;

class main
{
protected:
    string name, id;
public:
    main()
    {
        name = id = " ";
    }
    virtual void print() = 0;
};

class academic_officer : public main
{
    string officer_name, officer_id;
public:
    academic_officer()
    {
        officer_name = officer_id = " ";
    }
    void set_name(string name)
    {
        officer_name = name;
    }
    void set_id(string id)
    {
        officer_id = id;
    }
    string get_id()
    {
        return officer_id;
    }
    string get_name()
    {
        return officer_name;
    }
    void print()
    {
        cout << "Academic Officer - Name: " << officer_name << ", ID: " << officer_id << endl;
    }
};

class teacher : public main
{
    string teacher_name, teacher_id;
public:
    teacher()
    {
        teacher_name = teacher_id = " ";
    }
    void set_name(string name)
    {
        teacher_name = name;
    }
    void set_id(string id)
    {
        teacher_id = id;
    }
    string get_id()
    {
        return teacher_id;
    }
    string get_name()
    {
        return teacher_name;
    }
    void print()
    {
        cout << "Teacher - Name: " << teacher_name << ", ID: " << teacher_id << endl;
    }
};

class clos :public main {
    string name, id, desc;
public:
    clos()
    {
        name = id = desc = " ";
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_desc(string desc)
    {
        this->desc = desc;
    }
    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id;
    }
    string get_desc()
    {
        return desc;
    }
    void print()
    {
        cout << "id : " << id << "  " << "name : " << name << "  " << "description : " << desc << endl;
    }
};
class plos : public main {
    string name, id, desc;
public:
    plos()
    {
        name = id = desc = " ";
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_desc(string desc)
    {
        this->desc = desc;
    }
    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id;
    }
    string get_desc()
    {
        return desc;
    }
    void print()
    {
        cout << "id : " << id << "  " << "name : " << name << "  " << "description : " << desc << endl;
    }
};
class programes :public main
{
    string name, id;
    string* plos;
    int num_plos;
public:
    programes()
    {
        name = id = "";
        plos = nullptr;
        num_plos = 0;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_plo(string* p, int size)
    {
        plos = new string[size];
        num_plos = size;
        for (int i = 0; i < size; i++)
        {
            plos[i] = p[i];
        }
    }
    string get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    string* get_plos()
    {
        return plos;
    }
    int get_num_plos()
    {
        return num_plos;
    }
    void print()
    {
        cout << "Programe Name :" << name << endl;
        cout << "Id :" << id << endl;
        cout << "Plo's assoctiated with this programe  " << endl;
        for (int i = 0; i < num_plos; i++)
        {
            cout << i + 1 << ": " << plos[i] << endl;
        }
        cout << endl << " ------------------------------------------------------ " << endl;
    }

};
class course :public main
{
    string name, id, programe;
    string* clos;
    int num_clo;
public:
    course()
    {
        name = id = " ";
        clos = nullptr;
        num_clo = 0;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_programe(string programe)
    {
        this->programe = programe;
    }
    void set_clo(string* p, int size)
    {
        clos = new string[size];
        num_clo = size;
        for (int i = 0; i < size; i++)
        {
            clos[i] = p[i];
        }
    }

    string get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    string get_programe()
    {
        return programe;
    }
    string* get_clos()
    {
        return clos;
    }

    string get_checkclo()
    {
        string concatenated_clos;
        //int for_invajulation_clos_number = num_clo - 2;
        for (int i = 0; i < num_clo; ++i) {
            concatenated_clos += clos[i];
            if (i < num_clo - 1) { // Add a space after each string except the last one
                concatenated_clos += " ";
            }
        }

        return concatenated_clos; // Store the concatenated string
    }
    void print()
    {
        cout << endl;
        cout << "Course Name :" << name << endl;
        cout << "Id :" << id << endl;
        cout << "Programe : " << programe << endl;
        cout << "Clo's assoctiated with this Course  :" << endl;
        for (int i = 0; i < num_clo; i++)
        {
            cout << i + 1 << ": " << clos[i] << endl;
        }
        cout << "\t\t ***************** " << endl;
    }
};
class topics :public main
{
    string name, id, programe;
    string* clos;
    int num_clo;
public:
    topics()
    {
        name = id = " ";
        clos = nullptr;
        num_clo = 0;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_programe(string programe)
    {
        this->programe = programe;
    }
    void set_clo(string* p, int size)
    {
        clos = new string[size];
        num_clo = size;
        for (int i = 0; i < size; i++)
        {
            clos[i] = p[i];
        }
    }

    string get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    string get_programe()
    {
        return programe;
    }
    string* get_plos()
    {
        return clos;
    }
    void print()
    {
        cout << endl;
        cout << "Topic Name :" << name << endl;
        cout << "Clo's assoctiated with this Topic  :";
        for (int i = 0; i < num_clo; i++)
        {
            cout << i + 1 << ": " << clos[i] << endl << endl;
        }
        cout << "\t\t ***************** " << endl;
    }
};
class Evaluation {
    string name;
    string type;
    string description;
    string* clos;
    int num_clo;

public:
    Evaluation() {
        name = type = description = " ";
        clos = nullptr;
        num_clo = 0;
    }

    void set_name(string name) {
        this->name = name;
    }

    void set_type(string type) {
        this->type = type;
    }

    void set_description(string description) {
        this->description = description;
    }

    void set_clos(string* p, int size) {
        clos = new string[size];
        num_clo = size;
        for (int i = 0; i < size; i++) {
            clos[i] = p[i];
        }
    }

    string get_name() const {
        return name;
    }

    string get_type() const {
        return type;
    }

    string get_description() const {
        return description;
    }

    string* get_clos() const {
        return clos;
    }

    int get_num_clo() const {
        return num_clo;
    }

    string get_checkclo()const {

        // num_clo = size;
         // Concatenate all strings from p into one string
        string concatenated_clos;
        int for_invajulation_clos_number = num_clo - 2;
        for (int i = for_invajulation_clos_number; i < num_clo; ++i) {
            concatenated_clos += clos[i];
            if (i < num_clo - 1) { // Add a space after each string except the last one
                concatenated_clos += " ";
            }
        }

        return concatenated_clos; // Store the concatenated string

    }
    void print() const {
        cout << "\n\nEvaluation Name: " << name << endl;
        cout << "Evaluation Type: " << type << endl;
        cout << "Question Description: " << description << endl;
        cout << "CLOs: ";
        for (int i = 0; i < num_clo - 1; ++i) {
            cout << clos[i];
            if (i < num_clo - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
};

int count_lines(const string& filename)
{
    int count = 0;
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            count++;
        }
        file.close();
    }
    else
    {
        cout << "Error: Unable to open file " << filename << endl;
    }
    return count;
}

academic_officer* read_academicofficer(int& num_officer)
{
    num_officer = count_lines("academic.txt");
    academic_officer* academic = new academic_officer[num_officer];
    string id, name;
    string line;
    ifstream in("academic.txt");
    if (in.is_open())
    {
        for (int i = 0; i < num_officer; ++i)
        {
            getline(in, line);
            stringstream ss(line);
            ss >> name >> id;
            academic[i].set_name(name);
            academic[i].set_id(id);
        }
        in.close();
    }
    else
    {
        cout << "error in opening of file" << endl;
    }
    return academic;
}
teacher* read_teachers(int& num_teachers)
{
    num_teachers = count_lines("teacher.txt");
    teacher* teachers = new teacher[num_teachers];
    string id, name;
    string line;
    ifstream in("teacher.txt");
    if (in.is_open())
    {
        for (int i = 0; i < num_teachers; ++i)
        {
            getline(in, line);
            stringstream ss(line);
            ss >> name >> id;
            teachers[i].set_name(name);
            teachers[i].set_id(id);
        }
        in.close();
    }
    else
    {
        cout << "error in opening of file" << endl;
    }
    return teachers;
}
plos* read_plos(int& num_plos)
{
    num_plos = count_lines("plos.txt");
    plos* pl = new plos[num_plos];
    string line;
    string id, name, desc;
    ifstream in("plos.txt");
    if (in.is_open())
    {
        for (int i = 0; i < num_plos; ++i)
        {
            getline(in, line);
            stringstream ss(line);

            // Read name until we reach "-"
            name = "";
            string temp;
            while (ss >> temp && temp != "-")
            {
                if (!name.empty())
                    name += " ";
                name += temp;
            }

            // Read the ID
            ss >> id;

            // Read the rest of the line as description
            getline(ss, desc);

            // Set the attributes
            name.erase(std::remove(name.begin(), name.end(), '\t'), name.end()); // Remove tabs
            //cout << name << " "<<id<<" "<<desc<<endl;
            pl[i].set_name(name);
            pl[i].set_id(id);
            pl[i].set_desc(desc);
        }
        in.close();
    }
    else
    {
        cout << "Error: Unable to open file 'plos.txt'" << endl;
        delete[] pl; // Delete dynamically allocated memory before returning nullptr
        return nullptr; // Return nullptr on error
    }
    return pl;
}
programes* read_programe(int& num_programes)
{
    num_programes = count_lines("programes.txt");
    string name, id, plos[100], line;
    programes* programs = new programes[num_programes];
    ifstream in("programes.txt");
    if (in.is_open())
    {
        for (int i = 0; i < num_programes; i++)
        {
            getline(in, line);
            stringstream ss(line);
            ss >> name >> id;
            // Read PLOs until the end of the line
            string plo;
            int index = 0;
            while (ss >> plo && plo != "-") {
                plos[index++] = plo;
            }
            programs[i].set_name(name);
            programs[i].set_id(id);
            programs[i].set_plo(plos, index);
        }
        in.close();
        return programs;
    }
    else
    {
        cout << "error in opeing of programes file while reading " << endl;
    }

}
clos* read_clos(int& num_clos)
{
    num_clos = count_lines("avclos.txt");
    clos* cl = new clos[num_clos];
    string line;
    string id, name, desc;
    ifstream in("avclos.txt");
    if (in.is_open())
    {
        for (int i = 0; i < num_clos; ++i)
        {
            getline(in, line);
            stringstream ss(line);
            ss >> name >> id;
            getline(ss, desc);
            cl[i].set_name(name);
            cl[i].set_id(id);
            cl[i].set_desc(desc);
        }
        in.close();
    }
    else
    {
        cout << "Error: Unable to open file 'plos.txt'" << endl;
        delete[] cl; // Delete dynamically allocated memory before returning nullptr
        return nullptr; // Return nullptr on error
    }
    return cl;
}
course* read_courses(int& num_courses) {
    ifstream in("courses.txt");
    if (!in.is_open()) {
        cerr << "Error: Unable to open course file." << endl;
        num_courses = 0;
        return nullptr;
    }

    num_courses = count_lines("courses.txt");
    // cout << num_courses << " number of courses " << endl;
    course* courses = new course[num_courses];

    string line;
    for (int i = 0; i < num_courses; ++i) {
        getline(in, line);
        stringstream ss(line);
        string program_name, course_name, course_id;
        string* clos;
        clos = new string[100];
        int num_clos = 0;

        ss >> program_name;
        courses[i].set_programe(program_name);
        string temp;
        while (ss >> temp && temp != "-") {
            course_name += (temp + " ");
        }

        if (!course_name.empty()) {
            course_name.pop_back();
        }


        courses[i].set_name(course_name);
        ss >> course_id;
        while (ss >> temp && temp != "-") {
            clos[num_clos] = temp;
            num_clos++;
        }


        courses[i].set_clo(clos, num_clos);

        ss >> program_name;
        courses[i].set_programe(program_name);

        courses[i].set_id(course_id);
    }

    in.close();
    return courses;
}
topics* read_topics(int& num_topics) {
    ifstream in("topics.txt");
    if (!in.is_open()) {
        cerr << "Error: Unable to open topics file." << endl;
        num_topics = 0;
        return nullptr;
    }

    num_topics = count_lines("topics.txt");
    topics* topicss = new topics[num_topics];

    string line;
    for (int i = 0; i < num_topics; ++i) {
        getline(in, line);
        stringstream ss(line);
        string course_name;
        string* clos;
        clos = new string[100];
        int num_clos = 0;

        // Read course name until '-' is encountered
        getline(ss, course_name, '-');

        // Read CLOs
        string temp;
        while (ss >> temp && temp != "-") {
            clos[num_clos++] = temp;
        }

        // Set course name and CLOs for the topics object
        topicss[i].set_name(course_name);
        topicss[i].set_clo(clos, num_clos);
    }

    in.close();
    return topicss;
}
Evaluation* read_evaluations(int& num_evaluations) {
    ifstream in("evaluations.txt");
    if (!in.is_open()) {
        cerr << "Error: Unable to open evaluation file." << endl;
        num_evaluations = 0;
        return nullptr;
    }

    num_evaluations = count_lines("evaluations.txt");
    Evaluation* evaluations = new Evaluation[num_evaluations];

    string line;
    for (int i = 0; i < num_evaluations; ++i) {
        getline(in, line);
        stringstream ss(line);

        // Read name
        string name;
        getline(ss, name, '-');
        evaluations[i].set_name(name);

        // Read type
        string type;
        getline(ss, type, '-');
        evaluations[i].set_type(type);

        // Read description
        string description;
        getline(ss, description, '-');
        evaluations[i].set_description(description);

        // Read CLOs
        string clo_data;
        getline(ss, clo_data);
        stringstream clo_ss(clo_data);
        string clo;
        int num_clos = 0;
        while (clo_ss >> clo) {
            num_clos++;
        }

        // Allocate memory for CLOs
        evaluations[i].set_clos(new string[num_clos], num_clos);

        // Read CLOs again to store in array
        clo_ss.clear();
        clo_ss.seekg(0);
        num_clos = 0;
        while (clo_ss >> clo) {
            evaluations[i].get_clos()[num_clos++] = clo;
        }
    }

    in.close();
    return evaluations;
}

void pauseProgram() {
    cout << "Press ENTER to continue...";
    // Ignore any characters currently in the input buffer
    cin.ignore(32767, '\n'); // Assuming maximum buffer size is 32767 characters
    cin.get();
}
void readclo_plo()
{

    string line, plo_id, clo_id;
    int num_clos;
    clos* cl = read_clos(num_clos);
    ifstream in("clos.txt");
    if (in.is_open())
    {
        while (getline(in, line)) {
            stringstream ss(line);
            ss >> plo_id;
            cout << "PLO ID: " << plo_id << endl;
            //cout << endl;
            while (ss >> clo_id)
            {
                for (int i = 0; i < num_clos; i++)
                {
                    if (cl[i].get_name() == clo_id)
                    {
                        cout << "Clo number:  " << clo_id << "  " << endl;
                        cout << "Clo description:  " << cl[i].get_desc() << endl;

                    }
                }

            }
            cout << endl << "********************************************************" << endl;
        }
    }
    else
    {
        cout << "error in opeing of file " << endl;
    }
}

void AddCourse(int& num_course, programes* p, int& num_programes)
{
    string name, id, clos[100], programe;
    num_programes = count_lines("programes.txt");
    int select_prog;
    cout << "select programe no for course " << endl;
    for (int i = 0; i < num_programes; i++)
    {
        cout << i + 1 << " : " << p[i].get_name() << endl;
    }
    cin >> select_prog;
    programe = p[select_prog - 1].get_name();
    cout << programe << " has been slected for course " << endl;

    string line, plo_name, clo_id, plo_id;
    int k = 0;
    ifstream in("clos.txt");
    if (in.is_open())
    {
        while (getline(in, line)) {
            stringstream ss(line);
            while (ss >> plo_id && plo_id.find("-") == string::npos) {
                //cout << plo_id << " ";
            }
            //cout << endl;
            while (ss >> clo_id)
            {
                if (k == 0)
                {
                    clos[k++] = clo_id;
                }
                else
                {
                    bool f = false;
                    for (int i = 0; i < k; i++)
                    {
                        if (clos[i] == clo_id)
                        {
                            f = true;
                            break;
                        }
                    }
                    if (f == false)
                    {
                        clos[k++] = clo_id;
                    }
                }

            }
            cout << endl;
        }
    }
    else
    {
        cout << "Error: Unable to open file 'clos.txt'" << endl;
    }

    ofstream out("courses.txt", ios::app);
    if (out.is_open())
    {
        cout << "enter name of course " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "enter  id of course " << endl;
        cin >> id;
        out << programe << " ";
        out << name << " - ";
        out << id << "  ";
        while (true)
        {
            cout << "select clo's for the courses " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << i + 1 << " : " << clos[i] << endl;
            }
            int chose, turn;
            cin >> chose;
            out << clos[chose - 1] << " ";
            cout << "would you want to add more clo's ? enter 0 for stop " << endl;
            cin >> turn;
            if (turn == 0)
            {
                out << " - " << endl;
                break;
            }
        }
        out.close();
    }
    else
    {
        cout << "error in opeing of courses file while entering " << endl;
    }


}
void AddPlo(int& num_plos)
{
    string name, id, desc;
    int count = 0;
    cout << "How many PLOs do you want to add? " << endl;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter name of PLO: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID of PLO: " << endl;
        cin >> id;
        cin.ignore();
        cout << "Enter description of PLO: " << endl;
        getline(cin, desc);

        ofstream out("plos.txt", ios::app);
        if (out.is_open())
        {
            out << name << " - " << id << " " << desc << endl;
            cout << "PLO has been added successfully " << endl;
            Sleep(1000);
            system("cls");
            out.close();
        }
        else
        {
            cout << "Error in opening 'plos.txt' while adding new PLO " << endl;
        }

    }
}
void AddPrograme(plos* p, int& num_plos)
{
    string name, id, plos[100], line;
    int k = 0;
    cout << "enter name of programe " << endl;
    cin >> name;
    cout << "enter id of programe " << endl;
    cin >> id;
    bool found = true;
    int end;
    while (found)
    {
        cout << "select plo number from  these programes " << endl;
        int select;
        for (int i = 0; i < num_plos - 1; i++)
        {
            cout << "plo " << i + 1 << "  " << p[i].get_name() << endl;
        }
        cin >> select;
        plos[k++] = p[select - 1].get_id();
        cout << "enter 0 if you are agreed with only these plos otherwise enter 1" << endl;
        cin >> end;
        if (end == 0)
        {
            found = false;
        }
    }

    ofstream out("programes.txt", ios::app);
    if (out.is_open())
    {
        out << name << " " << id << " ";
        for (int i = 0; i < k; i++)
        {
            out << plos[i] << " ";
        }
        out << "-" << endl;
        out.close();
    }
    else
    {
        cout << "error in opeing of programes file " << endl;
    }

}
void AddClo(plos* p, int& num_plos)
{
    int num_clos;
    clos* cl = read_clos(num_clos);
    string clos[100];
    int k = 0;
    int select;
    ofstream out("clos.txt", ios::app);
    for (int j = 0; j < 2; j++)
    {
        cout << "select clo's for this plo  " << p[j].get_name() << endl;
        while (true)
        {
            for (int i = 0; i < num_clos; i++)
            {
                cout << i + 1 << " : " << cl[i].get_name() << endl;
            }
            cin >> select;
            clos[k++] = cl[select - 1].get_name();
            string choice;
            cout << "would you want to add more clos for this plo ?. enter y otherwise enter n";
            cin >> choice;
            if (choice == "n")
            {
                break;
                //k = 0;
            }
        }
        out << p[j].get_id() << " ";
        for (int m = 0; m < k; m++)
        {
            out << clos[m] << " ";
        }
        out << endl;
        k = 0;
        system("cls");
    }
    out.close();
    delete[] cl;
}
void AddEvaluation()
{
    string name, type, desc;
    int count = 0;
    cout << "How many evaluations do you want to add? " << endl;
    cin >> count;
    cin.ignore(); // Clear the input buffer

    const int MAX_CLOS = 100;
    string clos[MAX_CLOS];
    int num_clos = 0;

    ifstream clos_file("clos.txt");
    if (clos_file.is_open())
    {
        string clo_id;
        while (getline(clos_file, clo_id) && num_clos < MAX_CLOS)
        {
            clos[num_clos++] = clo_id;
        }
        clos_file.close();
    }
    else
    {
        cout << "Error: Unable to open file 'clos.txt'" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "Enter name of Evaluation: " << endl;
        getline(cin, name);
        cout << "Enter Type of Evaluation: " << endl;
        getline(cin, type);
        cout << "Enter description of Evaluation: " << endl;
        getline(cin, desc);

        ofstream out("evaluations.txt", ios::app);
        if (out.is_open())
        {
            // Store data in the specified format
            out << name << " - " << type << " - " << desc << " - CLOs: ";

            // Display available CLOs
            cout << "Available CLOs:" << endl;
            for (int j = 0; j < num_clos; j++)
            {
                cout << j + 1 << ": " << clos[j] << endl;
            }

            // Allow user to choose CLOs
            while (true)
            {
                int choice;
                cout << "Enter the number of the CLO to associate with the evaluation (enter 0 to finish): ";
                cin >> choice;
                if (choice == 0) break;
                if (choice < 1 || choice > num_clos)
                {
                    cout << "Invalid choice! Please enter a valid CLO number." << endl;
                    continue;
                }
                out << clos[choice - 1] << " "; // Write selected CLO
            }
            out << endl << endl; // Add newline and empty line
            out.close();
            cout << "Evaluation has been added successfully " << endl;
        }
        else
        {
            cout << "Error in opening 'evaluations.txt' while adding new Evaluation " << endl;
        }
    }
}
void AddTopic(topics* c, int& num_course)
{
    string name, id, clos[100], course;
    num_course = count_lines("courses.txt");

    string line, plo_name, clo_id, plo_id;
    int k = 0;
    ifstream in("clos.txt");
    if (in.is_open())
    {
        while (getline(in, line)) {
            stringstream ss(line);
            //while (ss >> plo_id && plo_id.find("-") == string::npos) {
            //    //cout << plo_id << " ";
            //}
            ////cout << endl;
            while (ss >> clo_id)
            {
                if (k == 0)
                {
                    clos[k++] = clo_id;
                }
                else
                {
                    bool f = false;
                    for (int i = 0; i < k; i++)
                    {
                        if (clos[i] == clo_id)
                        {
                            f = true;
                            break;
                        }
                    }
                    if (f == false)
                    {
                        clos[k++] = clo_id;
                    }
                }

            }
            cout << endl;
        }
    }
    else
    {
        cout << "Error: Unable to open file 'clos.txt'" << endl;
    }

    ofstream out("topics.txt", ios::app);
    if (out.is_open())
    {
        cout << "Enter name of Topic " << endl;
        cin.ignore();
        getline(cin, name);
        out << name << " - ";

        int num_clos = 0; // To keep track of the number of CLOs added
        while (true)
        {
            cout << "select clo's for the courses " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << i + 1 << " : " << clos[i] << endl;
            }
            int chose, turn;
            cin >> chose;
            if (num_clos > 0) {
                out << " "; // Add space between CLO entries
            }
            out << clos[chose - 1]; // Write CLO
            num_clos++; // Increment the count of CLOs added
            cout << "would you want to add more clo's ? enter 0 for stop " << endl;
            cin >> turn;
            if (turn == 0)
            {
                break;
            }
        }
        out << endl; // Add newline after all CLOs are added
        out.close();
    }
    else
    {
        cout << "error in opening of topics file while entering " << endl;
    }


    /*ofstream out("topics.txt", ios::app);
    if (out.is_open())
    {
        cout << "Enter name of Topic " << endl;
        cin.ignore();
        getline(cin, name);
        out << name << " - ";

        while (true)
        {
            cout << "select clo's for the courses " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << i + 1 << " : " << clos[i] << endl;
            }
            int chose, turn;
            cin >> chose;
            out << clos[chose - 1] << " ";
            cout << "would you want to add more clo's ? enter 0 for stop " << endl;
            cin >> turn;
            if (turn == 0)
            {
                out << endl;
                break;
            }
        }
        out.close();
    }
    else
    {
        cout << "error in opening of topics file while entering " << endl;
    }*/
}

void DeletePlo(plos* p, int& num_plos)
{
    string plo_name, plo_id;
    system("cls");
    int select;
    cout << "select plo number to delete " << endl;
    for (int i = 0; i < num_plos - 1; i++)
    {
        cout << p[i].get_id() << "  " << p[i].get_name() << "   " << p[i].get_desc() << endl;
    }
    cin >> select;
    plo_name = p[select - 1].get_name();
    plo_id = p[select - 1].get_id();
    //cout << plo_name << "  " << plo_id << " has been selected for deletion " << endl;
    // deletion from clos fie
    string line;
    ifstream inFile("plos.txt");
    ofstream tempFile("temp.txt", ios::app);
    if (inFile.is_open())
    {
        for (int i = 0; i < num_plos; ++i)
        {
            getline(inFile, line);
            stringstream ss(line);

            // Read name until we reach "-"
            string name = "";
            string id, desc;
            string temp;
            while (ss >> temp && temp != "-")
            {
                if (!name.empty())
                    name += " ";
                name += temp;
            }

            // Read the ID
            ss >> id;

            // Read the rest of the line as description
            getline(ss, desc);

            // Set the attributes
            name.erase(std::remove(name.begin(), name.end(), '\t'), name.end()); // Remove tabs
            //cout << name << " "<<id<<" "<<desc<<endl;
            if (name == plo_name)
            {
                //cout << name << " hase been found " << endl;
                continue;
            }
            else
            {
                tempFile << name << " - " << id << " " << desc << endl;
            }
        }
        inFile.close();
        tempFile.close();
    }
    else
    {
        cout << "error in opeing of plos file for deleting " << endl;
    }
    remove("plos.txt");
    rename("temp.txt", "plos.txt");

    // deleting this plo from programes

    int num_programes = count_lines("programes.txt");
    string prog_name, prog_id, plos[100], line1;
    programes* programs = new programes[num_programes];
    ifstream in("programes.txt");
    ofstream tempFile1("temp1.txt", ios::app);
    if (in.is_open())
    {
        for (int i = 0; i < num_programes; i++)
        {
            getline(in, line1);
            stringstream ss(line1);
            ss >> prog_name >> prog_id;
            // Read PLOs until the end of the line
            string plo;
            int index = 0;
            while (ss >> plo && plo != "-") {
                if (plo != plo_id)
                {
                    plos[index++] = plo;
                }
            }

            tempFile1 << prog_name << " " << prog_id << " ";
            for (int i = 0; i < index; i++)
            {
                tempFile1 << plos[i] << " ";
            }
            tempFile1 << "-" << endl;
        }
        in.close();
        tempFile1.close();
    }
    else
    {
        cout << "error in opeing of programes file while deleting plo  at  " << endl;
    }
    remove("programes.txt");
    rename("temp1.txt", "programes.txt");


    // delting clos against this plo
    string line2, plof_id, clof_id;
    int num_clos1;
    ifstream inFile2("clos.txt");
    ofstream tempFile2("temp2.txt", ios::app);

    if (inFile2.is_open())
    {
        while (getline(inFile2, line2)) {
            stringstream ss(line2);
            ss >> plof_id;
            if (plof_id != plo_id)
            {
                tempFile2 << plof_id << " ";
                while (ss >> clof_id)
                {
                    tempFile2 << clof_id << " ";
                }
                tempFile2 << endl;
            }
        }
        inFile2.close();
        tempFile2.close();
    }
    else
    {
        cout << "error in opening of file " << endl;
    }
    remove("clos.txt");
    rename("temp2.txt", "clos.txt");


    cout << "plo has been deleted sucessfully " << endl;
}
void DeletePrograme(programes* p, int& num_progs, int& num_courses)
{
    int select;
    cout << "select programe number to delete programe " << endl;
    for (int i = 0; i < num_progs; i++)
    {
        cout << i + 1 << " " << p[i].get_id() << "  " << p[i].get_name() << endl;
    }
    cin >> select;
    string prog_name = p[select - 1].get_name();
    string prog_id = p[select - 1].get_id();
    // deletion from programes file
    string line, progf_name, progf_id;
    ifstream in("programes.txt");
    ofstream tempFile("temp.txt", ios::app);
    if (in.is_open())
    {
        for (int i = 0; i < num_progs; i++)
        {
            getline(in, line);
            stringstream ss(line);
            string plos[100];
            ss >> progf_name >> progf_id;
            if (prog_name != progf_name)
            {
                tempFile << progf_name << " " << progf_id << " ";
                string plo;
                int index = 0;
                while (ss >> plo && plo != "-") {
                    plos[index++] = plo;
                }
                for (int i = 0; i < index; i++)
                {
                    tempFile << plos[i] << " ";
                }
                tempFile << "-" << endl;
            }
        }
        in.close();
        tempFile.close();
    }
    else
    {
        cout << "error in opeing of programes file while reading " << endl;
    }
    remove("programes.txt");
    rename("temp.txt", "programes.txt");

    // deleting courses related to programes
    ifstream in1("courses.txt");
    ofstream tempFile1("temp1.txt", ios::app);
    if (in1.is_open())
    {
        for (int i = 0; i < num_courses; ++i) {
            getline(in1, line);
            stringstream ss(line);
            string programf1_name, coursef1_name, coursef1_id;
            string* clos;
            clos = new string[100];
            int num_clos = 0;

            ss >> programf1_name;
            if (prog_name != programf1_name)
            {
                //cout <<programf1_name << " is adding " << endl;
                tempFile1 << programf1_name << " ";
                string temp;
                while (ss >> temp && temp != "-") {
                    coursef1_name += (temp + " ");
                }
                coursef1_name.pop_back();
                tempFile1 << coursef1_name << " " << " - ";
                ss >> coursef1_id;
                tempFile1 << coursef1_id << " ";
                while (ss >> temp && temp != "-") {
                    clos[num_clos] = temp;
                    num_clos++;
                }
                for (int i = 0; i < num_clos; i++)
                {
                    tempFile1 << clos[i] << " ";
                }
                tempFile1 << "-" << endl;
            }
        }

        in1.close();
        tempFile1.close();
    }
    else
    {
        cout << "error in file open for deleting programe from courses " << endl;
    }
    remove("courses.txt");
    rename("temp1.txt", "courses.txt");
}
void ReadCoursesForPlos(course*& courses, int& num_courses, programes*& programes, int& num_programes, plos*& plo, int& num_plos)
{
    int chose = 0;
    for (int i = 0; i < num_plos; i++)
    {
        cout << i + 1 << " " << plo[i].get_id() << endl;

    }
    cout << "enter plo number to see relevant courses " << endl;
    cin >> chose;
    string plo_id = plo[chose - 1].get_id();
    //cout << "selected plo " <<plo_id<< endl;
    // search ing plo from prograes 
    string file_courses[100];
    int num_fcourses = 0;
    for (int i = 0; i < num_programes; i++)
    {
        string* plos = programes[i].get_plos();
        int num = programes[i].get_num_plos();
        for (int j = 0; j < num; j++)
        {
            if (plos[j] == plo_id)
            {
                string prog = programes[i].get_name();
                for (int k = 0; k < num_courses; k++)
                {
                    if (courses[k].get_programe() == prog)
                    {
                        file_courses[num_fcourses++] = courses[k].get_name();
                    }
                }
            }
        }
    }

    //
    cout << "courses relevant to this plo " << endl;
    for (int i = 0; i < num_fcourses; i++)
    {
        cout << file_courses[i] << endl;
    }

}
void admin(plos*& plo, int& num_plos, programes*& programes, int& num_programes, course*& courses, int& num_course) {
    int choice;
    do {
        system("cls");
        cout << "enter 1 to add new plos " << endl;
        cout << "enter 2 to view all plos " << endl;
        cout << "enter 3 to add new programes " << endl;
        cout << "enter 4 to view all programes " << endl;
        cout << "enter 5 to add new clo's " << endl;
        cout << "enter 6 to see clo's " << endl;
        cout << "enter 7 to add new course " << endl;
        cout << "enter 8 to view courses " << endl;
        cout << "enter 9 to delete plo " << endl;
        cout << "enter 10 to delete the programes " << endl;
        cout << "enter 11 to view courses relevant to plo " << endl;
        cout << "enter 0 to exit admin domain" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting admin domain..." << endl;
            return;
        case 1:
            AddPlo(num_plos);
            plo = read_plos(num_plos);
            break;
        case 2:
            plo = read_plos(num_plos);
            cout << "following are the plos " << endl;
            for (int i = 0; i < num_plos; i++) {
                cout << plo[i].get_name() << " " << endl;
            }
            break;
        case 3:
            plo = read_plos(num_plos);
            AddPrograme(plo, num_plos);
            break;
        case 4:
            cout << "view programes " << endl;
            programes = read_programe(num_programes);
            system("cls");
            for (int i = 0; i < num_programes; i++) {
                programes[i].print();
            }
            break;
        case 5:
            plo = read_plos(num_plos);
            AddClo(plo, num_plos);
            break;
        case 6:
            system("cls");
            readclo_plo();
            break;
        case 7:
            programes = read_programe(num_programes);
            AddCourse(num_course, programes, num_programes);
            break;
        case 8:
            system("cls");
            courses = read_courses(num_course);
            for (int i = 0; i < num_course; i++) {
                courses[i].print();
            }
            break;
        case 9:
            plo = read_plos(num_plos);
            DeletePlo(plo, num_plos);
            break;
        case 10:
            programes = read_programe(num_programes);
            courses = read_courses(num_course);
            DeletePrograme(programes, num_programes, num_course);
            break;
        case 11: {
            plo = read_plos(num_plos);
            programes = read_programe(num_programes);
            courses = read_courses(num_course);
            ReadCoursesForPlos(courses, num_course, programes, num_programes, plo, num_plos);
            break;
        }
        default:
            cout << "Invalid input! Please try again." << endl;
            break;
        }
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();
    } while (true);
}
void teacher_entries(plos*& plo, int& num_plos, programes*& programes, int& num_programes, topics*& topics, int& num_topics, Evaluation*& evaluations, int& num_evaluations)
{
    int choice;
    do {
        system("cls");
        cout << "Teacher Entries Menu:" << endl;
        cout << "1. Add Topics Covered" << endl;
        cout << "2. View all Topics Covered\n";
        cout << "3. Add Evaluations" << endl;
        cout << "4. View Questions for Evaluation" << endl;
        cout << "5. Exit" << endl; // Added option 5
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddTopic(topics, num_topics);
            topics = read_topics(num_topics);
            break;
        case 2:
            system("cls");
            topics = read_topics(num_topics);
            for (int i = 0; i < num_topics; i++) {
                topics[i].print();
            }
            pauseProgram();
            Sleep(1000);
            break;
        case 3:
            AddEvaluation(); // Call the function to add evaluations
            break;
        case 4:
            // Read evaluations
            int num_evaluations;
            evaluations = read_evaluations(num_evaluations);
            if (evaluations != nullptr) {

                for (int i = 0; i < num_evaluations; ++i) {
                    cout << endl << evaluations[i].get_num_clo() << endl;
                    evaluations[i].print(); // Print each evaluation
                }
                pauseProgram();
                Sleep(1000);
                // delete[] evaluations; // Free the memory allocated for evaluations
            }
            break;
        case 5: // Added case 5 for "Exit"
            cout << "Exiting Teacher Entries..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Invalid input! Please enter a valid option." << endl;
            Sleep(1000);
            break;
        }
    } while (choice != 5); // Adjusted the exit condition to 5
}
void generateReport(Evaluation*& evaluations, int& num_evaluations, course*& courses, int& num_course) {
    int choice;
    bool exit = false;

    while (!exit) {
        system("cls");
        cout << "Select the report/query you want to generate:" << endl;
        cout << "1) Check whether a CLO has been tested or not (in two different questions)" << endl;
        cout << "2) Check whether all CLO's of a given course has been tested or not" << endl;
        cout << "3) For a given PLO, generate a list of all the relevant courses" << endl;
        cout << "4) Go back/Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string cloToCheck;
            cout << "Enter the CLO you want to check: ";
            cin >> cloToCheck;

            evaluations = read_evaluations(num_evaluations);
            if (evaluations != nullptr) {
                bool cloFound = false;
                for (int i = 0; i < num_evaluations - 1; ++i) {
                    string cloString = evaluations[i].get_checkclo();
                    if (cloString.find(cloToCheck) != string::npos) {
                        cloFound = true;
                        break;
                    }
                }
                if (cloFound)
                    cout << cloToCheck << " has been tested." << endl;
                else
                    cout << cloToCheck << " is not tested." << endl;

                pauseProgram();
                Sleep(1000);
            }
            break;
        }
        case 2: {


            string courseId;
            cout << "Enter the course ID: ";
            cin >> courseId;

            // Find the course with the given ID
            bool courseFound = false;
            string courseCLOs;
            for (int i = 0; i < num_course; ++i) {
                if (courses[i].get_id() == courseId) {
                    courseFound = true;
                    courseCLOs = courses[i].get_checkclo();
                    cout << "CLOs for course " << courseId << ": " << courseCLOs << endl;
                    break;
                }
            }

            if (!courseFound) {
                cout << "Course with ID " << courseId << " not found." << endl;
                pauseProgram();
                break;
            }

            // Check if each CLO in the course has been tested
            bool allCLOsTested = true;
            evaluations = read_evaluations(num_evaluations);
            if (evaluations != nullptr) {
                stringstream ss(courseCLOs);
                string clo;
                while (ss >> clo) {
                    bool cloTested = false;
                    for (int i = 0; i < num_evaluations - 1; ++i) {
                        string evaluationCLOs = evaluations[i].get_checkclo();
                        if (evaluationCLOs.find(clo) != string::npos) {
                            cloTested = true;
                            cout << "CLO " << clo << " has been tested." << endl;
                            break;
                        }
                    }
                    if (!cloTested) {
                        allCLOsTested = false;
                        cout << "CLO " << clo << " has not been tested." << endl;
                    }
                }

                if (allCLOsTested)
                    cout << "All CLOs of course " << courseId << " have been tested." << endl;
                else
                    cout << "Not all CLOs of course " << courseId << " have been tested." << endl;

                pauseProgram();
                Sleep(1000);
            }
            break;
        }


        case 3: {
            // Report 3 implementation
            cout << "\n\nThis info is present in 11th option of admin command\n";
            Sleep(1000);
            break;
        }
        case 4: {
            exit = true;
            Sleep(1000);
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
            Sleep(1000);
        }
    }
}


int main() {
    int num_teachers, num_officers, num_plos, num_programes, num_courses, tp_num, num_evaluations;

    teacher* teachers = read_teachers(num_teachers);
    academic_officer* ac = read_academicofficer(num_officers);
    plos* plo;

    programes* progs;
    course* courses;
    topics* top;
    Evaluation* evaluations;

    // Print all teachers
    cout << "Teachers:" << endl;
    for (int i = 0; i < num_teachers; i++) {
        teachers[i].print();
    }

    // Print all officers
    cout << "Officers:" << endl;
    for (int i = 0; i < num_officers; i++) {
        ac[i].print();
    }

    delete[] teachers;
    delete[] ac;
    Sleep(1000);

    char choice;

    courses = read_courses(num_courses);
    /*if (courses != NULL) {
        for (int i = 0; i < num_courses; ++i) {
            cout << courses[i].get_checkclo() << endl;
        }
    }
    pauseProgram();
    Sleep(1000);*/

    do {
        cout << "enter 1 for admin " << endl;
        cout << "enter 2 for teacher " << endl;
        cout << "enter 3 for report generation" << endl;
        cout << "enter 'q' to quit" << endl;
        cin >> choice;

        switch (choice) {
        case '1':
            admin(plo, num_plos, progs, num_programes, courses, num_courses);
            break;
        case '2':
            teacher_entries(plo, num_plos, progs, num_programes, top, tp_num, evaluations, num_evaluations);
            break;
        case '3': {
            generateReport(evaluations, num_evaluations, courses, num_courses);
            break;
        }
        case 'q':
        case 'Q':
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            pauseProgram();
            break;
        }
        system("cls");
    } while (true);

    return 0;
}