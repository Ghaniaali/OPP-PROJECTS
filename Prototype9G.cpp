#include <cstdlib>
#include <iostream> 
#include <fstream> //library for file handling 
#include <sstream> //library for Splitting of string  
#include <string> //library for string operations 
#include <iomanip> //library for setw and setp functions        
using namespace std;

const string PASSWORD = "4000";

//function for taking Inputs
void input(){
    cout<<endl;
    char ch;
    cout<<"Press Enter to continue: ";
    cin.ignore();
    ch = cin.get();
    system("cls");
}

// function for Admin validation 
bool authentication(){
    string pin;
    cout<<endl;
    cout<<"Enter Admin Password to Access this Feature: "; //password is 4000
    cin>>pin;
    if (pin == PASSWORD) {
        return true;
    }
    cout<<"Incorrect Password Entered.Returning to Main.... "<<endl;
    input();
    cout<<endl;
    return false;
}

//Class for all Menu Details and functionalities
class Menu {
    protected:
        const string filename; 
        static int id;
    public: 
        Menu(string file = "Menu.csv")  : filename(file) {}

		//Function to Create a Menu Item 
        string create(){
            ofstream file(filename, ios::app); //File opening and writing on a file 
            if (!file.is_open()) {
                cerr<<"| Error: Unable to open file '" << filename << "'. Please check the file and try again.| \n";
                return "";
            }

            int availability;
            string category, item;
            double price;
            
            id = ++id; //for making unique Id for every new Customer 

            cin.ignore();
            cout << "Enter Category: ";
            getline(cin, category);

            cout << "Enter Item Name: ";
            getline(cin, item);

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Availability: ";
            cin >> availability;

            file << id << "," << category << "," << item << "," << price << "," << availability << "\n";
            file.close();

            string data;
            ifstream tempfile(filename);

            if (!tempfile.is_open()) {
                cerr<<"| Error: Unable to open file '" << filename << "'. Please check the file and try again.| \n";
                return "";
            }

            for (int i = 1; i <= id + 1; i++) {
                getline(tempfile,data);
            }

            cout << "| Menu item added successfully!| \n";
            return data;
        }
        
        //function to display Menu 
        void displayMenu() { 
            ifstream file(filename); //displaying a file 
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again.| \n";
                return;
            }

            string currentCategory = ""; // To seperate Categories 
            
            cout << "\n------------------------- Menu -----------------------------\n";
            cout << "ID   | Category       | Item                     | Price   | \n";
            cout << "------------------------------------------------------------\n";

            string line;
            string header;
            getline(file,header);
            while (getline(file, line)) {
                stringstream ss(line);
                string id, category, item, price, availability;
                getline(ss, id, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                
                if (category != currentCategory) {
                    if (currentCategory != "") {
                        cout << "\n------------------------------------------------------------\n";
                    }
                    currentCategory = category;
                    cout << "                ------ " << category << " -----\n";
                    cout << "------------------------------------------------------------\n\n";
                }

                
                cout << left << setw(5) << id
                    << "| " << setw(15) << category
                    << "| " << setw(25) << item
                    << "| $" << setw(7) << price
                    << "| " << endl;
            }

            cout << "------------------------------------------------------------\n";
            file.close();
        }

   		//function to display Menu Category from a file 
        void displayMenuByCatagory() {
            ifstream file(filename); 
            if (!file.is_open()){
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again.| \n";
                return;
            }

            int choice;
            cout << "\n              Select a Category to Display:                 \n";
            cout << "\n------------------------- Menu -----------------------------\n";
            cout << "ID   | Category                                            | \n";
            cout << "------------------------------------------------------------\n";
            cout << "1.   | Vegetarian                                          |\n";
            cout << "2.   | Vegan                                               |\n";
            cout << "3.   | Gluten-Free                                         |\n";
            cout << "4.   | Specialty                                           |\n";
            cout << "5.   | Drinks                                              |\n";
            cout << "6.   | Other                                               |\n";
            cout << "------------------------------------------------------------\n";
            cout << "| Enter your choice (1-6): | ";
            cin >> choice;

            while(choice > 6 || choice < 0){
                cout<<"Enter a valid choice..."<<endl;
                cout << "| Enter your choice (1-6): | ";
                cin >> choice;
            }
            string categoryFilter;
            switch (choice) {
                case 1: 
                    categoryFilter = "Vegetarian"; 
                    break;
                case 2: 
                    categoryFilter = "Vegan"; 
                    break;
                case 3: 
                    categoryFilter = "Gluten-Free"; 
                    break;
                case 4: 
                    categoryFilter = "Specialty"; 
                    break;
                case 5: 
                    categoryFilter = "Drinks"; 
                    break;
                case 6: 
                    categoryFilter = "Other"; 
                    break;
                default:
                    cout << "| Invalid choice! Displaying all |\n";
                    break;
            }

            string line;
            bool found = false;

            cout << "\n------------------------- Menu -----------------------------\n";
            cout << "ID   | Category       | Item                     | Price   | \n";
            cout << "------------------------------------------------------------\n";

            getline(file,line); // to not print the header

            while (getline(file, line)) {
                stringstream ss(line);
                string id, category, item, price, availability;
                getline(ss, id, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');
                
                if ((category != "Vegetarian" && category != "Vegan" && category != "Gluten-Free" && category != "Specialty" && category != "Drinks") || categoryFilter == "Others") {
                    found = true;
                    cout << left << setw(5) << id << "| "
                        << setw(15) << category << "| "
                        << setw(25) << item << "| $"
                        << setw(7) << price << "| "
                        << endl;
                }

                if (category == categoryFilter) {
                    found = true;
                    
                    cout << left << setw(5) << id << "| "
                        << setw(15) << category << "| "
                        << setw(25) << item << "| $"
                        << setw(7) << price << "| "
                        << endl;
                }
            }

            if (!found) {
                cout << "| No items found in the \"" << categoryFilter << "\" category | \n";
            }

            cout << "------------------------------------------------------------\n";
            file.close();
        }
				
		//function to Search Menu Item's ID
        string search(int Id) {
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again | \n";
                return "";
            }

            int searchId=Id;

            string line;
            bool found = false;
            string header;
            getline(file,header);

            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"| {Line 226} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(idStr) == searchId) {
                    string order = line;
                    return order;
                }
            }
            file.close();
            return ""; //To prevent a garbage value 
        }

		//function to check if the Menu ID is valid
        bool searchIsItemValid(int Id){
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again | \n";
                return false;
            }

            int searchId=Id;

            string line;
            bool found = false;
            string header;
            getline(file,header);

            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"{Line 265} Error Converting to integer:- "<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(idStr) == searchId) {
                    return true;
                }
            }
            file.close();
            return false;
        }

		//function to update Menu Items 
        void update() {
            int updateId;
            cout << "| Enter Item ID to update: |";
            cin >> updateId;

            ifstream inFile(filename); 
            ofstream outFile("temp.csv"); 
            bool found = false;

            if (!inFile.is_open() || !outFile.is_open()) {
                cerr << "Error opening file.\n";
                return;
            }

            string line;
            string header;
            getline(inFile,header);
            outFile<<header<<endl;
            
            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"| {Line 308} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }

                if (stoi(idStr) == updateId) {
                    found = true;
                    cout << "| Enter new Category: |";
                    cin.ignore();
                    getline(cin, category);
                    cout << "| Enter new Item Name: |";
                    getline(cin, item);
                    cout << "| Enter new Price: |";
                    cin >> price;
                    cout << "| Enter new Availability: |";
                    cin >> availability;
                }
                outFile << idStr << "," << category << "," << item << "," << price << "," << availability << "\n";
            }

            inFile.close();
            outFile.close();

            if (found){
                remove(filename.c_str());
                rename("temp.csv", filename.c_str());
                cout << "| Menu item updated successfully! | \n";
            } else {
                remove("temp.csv");
                cout << "| Menu item with ID " << updateId << " not found | \n";
            }
        }
        
		//function to delete menu Item
        void deleteRecord() {
            int deleteId;
            cout << "| Enter Item ID to delete: |";
            cin >> deleteId;

            ifstream inFile(filename);
            ofstream outFile("temp.csv");
            bool found = false;

            if (!inFile.is_open() || !outFile.is_open()) {
                cerr << "| Error opening file |\n";
                return;
            }

            string line;
            string header;
            getline(inFile,header);
            outFile<<header<<endl;

            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr); //convert to integar 
                }catch (exception& Exception) {
                    cout<<"| {Line 371} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }

                if (stoi(idStr) == deleteId) {
                    found = true;
                    cout << "| Menu item deleted successfully! | \n";
                    continue;
                }
                outFile << idStr << "," << category << "," << item << "," << price << "," << availability << "\n";
            }

            inFile.close();
            outFile.close();

            if (found) {
                remove(filename.c_str());
                rename("temp.csv", filename.c_str());
            } else {
                remove("temp.csv");
                cout << "| Menu item with ID " << deleteId << " not found | \n";
            }
        }

		//function to Count Number of Menu Items 
        static int getNoItems(string Filename){
            ifstream file(Filename);
            string line;
            int count = 0;
            while (getline(file, line)) {
                count++;
            }
            return count - 1;
        }

		//function to get price of MenuItem 
        double getPrice(int id) {
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again.| \n";
                return 0;
            }

            int searchId = id;

            string line;
            bool found = false;
            string header;
            getline(file,header);
            
            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');
                
                try {
                    stoi(idStr);
                }   catch (exception& Exception){
                    cout<<"| {Line 431} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(idStr) == searchId) {
                    return stod( price); //to convert to double
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "| Menu item with ID " << searchId << " not found | \n";
            }
            file.close();
            return 0;
        }
        
		//function to get Order Name from Menu 
        string getOrderName(int id) {
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << filename << "'. Please check the file and try again |\n";
                return "";
            }

            int searchId = id;
            
            string line;
            bool found = false;
            string header;
            getline(file,header);

            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"{Line 475} Error Converting to integer:- "<<Exception.what()<<endl;
                    return "";
                }

                if (stoi(idStr) == searchId) {
                    return item;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "| Menu item with ID " << searchId << " not found |\n";
            }
            file.close();
            return "";
        }
};
int Menu :: id = getNoItems("Menu.csv"); //

//Class for all Customers Details and functionalities
class Customer {
    const string Filename;
    string id, name, contact, preference, points;
    static int ID;
    public: 
        Customer(string Name = "Customer.csv") : Filename(Name){}

  		//function to Add a new Customer 
        void AddCustomer() {
            ofstream file(Filename, ios::app);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again.| \n";
                return;
            }

            int points = 0; //Initialize new Customer Points to 0 
            ID = ++ID; //Every New Customer Gets his own unique ID 
            cin.ignore();
            cout << "| Enter Name: |";
            getline(cin, name);

            cout << "| Enter Contact: |";
            getline(cin, contact);
            
            cout << "| Enter Dietary Preference (e.g., Vegetarian, Vegan): | ";
            getline(cin, preference);

            file << ID << "," << name << "," << contact << "," << preference << "," << points << "\n";
            file.close();

            cout << "| Customer added successfully! |\n";
        }

		//Function to Display All Registered Customers
        void displayAllCustomers() {
            ifstream file(Filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again.| \n";
                return;
            }

            cout << "\n------------------- Customer List -----------------------------------------\n";
            cout <<"| "<< "ID  |                 Name |           Contact |      Preference | Points\n";
            cout << "---------------------------------------------------------------------------\n";

            string header;
            getline(file, header);

            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');

                cout <<"| "<< id <<setw(5) << " | " << setw(20) << name << " | " << setw(17) << contact << " | " << setw(15)<< preference << " | " << setw(5) << points << "\n";
            }
            cout << "---------------------------------------------------------------------------\n";
            file.close();
        }
        
	    //function to Search Customers By their ID
        bool isIDValid(int id) {
            ifstream file(Filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again | \n";
                return false;
            }

            int searchID = id;

            string line;
            string header;
            getline(file, header);

            bool found = false;
            while (getline(file, line)) {
                stringstream ss(line);
                string id;
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');

                try {
                    stoi(id);
                }catch (exception& Exception) {
                    cout<<"| {Line 582} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(id) == searchID) {
                    found = true;
                    return true;
                }
            }

            if (!found) {
                cout << "| Customer with ID " << searchID << " not found |\n";
            }
            file.close();
            return false;
        }
    
    	//Function to Update Customers Information
        void updateCustomer() {
            ifstream file(Filename);
            ofstream tempFile("temp.csv");
            if (!file.is_open() || !tempFile.is_open()) {
                cout << "| Error opening file to update customer | \n";
                return;
            }

            int updateID;
            cout << "| Enter Customer ID to update: |";
            cin >> updateID;

            string line;
            string header;
            getline(file, header);
            tempFile<<header<<endl;

            bool found = false;

            while (getline(file, line)) {
                stringstream ss(line);
                
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');
                
                try {
                    stoi(id);
                }catch (exception& Exception) {
                    cout<<"| {Line 630} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }
                if (stoi(id) == updateID) {
                    found = true;
                    cout << "| Updating details for Customer ID: " << id << "| \n";
                    cout << "| Enter new contact: |";
                    cin >> contact;
                    cout << "| Enter new dietary preference: |";
                    cin >> preference;
                }

                tempFile << id << "," << name << "," << contact << "," << preference << "," << points << "\n";
            }

            file.close();
            tempFile.close();

            if (found) {
                remove(Filename.c_str());
                rename("temp.csv", Filename.c_str());
                cout << "| Customer updated successfully! | \n";
            } else {
                remove("temp.csv");
                cout << "| Customer with ID " << updateID << " not found | \n";
            }
        }
    
        // Function to Delete Customer Information
        void deleteCustomer() {
            ifstream file(Filename);
            ofstream tempFile("temp.csv");
            if (!file.is_open() || !tempFile.is_open()) {
                cout << "| Error opening file to delete customer | \n";
                return;
            }

            int deleteID;
            cout << "| Enter Customer ID to delete: | ";
            cin >> deleteID;

            string line;
            string header;
            getline(file, header);
            tempFile<<header<<endl;

            bool found = false;
            while (getline(file, line)) {
                stringstream ss(line);          
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');

                try {
                    stoi(id);
                }catch (exception& Exception) {
                    cout<<"| {Line 687} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }

                if (stoi(id) == deleteID) {
                    found = true;
                    cout << "| Customer with ID " << id << " deleted successfully | \n";
                    continue;
                }
                tempFile << id << "," << name << "," << contact << "," << preference<< "," << points << "\n";
            }

            file.close();
            tempFile.close();

            if (found) {
                remove(Filename.c_str());
                rename("temp.csv", Filename.c_str());
            } else {
                remove("temp.csv");
                cout << "| Customer with ID " << deleteID << " not found | \n";
            }
        }

		//Function to Check Customers Loyalty Points 
        int checkPoints(int id){
            ifstream file(Filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again | \n";
                return 0;
            }

            string line;
            bool found = false;
            getline(file, line);
            while (getline(file, line)) {
                stringstream ss(line);
                string strID, name, contact, preference,points;
                getline(ss, strID, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');
                
                try {
                    stoi(strID);
                }catch (exception& Exception) {
                    cout<<"| {Line 733} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(strID) == id) {
                    found = true;
                    file.close();
                    return stoi(points);
                }
                
            }
            if(!found){
                cout<<"| Customer is not registered in the system | "<<endl;
            }
            file.close();
            return 0;
        }

		//function to Count Number of Customers
        static int getNoCustomers(string Filename){
            ifstream file(Filename);
            if (!file.is_open()) {
                cout << "| Error opening file | \n";
                return 0;
            }        

            string line;
            int count = 0;
            while (getline(file, line)) {
                count++;
            }
            
            file.close();
            return count - 1;
        } 
};
int Customer:: ID = getNoCustomers("Customer.csv");

//Class for all Inventory Details and functionalities
class Inventory{
    const string Filename ;
    public:
        Inventory(string name = "Menu.csv") : Filename(name){}

		//function To display Inventory 
        void displayInventory(){
            ifstream file("Menu.csv"); 
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '"<< Filename <<"'.Please check the file and try again | \n";
                return;
            }

            string currentCategory = "";
            
            cout << "\n----------------------------------- Menu ----------------------------------\n";
            cout << "ID   | Category       | Item                     | Price   | Inventory\n";
            cout << "---------------------------------------------------------------------------\n";

            string line;
            getline(file, line);
            while (getline(file, line)) {
                stringstream ss(line);
                string id, category, item, price, availability;
                getline(ss, id, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');
                
                cout << left << setw(5) << id
                    << "| " << setw(15) << category
                    << "| " << setw(25) << item
                    << "| $" << setw(7) << price
                    << "| " <<setw(9)<< availability
                    <<" |"<< endl;
            }

            cout << "---------------------------------------------------------------------------\n";
            file.close();
        }

		//Function to Update Inventory 
        void updateInventory(int id){ 
            ifstream inFile(Filename); // Open old file for display
            ofstream outFile("temp.csv"); // Open new file for write
            bool found = false;

            if (!inFile.is_open() || !outFile) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again.| \n";
                return;
            }

            string line;
            string header;
            getline(inFile, header);
            outFile<<header<<endl;

            int updateId = id;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');
                
                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"| {Line 839} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }

                if (stoi(idStr) == updateId) {
                    cout << "| Enter new Inventory: |";
                    cin >> availability;
                    found = true;
                }
                outFile << idStr << "," << category << "," << item << "," << price << "," << availability << "\n";
            }

            inFile.close();
            outFile.close();

            if (found) {
                remove(Filename.c_str());
                rename("temp.csv", Filename.c_str());
            } else {
                remove("temp.csv");
                cout << "| Menu item with ID " << updateId << " not found | \n";
            }
           
        }

		//Function to Check Inventory
        bool chkInventory(int id,int choice = 0){ 
            ifstream file(Filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again | \n";
                return false;
            }

            int searchId = id;

            string line;
            bool found = false;
            string header;
            getline(file, header);

            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"| {Line 890} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(idStr) == searchId) {
                    found = true;
                        try {
                            stoi(idStr);
                        }catch (exception& Exception) {
                            cout<<"| {Line 898} Error Converting to integer:- |"<<Exception.what()<<endl;
                            return 0;
                        }
                    if (stoi(availability) > 0 && stoi(availability) >= choice) {
                       return true;
                    }
                    if(stoi(availability) < choice){
                        cout<<"\n| Please Restock! only "<<stoi(availability)<<" Left in Inventory | \n\n";
                    }
                    return false;
                }
            }
            if (!found) {
                cout << "| Menu item with ID " << searchId << " not found. | \n";
            
            }
            file.close();
            return false;
        }

		//Function to get Inventory Items 
        int getInventory(int id){ 
            ifstream file(Filename);
            if (!file.is_open()) {
                cerr << "| Error: Unable to open file '" << Filename << "'. Please check the file and try again.| \n";
                return 0;
            }

            int searchId = id;

            string line;
            bool found = false;
            string header;
            getline(file, header);

            while (getline(file, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');

                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"| {Line 942} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return 0;
                }

                if (stoi(idStr) == searchId) {
                    return stoi(availability);
                }
            }

            cout << "| Menu item with ID " << searchId << " not found |\n";
            file.close();
            return 0;
        }

		//Function to Deduct items From inventory 
        void DeductInventory(int id,int quantity){
            ifstream inFile(Filename); // Open old file for display
            ofstream outFile("temp.csv"); // Open new file for write
            bool found = false;

            if (!inFile.is_open() || !outFile.is_open()) {
                cout << "Error opening file.\n";
                return;
            }

            string line;
            string header;
            getline(inFile, header);
            outFile<<header<<endl;

            int deleteId = id;
            int avail;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, category, item, price, availability;
                getline(ss, idStr, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, availability, ',');
                
                try {
                    stoi(idStr);
                }catch (exception& Exception) {
                    cout<<"{| Line 985} Error Converting to integer:- |"<<Exception.what()<<endl;
                    return;
                }

                if (stoi(idStr) == id) {
                    try {
                        avail = stoi(availability);
                    }catch (exception& Exception) {
                        cout<<"| {Line 993} Error Converting to integer:- |"<<Exception.what()<<endl;
                        return;
                    }
                    avail-= quantity;
                    outFile << idStr << "," << category << "," << item << "," << price << "," << avail << "\n";
                    found = true;
                    continue;
                }
                outFile << idStr << "," << category << "," << item << "," << price << "," << availability << "\n";
            }

            inFile.close();
            outFile.close();

            if (found) {
                remove(Filename.c_str());
                rename("temp.csv", Filename.c_str());
            } else {
                remove("temp.csv");
                cout << "| Menu item with ID " << id << " not found. | \n";
            }
        }
};

//Class for all Sales Details and functionalities
class Sales {
    const string Filename;

public:
    Sales(string name = "SalesReport.csv") : Filename(name) {}

    void addItemToSalesReport(string line){
        ofstream File(Filename,ios::app);

        if (!File.is_open()) {
            cerr << "Error: Unable to open file '" << Filename << "'. Please check the file and try again.\n";
            return;
        }

        File<<line<<endl;

    }

    //done
    void addToSalesReport(int itemID, int Quantity) {
        ifstream inFile(Filename);
        ofstream outFile("temp.csv");

        if (!inFile.is_open() || !outFile.is_open()) {
            cerr << "Error: Unable to open file '" << Filename << "'. Please check the file and try again.\n";
            return;
        }

        string line;
        getline(inFile, line);
        outFile << line << endl;

        bool found = false;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string idStr, category, item, count;
            getline(ss, idStr, ',');
            getline(ss, category, ',');
            getline(ss, item, ',');
            getline(ss, count, ',');

            try {
                int currentID = stoi(idStr);
                if (currentID == itemID) {
                    found = true;
                    int newCount = stoi(count) + Quantity;
                    outFile << idStr << "," << category << "," << item << "," << newCount << "\n";
                    continue;
                }
            } catch (const exception& e) {
                cerr << "Error converting to integer: " << e.what() << "\n";
                return;
            }

            outFile << idStr << "," << category << "," << item << "," << count << "\n";
        }

        inFile.close();
        outFile.close();

        if (found) {
            remove(Filename.c_str());
            rename("temp.csv", Filename.c_str());
        } else {
            remove("temp.csv");
            cout << "Menu item with ID " << itemID << " not found.\n";
        }
    }

    //done
    void addToDatedSalesReport(int customerID, string line, int quantity) {
    ofstream file("DatedSalesReport.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file 'DatedSalesReport.csv'. Please check the file and try again.\n";
        return;
    }

    stringstream ss(line);
    string ID,id, category, item, price;
    getline(ss, ID, ',');
    getline(ss, category, ',');
    getline(ss, item, ',');
    getline(ss, price, ',');

    file << __DATE__ << "," << __TIME__ << "," << customerID << "," << category << "," << item << "," << price << "," << quantity << endl;
    file.close();
    }

    //done
    void displaySalesReport() {
        ifstream file("DatedSalesReport.csv");
        if (!file.is_open()) {
            cerr << "Error: Unable to open file 'DatedSalesReport.csv'. Please check the file and try again.\n";
            return;
        }

        string line;
        getline(file, line); // Skip header

        cout << "\n------------------------- Sales Report -------------------------------\n";
        cout << "Date         |                    Item |          Quantity|     Price|\n";
        cout << "----------------------------------------------------------------------\n";

        string currentDate = "";
        double totalRevenue = 0;

        while (getline(file, line)) {
                stringstream ss(line);
                string date,time, cID,category,item,price,quantity;
                getline(ss, date, ',');
                getline(ss, time, ',');
                getline(ss, cID, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

            if (date != currentDate) {
                if (!currentDate.empty()) {
                    cout << "----------------------------------------------------------------------\n";
                }
                currentDate = date;
                cout << "\n                     ------ " << date << " ------\n";
                cout << "----------------------------------------------------------------------\n";
            }

            try {
                totalRevenue += stod(price) * stoi(quantity);
            } catch (const exception& e) {
                cerr << "Error converting price to integer: " << e.what() << "\n";
                return;
            }

            cout << setw(12) << date
                 << "| " << setw(25) << item
                 << "| " << setw(13) << quantity
                 << "    | $" << setw(8) << price
                 << "|\n";
            }

        cout << "----------------------------------------------------------------------\n";
        cout << "\n\nTotal Revenue of the Cafe: $" << totalRevenue << endl;

        file.close();
    }

    //done
    void displayDailySalesReport() {
        ifstream file("DatedSalesReport.csv");
        if (!file.is_open()) {
            cerr << "Error: Unable to open file 'DatedSalesReport.csv'. Please check the file and try again.\n";
            return;
        }

        cout << "\n------------------------- Sales Report -------------------------------\n";
        cout << " Date        |                     Item |         Quantity |    Price|\n";
        cout << "----------------------------------------------------------------------\n";

        string currentDate = __DATE__;
        string line;
        getline(file, line); // Skip header

        double dailyRevenue = 0;
        while (getline(file, line)) {
                stringstream ss(line);
                string date,time, cID,category,item,price,quantity;
                getline(ss, date, ',');
                getline(ss, time, ',');
                getline(ss, cID, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

            if (date == currentDate) {
                try {
                    dailyRevenue += stod(price) * stoi(quantity);
                } catch (const exception& e) {
                    cerr << "Error converting price to integer: " << e.what() << "\n";
                    return;
                }

                cout << setw(12) << date
                    << " | " << setw(25) << item
                    << "| " << setw(13) << quantity
                    << "    | $" << setw(7) << price
                    << "|\n";
                }       
        }

        cout << "----------------------------------------------------------------------\n";
        cout << "\n\nTotal Revenue for " << currentDate << ": $" << dailyRevenue << endl;

        file.close();
    }

    //done
    void displayMonthlySalesReport(string month) {
        fstream file("DatedSalesReport.csv");
        if (!file.is_open()) {
            cerr << "Error: Unable to open file 'DatedSalesReport.csv'. Please check the file and try again.\n";
            return;
        }

        cout << "\n------------------------- Sales Report -------------------------------\n";
        cout << " Date        |                     Item |         Quantity |    Price|\n";
        cout << "----------------------------------------------------------------------\n";

        string currentDate = month;
        string line;
        getline(file, line); // Skip header

        double monthlyRevenue = 0;
        while (getline(file, line)) {
                stringstream ss(line);
                string date,time, cID,category,item,price,quantity;
                getline(ss, date, ',');
                getline(ss, time, ',');
                getline(ss, cID, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');
            
            string monthCheck = date.substr(0,3);
            if (monthCheck == currentDate) {
                try {
                    monthlyRevenue += stod(price) * stoi(quantity);
                } catch (const exception& e) {
                    cerr << "Error converting price to integer: " << e.what() << "\n";
                    return;
                }

                cout << setw(12) << date
                    << " | " << setw(25) << item
                    << "| " << setw(13) << quantity
                    << "    | $" << setw(7) << price
                    << "|\n";
                }       
        }

        cout << "----------------------------------------------------------------------\n";
        cout << "\n\nTotal Revenue for this Month: $" << monthlyRevenue << endl;

        file.close();
    }

    //done
    void displayCustomerOrderHistory(int customerID){
            ifstream file("DatedSalesReport.csv"); 
            if (!file.is_open()) {
                cerr << "Error: Unable to open file '" << "DatedSalesReport.csv" << "'. Please check the file and try again.\n";
                return;
            }

            string currentDate = "";
            
            cout << "\n------------------------- Customer History ---------------------------\n";
            cout << " Date       |                      Item|         Quantity     |  Price|\n";
            cout << "----------------------------------------------------------------------\n";

            string line;
            string header;
            getline(file, header); // Skip the header line

            int countTotalRevenue = 0;
            while (getline(file, line)) {
                stringstream ss(line);
                string date,time, cID,category,item,price,quantity;
                getline(ss, date, ',');
                getline(ss, time, ',');
                getline(ss, cID, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');


                try {
                    stoi(cID);
                }catch (exception& Exception) {
                    cout<<"{Line 1175} Error Converting to integer:- "<<Exception.what()<<endl;
                    return;
                }
                if(stoi(cID) == customerID){
                    cout<< setw(12) << date << "| " << setw(25) << item
                    << "| " << setw(13) << quantity<< "        |  $" << setw(3) << price
                    << "|\n";
                }
 
            }

            cout << "----------------------------------------------------------------------\n";
            file.close();
    }

    //Additional function
    string selectFromCustomerOrderHistory(int customerID,int choice){
            ifstream file("DatedSalesReport.csv"); 
            if (!file.is_open()) {
                cerr << "Error: Unable to open file '" << "DatedSalesReport.csv" << "'. Please check the file and try again.\n";
                return "";
            }

            string line;
            string header;
            getline(file, header); // Skip the header line

            int countTotalRevenue = 0;
            while (getline(file, line)) {
                stringstream ss(line);
                string date,time, cID,category,item,price,quantity;
                getline(ss, date, ',');
                getline(ss, time, ',');
                getline(ss, cID, ',');
                getline(ss, category, ',');
                getline(ss, item, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

                try {
                    
                }catch (exception& Exception) {
                    cout<<"{Line 1313} Error Converting to integer:- "<<Exception.what()<<endl;
                    return "";
                }
                if(stoi(cID) == customerID){
                    cout<< "| " << setw(25) << item
                    << "| " << setw(13) << quantity
                    << "        | $" << setw(3) << price
                    << "|\n";

                    // return a line in the order format
                }
            }
            
            cout << "----------------------------------------------------------------------\n";
            file.close();
            return "";
    }    

    //done
    string popularItem() {
        ifstream file(Filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file '" << Filename << "'. Please check the file and try again.\n";
            return "";
        }

        string line;
        getline(file, line); // Skip header

        string popularItem;
        int popularItemCount = 0;

        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, category, item, count;
            getline(ss, idStr, ',');
            getline(ss, category, ',');
            getline(ss, item, ',');
            getline(ss, count, ',');

            try {
                int currentCount = stoi(count);
                if (currentCount > popularItemCount) {
                    popularItemCount = currentCount;
                    popularItem = item;
                }
            } catch (const exception& e) {
                cerr << "Error converting count to integer: " << e.what() << "\n";
                return "";
            }
        }

        file.close();
        return popularItem;
    }
};

//Class for all Order Details and functionalities
class Order :  public Menu , public Customer, public Inventory, public Sales{
    char again;
    bool isRegistered;
    int choice,Quantity,customerID,registerChoice,loyaltypoint,menuChoice;
    double discount,tax,totalprice,finalTotal;
    double Cheese = 1.50,Olives = 2.00,Avocado= 1.75,Fries= 3.00,Onionrings = 2.50;
public: 
    Order(){}

	//function to Place Order
    void placeOrder(){
        billClear();
        cout<<"Please Enter your Customer ID to proceed Further: ";
        cin>>customerID;
        if (!isIDValid(customerID)) {
            cout<<"Dear Customer you are currently not registered.Please register to proceed further.We are sorry for the inconvenience..."<<endl;
            AddCustomer();
            customerID = getNoCustomers("Customer.csv");
        }else {
            displayCustomerOrderHistory(customerID);
            input();
            
            // cout<<"Would you like to place the same order again?(Y/N)";
            // cin>>choice;
            // if (choice == 'y') {
            //     cout<<"Please Choose from the above options: ";
            //     cin>>choice;
            //     selectFromCustomerOrderHistory(customerID,choice);
            // }    
        }

    do{
        cout<<"|________________Menu Selection_______________|"<<endl;
        cout<<"|         1. View Full Menu                   |"<<endl;
        cout<<"|         2. View Sub Menu                    |"<<endl;
        cout<<"|         0. Back To Main                     |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cin>>menuChoice;
        
        while (choice < 0 || choice > 2) {
                cerr << "Invalid choice Entered...Please try again: ";
                cin>>choice;
        }
        system("cls");

        switch (menuChoice) {
            case 1: 
                displayMenu();
                break;
            case 2:
                displayMenuByCatagory();
                break;
            case 0:
                break;
        }

        cout<<"What would you like to order today? "<<endl;
        cin>>choice;

        while(!searchIsItemValid(choice)){
            cout<<"Invalid ID: "<<choice<<endl;
            cout<<"What would you like to order today? "<<endl;
            cout<<"Press 0 to go back to Menu..."<<endl;
            cin>>choice;
            if (choice == 0) {
                return;
            }
        }

        string line = search(choice);

        if (!chkInventory(choice)) {
            cout<<"\nLow stock! Item is not available to purchase\n\n";
        }

        cout<<"Select Your Quantity please: \n";
        cin>>Quantity;

        while(Quantity <= 0){
            cerr << "Invalid Quantity Please enter a Positive Integer\n";
            cout << "Select Your Quantity please: \n";
            cin >> Quantity;
        }

        while(!chkInventory(choice,Quantity)){
            cout<<"Stock is low please enter a lower quantity: \n";
            if(getInventory(choice) == 0){
                cout<<"No stock in Inventry.Restocking... "<<endl;
                updateInventory(choice);
            }
            cout<<"Select Your Quantity please: \n";
            cin>>Quantity;
        }

        if (line.length() > 1) {
            makeBill(line,Quantity);
        }

        char SideChoice;
        cout<<"Would you like to add some Toppings to your order?(Y/N): \n";
        cin>>SideChoice;

        totalprice = selectSide(SideChoice);
        
        addToDatedSalesReport(customerID,line,Quantity);
        addToSalesReport(choice,Quantity);
        DeductInventory(choice,Quantity);

        cout<<"Would you like to Place another order before proceeding to the Payment?(Y/N) \n";
        cin>>again;
    }while(again != 'N' && again != 'n');

        printAndSaveBill(customerID);

        cout<<"Thank You for your Patronage..."<<endl;
        input();
    }

    void billClear(){
        ofstream file("bill.csv",ios :: trunc);
        if (!file.is_open())
        {
            cerr<< "Error clearing Bill\n";
        }
        file.close();
    }

    //Sides Menu
    double selectSide(char SideChoice){
        int sides = 0;
        if (SideChoice == 'Y' || SideChoice == 'y' ) {
            cout<< "\n----------- Sides and Toppings Menu -----------\n";
            cout<< "| ID | Item Name              | Price ($) |\n";
            cout<< "|----|------------------------|-----------|\n";
            cout<< "|  1 | Extra Cheese           | 1.50      |\n";
            cout<< "|  2 | Olives                 | 2.00      |\n";
            cout<< "|  3 | Avocado                | 1.75      |\n";
            cout<< "|  4 | Fries                  | 3.00      |\n";
            cout<< "|  5 | Onion Rings            | 2.50      |\n";
            cout<< "---------------------------------------------\n";
            cout<<"What would you like on the side or for Toppings?\n";
            cout<<"Press 0 for None\n";
            cin>>sides;
        }
            
        while(sides < 0 || sides > 5){
            cout<<"Invalid Choice please try again "<<endl;
            cin>>sides;
        }

        switch(sides){
            case 0:
            totalprice = 0;
            break;

            case 1:
            totalprice = Quantity * Cheese;
            break;

            case 2:
            totalprice = Quantity * Olives;
            break;

            case 3:
            totalprice = Quantity * Avocado;
            break;

            case 4:
            totalprice = Quantity * Fries;
            break;

            case 5:
            totalprice = Quantity * Onionrings;
            break;
        }
        return totalprice;
    }

	//function to update customers loyalty points 
    void updatePoints(int ID,bool B){
            string Filename = "Customer.csv";
            ifstream file(Filename);
            ofstream tempFile("temp.csv");
            if (!file.is_open() || !tempFile.is_open()) {
                cout << "Error opening file to update customer.\n";
                return;
            }

            string line;
            string header;
            getline(file, header);
            tempFile<<header<<endl;

            bool found = false;

            while (getline(file, line)) {
                stringstream ss(line);
                string id,name,contact,preference,points;
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, preference, ',');
                getline(ss,points,',');
                
                try {
                    stoi(id);
                }catch (exception& Exception) {
                    cout<<"{Line 1234} Error Converting to integer:- "<<Exception.what()<<endl;
                    return;
                }
                if (stoi(id) == ID) {
                    found = true;
                    int newPoints;
                    if(B == false){
                        newPoints = stoi(points);
                        newPoints -= 1;
                    }else {
                        newPoints = stoi(points);
                        newPoints += 1;
                    }
                    tempFile << id << "," << name << "," << contact << "," << preference << "," << newPoints << "\n";
                    continue;
                }

                tempFile << id << "," << name << "," << contact << "," << preference << "," << points << "\n";
            }

            file.close();
            tempFile.close();

            if (found) {
                remove(Filename.c_str());
                rename("temp.csv", Filename.c_str());
            } else {
                remove("temp.csv");
                cout << "Customer with ID " << ID << " not found.\n";
            }
    }

	//function to register new customers 
    void registercustomer(){
            cout<<"Are you a registered customer with us? (1 for Yes, 0 for No): ";
            cin>>isRegistered;

            if(isRegistered) {
                cout<<"Please enter your Customer ID: ";
                cin>>customerID;
            }

           if (!isIDValid(customerID)) {  
                cout << "Customer ID not found! Please try again or register as a new customer.\n";
                cout << "Would you like to register now? (1 for Yes, 0 for No): ";
                cin >> registerChoice;
                    if (registerChoice == 1) {
                        AddCustomer(); 
                    }else if (registerChoice == 0) {
                        cout << "Sorry, we cannot proceed without customer details. Please register to continue.\n";
                        return; 
                    }else {
                        cout << "Invalid choice. Please try again.\n";
                    }    
            } else {
                cout << "Welcome back! We have found your details in our system.\n";
           }
    }

	//function to check customers loyalty points 
    double checkLoyaltypoints(int ID){
        double currentPoints = checkPoints(ID);
        char redeem;

            if (currentPoints >= 100) {
                cout<< "You have " << currentPoints << " loyalty points. Do you want to redeem 1 point for a 10 percent discount? (Y/N): ";
                cin>>redeem;
                if (redeem == 'y' || redeem == 'Y') {
                    updatePoints(ID, false);// false to deduct points
                    discount = 10;
                    return discount;
                }
            }
            return 0;
    }

	//function to make customers bill
    void makeBill(string line,int Quantity){
        string filename = "bill.csv";
        ofstream outfile(filename,ios ::app);
        if (!outfile.is_open()) {
            cout<<"Error opening "<<filename<<endl;
            return;
        }
        outfile<<line<<","<<Quantity<<endl;
    }

	//Fuction to print and save Bill
    void printAndSaveBill(int ID) {
        string billFilename = "bill.csv";
        string receiptFilename = "Receipt.txt"; 

        ifstream billFile(billFilename);
        if (!billFile.is_open()) {
            cerr << "Error opening " << billFilename << endl;
            return;
        }

        ofstream receiptFile(receiptFilename);
        if (!receiptFile.is_open()) {
            cerr << "Error opening " << receiptFilename << endl;
            billFile.close();
            return;
        }
        discount = checkLoyaltypoints(ID);

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // debatable line break choice
        cout<<"--------------- CAFE Receipt ------------------\n";
        cout << "           Welcome to Our Outlet              \n";
        cout << "      Address: 123 Food Street,lahore          \n";
        cout << "     Date: " << __DATE__ << "  Time: " << __TIME__ << "     \n";
        cout << "-----------------------------------------------\n";

        receiptFile <<  "--------------- CAFE Receipt ------------------\n";
        receiptFile << "           Welcome to Our Outlet              \n";
        receiptFile << "      Address: 123 Food Street,lahore          \n";
        receiptFile << "     Date: " << __DATE__ << "  Time: " << __TIME__ << "     \n";
        receiptFile << "-----------------------------------------------\n";

        cout << left << setw(15) << "Item" << setw(8) << "Qty" << setw(15) << "Unit Price"<< right << setw(8) << "Price" << "$\n";
        cout << "-----------------------------------------------\n";

        receiptFile << left << setw(15) << "Item" << setw(8) << "Qty" << setw(15) << "Unit Price" << right << setw(8) << "Price" << "$\n";
        receiptFile << "-----------------------------------------------\n";
        
        string line;
        double totalBill = 0.0;
        int count = 0;

       while (getline(billFile, line)){
            stringstream ss(line);
            string idStr, category, item, price, availability, quantityStr;
            getline(ss, idStr, ',');
            getline(ss, category, ',');
            getline(ss, item, ',');
            getline(ss, price, ',');
            getline(ss, availability, ',');
            getline(ss, quantityStr, ',');

            int quantity = 0;
            double unitPrice = 0.0;

            try {
                unitPrice = stod(price);
                quantity = stoi(quantityStr);
            } catch (exception& Exception) {
                cerr << "{Line Error} Unable to convert price or quantity: " << Exception.what() << endl;
                continue;
            }

            double total = unitPrice * quantity;
            totalBill += total;
            count+=quantity;
            cout << left << setw(15) << item 
                << setw(8) << quantity 
                << setw(15) << unitPrice 
                << right << setw(8) << total << "$\n";

            receiptFile << left << setw(15) << item 
                        << setw(8) << quantity 
                        << setw(15) << unitPrice
                        << right << setw(8) << total << "$\n";
        }
        tax = totalBill * 0.16;
        cout << "-----------------------------------------------" << endl;
        cout << "Total Items: " << setw(33) << count << endl;
        cout << "Total Bill: " << setw(34) << totalBill << "$" << endl;
        cout << "Tax: " << setw(41) << tax << "$" << endl;
        totalBill += tax; 
        cout << "Total Bill inclusive of tax: " << setw(17) << totalBill<< "$" << endl;
        cout << "Discount: " << setw(36) << totalBill - discount << "$" << endl;
        totalBill = totalBill - (totalBill / 10);
        cout << "Total Bill after Discount: " << setw(19) << totalBill<< "$" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Thank you for visiting Our Cafe! Enjoy your meal!\n";

        receiptFile << "-----------------------------------------------" << endl;
        receiptFile << "Total Items: " << setw(33) << count << endl;
        receiptFile << "Total Bill: " << setw(34) << totalBill - tax<< "$" << endl;
        receiptFile << "Tax: " << setw(41) << tax << "$" << endl;
        receiptFile << "Total Bill inclusive of tax: " << setw(17) << totalBill << "$" << endl;
        receiptFile << "Discount: " << setw(36) << discount<< "$" << endl;
        receiptFile << "Total Bill after Discount: " << setw(19) << totalBill << "$" << endl;
        receiptFile << "-----------------------------------------------" << endl;
        receiptFile << "Thank you for visiting Our Cafe! Enjoy your meal!\n";

        if(totalBill > 50){
            updatePoints(ID,true);// true to add points
        }

        billFile.close();
        receiptFile.close();

        billClear();
    }
};

class Manager: public Menu , public Customer, public Inventory, public Sales{
	public:
		int choice;
		string month;
	void CallManager(){
		
	do{
		system("cls"); 
		cout<<"|________________Welcome Manager______________|"<<endl;
		cout<<"|_____________________________________________|"<<endl;
		cout<<"|       -------------Menu--------------       |"<<endl;
        cout<<"|         1. Display All Menu Items           |"<<endl;
        cout<<"|         2. Add Menu Item                    |"<<endl;
        cout<<"|         3. Display Items by catagory        |"<<endl;
        cout<<"|         4. Update Menu Item                 |"<<endl;
        cout<<"|         5. Delete Menu Item                 |"<<endl;
	    cout<<"|       ------Customer Management------       |"<<endl;
        cout<<"|         6. Register New Customer            |"<<endl;
        cout<<"|         7. Display All Customers            |"<<endl;
        cout<<"|         8. Update Customer Details          |"<<endl;
        cout<<"|         9. Delete Customer                  |"<<endl;
        cout<<"|       -----Inventory Management------       |"<<endl;
        cout<<"|         10. Check Inventory                 |"<<endl;
        cout<<"|         11. Update Inventory                |"<<endl;
        cout<<"|       -------------Sales-------------       |"<<endl;
        cout<<"|         12. Generate sales Report           |"<<endl;
        cout<<"|         0. Back To Main                     |"<<endl;
       	cout<<"|_____________________________________________|"<<endl;
        cout<<"\n             Enter your choice: ";
        cin>> choice;

        //check valid choice
        while (choice < 0 || choice > 12) {
            cerr << "Invalid choice Entered...Please try again: ";
            cin>>choice;
        }
        system("cls");

        switch(choice){
            case 1:
                displayMenu();
                input();
                break;
            case 2:
                addItemToSalesReport(create());
                break;
            case 3:
                displayMenuByCatagory();
                input();
                break;
            case 4:
                update();
                input();
                break;
            case 5:
                deleteRecord();
                input();
                break;
            case 6: 
                AddCustomer();
                input();
                break;
            case 7:
                displayAllCustomers();
                input();
                break;
            case 8: 
                updateCustomer();
                input();
                break;
            case 9: 
                deleteCustomer();
                input();
                break;
            case 10: 
                displayInventory();
                input();
                break;
            case 11:
                displayInventory();
                int id;
                cout<<"Enter the ID to update"<<endl;
                cin>>id;
            	updateInventory(id);
                break;
            case 12:
                cout<<"|_________________Sales Menu__________________|"<<endl;
                cout<<"|         1. Daily sales Report               |"<<endl;
                cout<<"|         2. Monthly sales Report             |"<<endl;
                cout<<"|         3. Full sales Report                |"<<endl;
                cout<<"|         0. Back To Main                     |"<<endl;
                cout<<"|_____________________________________________|"<<endl;
                cin >> choice;

                while (choice < 0 || choice > 3) {
                    cerr << "Invalid choice Entered...Please try again: ";
                    cin>>choice;
                }
                system("cls");

                switch (choice) {
                    case 1: 
                        displayDailySalesReport();
                        break;
        	        case 2:
                        cout<<"Enter the Month {Jan,Feb....Dec}: ";
                        cin>>month;
                        displayMonthlySalesReport(month);
                        break;
                    case 3:
                        displaySalesReport();
                        break;
                    case 0:
                        break;
                }
                input();
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please try again.";
              }
          }while (choice != 0);
     }
};

class Staff: public Order{
	public:
		int choice;
        int menuChoice;
        string month;
    Staff(){}

	void CallStaff(){
		
	do{
		system("cls");
		cout<<"|_________________Welcome Staff_______________|"<<endl;
		cout<<"|_____________________________________________|"<<endl;
		cout<<"|       -------------Order-------------       |"<<endl;
        cout<<"|         1. Place Order                      |"<<endl;
        cout<<"|         2. Generate sales Report            |"<<endl;
		cout<<"|       -------------Menu--------------       |"<<endl;
        cout<<"|         3. Display All Menu Items           |"<<endl;
        cout<<"|         4. Display Items by catagory        |"<<endl;
        cout<<"|       ------Customer Management------       |"<<endl;
        cout<<"|         5. Register New Customer            |"<<endl;
        cout<<"|       -----Inventory Management------       |"<<endl;
        cout<<"|         6. Check Inventory                  |"<<endl;
        cout<<"|         0. Back To Main                     |"<<endl;
       	cout<<"|_____________________________________________|"<<endl;
        cout<<"\n             Enter your choice: ";
        cin >> choice;

        //check valid choice
        while (choice < 0 || choice > 12) {
            cerr << "Invalid choice Entered...Please try again: ";
            cin>>choice;
        }
        system("cls");

        switch(choice){
        	
        	case 1: 
        	    placeOrder();
        	    break;
        	case 2:
                cout<<"|_________________Sales Menu__________________|"<<endl;
                cout<<"|         1. Daily sales Report               |"<<endl;
                cout<<"|         2. Monthly sales Report             |"<<endl;
                cout<<"|         3. Full sales Report                |"<<endl;
                cout<<"|         0. Back To Main                     |"<<endl;
                cout<<"|_____________________________________________|"<<endl;
                cin >> menuChoice;

                while (menuChoice < 0 || menuChoice > 3) {
                    cerr << "Invalid choice Entered...Please try again: ";
                    cin>>menuChoice;
                }
                system("cls");

                switch (menuChoice) {
                    case 1: 
                        displayDailySalesReport();
                        break;
        	        case 2:
                        cout<<"Enter the Month {Jan,Feb....Dec}: ";
                        cin>>month;
                        displayMonthlySalesReport(month);
                        break;
                    case 3:
                        displaySalesReport();
                        break;
                    case 0:
                        break;
                }
                input();
                break;
            case 3:
                displayMenu();
                input();
                break;
            case 4:
                displayMenuByCatagory();
                input();
                break;
            case 5: 
                AddCustomer();
                input();
                break;
            case 6: 
                displayInventory();
                input();
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please try again.";
              }
          } while (choice != 0);
     }
};

int main(){
    system("cls");
    Manager manager;
    Staff staff;
    int choice;

    do{
        cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
        cout<<"|<<<<<<<<<<<<<<WELCOME TO CAMPUS BITES>>>>>>>>>>>>>>|"<<endl;
        cout<<"|        --Where Every Bite Feels Like Home--       |"<<endl;
        cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
        cout<<"|            -Who is using the System?              |"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|             1.  Manager                           |"<<endl;
        cout<<"|             2.  Staff                             |"<<endl;
        cout<<"|             0.  Exit the program                  |"<<endl;
        cout<<"|___________________________________________________|"<<endl;
        cout<<"\n                  Enter your choice: ";
        cin >> choice;

        //check valid choice
        while (choice < 0 || choice > 2) {
            cerr << "            Invalid choice! Please try again.\n";
            cout<<"\n                  Enter your Choice: ";

            cin>>choice;
        }
        system("cls");

        switch (choice) {
            case 1:
            	if(authentication()){
               		manager.CallManager();
                }
                break;
            case 2:
                staff.CallStaff();
                break;
            case 0:
                cout << "Exiting the program..... ";
                break;
            default:
                cout << "         Invalid choice! Please try again.";
        }
    } while (choice != 0);
    return 0;
}

//select from past orders

   