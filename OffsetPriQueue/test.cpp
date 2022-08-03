#include <iostream>
#include "OffsetPriQueue.h"
#include <cstdlib>
#include <time.h>
using namespace std;

struct Test {
	long Jones;
	int target;
	long williwam;
	Test(int t){
		target = t;
	}
};

int main(){
	srand(time(NULL));
	cout << "calling pq constructor...\n";
	OffsetPriQueue<Test, int> pq(offsetof(Test, target));
	cout << "populating q w/ 50 rand nums...\n";
	for (int i = 0; i < 50; i++){
		int ran = rand() % 100;
		cout << ran << " ";
		pq.enqueue(Test(ran));
	}
	cout << "\n";
	cout << "size: " << pq.size() << endl;
	cout << "DISPLAY:\n";
	pq.display();
	cout << "dequeueing while !empty...\n";
	int i = 0;
	while (!pq.isEmpty()){
		if (i % 20 == 19)
			cout << "\n";
		cout << pq.dequeue().target << " ";
		i++;
	}
	cout << "\n";
	cout << "ending program...\n";
	return 0;
}
