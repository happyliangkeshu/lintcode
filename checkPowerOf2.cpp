   #include <iostream>
   using namespace std;
   
    bool checkPowerOf2(int n);
   int main()
   {
   	for(int i =-30; i < 100 ; ++i){
   		
   		cout << i << ' ' <<	checkPowerOf2(i) << ' ' << endl;
   		
	   }
   		
   	
   	return 0;
   }
   
   bool checkPowerOf2(int n) {
        // write your code here
        if (n <= 0 )
        return false;
        
       n &= (n - 1);
       if(n == 0)
       return true;
       else 
       return false;

    }
