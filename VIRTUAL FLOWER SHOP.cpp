#include<iostream> 
#include<iomanip> 
using namespace std;

class flowershop{
	
	public:
		
		double small = 5.5;
		int smallcount = 0;
		double medium = 7.5;
		int mediumcount = 0;
		double large = 9.5;
		int largecount = 0;
		double sizeprice;
		int sizechoice;
		
		void bouquetsize(){
			system("CLS");
			
			cout<<"| Please Select Bouquet Size |"<<endl;
			cout<<endl;
			cout<<"| 1. Small ($5.5)            |"<<endl;
			cout<<"| 2. Medium ($7.5)           |"<<endl;
			cout<<"| 3. Large ($9.5)            |"<<endl;
			cin>>sizechoice;
			
			while(sizechoice < 1 || sizechoice > 3 ){
				
				cout<<"| Invalid Option, please try again! |"<<endl;
    	         cin>>sizechoice;
			}
			
			switch(sizechoice){
				case 1:
					sizeprice = small;
					smallcount++;
					break;
				case 2:
					sizeprice = medium;
					mediumcount++;
					break;
				case 3:
					sizeprice = large;
					largecount++;
					break;
			}
		}
		
		double rose = 1.2;
		int rosecount = 0;
		double lily = 1.3;
		int lilycount = 0;
		double carnations = 1.0;
		int carnationscount = 0;
		double daffodil = 1.0;
		int daffodilcount = 0;
		double gerbera = 1.1;
		int gerberacount = 0;
		double chrysanthemum = 1.1;
		int chrysanthemumcount = 0;
		double assorted = 0.8;
		int assortedcount = 0;
		double typeprice;
		int typechoice;
		
			void flowertype(){
			system("CLS");
			
			cout<<"| Please Select Flower Type |"<<endl;
			cout<<endl;
			cout<<"| 1. Rose ($1.2)            |"<<endl;
			cout<<"| 2. Lily ($1.3)            |"<<endl;
			cout<<"| 3. Carnations ($1.0)      |"<<endl;
			cout<<"| 4. Daffodil ($1.0)        |"<<endl;
			cout<<"| 5. Gerbera ($1.1)         |"<<endl;
			cout<<"| 6. Chrysanthemum ($1.1)   |"<<endl;
			cout<<"| 7. Assorted ($0.8)        |"<<endl;
			cin>>typechoice;
			
			while(typechoice < 1 || typechoice > 7 ){
				
				cout<<"| Invalid Option, please try again! |"<<endl;
    	         cin>>typechoice;
			}
			
			switch(typechoice){
				case 1:
					typeprice = rose;
					rosecount++;
					break;
				case 2:
					typeprice = lily;
					lilycount++;
					break;
				case 3:
					typeprice = carnations;
					carnationscount++;
					break;
			    case 4:
					typeprice = daffodil;
					daffodilcount++;
					break;
				case 5:
					typeprice = gerbera;
					gerberacount++;
					break;
				case 6:
					typeprice = chrysanthemum;
					chrysanthemumcount++;
					break;
			    case 7:
					typeprice = assorted;
					assortedcount++;
					break;		
			}
		}
		
		double white = 1.3;
		int whitecount = 0;
		double red = 1.2;
		int redcount = 0;
		double pink = 1.1;
		int pinkcount = 0;
		double yellow = 1.1;
	    int yellowcount = 0;
		double blue = 1.2;
		int bluecount = 0;
		double mixed = 1.0;
		int mixedcount = 0;
		double colourprice;
		int colourchoice;
		
		void flowercolour(){
			system("CLS");
			
			cout<<"| Please Select Flower Colour |"<<endl;
			cout<<endl;
			cout<<"| 1. White ($1.3)             |"<<endl;
			cout<<"| 2. Red ($1.2)               |"<<endl;
			cout<<"| 3. Pink ($1.1)              |"<<endl;
			cout<<"| 4. Yellow ($1.1)            |"<<endl;
			cout<<"| 5. Blue ($1.2)              |"<<endl;
			cout<<"| 6. Mixed ($1.0)             |"<<endl;
			cin>>colourchoice; 
			
			while(colourchoice < 1 || colourchoice > 6 ){
				
				cout<<"| Invalid Option, please try again! |"<<endl;
    	         cin>>colourchoice;
			}
			
			switch(colourchoice){
			    case 1:
					colourprice = white;
					whitecount++;
					break;
				case 2:
					colourprice = red;
					redcount++;
					break;
				case 3:
					colourprice = pink;
					pinkcount++;
					break;
			    case 4:
					colourprice = yellow;
					yellowcount++;
					break;
				case 5:
					colourprice = blue;
					bluecount++;
					break;
				case 6:
					colourprice = mixed;
					mixedcount++;
					break;	
				}
		}
		
		double flowerprice;
		double Totalsales = 0.0;
		double minprice = 0.0;
		double maxprice = 0.0;
		double averageprice = 0.0;
		int ordercount = 0;
		
		void bouquetprice(){
			system("CLS");
			
			flowerprice = (typeprice+colourprice)*sizeprice;
			cout<<"| Great choice! Your total for this purchase is: |"<<endl;
			cout<<"  Total: $"<<flowerprice<<endl;
			
			Totalsales += flowerprice;
			ordercount++;
			cout<<"  Your Total Order Costs: $"<<Totalsales<<endl;
			
			if (ordercount == 1 || flowerprice < minprice) {
                minprice = flowerprice;
           }
            if (flowerprice > maxprice) {
                maxprice = flowerprice;
           }
			
			averageprice = Totalsales/ordercount;
		}
		
		int statisticschoice;
		
		void orderstatistics(){	
		system("CLS");
		
		while (true){
		cout<<"|___________________________________|"<<endl;
	    cout<<"|         Sales Statistics          |"<<endl;
       	cout<<endl;
     	cout<<"|Please Choose any of the following:|"<<endl;
    	cout<<"| 1.Number of Bouquets Sold by Size |"<<endl;
	    cout<<"| 2.Number of Bouquets Sold by Type |"<<endl;
	    cout<<"| 3.Number of Bouquets Sold by Color|"<<endl;
	    cout<<"| 4.Statistics of the Day           |"<<endl;
	    cout<<"| 5.Back to Main Menu               |"<<endl;
	    cin>>statisticschoice;
	    
	    while(statisticschoice < 1 || statisticschoice > 5){
				
				cout<<"| Invalid Option, please try again! |"<<endl;
    	         cin>>statisticschoice;
			}
			
			switch(statisticschoice){	
			case 1:
				soldbysize();
				
				system("CLS");
				break;	
			case 2:
				soldbytype();
				
				system("CLS");
				break;	
			case 3:
				soldbycolour();
				
				system("CLS");
				break;	
			case 4:
				daystatistics();
				
				system("CLS");
				break;	
			case 5:
				return;
				
			}
			
		}
		
	}
		void soldbysize(){
			system("CLS");
			
			cout<<"|_______________________________________|"<<endl;
			cout<<" Small size Sold:  "<<smallcount<<endl;
			cout<<" Medium size Sold: "<<mediumcount<<endl;
			cout<<" Large size Sold:  "<<largecount<<endl;
			cout<<endl;
			cout<<"| Press Enter to Return to the Submenu! |"<<endl;
			cin.ignore();
			cin.get();
		}
		
		void soldbytype(){
			system("CLS");
			
			cout<<"|_______________________________________|"<<endl;
			cout<<" Rose Sold:          "<<rosecount<<endl;
			cout<<" Lily Sold:          "<<lilycount<<endl;
			cout<<" Carnations Sold:    "<<carnationscount<<endl;
			cout<<" Daffodils Sold:     "<<daffodilcount<<endl;
			cout<<" Gerbera Sold:       "<<gerberacount<<endl;
			cout<<" Chrysanthemum Sold: "<<chrysanthemumcount<<endl;
			cout<<" Assorted Sold:      "<<assortedcount<<endl;
			cout<<endl;
			cout<<"| Press Enter to Return to the Submenu! |"<<endl;
			cin.ignore();
			cin.get();
		}
		
		void soldbycolour(){
			system("CLS");
			
	        cout<<"|______________________________________|"<<endl;
			cout<<" White Sold:  "<<whitecount<<endl;
			cout<<" Red Sold:    "<<redcount<<endl;
			cout<<" Pink Sold:   "<<pinkcount<<endl;
			cout<<" Yellow Sold: "<<yellowcount<<endl;
			cout<<" Blue Sold:   "<<bluecount<<endl;
			cout<<" Mixed Sold:  "<<mixedcount<<endl;
			cout<<endl;
			cout<<"| Press Enter to Return to the Submenu! |"<<endl;
			cin.ignore();
			cin.get();
		}
		
		void daystatistics(){
			system("CLS");
			
			cout<<"|_______________________________________|"<<endl;
			cout<<"|         Statistics of the Day         |"<<endl;
       	    cout<<endl;
          	cout<<" Minimum price of Bouquets sold: $"<<minprice<<endl;
        	cout<<" Maximum price of Bouquets sold: $"<<maxprice<<endl;
        	cout <<fixed<<setprecision(2);
	        cout<<" Average price of Bouquets sold: $"<<averageprice<<endl;
	        cout<<" Total Number of Bouquets sold:   "<<ordercount<<endl;
	        cout<<" Total sales Amount:             $"<<Totalsales<<endl;
	 		cout<<endl;
			cout<<"| Press Enter to Return to the Submenu! |"<<endl;
			cin.ignore();
			cin.get();
		}
		
		
	
};

int main(){
	
	flowershop f;
	int choice;
	
 while(true){
	system("CLS");
	
	cout<<"|___________________________________|"<<endl;
	cout<<"|    Welcome to my Flower Shop!     |"<<endl;
	cout<<endl;
	cout<<"|Please Choose any of the following:|"<<endl;
	cout<<"| 1. Place an order.                |"<<endl;
	cout<<"| 2. Veiw Sales Statistics.         |"<<endl;
	cout<<"| 3. Exit the program.              |"<<endl;
	cin>>choice;
	
    while(choice < 1 || choice > 3){
    	
    	cout<<"| Invalid Option, please try again! |"<<endl;
    	cin>>choice;
	}
	
	switch(choice){
		case 1:
			system("CLS");
			
			if (f.ordercount >= 10){
			cout<<"| You have reached your order limit!      |"<<endl;
			cout<<"| Press Enter to Return to the Main Menu! |"<<endl;
			cin.ignore();
			cin.get();
		}
		else 
		{
			f.bouquetsize();
			f.flowertype();
			f.flowercolour();
			f.bouquetprice();	
			cout<<endl;
			
			cout<<"| Press Enter to Return to the Main Menu! |"<<endl;
			cin.ignore();
			cin.get();
		}
			break;
			
		case 2:
			system("CLS");
			
			f.orderstatistics();
			break;
			
		case 3:
		   system("CLS");
		
		   cout<<"| Thank you for Visiting my Shop! |"<<endl;
		   cout<<"| Hope you visit again, Bye!      |"<<endl;
		   
		   return 0;
	}	
}	
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
