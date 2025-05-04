#include<iostream>
using namespace std;

void calculateavg(int arr[],int n,double &avg){
	
	int sum=0;
	
	if (n==3){
		
		for(int i=0; i<n; i++){
			sum+=arr[i];
		}
		
		avg=sum/n;	
	}
	
	cout<<"The average of the grades are: "<<avg<<endl;	
}

void calculateavg(int arr[],int n, bool isfour,double &avg){
	
	int sum=0;
	
	if (n==4 && isfour){
		
		for(int i=0; i<n; i++){
			sum+=arr[i];
		}
		
		avg=sum/n;	
	}
	
	cout<<"The average of the grades are: "<<avg<<endl;	
}

void assigngrade(double avg,char &grade){
	
    if(avg >= 90){
        grade='A';
        
    } else if(avg >= 80){
    	grade='B';
        
    } else if(avg >= 70){
        grade='C';
        
    } else if(avg >= 60){
        grade='D';
        
    } else{
        grade='F';
        
    }
}

int main(){
	
	int arr[4];
	int n;
	double avg;
	char grade;
    int option;
    
    do{
		
	cout<<"Welcome to student Grade Management system"<<endl;
	cout<<"How many subjects do you wish to enter? 3 or 4?"<<endl;
	cin>>n;
	
	while(n<=0 || n==1 || n==2 || n>4){
		cout<<"Please enter valid subjects: ";
		cin>>n;
	}
	
	cout<<"Enter subject marks: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(n==3){
        calculateavg(arr,n,avg);
    } else if(n==4){
        calculateavg(arr,n,true,avg); 
    }

    assigngrade(avg,grade);
    

    cout<<"The assigned grade is: "<<grade<<endl;
    cout<<"press any number to retry or 0 to exit the program"<<endl;
    cin>>option;
	
   }while(option!=0);
	    
    return 0;
}