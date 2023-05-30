#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// int findCelebrity(int n) {
//  	// Write your code here.
// 	 vector<int>indegree(n);
// 	 vector<int>outdegree(n);
// 	 for(int i=0;i<n;i++){
// 		 for(int j=0;j<n;j++){
//                    if (knows(i, j)) {
//                      indegree[j]++;
//                      outdegree[i]++;
//                    }
//                  }
// 	 }
// 	 int celeb=-1;
// 	 for(int i=0;i<n;i++){
// 		 if(indegree[i]==n-1 && outdegree[i]==0){
// 			 celeb=i;
// 			 break;
// 		 }
// 	 }
// 	 return celeb;
// }
// Optimised Code
int findCelebrity(int n) {
    
    int celebrity = -1;

    // Check one by one whether the person is a celebrity or not.
    for(int i = 0; i < n; i++) {
        bool knowAny = false, knownToAll = true;

        // Check whether perosn with id 'i' knows any other person.
        for(int j = 0; j < n; j++) {
            if(knows(i, j)) { //aur if(know(i,j))true means i knows j
                knowAny = true;
                break;
            }
        }

        // Check whether perosn with id 'i' is known to all the other person.
        for(int j = 0; j < n; j++) {
            if(i != j and !knows(j, i)) { //hum kah rai agr j , i false 
			// aya means !(true) to knowntoall false kar do ,means koi janta ni hoga
			// use to false
                knownToAll = false;
                break;
            }
        }

        if(!knowAny && knownToAll) { 
            celebrity = i;
            break;
        }
    }

    return celebrity;
}
