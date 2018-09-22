#include <iostream>
#include <string>
using namespace std;

float calculatePopulation( float, float);

int main(int argc, const char * argv[]) {
    
    int pop;
    int growth;
    int newpop;

    string univName;
    
    char done  = 'N';
    
    cout << "Enter the name of the university\n";
    getline(cin, univName);
    
    do {
        cout << "What is the current population? ";
        cin >> pop;
        while( pop < 1)
        {
            cout << "Please specify a non-negative number.\n";
            cin >> pop;
        }
        
        cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
        cin >> growth;
        while(growth < 0)
        {
            cout << "Please specify a non-negative percentage.\n";
            cin >> growth;
        }
        
        cout << "\nYear\tNew Population" << endl;
        
        int i;
        for (i = 1; i <= 5; i++) {
            newpop = (int)calculatePopulation( pop , growth );
            pop = newpop;
            cout << i << "\t \t" << newpop << endl;
        }

        cout << "\nFinal population of ";
        cout << univName;
        cout << " is " << newpop << endl;
        cout << "Done? (Y/N) ";
        cin >> done;
        switch (toupper(done))
        {
            case 'Y':
                cout << "Exiting...\n";
                break;
            case 'N':
                cout << "Starting again\n";
                cout << "------------------------------\n";
                break;
            default:
                cout << "Invalid input\n";
                cout << "The program will start again\n";
                cout << "------------------------------\n";
                break;
        }
        
    } while((done != 'Y') && (done != 'y'));
    
    return 0;
}

float calculatePopulation( float pop, float growth)
{
    float growthRate = growth / 100;
    float increase = (float) pop * growthRate;
    return (pop + increase);

}
