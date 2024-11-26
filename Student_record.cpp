
// student data management system 


# include <iostream>
# include <vector>



using namespace std;

class Student
{
    private:        // cannot be shared
        string name;
        int roll_no, age;
        

    public:
        // constructor student
        Student(string stdName, int std_Roll_no, int stdAge)
        {
            name = stdName;
            roll_no = std_Roll_no;
            age = stdAge; 
        }

        // setter for variables - name, roll_no, age

        void setName(string stdName)
        {
            name = stdName;
        }

        void setRoll( int std_Roll_no)
        {
            roll_no = std_Roll_no;
        }

        void setAge(int stdAge)
        {
            age = stdAge;
        }

        // getter for variables - name, roll_no, age

        string getName()
        {
            return name;
        }

        int getRoll()
        {
            return roll_no;
        }

        int getAge()
        {
            return age;
        }

        void Display_student()
        {
            cout << endl;
            cout << " Name : " << name << endl ;
            cout << " Roll no : " << roll_no << endl;
            cout << " Age : " << age << endl  << endl;
        }

};

// function to add new student to record
void Create_Student(vector<Student> &students)
{
    int roll_no, age;
    string name;

    cout << " Enter student name : " <<endl;
    cin >> name;

    cout << " Enter student roll no : " <<endl;
    cin >> roll_no;

    // check if student already exist
    for( int i =0; i< students.size(); i++)
    {
        if ( students[i].getRoll() == roll_no)
        {
            cout << " Student already exists in record .. !" << endl;
            return; // exist the loop
        }
    }

    cout << " Enter student age : " <<endl;
    cin >> age;

    // cretaet student object to add new student in record
    Student newStudent(name, roll_no, age);
    
    // store the values of new student in vector list under newStudent
    // push the values in vector
    students.push_back(newStudent);

    cout << " New student Successfully added .. !" << endl;
}


// function to display details of all students in record
void Display_AllStudent(vector<Student> &students)      // vector < class name> & students(obj name)
{

    if(students.empty())
    {
        cout << " \t \t No student is present in record .. ! " << endl;
        return;
    }
    for( int i  = 0; i< students.size(); i++)
    {
        students[i].Display_student();      // prints details for all students in record one by onre 
        cout << endl <<" Student found .. !" << endl << endl <<endl;
        
    }
    return;

}

// function to find particular student from record

void Search_Student(vector<Student> &students)
{
    // search student by his roll no.
    int roll_no;
    cout<< " Enter roll no to search a student : " << endl;
    cin >> roll_no;

    for( int i = 0; i< students.size(); i++)
    {
        if(students[i].getRoll() == roll_no)
        {
            cout << " Student found in record .. " << endl;
            students[i].Display_student();      // print details of the found student
            return;
        }
    }
}

// function to update the existing student details
void Update_Student(vector<Student> &students)
{
    int roll_no;
    string name;
    bool roll = false;

    cout << " Enter roll no for which you want to update the data : " << endl;
    cin >> roll_no;

    for(int i = 0; i< students.size(); i++)
    {      // If the roll no is in record then update the required data
        if( students[i].getRoll() == roll_no)
        {
            roll = true;

            cout << " Student found .. " << endl;

            cout << " 1. Update name " << endl;
            cout << " 2. Update age " << endl;
            cout << " 3. Exit " << endl;

            cout << " Enter your choice : " << endl;

            int choice1;

            cin >> choice1;

            switch(choice1)
            {
                case 1:
                {
                    string name;
                    cout << " Enter new name : " << endl;
                    //cin >> name;
                    cin.ignore();
                    getline(cin, name);     // take input of new name 
                    students[i].setName(name);
                    cout << " Student name is updated .. "<<endl;
                    break;
                }

                case 2:
                {
                    int age;
                    cout << " Enter the new age for the student : " << endl;
                    cin >> age;
                    students[i].setAge(age);
                    cout << " Student age is updated .. "<<endl;
                    break;
                }
                
                default:
                    cout << " Incorrect input , Enter correct choice .. " << endl;
                    
                }

        }
       /* if(!roll)
        {
            cout << " Record for the student not found " << endl;
            return;
        }
        */
    }
}

void Delete_Student(vector <Student> &students)
{
    string name;
    int roll_no, age;

    cout << " Enter the name of student you want to delete : " << endl;
    cin.ignore();
    getline(cin, name);

    for( int i =0; i< students.size(); i++)
    {
        if(name == students[i].getName() )
        {
            students.erase((students.begin()+i));
            cout << " Student deleted successfully " << endl;

        }
    }

}

 int main()
{
    vector<Student> students;

    students.push_back(Student("Avin", 1, 15)); 
      
    char choice;
    //cin >> choice;
    do
    {
    //system("cls");      // clear previous output
    int option;
    cout << " \t \t \t ************ Student record management system ********** \t \t " << endl;
    cout << " ===================================================   ===================================== " << endl;
    cout <<" 1. Add a student " << endl;
    cout <<" 2. Display all students " << endl;
    cout << " 3. Search student " << endl;
    cout << " 4. Update student " << endl;
    cout << " 5. Delete student " << endl;
    cout << " 6. Exit  " << endl;

    cout << " Enter your option : " << endl;
    cin >> option;

    switch(option)
    {
        case 1:
            Create_Student(students);
            break;

        case 2:
            Display_AllStudent(students);
            break;

        case 3:
            Search_Student(students);
            break;

        case 4:
            Update_Student(students);
            break;

        case 5:
            Delete_Student(students);
            break;

        case 6:
            exit(1);
            
        default: 
            cout << " Enter correct option .. ";

    }       // switch
    cout << " If you want to continue type y or Y : " << endl;
    cin >> choice;
    }
    while( choice == 'y' || choice == 'Y');

    



}



