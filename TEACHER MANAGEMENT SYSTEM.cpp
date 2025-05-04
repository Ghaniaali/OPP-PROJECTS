#include<iostream>
using namespace std;


class person{
	
	protected:
		string name;
		int age;
		
	public: 
	    person(){	
		}
		
	    person(string n,int a){
	    	name = n;
	    	age = a;
		}    	    
};

class Qualification{
	
	protected:
		string degree;
		int yearsofexperience;
		
	public:
		Qualification(){	
		}
		
		Qualification(string d, int experience){
			degree = d;
			yearsofexperience = experience;
		}
		
	void displayQualification(){
		cout<<"Degree: "<<degree<<endl;
		cout<<"Years Of Experience: "<<yearsofexperience<<endl;	
	}
		
};

class Teacher : public person{
	
	protected:
		Qualification qualifications;
		
	public:
	Teacher(string name, int age, string degree, int yearsofexperience): person(name, age),qualifications(degree, yearsofexperience){
	
	}
		
	void displayTeacher(){	
		cout<<"Teacher Name: "<<name<<endl;
		cout<<"Teacher Age: "<<age<<endl;
		qualifications.displayQualification();
	}
		
};

class Student : public person{
	
	protected: 
	  int studentId;
	  
	public:
		Student(){
			
		}
		
	Student(string name, int age, int Id) : person(name, age){
		studentId = Id;
	}
	
		void displayStudent(){
			
		cout<<"Student Name: "<<name<<endl;
		cout<<"Student Age: "<<age<<endl;
		cout<<"Student ID: "<<studentId<<endl;
		
	}
	
};

class Course{
	
	protected:
		string coursename;
		int coursecode;
		
	public: 
	   Course(){
	   	
	   }
	   Course(string courseN, int courseC){
        	coursename = courseN;
        	coursecode = courseC;
	   }
	   
	   void displaycourses(){
	   	
	   	cout<<"Course Name: "<<coursename<<endl;
		cout<<"Course Code: "<<coursecode<<endl;
	
	   }
	
};

class Department{
	
	protected:
		string departmentname;
    	Teacher* teachers[10];
    	Student* students[10];
    	Course* courses[10];
    	static int Teachercount;
    	static int Studentcount;
    	static int Coursecount;
	
	public:
		Department(){
		}
		
		Department(string depName){
			departmentname = depName;
		}
		
	string getName() const {
        return departmentname;
    }
		
		
		void addTeacher(Teacher* teacher){
			
			if(Teachercount < 10){
				teachers[Teachercount++] = teacher;
				cout<<"Teacher Added Successfully! "<<endl;
			}
			else{
				cout<<"Teacher cannot be added because the slots are full"<<endl;
			}
			
		}
		
		void addStudent(Student* student){
			
			if(Studentcount < 10){
				students[Studentcount++] = student;
				cout<<"Student Added Successfully! "<<endl;
			}
			else{
				cout<<"Student cannot be added because the slots are full"<<endl;
			}
			
		}
		
		void addCourse(Course* course){
			
			if(Coursecount < 10){
				courses[Coursecount++] = course;
				cout<<"Course Added Successfully! "<<endl;
			}
			else{
				cout<<"Course cannot be added because the slots are full"<<endl;
			}
		}
		
		void displayteacher(){
			
			if(Teachercount==0){
				cout<<"No Teachers are available! "<<endl;
			}
			else{
			cout<<" --Teachers in "<<departmentname<<" Department are: -- "<<endl;
			for (int i=0; i<Teachercount; i++){
				cout<<"Teacher No "<<i+1<<":"<<endl;
				cout<<endl;
				teachers[i]->displayTeacher();
				cout<<endl;
			}
		}
			
	}
		
		void displaystudent(){
			
			if(Studentcount==0){
				cout<<"No Students are available! "<<endl;
			}
			else{
			cout<<" --Students in "<<departmentname<<" Department are:  -- "<<endl;
			for (int i=0; i<Studentcount; i++){
				cout<<"Student No "<<i+1<<":"<<endl;
				cout<<endl;
				students[i]->displayStudent();
				cout<<endl;
			}
		}
				
	}
		
		void displaycourse(){
		
		if(Coursecount==0){
				cout<<"No Courses are available! "<<endl;
			}
			else{
			cout<<" --Courses in "<<departmentname<<" Department are: -- "<<endl;
			for (int i=0; i<Teachercount; i++){
				cout<<"Course No "<<i+1<<":"<<endl;
				cout<<endl;
				courses[i]->displaycourses();
				cout<<endl;
			}
		}
			
	}
	
	void ManageDepartment(){
			int option;
			
			do{
				cout<<endl;
				cout<<"  --- "<<departmentname<<" Department Menu ---  "<<endl;
				cout<<"  1. Add teacher "<<endl;
				cout<<"  2. Add Student "<<endl;
				cout<<"  3. Add Course "<<endl;
				cout<<"  4. Display All teachers "<<endl;
				cout<<"  5. Display All Students "<<endl;
				cout<<"  6. Display All Courses "<<endl;
				cout<<"  0. Go back "<<endl;
				cin>>option;
				
				while(option<0 || option>6){
					
					cout<<"Invalid, please try again:  "<<endl;
        	        cin>>option;
				}
				
				switch(option){
					
					case 1: {
	
				string name, degree;
                int age, yearsofexperience;
                
                cout<<" --Enter teacher details: -- "<<endl;
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter age: ";
                cin>>age;
                cout<<"Enter degree: ";
                cin.ignore();
				getline(cin,degree);
                cout<<"Enter years of experience: ";
                cin>>yearsofexperience;
               addTeacher(new Teacher(name, age, degree, yearsofexperience));		
                
                break;
                
            }
                   case 2: {
                   	
                string name;
                int age, studentId;
                
                cout<<" --Enter student details: -- "<<endl;
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter age: ";
                cin>>age;
                cout<<"Enter student ID: ";
                cin>>studentId;
                addStudent(new Student(name, age, studentId));
				
				break;
				
			}
				  case 3: {
					
				string coursename;
				int coursecode;
				  
                cout<<" --Enter course details: -- "<<endl;
                cout<<"Enter course name: ";
                cin.ignore();
                getline(cin, coursename);
                cout<<"Enter course code: ";
                cin>>coursecode;
                addCourse(new Course(coursename, coursecode));
				
				break;
			}
				 case 4: 
				
				displayteacher();
				 
				break;
				 
				 case 5:
				 
		        displaystudent();
				 
				break;
				
				 case 6:
				 
			    displaycourse();
				 
				break;
				
				case 0:
					
                cout << "Returning to main menu..." << endl;
                
                break;
                    
                default:
                	
                 cout << "Invalid option. Try again." << endl;
				
			}
				
		}while(option!=0);
		
	}
	

};

int Department::Teachercount=0;
int Department::Studentcount=0;
int Department::Coursecount=0;

class UOL{
	
	private:
		Department departments[10];
	    static int Departmentcount;
		
	public:
		
		void addDepartment(const Department& department){
			cout<<endl;
			
			if(Departmentcount<10){
            departments[Departmentcount++] = department;
            cout<<"Department added successfully!"<<endl;
        } 
            else{
             cout<<"Cannot Add more Departments! "<<endl;
       }			
	}
	
	   	void showDepartment(){
	   		
        if (Departmentcount==0){
            cout<<"No departments available."<<endl;
        }
        else{
        cout<<"Departments: "<<endl;
        for(int i = 0; i<Departmentcount; i++){
            cout<<i+1 <<". "<<departments[i].getName()<< endl;
        }
    }
}

        void enterDepartment(){
        	
        	showDepartment();
            if (Departmentcount == 0) return;
        	int choice;
        	
        	cout<<endl;
        	cout<<"Enter Department Number To Manage: "<<endl;
        	cin>>choice;
        	
           	while(choice < 1 || choice > Departmentcount){
        	
        	cout<<"Invalid, please try again:  "<<endl;
        	cin>>choice;
        }
        	
        	 departments[choice - 1].ManageDepartment();
        	 
		}
		
};

int UOL::Departmentcount=0;

int main(){
	
	UOL university ;
	int choice;
	
	do{
		
		cout<<endl;
		cout<<"  == University Of Lahore Main Menu ==  "<<endl;
		cout<<"  1. Add Department "<<endl;
		cout<<"  2. Show Department "<<endl;
		cout<<"  3. Enter Department "<<endl;
		cout<<"  0. Exit "<<endl;
	    cin>>choice;
	    
	    while(choice<0 || choice>3){
	    	
	    	cout<<"Invalid, please try again:  "<<endl;
            cin>>choice;
		}
		
		switch (choice) {
			
        case 1: {
        	
            string name;
            cout<<"Enter Department Name: "<<endl;
            cin.ignore();
            getline(cin, name);
            university.addDepartment(Department(name));
            break;
      }
        case 2:{
        	
            university.showDepartment();
            break;
    }
        case 3:{
        	
            university.enterDepartment();
            break;
    } 
        case 0: {
        	
            cout << "Exiting the Program...." << endl;
            break;
	}
	
        default:
            cout << "Invalid, please try again." << endl;
    }
    
} while (choice != 0);
		

	return 0;
}
