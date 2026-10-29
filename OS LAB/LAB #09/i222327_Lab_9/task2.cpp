#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <pthread.h>

using namespace std;

struct Transaction
{
    int amount1;
    int amount2;
    string customer1Name;
    string customer2Name;
    string transactionType1;
    string transactionType2;
};

void* processTransaction(void* arg) 
{
    Transaction* trans = (Transaction*)arg;

    sleep(1);

    cout << "Transaction Details:" << endl;
    cout << trans->customer1Name << " performs a " << trans->transactionType1 
         << " of $" << trans->amount1 << endl;
    cout << trans->customer2Name << " performs a " << trans->transactionType2 
         << " of $" << trans->amount2 << endl;
    cout << "----------------------------------------\n";

    pthread_exit(NULL);
}



int  main()
{
    int numPairs;
    cin>>numPairs;



    int numCustomers = numPairs * 2;
    Transaction transactions[numPairs];
    pthread_t threads[numPairs];

    for (int i = 0; i < numPairs; i++) 
    {
        transactions[i].customer1Name = "Customer_1" ;//+ to_string(i * 2 + 1);
        transactions[i].customer2Name = "Customer_2" ;//+ to_string(i * 2 + 2);
        
        transactions[i].amount1 = rand() % 901 + 100;  
        transactions[i].amount2 = rand() % 901 + 100;

        transactions[i].transactionType1 = (rand() % 2 == 0) ? "Deposit" : "Withdrawal";
        transactions[i].transactionType2 = (rand() % 2 == 0) ? "Deposit" : "Withdrawal";
    }

    for (int i = 0; i < numPairs; i++)
    {
        pthread_create(&threads[i], NULL, processTransaction, &transactions[i]);
    }

    for (int i = 0; i < numPairs; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    cout << "\nAll banking transactions have been completed!\n";

    return 0;
}


