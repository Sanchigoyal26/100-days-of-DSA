#include <iostream>
using namespace std;

int getSingleDigit(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int hashFunction(int sap_id) {
    int lastThree = sap_id % 1000;
    return getSingleDigit(lastThree);
}

int main() {
    int hashTable[10] = {0};  // array of size 10

    int sap_id = 590027285;

    int key = hashFunction(sap_id);

    hashTable[key] = sap_id;

 // display
    cout << "Hash Table:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " -> " << hashTable[i] << endl;
    }

    // Accessing using hash key
    cout << "\nAccessing using key:\n";
    cout << "Key " << key << " contains SAP ID: " << hashTable[key] << endl;

    return 0;
}