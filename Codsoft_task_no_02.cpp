#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	
	  char op;
	
	double num_1, num_2, result;
	
	
	cout<<" ************** Basic Calculator **************   "<<endl<<endl;
	
	cout<<" Enter the Ist Number: "<<endl;
	cin>>num_1;
	
	cout<<" Enter the operator (' / ', ' * ', ' + ', ' - ') to be performed: ) "<<endl;
	cin>> op;
	cout<<" Enter the 2nd Number: "<<endl;
	cin>>num_2;
	
	
	switch(op){
		
		case '/':
			if (num_2 != 0) {
            result = num_1 / num_2;
            cout << "The Result of : " << num_1 << " / " << num_2 << " = " << result <<endl;
            } else {
            cout << "Error: Invalid Input." <<endl;
            }
            break;
			
		case '*':
		    result = (num_1 * num_2);
		    cout << "The Result of : " << num_1 << " * " << num_2 << " = " << result <<endl;
		    break;
		
		case '+':
		    result = (num_1 + num_2);
		    cout << "The Result of : " << num_1 << " + " << num_2 << " = " << result <<endl;
			break;
			
		case '-':
		    result = (num_1 - num_2);
		    cout << "The Result of : " << num_1 << " - " << num_2 << " = " << result <<endl;
			break;	
			
	    default:
            cout << "Error: Invalid operator." << endl;	    
	}

	return 0;
}