//#include <stdlib.h> 
// #include <stdio.h> 
#include <time.h> 
#include <iostream>


  
int main () 
{ 
    time_t t ; 
    struct tm *tmp ; 
    char current_time[20]; 
    time( &t ); 
      
    tmp = localtime(&t); 
      
   
    strftime(current_time, sizeof(current_time), "%Y%m%d_%H%M%S", tmp); 
    std::cout << "[" << current_time << "]";
    std::cout <<std::endl;
    //printf("[%s]\n", current_time ); 
    return(0); 
}

//[20150406_153629]